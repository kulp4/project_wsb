// 16. Napisz program obliczający procentową ilość wystąpienia konkretnej cyfry w n rzutach kostką. 
// Najpierw użytkownik określa, dla jakiej liczby będzie dokonywał obliczeń oraz liczbę n rzutów. 
// Następnie zasymuluj n rzutów kostką (cyfry od 1 do 6), wyświetl je i w kolejnym kroku oblicz ile 
// razy dana cyfra wystąpiła w ciągu liczb. Wynik przedstaw w procentach z pominięciem wartości 
// po przecinku.
// Przykład:
// INPUT: 5 12
// OUTPUT: 1 4 2 5 2 1 3 3 5 1 2 2
// OUTPUT: 17%

#include "header.h"

int main () {

    hello_message();                // Wywołanie wiadomości powitalnej

    string yes_or_no;               // Zadeklarowanie zmiennej do możliwości wykonania poniższej pętli 'do-while'

    do {                            // Otwarcie pętli do możliwości powtórnego włączenia programu po zakończeniu całego cyklu obliczeń
        
        // Przypisanie wyniku funkcji enter_the_number_to_check do zmiennej number_to_check,
        // w celu dalszego użycia tej zmiennej w programie.
        // Opis działania funkcji wskazałam przy jej definicji:

        int number_to_check = enter_the_number_to_check();

        // Przypisanie wyniku funkcji enter_the_number_of_rolls do zmiennej number_of_rolls,
        // w celu dalszego użycia tej zmiennej w programie.
        // Opis działania funkcji wskazałam przy jej definicji:
  
        long long number_of_rolls = enter_the_number_of_rolls();
        
        // Przypisanie wyniku funkcji create_array - do wskaźnika na tablicę array_with_results_of_rolls,
        // w celu dalszego użycia tej tablicy w programie. Funkcja create_array zwraca wskaźnik,
        // stąd array_with_results_of_rolls też nim musi być. Użyłam wskaźników, ponieważ
        // jest to jeden ze sposobów na zwrócenie z funkcji całej zawartości tablicy.
        // Opis działania funkcji wskazałam przy jej definicji. 
        // Mam nadzieję, że to jest ok, wiem, że w łatwy sposób można byłoby to wrzucić tutaj bez funkcji,
        // ale mimo trudności i konieczności użycia wskaźników chciałam podzielić program 
        // na konkretne części w postacji funkcji w celu zachowania przejrzystości.

        int *array_with_results_of_rolls = create_array(number_of_rolls);

        // Przypisanie wyniku funkcji nice_look_of_array do zmiennej how_many_times,
        // do dalszej możliwości użycia tej zmiennej w programie.
        // Opis działania funkcji wskazałam przy jej definicji:

        long long how_many_times = nice_look_of_array(array_with_results_of_rolls, number_of_rolls, number_to_check);

        // Uruchomienie funkcji function_probability, liczącej prawdopodobieństwo 
        // wystąpienia konkretnej cyfry w n rzutach kostką.
        // Opis działania funkcji wskazałam przy jej definicji:
            
        function_probability(number_to_check, number_of_rolls, how_many_times);

        // Wiadomość pożegnalna i możliwość ponownego uruchomienia programu:

        cout << "Thanks for fun! Do You want to calculate again? Click 'Y' to start again or anything else to quit." << endl;
        cout << endl;

        cin >> yes_or_no;

        cout << endl;

        } while (yes_or_no == "Y" || yes_or_no == "y");

return 0;
}