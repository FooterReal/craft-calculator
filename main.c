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
void AddMaterial(const char*, Material*, int* const, int* const);
void AddRecipe(char*, Recipe*, const int*, const int*, const Material*, const int);
int IndexOfMaterial(const Material*, const char*, const int);

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
    int maxlen = 10;

    char buffer[50];

    while (!feof(materialFile))
    {
        fgets(buffer,50,materialFile);

        buffer[strcspn(buffer, "\r\n")] = 0;
        char* material = (char*)malloc(sizeof(char)*50);

        strcpy(material,buffer);    

        AddMaterial(material,materials,len,&maxlen);

        free(material);

        printf("Loaded %s\n",buffer);
    }

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
    const int* len, const int* maxlen, const Material* materials, const int matLen)
{
    if (len == maxlen) {
        maxlen += 10;
        recipes = (Recipe*)realloc(recipes,sizeof(Recipe) * (*maxlen));
    }

    char* token;
    token = strtok_r(recipe,"=>", &recipe);
    
    printf("%s\n",token);
}

Recipe* loadRecipes(int* len, Material* materials, const int matLen)
{
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

int main()
{
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