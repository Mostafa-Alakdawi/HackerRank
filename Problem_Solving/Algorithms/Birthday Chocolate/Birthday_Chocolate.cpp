#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
int checkFollowingSegments(vector<int> segment, int segemntIndex, int numberFollowingSegments);
int birthday(vector<int> segment, int sumOfSegments, int numberOfSegments);

/*
 *	Function name: 
 *	checkFollowingSegments
 *
 *	Parameters:
 *	segment: a vector that contains the segements of chocolate
 *	segemntIndex: an integer that represents the index of the segment
 *	numberFollowingSegments: an integer that represents the number of
 *	the following segements
 *
 *	return:
 *	an integer that represents the sum of a number of following segements  
 *	in the chocolate bar
 *
 *
 *	Function description:	 
 *	Calculates and returns the sum of a number of following segements  
 *	in the chocolate bar
 *
 */
int checkFollowingSegments(vector<int> segment, int segemntIndex, int numberFollowingSegments) {

    int sum  = 0;

    for (int index = segemntIndex; index < (segemntIndex + numberFollowingSegments); index++) {
        sum += segment[index];
    }

    return sum;

}

/*
 *	Function name: 
 *	birthday
 *
 *	Parameters:
 *	segment: a vector that contains the segements of chocolate
 *	sumOfSegments: an integer that represents the target sum of the
 *		       segments	
 *	numberOfSegments: an integer that represents the number of
 *	 		  segements to be summed
 *
 *	return:
 *	an integer that represents the number of combinations by which the 
 *	chocolate bar can be divided into numberOfSegments of segments to get
 *	sumOfSegments
 *
 *	Function description:	 
 *	Calculates and returns the number of combinations by which the 
 *	chocolate bar can be divided into numberOfSegments of segments to get
 *	sumOfSegments
 *
 */
int birthday(vector<int> segment, int sumOfSegments, int numberOfSegments) {

    int numberOfCombination = 0;

    if(numberOfSegments > segment.size()){
        return numberOfCombination;
    }

    else{
    
        for (int index = 0; index < segment.size(); index++){

            if(numberOfSegments > (segment.size() - index)){
                return numberOfCombination;
            }
            else {
                numberOfCombination += (int)(checkFollowingSegments(segment, index, numberOfSegments) == sumOfSegments);
            }
        }
    }

    return numberOfCombination;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string s_temp_temp;
    getline(cin, s_temp_temp);

    vector<string> s_temp = split(rtrim(s_temp_temp));

    vector<int> s(n);

    for (int i = 0; i < n; i++) {
        int s_item = stoi(s_temp[i]);

        s[i] = s_item;
    }

    string dm_temp;
    getline(cin, dm_temp);

    vector<string> dm = split(rtrim(dm_temp));

    int d = stoi(dm[0]);

    int m = stoi(dm[1]);

    int result = birthday(s, d, m);

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

