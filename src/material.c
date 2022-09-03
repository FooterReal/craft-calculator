#include <stdio.h>
#include "material.h"

void AddMaterial(const char* material, Material* materials, int* const len , int* const maxlen)
{
    if ((*len) == (*maxlen)) {
        (*maxlen) += 10;
        materials = realloc(materials,sizeof(Material) * (*maxlen));
    }

    strcpy(materials[*len].name, material);
    materials[*len].base = true;

    (*len) = (*len) + 1;
}

Material* LoadMaterials(int* const len)
{
    FILE* materialFile = fopen("./src/materials.txt","r");

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

void WriteMaterial(const Material* const mat) 
{
    char tr[10] = "true\0";
    char fr[10] = "false\0";

    if(mat->base) printf("Material: %s (%s)\n",mat->name,tr);
    else printf("Material: %s (%s)\n",mat->name,fr);   
}

void WriteCraftingMaterial(const CraftingMaterial* const mat)
{
    char tr[10] = "true\0";
    char fr[10] = "false\0";

    if(mat->material->base) printf("Crafting mat: %d %s (%s)\n",*(mat->amount),mat->material->name,tr);
    else printf("Crafting mat: %d %s (%s)\n",*(mat->amount),mat->material->name,fr);
}

void AddCraftingMaterial(const char* name, const int amount,
     CraftingMaterial* mats, int* const len, int* const maxlen, Material* const materials, const int matLen)
{
    int index = IndexOfMaterial(materials,name,matLen);

    if (index == -1)
    {
        printf("Unkown material: %s\n",name);
    }
    else 
    {
        if((*len) == (*maxlen))
        {
            (*maxlen) += 10;
            mats = (CraftingMaterial*)realloc(mats,sizeof(CraftingMaterial)*(*maxlen));
        }

        mats[*len].amount = (int*)malloc(sizeof(int));
        *(mats[*len].amount) = amount;

        mats[*len].material = materials+index;

        (*len)++;
    }
}

CraftingMaterial* GetRequired(int* const len, Material* const materials, const int matLen)
{
    int maxlen = 10;
    CraftingMaterial* mats = (CraftingMaterial*)malloc(sizeof(CraftingMaterial)*maxlen);

    int amount = -1;
    char name[50];

    printf("Input required materials!\n");

    do
    {
        printf("Amount (0 or lower to stop): ");
        scanf("%d",&amount);

        if (amount > 0)
        {
            printf("Name: ");
            scanf("%c", name);
            scanf("%[^\n]", name);

            AddCraftingMaterial(name, amount, mats, len, &maxlen, materials, matLen);
        }
    } while (amount > 0);
    
    return mats;
}