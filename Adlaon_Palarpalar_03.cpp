/* Written by: Jodell Adlaon and Cherlie Palarpalar
CMSC 28 - Programming Exercise 03 - Stack Implementation */

#include <iostream> 
#include <cstring>  // for 'strcpy' function implementation

// Node structure for the linked list
struct Node {
    char data[100];     // Assuming each cell can hold a string of up to 99 characters (+1 for null terminator)
    Node* next;         // Pointer to the next node
};

// class 'Stack' representing a stack data structure
class Stack {       
private:
    static const int MAX_SIZE = 100;    // Maximum size of the stack
    // 'MAX_SIZE' and 'top' are private members of the 'Stack' class.
    // Access to 'top' is controlled through public member functions of the class, such as 'PUSH', 'POP', 'EMPTY', etc.
    Node* top;                          // Pointer to the top of the stack

public:
    // Constructor
    Stack() {
        top = nullptr;                  // Initialize top to nullptr (empty stack)
    }

    // Function to check if the stack is full
    bool FULL() { 
        int count = 0;                  // Initialize a counter variable to count the number of elements in the stack
        Node* current = top;            // Pointer to navigate through the stack, begin at the top
        while (current != nullptr) {    // Loop through the stack until the current node is nullptr (end of the stack)
            count++;                    // Increment the counter for each visited node 
            current = current->next;    // Move to the next node in the stack
        }
        return count == MAX_SIZE;       // Return true if the count equals the maximum size of the stack
    }

    // Function to check if the stack is empty
    bool EMPTY() { 
        return top == nullptr;          // Return true if the top pointer is nullptr, indicating the stack is empty
    }

    // Function to push an element onto the stack
    void PUSH(const char* value) {
        if (FULL()) {
            std::cout << "The STACK is FULL. Cannot add kitchenware.\n";
            return;                     // Return without pushing if the stack is full
        }
        Node* newNode = new Node();     // Create a new node
        strcpy(newNode->data, value);   // Copy the string into the node's data
        newNode->next = top;            // Set the new node's next pointer to the current top
        top = newNode;                  // Set top to point to the new node
    }

    // Function to pop an element from the stack
    char* POP() {
        if (EMPTY()) {
            return nullptr;
        }
        Node* temp = top;                                       // Store the current top
        top = top->next;                                        // Move top to the next node
        char* poppedValue = new char[strlen(temp->data) + 1];   // Allocate memory for the popped value
        strcpy(poppedValue, temp->data);                        // Copy the data from the top node
        delete temp;                                            // Delete the old top node
        return poppedValue;
    }

    // Function to return the top element of the stack
    char* TOP() { 
        if (EMPTY()) {          // Check if the stack is empty
            return nullptr;     // Return nullptr if the stack is empty
        }
        return top->data;       // Return the data of the top node of the stack
    }

    // Function to make the stack empty
    void MAKENULL() {
        while (!EMPTY()) {
            POP();              // Keep popping elements until stack becomes empty
        }
    }

    // Destructor to deallocate memory
    ~Stack() {
        MAKENULL();             // Make the stack empty 
    }
};

// Main function definition
int main() { 
    Stack kitchenwareStack;     // Create an instance of the Stack class named kitchenwareStack
    int choice;                 // Declare an integer variable to store the user's choice
    char kitchenware[100];      // Declare a character array to store kitchenware names

    // do-while loop to display the menu and process user input
    do { 
        std::cout << "\nKitchenware Washing Machine\n\n"; 
        std::cout << "[1] Add kitchenware\n"; 
        std::cout << "[2] Wash kitchenware\n"; 
        std::cout << "[3] Top kitchenware\n"; 
        std::cout << "[4] Wash all\n"; 
        std::cout << "[0] Exit\n";
        std::cout << "\nEnter choice: ";    // Prompt the user to enter a choice
        std::cin >> choice;                 // Read the user's choice from the console

        // switch statement to handle different menu choices
        switch (choice) { 
            case 1: // If user chooses option 1
                std::cout << "Enter kitchenware to be washed: ";                // Prompt the user to enter a kitchenware name
                std::cin >> kitchenware;                                        // Read the inputted kitchenware name from the console
                kitchenwareStack.PUSH(kitchenware);                             // Add the kitchenware to the stack
                std::cout << "Kitchenware to be washed added successfully.\n";  // Print a message indicating the kitchenware was added successfully
                break;                                                          // Exit the switch statement
            case 2: // If user chooses option 2
                if (!kitchenwareStack.EMPTY()) {                                        // Check if the stack is not empty
                    std::cout << kitchenwareStack.POP() << " is being washed.\n";       // Wash the top kitchenware and print a message
                } else { // If the stack is empty
                    std::cout << "The STACK is EMPTY. No more kitchenware to wash.\n";  // Print a message indicating the stack is empty
                }
                break;                                                                  // Exit the switch statement
            case 3: // If user chooses option 3
                if (!kitchenwareStack.EMPTY()) {                                            // Check if the stack is not empty
                    std::cout << kitchenwareStack.TOP() << " is next to be washed.\n";      // Print the name of the top kitchenware
                } else { // If the stack is empty
                    std::cout << "The STACK is EMPTY. No kitchenware to wash.\n";           // Print a message indicating the stack is empty
                }
                break;                                                                      // Exit the switch statement
            case 4: // If user chooses option 4
                if (!kitchenwareStack.EMPTY()) {                                        // Check if the stack is not empty
                    std::cout << "Washing all kitchenware:\n";                          // Print a message indicating washing all kitchenware
                    while (!kitchenwareStack.EMPTY()) {                                 // while-loop to wash all kitchenware when stack is not empty
                        std::cout << kitchenwareStack.POP() << " is being washed.\n";   // Wash the top kitchenware and print a message
                    }
                    std::cout << "All kitchenware has been washed.\n";                  // Print a message indicating all kitchenware has been washed
                } else { // If the stack is empty
                    std::cout << "The STACK is EMPTY. No kitchenware to wash.\n";       // Print a message indicating the stack is empty
                }
                break;                                                                  // Exit the switch statement
            case 0: // If user chooses option 0
                std::cout << "Exiting... Washing machine process terminated.\n";      // Print a message indicating program termination
                break;                                                                // Exit the switch statement
            default: // If user enters an invalid choice
                std::cout << "Invalid choice. Please try again.\n";                     // Print a message indicating an invalid choice
        }
    } while (choice != 0);                                                            // Repeat the loop until the user chooses to exit
    return 0; 
} 