#include <iostream>
#include <fstream>
#include <climits> // For INT_MIN and INT_MAX

using namespace std;

// Constants for array dimensions
const int ROWS = 125;
const int COLS = 20;

// Function prototypes
int findMax(int arr[ROWS][COLS], int rows, int cols);
int findMin(int arr[ROWS][COLS], int rows, int cols);
int countZeros(int arr[ROWS][COLS], int rows, int cols);
void printArray(int arr[ROWS][COLS], int rows, int cols);

int main() {
    // 2D array to store the data (excluding the sum column)
    int data[ROWS][COLS] = {0};

    // Open the file for reading
    ifstream inputFile("julian.txt");
    if (!inputFile) {
        cerr << "Error: Unable to open file 'data.txt' for reading." << endl;
        return 1;
    }

    int rowCount = 0;
    int colCount = 0;
    int sumFromFile = 0;
    int calculatedSum = 0;

    // Read data from the file
    while (rowCount < ROWS && inputFile >> data[rowCount][colCount]) {
        calculatedSum += data[rowCount][colCount];
        colCount++;

        // If we've read 20 values, read the sum from the file and validate it
        if (colCount == COLS) {
            inputFile >> sumFromFile;

            if (calculatedSum != sumFromFile) {
                cerr << "Error: Sum mismatch in row " << rowCount + 1 << endl;
                cerr << "Expected sum: " << sumFromFile << ", Calculated sum: " << calculatedSum << endl;
                return 1;
            }

            // Reset for the next row
            colCount = 0;
            calculatedSum = 0;
            rowCount++;
        }
    }

    // Close the file
    inputFile.close();

    // Use functions to find max, min, and count zeros
    int maxVal = findMax(data, rowCount, COLS);
    int minVal = findMin(data, rowCount, COLS);
    int zeroCount = countZeros(data, rowCount, COLS);

    // Report results
    cout << "Maximum value in the array: " << maxVal << endl;
    cout << "Minimum value in the array: " << minVal << endl;
    cout << "Number of zeros in the array: " << zeroCount << endl;

    // Print the entire array
    cout << "\nArray contents:" << endl;
    printArray(data, rowCount, COLS);

    return 0;
}

// Function to find the maximum value in the array
int findMax(int arr[ROWS][COLS], int rows, int cols) {
    int maxVal = INT_MIN;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] > maxVal) {
                maxVal = arr[i][j];
            }
        }
    }
    return maxVal;
}

// Function to find the minimum value in the array
int findMin(int arr[ROWS][COLS], int rows, int cols) {
    int minVal = INT_MAX;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] < minVal) {
                minVal = arr[i][j];
            }
        }
    }
    return minVal;
}

// Function to count the number of zeros in the array
int countZeros(int arr[ROWS][COLS], int rows, int cols) {
    int zeroCount = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] == 0) {
                zeroCount++;
            }
        }
    }
    return zeroCount;
}

// Function to print the entire array
void printArray(int arr[ROWS][COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}