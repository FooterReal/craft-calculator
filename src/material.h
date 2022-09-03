#ifndef MATERIAL_H_
#define MATERIAL_H_

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

Material* loadMaterials(int*);
void AddMaterial(const char*, Material*, int* const, int* const);
int IndexOfMaterial(const Material*, const char*, const int);
void writeMaterial(const Material* const);
void writeCraftingMaterial(const CraftingMaterial* const);

CraftingMaterial* getRequired(int* const, Material* const, const int);

#endif