#include <stdio.h>
#include <stdlib.h>
#include "recipe.h"
#include "material.h"

void freeAll(Recipe*, Material*, const int);

void freeAll(Recipe* recipes, Material* materials, const int recLen)
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

    free(recipes);

    free(materials);
}

int main()
{
    int matLen = 0;
    Material* materials = loadMaterials(&matLen);

    printf("------------------------\nLoaded %d materials\n",matLen);

    int recLen = 0;
    Recipe* recipes = loadRecipes(&recLen, materials, matLen);

    printf("------------------------\nLoaded %d recipes\n",matLen);

    freeAll(recipes, materials, recLen);

    return 0;
}