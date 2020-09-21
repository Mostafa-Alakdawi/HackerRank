#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
int nonDivisibleSubset(int divisor, vector<int> setOfNumbers);

/*
 * Complete the 'nonDivisibleSubset' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY s
 */

/*
 *	Function name: 
 *	nonDivisibleSubset
 *
 *	Parameters:
 *	int: the divisor
 *	vector<int>: the set of numbers
 *
 *	return:
 *	An integer the represents th size of the 
 *      largest set of numbers that can't be evenly 
 *	divided by the divisor
 *
 *	Function description:	 
 *	Checks the set of numbers to determine which 
 *	numbers can be summed together without creating 
 *	a number that can't be evenly divided by the divisor
 *	then returns an integer that represents the largest 
 *	set that can contain these numbers whose sum can't 
 *      be evenly divided by the divisor
 *
 */
int nonDivisibleSubset(int divisor, vector<int> setOfNumbers) {

    int counter = 0;
    int maxCounter = 0;
    vector<int> countersOfModulusFrequency (divisor,0);

    for(int index = 0; index < setOfNumbers.size(); index++)
        countersOfModulusFrequency[setOfNumbers[index]%divisor]++;

    /**for debugging purposes
    for(int index = 0; index < countersOfModulusFrequency.size(); index++){

            std::cout << "Hello " << index << " " << countersOfModulusFrequency[index] <<std::endl;

    }
    **/

    if (divisor % 2 == 0) 
        countersOfModulusFrequency[divisor/2] = min(countersOfModulusFrequency[divisor/2], 1); 

    maxCounter = min(countersOfModulusFrequency[0],1);

    for (int index = 1; index <= divisor/2; index++) 
        maxCounter += max(countersOfModulusFrequency[index], countersOfModulusFrequency[divisor-index]); 

    return maxCounter;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string s_temp_temp;
    getline(cin, s_temp_temp);

    vector<string> s_temp = split(rtrim(s_temp_temp));

    vector<int> s(n);

    for (int i = 0; i < n; i++) {
        int s_item = stoi(s_temp[i]);

        s[i] = s_item;
    }

    int result = nonDivisibleSubset(k, s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
