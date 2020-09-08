#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;

/* Define the exception here */
class BadLengthException: public exception
{
  public:
  int numberOfCharacter;
  BadLengthException(int n){numberOfCharacter = n;};
  ~BadLengthException(){};
  //void getreturn(){cout << numberOfCharacter;}
  virtual const char* what() const throw()
  {
    if(numberOfCharacter == 1)
        //return("1");

    if(numberOfCharacter == 2)
        //return("2");
    
    string text = to_string(numberOfCharacter);
    //getreturn();
    cout << numberOfCharacter;

    return "";
  }
};

bool checkUsername(string username) {
	bool isValid = true;
	int n = username.length();
	if(n < 5) {
		throw BadLengthException(n);
	}
	for(int i = 0; i < n-1; i++) {
		if(username[i] == 'w' && username[i+1] == 'w') {
			isValid = false;
		}
	}
	return isValid;
}

int main() {
	int T; cin >> T;
	while(T--) {
		string username;
		cin >> username;
		try {
			bool isValid = checkUsername(username);
			if(isValid) {
				cout << "Valid" << '\n';
			} else {
				cout << "Invalid" << '\n';
			}
		} catch (BadLengthException e) {
			cout << "Too short: " << e.what() << '\n';
		}
	}
	return 0;
}
