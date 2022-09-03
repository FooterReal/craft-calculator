#include <stdio.h>
#include "recipe.h"

void AddRecipe(char* recipe, Recipe* recipes,
    const int* len, int* const maxlen, Material* const materials, const int matLen)
{
    if ((*len) == (*maxlen)) {
        *maxlen += 10;
        recipes = (Recipe*)realloc(recipes,sizeof(Recipe) * (*maxlen));
    }

    char* craftMats = strtok_r(recipe, "=>", &recipe);
    char* result = strtok_r(0, "=>", &recipe);

    char* cmats_tok = strtok_r(craftMats, ",", &craftMats);
    recipes[*len].materialsLength = 0;

    while (cmats_tok != NULL)
    {
        const char* amount = strtok_r(cmats_tok,";",&cmats_tok);
        const char* name = strtok_r(0,";",&cmats_tok);

        int index = IndexOfMaterial(materials, name, matLen);

        if (index == -1)
        {
            printf("Unkown material: %s\n",name);
        }
        else
        {
            int craftLen = recipes[*len].materialsLength;

            recipes[*len].materials[craftLen] = (CraftingMaterial*)malloc(sizeof(CraftingMaterial));

            int* amHelper = (int*)malloc(sizeof(int));
            (*amHelper) = atoi(amount);

            recipes[*len].materials[craftLen]->amount = amHelper;
            recipes[*len].materials[craftLen]->material = materials + index;

            recipes[*len].materialsLength++;
        }

        cmats_tok = strtok_r(0, ",", &craftMats);
    }

    const char* amount = strtok_r(result,";",&result);
    const char* name = strtok_r(0,";",&result);

    int index = IndexOfMaterial(materials, name, matLen);

    if (index == -1)
    {
        printf("Unkown material: %s\n",name);
    }
    else
    {
        recipes[(*len)].result = (CraftingMaterial*)malloc(sizeof(CraftingMaterial));

        int* amHelper = (int*)malloc(sizeof(int));
        (*amHelper) = atoi(amount);

        recipes[(*len)].result->amount = amHelper;
        recipes[(*len)].result->material = materials + index;
        
        if ((materials + index)->base) (materials + index)->base = false;
    }
}

Recipe* loadRecipes(int* len, Material* materials, const int matLen)
{
    FILE* recipeFile = fopen("./src/recipes.txt","r");

    if (recipeFile == NULL) {
        printf("Error: File 'materials.txt' couldn't be opened.\n");
        exit(1);
    }

    Recipe* recipes = (Recipe*)malloc(sizeof(Recipe) * 10);
    int maxlen = 10;

    char buffer[500];
    char* recipe = (char*)malloc(sizeof(buffer) + 1);

    while (!feof(recipeFile))
    {
        fgets(buffer,500,recipeFile);
        buffer[strcspn(buffer, "\r\n")] = 0;

        strcpy(recipe, buffer);

        AddRecipe(recipe,recipes,len,&maxlen,materials,matLen);

        printf("Loaded recipe for %s\n",recipes[(*len)].result->material->name);

        (*len)++;
    }

    free(recipe);

    fclose(recipeFile);

    return recipes;
}

void writeRecipe(const Recipe* const rec)
{
    printf("Recipe (%d materials):\n",rec->materialsLength);

    for(int i = 0; i < rec->materialsLength; i++)
    {
        printf("Needs %d %s\n",*(rec->materials[i]->amount),rec->materials[i]->material->name);
    }

    printf("Makes %d %s\n",*(rec->result->amount),rec->result->material->name);
}