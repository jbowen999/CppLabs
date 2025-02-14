/*1. write a function that  counts and returns the 
number of times a given number occurs in a given array of length elements.  
(note: the phrase "given number" means it is an input parameter, 
"given array" is also an input parameter, as would be the length. )*/

#include <iostream>
using namespace std;

int count(int arg[], int len, int target){
    int count = 0;
    for (int i = 0; i < len; i++){
        if (arg[i] == target){
            count++;
        }
    }
    return count;
}

int main(){

int testArray1[15] = {1,343,66,3,1,66,2,6,2, 66};
cout << "Should be 2: " << count(testArray1, 15, 1) << endl;
cout << "Should be 3: " << count(testArray1, 15, 66) << endl;
cout << "Should be 0: " << count(testArray1, 15, 666) << endl;
}