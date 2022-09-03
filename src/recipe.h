#ifndef RECIPE_H_
#define RECIPE_H_

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "material.h"

struct recipe;
typedef struct recipe Recipe;

struct recipe {
    CraftingMaterial* result;
    CraftingMaterial* materials[9];
    int materialsLength;
};

Recipe* loadRecipes(int*, Material*, const int);
void AddRecipe(char*, Recipe*, const int* , int* const, Material* const, const int);
void writeRecipe(const Recipe* const);

#endif