#include <bits/stdc++.h>

using namespace std;

void multipy(vector<int> &factorialResultVector, int multiplier, int &numberOfDigits){

    int carry = 0;    
    int product = 0;

    for(int index = 0; index < numberOfDigits; index++){

        product = (multiplier*factorialResultVector[index]) + carry;
        factorialResultVector[index] = (product%10);
        carry = product/10;

    }
    
    while(carry){

        //std::cout << carry << std::endl;

        factorialResultVector[numberOfDigits] +=  carry%10;
        carry /= 10;
        numberOfDigits++;
    }
    
}

// Complete the extraLongFactorials function below.
void extraLongFactorials(int n) {

    int value = n;
    vector <int> resultOfFactorial(158, 0);
    
    int numberOfDigitsInNumber = 1;
    resultOfFactorial[0] = 1;

    for(int count = 2; count <= value; count++){
        multipy(resultOfFactorial, count, numberOfDigitsInNumber);
    }

    for(int index = numberOfDigitsInNumber-1; index >= 0; index--) {
        cout << resultOfFactorial[index];
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    extraLongFactorials(n);

    return 0;
}
