#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player);

/*
 *	Function name: 
 *	climbingLeaderboard
 *
 *	Parameters:
 *	ranked: a vector that contains the scores of the other ranked players
 *	player: a vector that contains the scores of the player to be ranked
 *
 *	return:
 *	a vector that contains the ranks the player gets for every score
 *
 *	Function description:	 
 *	Calculates the rank the player gets for each then stores them in a  
 *	vector and returns the vector	
 *
 */
vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {

    vector<int> ranks;
    vector<int> result;
    int prevValue = 0;

    if( ranked.size() == 0 || player.size() == 0)
        return result;
    
    ranks.push_back(prevValue);

    for(int index = ranked.size()-1; index >= 0; index--){
        
        if(ranked[index] != prevValue)
            ranks.push_back(ranked[index]);

        prevValue = ranked[index];
    }

    /**For Debugging Only**/
    /**
    for(int index = 0; index < ranks.size(); index++){       
        std::cout << ranks[index] <<std::endl;
    }
    **/

    int currentRank = ranks[0];
    int currentRankIndex = 0;
    bool locked = false;

    for(int index = 0; index < player.size(); index++){       

        while( (player[index] >= currentRank)  ){

            if((currentRankIndex == (ranks.size()-1)) && (index == (player.size()-1))){
                result.push_back(ranks.size()-(currentRankIndex));            
                return result;
            }
            else if((currentRankIndex == (ranks.size()-1)) && (index < (player.size()-1))){
                result.push_back(ranks.size()-(currentRankIndex));
                locked = true;
                break;            
            }
            else{
                currentRankIndex++;
                currentRank = ranks[currentRankIndex];
            }
        }

        if(! locked ){
            result.push_back(ranks.size()-(currentRankIndex-1));
        }

    }

    /**For Debugging Only**/
    /**
    for(int index = 0; index < result.size(); index++){       
        std::cout << result[index] <<std::endl;
    }
    **/

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string ranked_count_temp;
    getline(cin, ranked_count_temp);

    int ranked_count = stoi(ltrim(rtrim(ranked_count_temp)));

    string ranked_temp_temp;
    getline(cin, ranked_temp_temp);

    vector<string> ranked_temp = split(rtrim(ranked_temp_temp));

    vector<int> ranked(ranked_count);

    for (int i = 0; i < ranked_count; i++) {
        int ranked_item = stoi(ranked_temp[i]);

        ranked[i] = ranked_item;
    }

    string player_count_temp;
    getline(cin, player_count_temp);

    int player_count = stoi(ltrim(rtrim(player_count_temp)));

    string player_temp_temp;
    getline(cin, player_temp_temp);

    vector<string> player_temp = split(rtrim(player_temp_temp));

    vector<int> player(player_count);

    for (int i = 0; i < player_count; i++) {
        int player_item = stoi(player_temp[i]);

        player[i] = player_item;
    }

    vector<int> result = climbingLeaderboard(ranked, player);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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

