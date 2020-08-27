#include <sstream>
#include <vector>
#include <iostream>
using namespace std;
vector<int> parseInts(string str);

/*
 *	function: parseInts
 *	Exracts numerical data from strings and returns 
 *	them as a vector of intgers
 */
vector<int> parseInts(string str) {
    int start = 0;
    int end = 0;
    vector<int> numbers;

    for(int count = 0; count < str.length()+1; count++){
        
        if(str[count] == ',' || count == str.length()){
            end = count;
            numbers.push_back(stoi(str.substr(start,(end-start))));
            start = end+1;
        }
    }

    return numbers;
}


int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}
