#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct storage{
    char name[25];
    char category[20];
};
const int tableSize = 7;
struct storage hashTable[tableSize];

void init(){
    for (int i = 0; i < tableSize; i++){
        strcpy(hashTable[i].name, "");
        strcpy(hashTable[i].category, "");
    }
}

int generateKey(const char *name){
    int key;
    key = name[0] - 'A';
    return key % tableSize;
}

int linearProbing(int key){
    int i = key;
    //[15%] (1) INSERT YOUR CODE HERE
    //parse through hastable from top to bottom then bottom to up till index
    while (i < tableSize){
        if (strcmp(hashTable[i].name, "") == 0)
            return i;
        i++;
        if (i == tableSize)
            i = 0;
        if (i == key){
            return -1;
        }
    }

    return -1;
}

void insert(const char *name, const char *category){
    //[15%] (2) INSERT YOUR CODE HERE
    int index = generateKey(name);
    //check if the cell is emoty or not at index in hashtable
    if (strlen(hashTable[index].name) > 0)
        index = linearProbing(index);
    if (index == -1)
        printf("The hashTable is full!\n");

    strcpy(hashTable[index].name, name);
    strcpy(hashTable[index].category, category);
}

void printAll(){
    for (int i = 0; i < tableSize; i++){
        printf("[%2d] : ", i);
        if (strcmp(hashTable[i].name, "") != 0){
            printf("%s", hashTable[i].name);
        }else{
            printf("NULL");
        }
        printf("\n");
    }
}

int main(){
    init();
    insert("Sate Ayam", "Daging");
    insert("Gulai Kambing", "Daging");
    insert("Kangkung", "Sayuran");
    insert("Coca Cola", "Minuman");
    insert("Sate Kambing", "Daging");
    insert("Opor Ayam", "Daging");
    insert("Sprite", "Minuman");
    insert("Fanta", "Minuman");
    insert("Ayam Kalasan", "Daging");
    printAll();
    return 0;
}
