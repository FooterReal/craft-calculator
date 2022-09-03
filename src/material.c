#include <stdio.h>
#include "material.h"

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