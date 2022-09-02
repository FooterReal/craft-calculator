#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct material;
typedef struct material Material;

struct material {
    char name[50];
    bool base;
};

struct craftmaterial;
typedef struct craftmaterial CraftingMaterial;

struct craftmaterial {
    int* amount;
    Material* material;
};

struct recipe;
typedef struct recipe Recipe;

struct recipe {
    CraftingMaterial* result;
    CraftingMaterial* materials[9];
    int materialsLength;
};

Material* loadMaterials(int*);
Recipe* loadRecipes(int*, Material*, const int);
void AddMaterial(const char*, Material*, int* const, int* const);
void AddRecipe(char*, Recipe*, const int* , int* const, Material* const, const int);
int IndexOfMaterial(const Material*, const char*, const int);
void freeAll(Recipe*, Material*, const int, const int);

void AddMaterial(const char* material, Material* materials, int* const len , int* const maxlen)
{
    if ((*len) == (*maxlen)) {
        (*maxlen) += 10;
        materials = realloc(materials,sizeof(Material) * (*maxlen));
    }

    strcpy(materials[*len].name, material);

    (*len) = (*len) + 1;
}

Material* loadMaterials(int* const len)
{
    FILE* materialFile = fopen("materials.txt","r");

    if (materialFile == NULL) {
        printf("Error: File 'materials.txt' couldn't be opened.\n");
        exit(1);
    }

    Material* materials = (Material*)malloc(sizeof(Material) * 10);
    int* const maxlen = (int*)malloc(sizeof(int));
    (*maxlen) = 10;

    char buffer[50];
    char* material = (char*)malloc(sizeof(buffer) + 1);

    while (!feof(materialFile))
    {
        fgets(buffer,50,materialFile);

        buffer[strcspn(buffer, "\r\n")] = 0;

        strcpy(material, buffer);    

        AddMaterial(material, materials, len, maxlen);

        printf("Loaded %s\n", material);
    }

    free(material);

    fclose(materialFile);

    return materials;
}

int IndexOfMaterial(const Material* materials, const char* material, const int len)
{
    int i = 0;
    while(i < len && strcmp(materials[i].name,material) != 0) i++;

    if (i >= len) i = -1;
    return i;
}

void AddRecipe(char* recipe, Recipe* recipes,
    const int* len, int* const maxlen,  Material* const materials, const int matLen)
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
    }
}

Recipe* loadRecipes(int* len, Material* materials, const int matLen)
{
    FILE* recipeFile = fopen("recipes.txt","r");

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

void freeAll(Recipe* recipes, Material* materials, const int recLen, const int matLen)
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

    freeAll(recipes, materials, recLen, matLen);

    return 0;
}