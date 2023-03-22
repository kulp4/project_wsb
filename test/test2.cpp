#include "../source/header.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//     test function: 
//     float function_probability(long long number_of_rolls, long long how_many_times) 
//     float probability = static_cast<float>(how_many_times) / number_of_rolls * 100 ;
//     float round_probability = round(probability);

int main() {
  

// checking the correctness of the result:

    long long test1 = 3;
    long long test2 = 1;
    
    if (function_probability(test2, test1) != 300) {
                
            cout << "FAIL - bad result" << endl;
            return 1;
    }


// checking if the final result is rounded:

    long long test3 = 1;
    long long test4 = 3;
    float test5 = (static_cast<float>(test3)/test4)*100;

    if (function_probability(test4, test3) != floor(test5)) {
                
            cout << "FAIL - function result is not rounded" << endl;
            return 1;
    }

    cout << "TEST - EVERYTHING OK" << endl;
    return 0;

}