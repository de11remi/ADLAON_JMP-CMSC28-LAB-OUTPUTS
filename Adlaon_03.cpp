/* Written by: Jodell Mae P. Adlaon
CMSC 28 (K-1L) - Programming Exercises 03 - Queue Implementation */

#include <iostream>   // Input/output stream library
#include <iomanip>    // Input/output manipulators
#include <string>     // String library

// Class definition for a Queue
class Queue {
private:
    // Struct for a Node in the queue
    struct Node {
        std::string name;       // Name of the customer
        float totalAmount;      // Total amount payable by the customer
        Node* next;             // Pointer to the next node in the queue

        // Constructor to initialize node
        Node(const std::string& n, float amt) : name(n), totalAmount(amt), next(nullptr) {}
    };

    Node* front;    // Pointer to the front of the queue
    Node* rear;     // Pointer to the rear of the queue

public:
    // Constructor for the Queue class
    Queue() : front(nullptr), rear(nullptr) {}

    // Destructor to deallocate memory
    ~Queue() {
        while (!isEmpty()) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;    // Return true if front is null, indicating an empty queue
    }

    // Function to enqueue (add) a customer to the queue
    void enqueue(const std::string& name, float totalAmount) {
        Node* newNode = new Node(name, totalAmount);   // Create a new node
        if (isEmpty()) {        // Check if the queue is empty
            front = newNode;    // If empty, set both front and rear pointers to the new node
            rear = newNode;
        } else {
            rear->next = newNode;   // If not empty, add the new node to the end of the queue
            rear = newNode;         // Update the rear pointer to the new node
        }
    }

    // Function to dequeue (remove) a customer from the queue
    Node* dequeue() {
        if (isEmpty()) {        // Check if the queue is empty
            return nullptr;     // Return null pointer
        }
        Node* temp = front;     // Store the front node in a temporary variable
        front = front->next;    // Move the front pointer to the next node
        return temp;            // Return the removed node
    }

    // Function to get the front element of the queue
    Node* frontElement() {
        if (isEmpty()) {        // Check if the queue is empty
            return nullptr;     // Return null pointer
        }
        return front;           // Return the front node
    }

    // New method to serve a customer and return their details
    std::pair<std::string, float> serveCustomer() {
        if (isEmpty()) {                                                // Check if the queue is empty
            std::cerr << "The QUEUE is EMPTY. No orders to serve.\n";   // Print error message if queue is empty
            return std::make_pair("", 0.0f);                            // Return empty pair
        }
        Node* temp = dequeue();     // Dequeue the front customer
        std::pair<std::string, float> customerDetails = std::make_pair(temp->name, temp->totalAmount);   // Store customer details in a pair
        delete temp;                // Delete the dequeued node
        return customerDetails;     // Return customer details
    }

    // Operation to initialize an empty queue
    void init() {
        while (!isEmpty()) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
    }
};

// Function to display the menu options
void displayMenu(const std::string& shopName) {
    std::cout << shopName << " Counter 0:\n\n";     // Display shop name
    std::cout << "[1] Fall in line\n";              // Option to fall in line
    std::cout << "[2] Serve customer\n";            // Option to serve a customer
    std::cout << "[3] Next customer\n";             // Option to view the next customer
    std::cout << "[4] Closing time\n";              // Option to close the counter
    std::cout << "[0] Exit\n";                      // Option to exit
    std::cout << "Enter choice: ";                  // Prompt for user input
}

// Function to add a customer to the queue
void fallInLine(Queue& queue) {
    std::string name;       // Variable to store customer name
    float totalAmount;      // Variable to store total amount payable
    std::cout << "Enter customer's last name: ";    // Prompt for customer's last name
    std::cin >> name;                               // Input customer's last name
    std::cout << "Enter customer's total amount of the items to be paid (up to 4 decimal places): ";    // Prompt for total amount payable
    std::cin >> std::setprecision(4) >> totalAmount;    // Input total amount payable
    queue.enqueue(name, totalAmount);                   // Enqueue the customer
    std::cout << name << " has fallen in line.\n";      // Print message confirming customer addition
}

// Function to serve the next customer in the queue
void serveCustomer(Queue& queue) {
    std::pair<std::string, float> customer = queue.serveCustomer();     // Serve the next customer in the queue
    if (!customer.first.empty()) {                                      // Check if the customer details are not empty
        std::cout << "Now serving " << customer.first << " with total amount payable of " << std::fixed << std::setprecision(4) << customer.second << ".\n";  // Print the details of the served customer
    }
}

// Function to view the details of the next customer in the queue
void nextCustomer(Queue& queue) {
    if (queue.isEmpty()) {                                          // Check if the queue is empty
        std::cout << "The QUEUE is EMPTY. No order to serve.\n";    // Print message if queue is empty
        return;                                                     // Exit the function
    }

    std::pair<std::string, float> customer = std::make_pair(queue.frontElement()->name, queue.frontElement()->totalAmount);  // Get details of the next customer in the queue
    std::cout << "Next order: For " << customer.first << " with total amount payable of " << std::fixed << std::setprecision(4) << customer.second << ".\n";    // Print details of the next customer
}

// Function to close the counter and serve remaining customers
void closingTime(Queue& queue) {
    if (queue.isEmpty()) {                                              // Check if the queue is empty
        std::cout << "The QUEUE is EMPTY. No customer/s to serve.\n";   // Print message if queue is empty
        return;                                                         // Exit the function
    }

    std::cout << "Closing time. Serving remaining customers:\n";    // Print message indicating closing time
    while (!queue.isEmpty()) {                                      // Loop until the queue is empty
        serveCustomer(queue);                                       // Serve the next customer in the queue
    }
    std::cout << "All customers have been served.\n";   // Print message indicating all customers have been served
}

// Main function
int main() {
    Queue queue;                        // Create a queue object
    std::string shopName = "\nNDS";     // Define the shop name

    while (true) {                  // Loop indefinitely
        displayMenu(shopName);      // Display menu options
        int choice;                 // Variable to store user choice
        std::cin >> choice;         // Input user choice

        switch (choice) {   // Switch statement based on user choice
            case 1:
                fallInLine(queue);      // Option to fall in line
                break;
            case 2:
                serveCustomer(queue);   // Option to serve a customer
                break;
            case 3:
                nextCustomer(queue);    // Option to view the next customer
                break;
            case 4:
                closingTime(queue);     // Option to close the counter
                break;
            case 0:
                std::cout << "The checkout system for NDS Counter 0 has been terminated. Goodbye!\n";   // Option to exit
                return 0;   // Exit the program
            default:
                std::cout << "Invalid choice. Please try again.\n";    // Invalid choice
        }
    }

    return 0;   // Return 0 to indicate successful completion
}