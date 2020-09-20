#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

enum movementDirections { vertical, horizontal, diagonalRightLeft, diagonalLeftRight };

class queen{
    private:
        int _row;
        int _colomn;

    public:
        queen(int row, int colomn){
            _row = row;
            _colomn = colomn;
        }

        int getRow(){return _row;}
        int getColomn(){return _colomn;}
};

class chessBoard{
    private:
        vector<vector<int> > board;

    public:
        chessBoard(int size){
            board = vector<vector<int> > ( size, vector<int> (size, 0));
        }  

        void setObstaclesOnChessBoard(vector<vector<int>> obstacles){
            
            for(int row =0; row < obstacles.size(); row++){
                for(int colomn =0; colomn < 2; colomn++){
                    board[row][colomn] = 1;
                }
            }
        }

        void printCellsChessBoard(void){
            
            for(int row =0; row < board.size(); row++){
                for(int colomn =0; colomn < board.size(); colomn++){
                    std::cout << board[row][colomn] << std::endl;
                }
            }
        }

        void moveVeritical(queen &Queen, int &numberOfAllPossibleMoves){
            vector<int> allPossibleMoves;
            int row = Queen.getRow();
            int colomn = Queen.getColomn();

            for(int rowIndex = row; rowIndex < board.size(); rowIndex++){
                
                if( board[rowIndex][colomn] == 0)
                    numberOfAllPossibleMoves++;

                else 
                    break;
            }

            for(int rowIndex = row; rowIndex > 0; rowIndex--){
                
                if( board[rowIndex][colomn] == 0)
                    numberOfAllPossibleMoves++;

                else 
                    break;
            }

        }

        void moveHorizontal(queen &Queen, int &numberOfAllPossibleMoves){
            vector<int> allPossibleMoves;
            int row = Queen.getRow();
            int colomn = Queen.getColomn();

            for(int colomnIndex = row; colomnIndex < board.size(); colomnIndex++){
                
                if( board[row][colomnIndex] == 0)
                    numberOfAllPossibleMoves++;

                else 
                    break;
            }

            for(int colomnIndex = row; colomnIndex > 0; colomnIndex--){
                
                if( board[row][colomnIndex] == 0)
                    numberOfAllPossibleMoves++;

                else 
                    break;
            }

        }

        int findAllPossibleMoves(queen &Queen){
            int numberOfAllPossibleMoves;
            int row = Queen.getRow();
            int colomn = Queen.getColomn();

            return numberOfAllPossibleMoves;
        }
};

// Complete the queensAttack function below.
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {

    queen Queen = queen(r_q, c_q);
    chessBoard ChessBoard = chessBoard(n);
    ChessBoard.setObstaclesOnChessBoard(obstacles);
    ChessBoard.printCellsChessBoard();

    return ChessBoard.findAllPossibleMoves(Queen);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]);

    int c_q = stoi(r_qC_q[1]);

    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> obstacles[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

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
