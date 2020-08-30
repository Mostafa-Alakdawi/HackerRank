#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
int getSecondElement(int firstEementIndex, int firstEement, int k, vector<int> ar);
int divisibleSumPairs(int n, int k, vector<int> ar);

/*
 *	Function name: 
 *	getSecondElement
 *
 *	Parameters:
 *	firstEementIndex: Ineger that represents index of the first element
 *	firstEement: Ineger that represents value of the first element
 *	k: Ineger that represents the divisor
 *	ar: Vector of the integers to be searched
 *
 *	return:
 *	an integer which when summed up with the first
 *      number, their sum will be evenly divisible by k 
 *
 *
 *	Function description:	 
 *	Searches through a vector of integers and returns the number of possible 
 *	second elements which whensummed up with the first number, their sum 
 *  	will be evenly divisible by k 
 *
 */
int getSecondElement(int firstEementIndex, int firstEement, int k, vector<int> ar) {

    int numberOfPairs = 0;
        
    for(int index = firstEementIndex+1; index < ar.size(); index++){
        if( ((ar[firstEementIndex] + ar[index])%k) == 0 ){
            numberOfPairs++;
        }
    }
    return numberOfPairs;
}

/*
 *  divisibleSumPairs: returns the number of possible pairs which when
 *  summed up, their sum will be evenly divisible by k 
 */
int divisibleSumPairs(int n, int k, vector<int> ar) {

    int numberOfPairs = 0;

    if ( n < 2 ){
        return numberOfPairs;
    }
    else{
        
        for(int index = 0; index < (n-1); index++){
            numberOfPairs += getSecondElement(index, ar[index], k, ar);
        }
    }

    return numberOfPairs;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string ar_temp_temp;
    getline(cin, ar_temp_temp);

    vector<string> ar_temp = split_string(ar_temp_temp);

    vector<int> ar(n);

    for (int i = 0; i < n; i++) {
        int ar_item = stoi(ar_temp[i]);

        ar[i] = ar_item;
    }

    int result = divisibleSumPairs(n, k, ar);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

