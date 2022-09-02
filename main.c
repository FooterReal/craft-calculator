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
    int amount;
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
void AddMaterial(char*, Material*, int*, int*);
void AddRecipe(char*, Recipe*, int*, int*, Material*, const int);
int IndexOfMaterial(Material*, char*, const int);

void AddMaterial(char* material, Material* materials, int* len, int* maxlen) {
    if (len == maxlen) {
        maxlen += 10;
        materials = realloc(materials,sizeof(Material) * (*maxlen));
    }

    strcpy(materials[*len].name, material);

    (*len)++;
}

Material* loadMaterials(int* len) {
    FILE* materialFile = fopen("materials.txt","r");

    Material* materials = (Material*)malloc(sizeof(Material) * 10);
    int maxlen = 10;

    char buffer[50];

    while (!feof(materialFile))
    {
        fgets(buffer,50,materialFile);
        buffer[strcspn(buffer, "\r\n")] = 0;
        AddMaterial(buffer,materials,len,&maxlen);

        printf("Loaded %s\n",buffer);
    }

    fclose(materialFile);

    return materials;
}

int IndexOfMaterial(Material* materials, char* material, const int len) {
    int i = 0;
    while(i < len && strcmp(materials[i].name,material) != 0) i++;

    if (i >= len) i = -1;
    return i;
}

void AddRecipe(char* recipe, Recipe* recipes, int* len, int* maxlen, Material* materials, const int matLen) {
    if (len == maxlen) {
        maxlen += 10;
        recipes = realloc(recipes,sizeof(Recipe) * (*maxlen));
    }

    char* token = strtok(recipe,"=>");
    
    printf("%s\n",token);
}

Recipe* loadRecipes(int* len, Material* materials, const int matLen) {
    FILE* recipeFile = fopen("recipes.txt","r");

    Recipe* recipes = (Recipe*)malloc(sizeof(Recipe) * 10);
    int maxlen = 10;

    char buffer[500];

    while (!feof(recipeFile))
    {
        fgets(buffer,500,recipeFile);
        buffer[strcspn(buffer, "\r\n")] = 0;
        AddRecipe(buffer,recipes,len,&maxlen,materials,matLen);

        printf("Loaded recipe for %s\n",recipes->result);
    }

    fclose(recipeFile);

    return recipes;
}

int main() {
    int matLen = 0;
    Material* materials = loadMaterials(&matLen);

    printf("------------------------\nLoaded %d materials\n",matLen);

    int recLen = 0;
    Recipe* recipes = loadRecipes(&recLen, materials, matLen);

    printf("------------------------\nLoaded %d recipes\n",matLen);

    free(materials);
    free(recipes);

    return 0;
}