#include "../source/header.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
  
        string test[4] = {" ", "a", "Aa", "Abc"};

        for (int i = 0; i < 4; i++) {        
           
            if (hello_message(test[i]).find("Hello") == string::npos) {
                
                cout << "FAIL - missing \"Hello\" " << endl;
                return 1;
            }
        }
        
        for (int i = 0; i < 4; i++) {

            if (hello_message(test[i]).find(test[i]) == string::npos) {
            
                cout << "FAIL - missing name \" " << test[i] << " \" " << endl;
                return 1;
            }
        }

    cout << "TEST - EVERYTHING OK" << endl;
    return 0;

}