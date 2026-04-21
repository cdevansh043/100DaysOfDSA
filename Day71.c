#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY -1
#define DELETED -2

typedef struct {
    int *table;
    int size;
} HashTable;

HashTable* createTable(int m) {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->size = m;
    ht->table = (int*)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) ht->table[i] = EMPTY;
    return ht;
}

void insert(HashTable* ht, int key) {
    for (int i = 0; i < ht->size; i++) {
        int idx = (key % ht->size + i * i) % ht->size;
        if (ht->table[idx] == EMPTY || ht->table[idx] == DELETED) {
            ht->table[idx] = key;
            return;
        }
    }
}

int search(HashTable* ht, int key) {
    for (int i = 0; i < ht->size; i++) {
        int idx = (key % ht->size + i * i) % ht->size;
        if (ht->table[idx] == EMPTY) return 0;
        if (ht->table[idx] == key) return 1;
    }
    return 0;
}

int main() {
    int m, n;
    if (scanf("%d %d", &m, &n) != 2) return 0;

    HashTable* ht = createTable(m);
    char cmd[10];
    int key;

    for (int i = 0; i < n; i++) {
        scanf("%s %d", cmd, &key);
        if (strcmp(cmd, "INSERT") == 0) {
            insert(ht, key);
        } else if (strcmp(cmd, "SEARCH") == 0) {
            if (search(ht, key)) printf("FOUND\n");
            else printf("NOT FOUND\n");
        }
    }

    free(ht->table);
    free(ht);
    return 0;
}