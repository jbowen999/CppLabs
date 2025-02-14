/*2. write a function that returns the maximum value of a given array of double numbers. 
(Note, again, "given array" means that the array is an input parameter to the function). 
Write another function that returns the minimum value of a given array of double numbers.

3. write an overloaded function that returns the maximum value of a given array of integer numbers. 
Write another overloaded function that returns the minimum value of a given array of integer numbers.
*/

#include <iostream>
using namespace std;

double maxValue(double arg[], int len){
    double n = arg[0];
    for (int i = 0; i < len; i++){
        if (arg[i] > n){
            n = arg[i];
        }
    }
    return n;
}

int maxValue(int arg[], int len){
    int n = arg[0];
    for (int i = 0; i < len; i++){
        if (arg[i] > n){
            n = arg[i];
        }
    }
    return n;
}

double minValue(double arg[], int len){
    double n = arg[0];
    for (int i = 0; i < len; i++){
        if (arg[i] < n){
            n = arg[i];
        }
    }
    return n;
}

int minValue(int arg[], int len){
    int n = arg[0];
    for (int i = 0; i < len; i++){
        if (arg[i] < n){
            n = arg[i];
        }
    }
    return n;
}


int main(){
    double doubleArray1[10] = {1.1, 3.3, 4.4, 5.5, 1.1, 0.2, .005, 12224.5, 9, 3.14};
    cout << "Should be 12224.5: " << maxValue(doubleArray1, 10) << endl;
    cout << "Should be 0.005: " << minValue(doubleArray1, 10) << endl;

    int intArray1[10] = {1,2,3,4,6,7,8,56,3,234};
    cout << "Should be 234: " << maxValue(intArray1, 10) << endl;
    cout << "Should be 1: " << minValue(intArray1, 10) << endl;

}