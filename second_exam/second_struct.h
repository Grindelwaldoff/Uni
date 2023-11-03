/*
эта структура и функция которая ее использует
заменяет следующие 4 строчки
min = (order[i] < min)? order[i] : (i == 1)? order[i] : min;
max = (order[i] > max)? order[i] : (i == 1)? order[i] : max;
min_index = (order[i] == min)? i : min_index;
max_index = (order[i] == max)? i : max_index;

NO COMMENTS
*/


#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 4

typedef struct {
    char* key;
    double value;
} Entry;

typedef struct {
    Entry* entries;
    int size;
} HashTable;

int hash(char* key) {
    int hashValue = 0;
    for (int i = 0; i < strlen(key); i++) {
        hashValue += key[i];
    }
    return hashValue % TABLE_SIZE;
}

HashTable* createHashTable() {
    HashTable* hashTable = (HashTable*) malloc(sizeof(HashTable));
    hashTable->entries = (Entry*) malloc(TABLE_SIZE * sizeof(Entry));
    hashTable->size = TABLE_SIZE;
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable->entries[i].key = NULL;
        hashTable->entries[i].value = 0;
    }
    return hashTable;
}

void insert(HashTable* hashTable, char* key, double value) {
    int index = hash(key);
    while (hashTable->entries[index].key!= NULL) {
        if (strcmp(hashTable->entries[index].key, key) == 0) {
            hashTable->entries[index].value = value;
            return;
        }
        index = (index + 1) % hashTable->size;
    }
    hashTable->entries[index].key = strdup(key);
    hashTable->entries[index].value = value;
}

double get(HashTable* hashTable, char* key) {
    int index = hash(key);
    while (hashTable->entries[index].key!= NULL) {
        if (strcmp(hashTable->entries[index].key, key) == 0) {
            return hashTable->entries[index].value;
        }
        index = (index + 1) % hashTable->size;
    }
    return 0;
}


void destroyHashTable(HashTable* hashTable) {
    for (int i = 0; i < hashTable->size; i++) {
        if (hashTable->entries[i].key!= NULL) {
            free(hashTable->entries[i].key);
        }
    }
    free(hashTable->entries);
    free(hashTable);
}
