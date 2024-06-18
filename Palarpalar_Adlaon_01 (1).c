/* Written by: Cherlie Palarpalar and Jodell Adlaon
CMSC 28 - Programming Exercise 01 - Linked List Implementation 
This program takes an item (withy variable type char) and stores it in a linked list. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {   // Node structure
    char data[100];     // Item data
    struct Node *next;  // Pointer to the next node
} Node;                 // Alias for struct Node

Node *head = NULL;      // Pointer to the first node

// Function prototypes

// Function to load the list from the file
void loadList() {
    FILE* file = fopen("Palarpalar_Adlaon_01.txt", "r");           // Open the file for reading
    if (file == NULL) {                            // If the file cannot be opened, return
        return;
    }
    char item[100];                                 // Item to be read from the file
    Node* temp = NULL;                              // Temporary pointer to the current node
    while (fgets(item, sizeof(item), file)) {       // Read the item from the file
        item[strcspn(item, "\n")] = 0;              // Remove the newline character
        Node* node = (Node*)malloc(sizeof(Node));   // Allocate memory for the new node
        strcpy(node->data, item);                   // Copy the item to the new node
        node->next = NULL;                          // Set the next pointer of the new node to NULL
        
        // If the list is empty, set the head to the new node, else set the next pointer of the current node to the new node
        if (head == NULL) {
            head = node;
        } else {
            temp->next = node;
        }
        temp = node;                                // Set the temporary pointer to the new node
    }
    fclose(file);
}

// Function to save the list to the file
void saveList() {
    FILE* file = fopen("Palarpalar_Adlaon_01.txt", "w");                // Open the file for writing
    if (file == NULL) {                                 // If the file cannot be opened, return
        printf("Unable to open file for writing\n");
        return;
    }
    Node* node = head;                                  // Pointer to the current node
    
    // While the list is not empty, write the item to the file
    while (node != NULL) {
        fprintf(file, "%s\n", node->data);
        node = node->next;
    }
    fclose(file);
}

// Function to add an item to the list
void addItem() {
    char item[100];                                 // Item to be added
    int choice;                                     // Choice of position of the item
    printf("\nPlease enter the item to be added: ");  // Prompt for the item
    scanf("%s", item);                              // Read the item
    
    // Convert the item to lowercase
    for (int i = 0; item[i] != '\0'; i++) {
        item[i] = tolower(item[i]);
    }
    
    printf("Where to add the item?\n[1] Start of the list\n[2] End of the list\n[3] Specific position\n[0] Cancel\n"); 
    printf("Enter choice: ");                       // Prompt for the choice
    scanf("%d", &choice);                           // Read the choice
    Node *node = (Node *)malloc(sizeof(Node));      // Allocate memory for the new node
    strcpy(node->data, item);                       // Copy the item to the new node
    
    // Add the new node to the list
    while (1) {
        if (choice == 1) {                      // Add to the start of the list            
            node->next = head;                  // Set the next pointer of the new node to the current head
            head = node;                        // Set the head to the new node
            break;
        } else if (choice == 2) {               // Add to the end of the list
            if (head == NULL) {                 // If the list is empty
                node->next = NULL;              // Set the next pointer of the new node to NULL
                head = node;                    // Set the head to the new node
            } else {
                Node* temp = head;              // Temporary pointer to the head
                while (temp->next != NULL) {    // While the next pointer of the current node is not NULL
                    temp = temp->next;          // Move to the next node
                }
                temp->next = node;              // Set the next pointer of the last node to the new node
                node->next = NULL;              // Set the next pointer of the new node to NULL
            }
            break;
        } else if (choice == 3) {               // Add to a specific position
            int pos;                            // Position of the new node
            printf("Enter the position: ");     // Prompt for the position
            scanf("%d", &pos);                  // Read the position
            Node* temp = head;                  // Temporary pointer to the head
            
            // While the position is not found
            for (int i = 1; temp != NULL && i < pos-1; i++) {  
                temp = temp->next;              // Move to the next node
            }
            if (temp != NULL) {                 // If the position is found
                node->next = temp->next;        // Set the next pointer of the new node to the next node of the current node
                temp->next = node;              // Set the next pointer of the current node to the new node
            } else {                            // If the position is not found
                printf("Position not found. Adding to the end of the list.\n");  // Prompt that the position is not found
                temp = head;                    // Reset the temporary pointer to the head
                while (temp->next != NULL) {    // Traverse the list until the last node
                    temp = temp->next;          // Move to the next node
                }
                temp->next = node;              // Set the next pointer of the last node to the new node
                node->next = NULL;              // Set the next pointer of the new node to NULL
            }
            break;
        } else if (choice == 0) {               // Cancel the operation    
            return;                             // Return to the main menu
        } // Invalid choice
          else {
            printf("Invalid choice. Please try again.\n");
            printf("Enter choice: ");           // Prompt for the choice
            scanf("%d", &choice);               // Read the choice again
        }
    }
}

// Function to delete an item from the list
void deleteItem() {
    char item[100];                                     // Item to be deleted
    printf("Please enter the item to be deleted: ");    // Prompt to enter the item
    scanf("%s", item);                                  // Read the item
    
    // Convert the item searched to lowercase
    for (int i = 0; item[i] != '\0'; i++) {
        item[i] = tolower(item[i]);
    }
    
    Node *temp = head;      // Pointer to the current node
    Node *prev = NULL;      // Pointer to the previous node

    // Delete the item from the list
    // If the item is at the start of the list
    if (temp != NULL && strcmp(temp->data, item) == 0) {
        head = temp->next;  // Set the head to the next node
        free(temp);         // Free the memory of the node
        printf("The element %s, which is at position 1, has been deleted\n", item);
        return;
    }

    // Search the list until the item is found
    int position = 1;       // Position of the current node
    while (temp != NULL && strcmp(temp->data, item) != 0) {
        prev = temp;        // Set the previous pointer to the current node
        temp = temp->next;  // Move to the next node
        position++;         // Increment the position
    }

    // If the item is not found
    if (temp == NULL) {
        printf("The list contains no such element\n");
        return;
    }
    prev->next = temp->next;    // Unlink the node from the list
    free(temp);                 // Free the memory of the node
    printf("The element %s, which is at position %d, has been deleted\n", item, position);
}

// Function to display the list
void displayList() {
    Node *node = head;          // Pointer to the current node
    int i = 1;                  // Position of the current node
    
    // While the list is not empty
    while (node != NULL) {
        printf("Position %d: %s\n", i, node->data);
        node = node->next;      // Move to the next node
        i++;                    // Increment the position
    }
}

// Function to delete the list
void deleteList() {
    Node *current = head;       // Pointer to the current node
    Node *next;                 // Pointer to the next node

    // While the list is not empty
    while (current != NULL) {
        next = current->next;   // Set the next pointer to the next node
        free(current);          // Free the memory of the current node
        current = next;         // Move to the next node
    }
    head = NULL;                // Set the head to NULL
    printf("The list has been emptied!\n");
}

int main() {
    loadList();                     // Load the list from the file
    // While the user does not exit the program
    while (1) {
        int choice;                 // Choice of operation
        printf("\nList MENU\n[1] Add Item\n[2] Delete Item\n[3] Display List\n[4] Delete List\n[0] Exit Program\n");
        printf("Enter choice: ");   // Prompt for the choice
        scanf("%d", &choice);       // Read the choice
        
        // Perform the operation based on the choice
        if (choice == 1) {          
            addItem();
        } else if (choice == 2) {
            deleteItem();
        } else if (choice == 3) {
            displayList();
        } else if (choice == 4) {
            deleteList();
        } else if (choice == 0) {
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    saveList();                     // Save the list to the file
    return 0;
}
