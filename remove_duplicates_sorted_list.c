/*************************************************************** 

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,

Given 1->1->2, return 1->2.

Given 1->1->2->3->3, return 1->2->3.


 ***************************************************************/
/**
 * @input A : Head pointer of linked list 
 * 
 * @Output head pointer of list.
 */


#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
 };
 
 typedef struct ListNode listnode;


// Function to create a new node
listnode* listnode_new(int val) {
    listnode* node = (listnode *) malloc(sizeof(listnode));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    node->val = val;
    node->next = NULL;
    return node;
}



// Function to remove duplicates from a sorted linked list
listnode* deleteDuplicates(listnode* head) {
    if (head == NULL) return head;

    listnode* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->val == current->next->val) {
            listnode* duplicate = current->next;
            current->next = current->next->next; // Skip the duplicate node
            free(duplicate); // Free the memory of the duplicate node
        } else {
            current = current->next; // Move to the next node
        }
    }
    return head;
}

// Function to delete a node with a specific value from the list
void delete_node(listnode** head, int val) {
    if (*head == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return;
    }

    listnode* current = *head;
    listnode* prev = NULL;

    // If the head node contains the value to be deleted
    if (current->val == val) {
        *head = current->next;
        free(current);
        printf("Deleted node with value %d.\n", val);
        return;
    }

    // Traverse the list to find the node to delete
    while (current != NULL && current->val != val) {
        prev = current;
        current = current->next;
    }

    // If the value is not found
    if (current == NULL) {
        printf("Value %d not found in the list.\n", val);
        return;
    }

    // Unlink the node and free memory
    prev->next = current->next;
    free(current);
    printf("Deleted node with value %d.\n", val);
}



// Function to add a new node at the end of the list
void append_node(listnode** head, int val) {
    listnode* new_node = listnode_new(val);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    listnode* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

// Function to print the linked list
void print_list(listnode* head) {
    listnode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to free the memory of the linked list
void free_list(listnode* head) {
    listnode* current = head;
    while (current != NULL) {
        listnode* temp = current;
        current = current->next;
        free(temp);
    }
}

// Main function to demonstrate usage
int main() {
    listnode* head = NULL;

    // Add nodes to the list
    append_node(&head, 1);
    append_node(&head, 1);
    append_node(&head, 2);

    // Print the list
    printf("Linked List: ");
    print_list(head);

    // remove duplicates
    printf("\nremoving duplicates...\n");
    deleteDuplicates(head);
    printf("New linked List: ");
    print_list(head);

    // Free the list
    free_list(head);

    return 0;
}