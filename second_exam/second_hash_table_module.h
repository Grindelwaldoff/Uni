typedef struct {
    char* key;
    double value;
} Entry;

typedef struct {
    Entry* entries;
    int size;
} HashTable;

HashTable* max_min_finder(double element, HashTable* min_max_table, int i);

void destroyHashTable(HashTable* hashTable);

double get(HashTable* hashTable, char* key);

void insert(HashTable* hashTable, char* key, double value);

HashTable* createHashTable(void);
