#include <stdio.h>

#define TABLE_SIZE 7

int hashTable[TABLE_SIZE];

// Initialize table to -1 (empty)
void initTable() {
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = -1;
}

int hash(int key) {
    return key % TABLE_SIZE;
}

void insert(int key) {
    int index = hash(key);
    int i = 0;

    // while (hashTable[(index + i*i) % TABLE_SIZE] != -1) {
    //     i++;
    //     if (i == TABLE_SIZE) {
    //         printf("Hash table is full\n");
    //         return;
    //     }
    // }

    int newIndex = (index + i*i) % TABLE_SIZE;
    hashTable[newIndex] = key;
}

void display() {
    for (int i = 0; i < TABLE_SIZE; i++)
        printf("Index %d: %d\n", i, hashTable[i]);
}

int main() {
    initTable();

    insert(10);
    insert(20);
    insert(5);
    insert(15);
    insert(7);

    display();

    return 0;
}
