#include <stdio.h>

#define TABLE_SIZE 7

int hashTable[TABLE_SIZE];

// Initialize all slots to -1 (empty)
void initTable() {
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = -1;
}

// Simple hash function
int hash(int key) {
    return key % TABLE_SIZE;
}

// Insert key with linear probing collision handling
void insert(int key) {
    int index = hash(key);
    int i = 0;

    // Probe linearly until empty slot
    while (hashTable[(index + i) % TABLE_SIZE] != -1) {
        i++;
        if (i == TABLE_SIZE) {  // Table full
            printf("Hash table is full\n");
            return;
        }
    }

    hashTable[(index + i) % TABLE_SIZE] = key;
}

// Display hash table contents
void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: %d\n", i, hashTable[i]);
    }
}

int main() {
    initTable();

    insert(10);
    insert(20);
    insert(5);
    insert(15);
    insert(7);
    insert(32);

    display();

    return 0;
}
