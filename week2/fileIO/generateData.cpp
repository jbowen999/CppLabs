/*
Generate a random number of  rows (between 30 and 125)

Each row has 20 random integer values between -50 and 50.

When you write the row to a file, sum the data (last value in the row is the sum of the values in that row)(So that each row actually has 21 values).  

*/

#include <iostream>  // Input/output
#include <fstream>   // File operations
#include <sstream>   // String parsing
#include <string>    // String handling

#include <cstdlib>   // Random number generation
#include <ctime>     // Time functions
#include <climits>   // Integer limits
using namespace std;

const int MAX_ROWS = 125; // The max number of rows
const int COLS = 20; // fixed number of columns to exclude sum 

// Function to generate the data and write it to a file
void generateData(const string& filename) {
    srand(time(0));
    int rowCount = rand() % (125 - 30 + 1) + 30; // Random number of rows between 30 and 125
    ofstream myfile(filename);
    if (!myfile.is_open()) {
        cerr << "Error creating file!" << endl;
        return;
    }

    for (int n = 0; n < rowCount; n++) {
        int sum = 0; // Reset sum for each row
        for (int i = 0; i < COLS; i++) {
            int num = rand() % 101 - 50; // Random number between -50 and 50
            myfile << num << " ";
            sum += num;
        }
        myfile << sum << endl; // Write the sum as the 21st value
    }
    myfile.close();
}

// validates the sum of a row when called
bool validateRowSum(const int* row, int expectedSum) {
    int calculatedSum = 0;
    for (int i = 0; i < 20; i++) {
        calculatedSum += row[i];
    }
    return calculatedSum == expectedSum;
}


// Function that reads data into a 2D array
int readData(const string& filename, int data[MAX_ROWS][COLS]){
  ifstream myfile(filename);
  if(!myfile.is_open()){
    cerr << "Error opening file!" << endl;
    return 0;
  }

  int numRows = 0;
  string line;
  while (getline(myfile, line) && numRows < MAX_ROWS){
    stringstream ss(line);
    int sum = 0;
    for (int j = 0; j < COLS; j++){
      if(!(ss >> data[numRows][j])){
        cerr << "Error reading data at row " << numRows + 1 << endl;
        break;
      }
      sum += data[numRows][j];
    }

    int fileSum;
    if (!(ss >> fileSum)){
      cerr << "Error reading sum at row " << numRows + 1 << endl;
      continue;
    }

    if (!validateRowSum(data[numRows], fileSum)){
      cerr << "Sum mismatch in row " << numRows + 1 << endl;
    }

    numRows++;
  }
  myfile.close();
  return numRows;
}

// Function to find the maximum value in the array
int findMax(int data[MAX_ROWS][COLS], int numRows) {
    int maxVal = INT_MIN;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < COLS; j++) {
            if (data[i][j] > maxVal) {
                maxVal = data[i][j];
            }
        }
    }
    return maxVal;
}

// Function to find the minimum value in the array
int findMin(int data[MAX_ROWS][COLS], int numRows) {
    int minVal = INT_MAX;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < COLS; j++) {
            if (data[i][j] < minVal) {
                minVal = data[i][j];
            }
        }
    }
    return minVal;
}

// Function to count the number of zeros in the array
int countZeros(int data[MAX_ROWS][COLS], int numRows) {
    int zeroCount = 0;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < COLS; j++) {
            if (data[i][j] == 0) {
                zeroCount++;
            }
        }
    }
    return zeroCount;
}

// Function to print the entire array
void printArray(int data[MAX_ROWS][COLS], int numRows) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    const string filename = "julian.txt";

    // Step 1: Generate data and write it to a file
    generateData(filename);
    cout << "Data generated and written to " << filename << endl;

    // Step 2: Read data from the file into a 2D array
    int data[MAX_ROWS][COLS];
    int numRows = readData(filename, data);
    if (numRows == 0) {
        cerr << "No data read from file. Exiting program." << endl;
        return 1;
    }

    // Step 3: Find and report the maximum and minimum values
    int maxVal = findMax(data, numRows);
    int minVal = findMin(data, numRows);
    cout << "Maximum value in the array: " << maxVal << endl;
    cout << "Minimum value in the array: " << minVal << endl;

    // Step 4: Count and report the number of zeros
    int zeroCount = countZeros(data, numRows);
    cout << "Number of zeros in the array: " << zeroCount << endl;

    // Step 5: Print the entire array
    cout << "\nArray contents:" << endl;
    printArray(data, numRows);

    return 0;
}