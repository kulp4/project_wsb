#ifndef _HEADER_H // The following directives prevent an attempt
#define _HEADER_H // to include the same file more than once
#include <iostream>
#include <string>

using namespace std;

// Deklaracja funkcji użytych w programie:

void hello_message();
int enter_the_number_to_check();
long long enter_the_number_of_rolls();
int *create_array(long long number_of_rolls);   //Zmienna create_array jest funkcją z jednym parametrem typu long long
                                                //zwracającą wskaźnik do zmiennej typu int
long long nice_look_of_array(int array_with_results_of_rolls[], long long number_of_rolls, int number_to_check);
void function_probability(int number_to_check, long long number_of_rolls, long long how_many_times);

#endif
