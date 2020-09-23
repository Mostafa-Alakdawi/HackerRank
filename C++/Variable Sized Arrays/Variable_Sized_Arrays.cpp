#include <cmath>
#include <cstddef>
#include <cstdio>
#include <memory>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int numberOfElements;

long** readArray(){
    long temp = 0;
    long tempElement = 0;
    int numberofArrays; 
    long** arrayOfArrays = NULL;

    cin >> numberofArrays;
    cin >> numberOfElements;

    arrayOfArrays = new long*[numberOfElements];

    for(int arrayCount = 0; arrayCount < numberofArrays; arrayCount++){
        cin >> temp;
        arrayOfArrays[arrayCount] = new long[temp];

        for(int Count = 0; Count < temp; Count++){
            cin >> tempElement;
            arrayOfArrays[arrayCount][Count] = tempElement;
        }

    }

/**
    for(int arrayCount = 0; arrayCount < numberofArrays; arrayCount++){
        for(int Count = 0; Count < 3; Count++){
            cout << endl;
            cout << arrayOfArrays[arrayCount][Count];
        }
    }
*/

return arrayOfArrays;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    long** arrayOfArrays = NULL;
    //int* firstIndexArray = new int[numberOfElements];
    int firstIndexArraySize = 0;
    //int* secondIndexArray = new int[numberOfElements];
    int secondIndexArraySize = 0;
    int temp = 0;
    long temp2 = 0;

    arrayOfArrays = readArray();
 
    for (int count = 0; count < numberOfElements; count++) {
        cin >> temp;
        //firstIndexArray[count] = temp;
        cin >> temp2;
        //secondIndexArray[count] = temp;
        cout << arrayOfArrays[temp][temp2] << endl;
    }
/**
    for (int count = 0; count < numberOfElements; count++) {
        cout << arrayOfArrays[firstIndexArray[count]][secondIndexArray[count]] << endl;
    }
*/


    return 0;
}

