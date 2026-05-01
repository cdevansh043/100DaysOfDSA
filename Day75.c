#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    int value;
} HashNode;

typedef struct {
    int size;
    HashNode *table;
} HashMap;

int hash(int key, int size) {
    int h = key % size;
    return (h < 0) ? h + size : h;
}

void insert(HashMap *map, int key, int value) {
    int idx = hash(key, map->size);
    while (map->table[idx].value != -2) {
        if (map->table[idx].key == key) return;
        idx = (idx + 1) % map->size;
    }
    map->table[idx].key = key;
    map->table[idx].value = value;
}

int find(HashMap *map, int key) {
    int idx = hash(key, map->size);
    int startIdx = idx;
    while (map->table[idx].value != -2) {
        if (map->table[idx].key == key) return map->table[idx].value;
        idx = (idx + 1) % map->size;
        if (idx == startIdx) break;
    }
    return -1;
}

int main() {
    int arr[10000], n = 0;
    while (scanf("%d", &arr[n]) != EOF) n++;

    HashMap map;
    map.size = n * 2 + 1;
    map.table = (HashNode *)malloc(map.size * sizeof(HashNode));
    for (int i = 0; i < map.size; i++) map.table[i].value = -2;

    int max_len = 0, curr_sum = 0;
    for (int i = 0; i < n; i++) {
        curr_sum += arr[i];
        if (curr_sum == 0) {
            max_len = i + 1;
        } else {
            int prev_idx = find(&map, curr_sum);
            if (prev_idx != -1) {
                if (i - prev_idx > max_len) max_len = i - prev_idx;
            } else {
                insert(&map, curr_sum, i);
            }
        }
    }

    printf("%d\n", max_len);
    free(map.table);
    return 0;
}