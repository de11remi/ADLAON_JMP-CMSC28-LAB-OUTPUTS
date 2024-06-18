#include <iostream>     // Include the input/output stream library
#include <cmath>        // Include the math library for mathematical operations
using namespace std;     

const int MAX_SIZE = 10;    // Define a constant for the maximum size of the array

// Function prototypes
void inputData(int num[], int& size);                       // Function to input data into the array
int findLargestNumber(int num[], int size);                 // Function to find the largest number in the array
int findSmallestNumber(int num[], int size);                // Function to find the smallest number in the array
double findAverage(int num[], int size);                    // Function to find the average of the numbers in the array
double findVariance(int num[], int size, double average);   // Function to find the variance of the numbers in the array
double findStandardDeviation(double variance);              // Function to find the standard deviation of the numbers in the array
void outputResults(int largest_num, int smallest_num, double average, double standardDeviation, double variance);   // Function to output the results

int main() {
    // Output P.E. # and programmer's name
    cout << "Programming Exercise 05\n\nSubmitted by: Jodell Mae P. Adlaon\n\n--------------------------------------------------------------------------------------------------------------------------------------\n\n";     
    
    int num[MAX_SIZE];  // Declare an array to store numbers
    int size = 0;       // Initialize the size of the array

    // Input data
    inputData(num, size); // Call the function to input data into the array

    // Find required values
    int largest_num = findLargestNumber(num, size);                 // Call the function to find the largest number in the array
    int smallest_num = findSmallestNumber(num, size);               // Call the function to find the smallest number in the array
    double average = findAverage(num, size);                        // Call the function to find the average of the numbers in the array
    double variance = findVariance(num, size, average);             // Call the function to find the variance of the numbers in the array
    double standardDeviation = findStandardDeviation(variance);     // Call the function to find the standard deviation of the numbers in the array

    // Output results
    outputResults(largest_num, smallest_num, average, standardDeviation, variance);     // Call the function to output the results

    return 0;   // Return 0 to indicate successful execution
}

void inputData(int num[], int& size) {
    // Program description
    cout << "This program will ask the user to input various numbers (positive or negative but not zero) and perform basic statistics on these numbers.\n\n";  
    
    cout << "Input an integer: ";  // Prompt the user to input an integer
    int num_input;                                 // Declare a variable to store the user input
    do {
        cin >> num_input;                          // Read the user input
        if (num_input != 0 && size < MAX_SIZE) {   // Check if the input is not zero and the array is not full
            num[size++] = num_input;               // Assign the input to the next element in the array and increment the size
            if (size < MAX_SIZE)                   // Check if the array is not full
                cout << "Input an integer: ";      // Prompt the user to input another integer
        }
    } while (num_input != 0 && size < MAX_SIZE);   // Continue the loop until the input is zero or the array is full
}

int findLargestNumber(int num[], int size) {
    int largest_num = num[0];           // Initialize the largest number with the first element of the array
    for (int i = 1; i < size; ++i) {    // Loop through the array starting from the second element
        if (num[i] > largest_num) {     // Check if the current element is larger than the largest number found so far
            largest_num = num[i];       // Update the largest number if the current element is larger
        }
    }
    return largest_num;                 // Return the largest number
}

int findSmallestNumber(int num[], int size) {
    int smallest_num = num[0];          // Initialize the smallest number with the first element of the array
    for (int i = 1; i < size; ++i) {    // Loop through the array starting from the second element
        if (num[i] < smallest_num) {    // Check if the current element is smaller than the smallest number found so far
            smallest_num = num[i];      // Update the smallest number if the current element is smaller
        }
    }
    return smallest_num;                // Return the smallest number
}

double findAverage(int num[], int size) {
    double sum = 0;                     // Initialize the sum of numbers to zero
    for (int i = 0; i < size; ++i) {    // Loop through the array
        sum += num[i];                  // Add each element of the array to the sum
    }
    return sum / size;                  // Return the average by dividing the sum by the size of the array
}

double findVariance(int num[], int size, double average) {
    double variance = 0;                        // Initialize the variance to zero
    for (int i = 0; i < size; ++i) {            // Loop through the array
        variance += pow(num[i] - average, 2);   // Add the square of the difference between each number and the average to the variance
    }
    return variance / size;                     // Return the variance by dividing the sum of squared differences by the size of the array
}

double findStandardDeviation(double variance) {
    return sqrt(variance);  // Return the square root of the variance to calculate the standard deviation
}

void outputResults(int largest_num, int smallest_num, double average, double standardDeviation, double variance) {
    cout << "\nLargest = " << largest_num << "\n";                 // Output the largest number
    cout << "Smallest = " << smallest_num << "\n";                 // Output the smallest number
    cout << "Average = " << average << "\n";                       // Output the average
    cout << "Standard deviation = " << standardDeviation << "\n";  // Output the standard deviation
    cout << "Variance = " << variance << "\n";                     // Output the variance
}
