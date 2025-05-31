/*
Objective
Today, we're learning about Key-Value pair mappings using a Map or Dictionary data structure. Check out the 
Tutorial tab for learning materials and an instructional video!

Task
Given n names and phone numbers, assemble a phone book that maps friends' names to their respective phone numbers. 
You will then be given an unknown number of names to query your phone book for. For each n queried, print the 
associated entry from your phone book on a new line in the form name=phoneNumber; if an entry for name is not found, 
print Not found instead.

Note: Your phone book should be a Dictionary/Map/HashMap data structure.

Input Format
The first line contains an integer, n, denoting the number of entries in the phone book.
Each of the  subsequent lines describes an entry in the form of 2 space-separated values on a single line. The 
first value is a friend's name, and the second value is an 8-digit phone number.

After the n lines of phone book entries, there are an unknown number of lines of queries. Each line (query) contains
a name to look up, and you must continue reading lines until there is no more input.

Note: Names consist of lowercase English alphabetic letters and are first names only.

Constraints
1 <= n <= 10^5
1 <= queries <= 10^5

Output Format
On a new line for each query, print Not found if the name has no corresponding entry in the phone book; otherwise, 
print the full name and phoneNumber in the format name=phoneNumber.

Sample Input

3
sam 99912222
tom 11122222
harry 12299933
sam
edward
harry


Sample Output

sam=99912222
Not found
harry=12299933


Explanation
We add the following n=3 (Key,Value) pairs to our map so it looks like this:
phoneBook = {(sam, 99912222), (tom, 11122222), (harry, 12299933)}

We then process each query and print key=value if the queried key is found in the map; otherwise, we print Not found.

Query 0: sam
Sam is one of the keys in our dictionary, so we print sam=99912222.

Query 1: edward
Edward is not one of the keys in our dictionary, so we print Not found.

Query 2: harry
Harry is one of the keys in our dictionary, so we print harry=12299933.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100003  // A large prime number for better hashing
#define NAME_SIZE 100
#define PHONE_SIZE 10  // 8 digits + '\0'

typedef struct Node {
    char name[NAME_SIZE];
    char phone[PHONE_SIZE];
    struct Node* next;  // Linked list for collision handling
} Node;

Node* hashTable[TABLE_SIZE];  // Hash table

// DJB2 Hash Function (Fast and Efficient)
unsigned long hash(char* str) {
    unsigned long hash = 5381;  // Bernstein algorithm.
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;  // hash * 33 + c
    return hash % TABLE_SIZE;
}

// Insert into Hash Table
void insert(char* name, char* phone) {
    unsigned long index = hash(name);
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->next = hashTable[index];  // Insert at head
    hashTable[index] = newNode;
}

// Search in Hash Table
char* search(char* name) {
    unsigned long index = hash(name);
    Node* temp = hashTable[index];
    while (temp) {
        if (strcmp(temp->name, name) == 0)
            return temp->phone;
        temp = temp->next;
    }
    return NULL;
}

// Free Hash Table Memory
void freeTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* temp = hashTable[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
}

int main() {
    int n;
    char name[NAME_SIZE], phone[PHONE_SIZE];

    // Read number of entries
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid number of entries.\n");
        return EXIT_FAILURE;
    }

    // Read phone book entries
    for (int i = 0; i < n; i++) {
        if (scanf("%s %s", name, phone) != 2) {
            fprintf(stderr, "Invalid input format.\n");
            return EXIT_FAILURE;
        }
        insert(name, phone);
    }

    // Process queries until EOF
    while (scanf("%s", name) != EOF) {
        char* found = search(name);
        if (found)
            printf("%s=%s\n", name, found);
        else
            printf("Not found\n");
    }

    // Free memory
    freeTable();
    
    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100003  // A large prime number for better hashing
#define NAME_SIZE 100
#define PHONE_SIZE 10  // 8 digits + '\0'

typedef struct Node {
    char name[NAME_SIZE];
    char phone[PHONE_SIZE];
    struct Node* next;  // Linked list for collision handling
} Node;

Node* hashTable[TABLE_SIZE];  // Hash table

// DJB2 Hash Function (Fast and Efficient)
unsigned long hash(char* str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;  // hash * 33 + c
    return hash % TABLE_SIZE;
}

// Insert into Hash Table
void insert(char* name, char* phone) {
    unsigned long index = hash(name);
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->next = hashTable[index];  // Insert at head
    hashTable[index] = newNode;
}

// Search in Hash Table
char* search(char* name) {
    unsigned long index = hash(name);
    Node* temp = hashTable[index];
    while (temp) {
        if (strcmp(temp->name, name) == 0)
            return temp->phone;
        temp = temp->next;
    }
    return NULL;
}

// Free Hash Table Memory
void freeTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* temp = hashTable[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
}

int main() {
    int n;
    char name[NAME_SIZE], phone[PHONE_SIZE];

    // Read number of entries
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid number of entries.\n");
        return EXIT_FAILURE;
    }

    // Read phone book entries
    for (int i = 0; i < n; i++) {
        if (scanf("%s %s", name, phone) != 2) {
            fprintf(stderr, "Invalid input format.\n");
            return EXIT_FAILURE;
        }
        insert(name, phone);
    }

    // Process queries until EOF
    while (scanf("%s", name) != EOF) {
        char* found = search(name);
        if (found)
            printf("%s=%s\n", name, found);
        else
            printf("Not found\n");
    }

    // Free memory
    freeTable();
    
    return 0;
}*/