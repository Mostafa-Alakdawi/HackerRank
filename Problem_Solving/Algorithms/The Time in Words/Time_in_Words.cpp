#include <bits/stdc++.h>

using namespace std;

// Complete the timeInWords function below.
string numbersInWords(int n) {
    string word;
    switch (n) {
    case 0:
        word = "o' clock";
        break;
    case 1:
        word = "one";
        break;
    case 2:
        word = "two";
        break;
    case 3:
        word = "three";
        break;
    case 4:
        word = "four";
        break;
    case 5:
        word = "five";
        break;
    case 6:
        word = "six";
        break;
    case 7:
        word = "seven";
        break;
    case 8:
        word = "eight";
        break;
    case 9:
        word = "nine";
        break;
    case 10:
        word = "ten";
        break;
    case 11:
        word = "eleven";
        break;
    case 12:
        word = "twelve";
        break;
    case 13:
        word = "thirteen";
        break;
    case 14:
        word = "fourteen";
        break;
    case 15:
        word = "quarter";
        break;
    case 16:
        word = "sixteen";
        break;
    case 17:
        word = "seventeen";
        break;
    case 18:
        word = "eighteen";
        break;
    case 19:
        word = "ninteen";
        break;
    case 20:
        word = "twenty";
        break;
    case 30:
        word = "half";
        break;
    case 40:
        word = "fourty";
        break;
    case 50:
        word = "fifty";
        break;
    default:
        word = "error";
    }
    return word;
}

// Complete the timeInWords function below.
string timeInWords(int h, int m) {
    string Words;

    //cout <<  numbersInWords(m) << endl;
    //cout <<  numbersInWords(h) << endl;        

    if(m > 30){

        if((60-m) > 20 && (60-m) < 30){
            Words.append(numbersInWords((int)(20)));
            Words.append(" ");
            Words.append(numbersInWords((int)(40-m)));
            Words.append(" ");
        }
        else{
            Words.append(numbersInWords((int)(60-m)));
            Words.append(" ");
        }

        if(m == 59){
            Words.append("minute ");    
        }
        
        else if((m%15) != 0){
            Words.append("minutes ");    
        }

        Words.append("to ");
        Words.append(numbersInWords(h+1));        
    }

    else if( m == 0 ){
        Words.append(numbersInWords(h));
        Words.append(" ");
        Words.append(numbersInWords(m));                
    }

    else {

        if(m > 20 && m < 30){
            Words.append(numbersInWords((int)(20)));
            Words.append(" ");
            Words.append(numbersInWords((int)(m-20)));
            Words.append(" ");
        }
        else{
            Words.append(numbersInWords((int)(m)));
            Words.append(" ");
        }

        if(m == 1){
            Words.append("minute ");    
        }

        else if((m%15) != 0){
            Words.append("minutes ");    
        }

        Words.append("past ");
        Words.append(numbersInWords(h));    
    }

    return Words;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int h;
    cin >> h;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = timeInWords(h, m);

    fout << result << "\n";

    fout.close();

    return 0;
}

