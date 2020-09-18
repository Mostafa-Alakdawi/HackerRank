#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    int row = 0, col = 0;
    int max_sum = -100, current_sum = 0;

    while(row < 4 && col < 4){
        
        current_sum = arr[row][col] + arr[row][col+1] + arr[row][col+2] + arr[row+1][col         +1] + arr[row+2][col] + arr[row+2][col+1] + arr[row+2][col+2];

        if(current_sum > max_sum){
            max_sum = current_sum;
        }
        
        if(col == 3){
            row++;
            col = 0;
        }
        else{
            col++;
        }
    }

    return max_sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
