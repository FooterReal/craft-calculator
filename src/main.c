#include <stdio.h>
#include <stdlib.h>
#include "recipe.h"
#include "material.h"

void freeAll(Recipe*, Material*, CraftingMaterial*, const int, const int);

void freeAll(Recipe* recipes, Material* materials, CraftingMaterial* required, const int recLen, const int reqLen)
{
    for(int i = 0; i < recLen; i++)
    {
        int craftLen = recipes[i].materialsLength;

        for(int j = 0; j < craftLen; j++)
        {
            free(recipes[i].materials[j]->amount);
            free(recipes[i].materials[j]);
        }
    }

    for(int i = 0; i < reqLen; i++)
    {
        free(required[i].amount);
    }

    free(required);

    free(recipes);

    free(materials);
}

int main()
{
    int matLen = 0;
    Material* materials = LoadMaterials(&matLen);

    printf("------------------------\nLoaded %d materials\n\n",matLen);

    int recLen = 0;
    Recipe* recipes = LoadRecipes(&recLen, materials, matLen);

    printf("------------------------\nLoaded %d recipes\n\n",recLen);

    int reqLen = 0;
    CraftingMaterial* required = GetRequired(&reqLen, materials, matLen);

    int maxlen = reqLen + 10 - (reqLen % 10);

    for (int i = 0; i < reqLen; i++)
    {
        WriteCraftingMaterial(&required[i]);
    }

    printf("Maxlen: %d\n",maxlen);

    int i = 0;
    while(i < reqLen)
    {
        printf("Mat: %s\n",required[i].material->name);

        if (!required[i].material->base)
        {
            printf("Material not base.\n");

            Recipe* recipe = FindRecipe(required[i].material->name, recipes, recLen);
            int mult = *(required[i].amount);
            int div = *(recipe->result->amount);

            for (int j = 0; j < recipe->materialsLength; j++)
            {
                int needed = ((*recipe->materials[j]->amount) * mult);
                int remainder = needed % div;

                needed = needed / div;
                if (remainder > 0) needed += *(recipe->materials[j]->amount);

                AddCraftingMaterial(recipe->materials[j]->material->name, needed, required, &reqLen, &maxlen, materials, matLen); 
            }

            required[i] = required[reqLen-1];
            reqLen--;
        }
        else
        {
            printf("Material base.\n");

            i++;
        }
    }

    printf("Hello\n");

    for (int i = 0; i < reqLen; i++)
    {
        WriteCraftingMaterial(&required[i]);
    }

    freeAll(recipes, materials, required, recLen, reqLen);

    return 0;
}