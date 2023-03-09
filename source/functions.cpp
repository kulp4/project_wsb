#include "header.h"
#include <cmath>

// OPIS POSZCZEGÓLNYCH CZĘŚCI/FUNKCJI PROGRAMU:
// Część 1. Wiadomość powitalna:

void hello_message() {
    cout << endl << "Hello!" << endl;
    cout << "This is a program that calculates the percentage of occurrences of a particular number in N rolls of a dice." << endl;
    cout << "If You want to quit, You can press CTRL+C anytime." << endl << endl;
}


// Część 2. Wprowadzenie liczby w zakresie 1-6, dla której będziemy sprawdzać prawdopodobieństwo.
// Zawiera sprawdzenie czy liczba mieści się w zakresie 1-6, tzn. czy jest poprawnie wpisana.
// Umożliwia ponowne wpisanie - w przypadku podania złej wartości.

int enter_the_number_to_check() {
    
    int number_to_check;

    cout << "Enter the number (from 1 to 6) for which you want to make calculations:" << endl;
    cin >> number_to_check;

    if (1 > number_to_check || number_to_check > 6) {
            do {
                cout << endl << "No way! You must choose number from 1 to 6 - like on dice." << endl;
                cout << "Please, enter the number once again (from 1 to 6):" << endl;
                cin >> number_to_check;
                }   while (1 > number_to_check || number_to_check > 6);
    }

    cout << endl;    
    cout << "Well done! Your number to calculate is " << number_to_check << "!" << endl;

return number_to_check;
}


// Część 3. Wprowadzenie liczby rzutów kostką.
// Zawiera sprawdzenie czy liczba wpisana przez użytkowanika jest większa od zera,
// tzn. czy jest poprawnie wpisana.
// Umożliwia ponowne wpisanie - w przypadku podania złej wartości.

long long enter_the_number_of_rolls() {

    long long number_of_rolls;

    cout << endl << "In next step You must enter the number of dice rolls for which You want to make calculations: " << endl;
    cin >> number_of_rolls;

        if (number_of_rolls <= 0) {
                do {
                    cout << endl << "You must choose positive number, more than 0!" << endl;
                    cout << "Please, enter the number of dice rolls again:" << endl;
                    cin >> number_of_rolls;
                    } while (number_of_rolls <= 0);
        }

    cout << endl << "Ok! I will roll the dice for You " << number_of_rolls << " time(s)." << endl;

return number_of_rolls;
}


// Część 4. Utworzenie tablicy o wielkości równej wskazanej ilości rzutów kostką - number_of_rolls, 
// wypełnioną losowymi liczbami w zakresie 1-6:

int *create_array(long long number_of_rolls) {
    
    // Używam 'new' do stworzenia dynamicznej tablicy (o nieznanym rozmiarze w momencie inicjalizacji).
    // Posiłkowałam się stronami: https://www.guru99.com/cpp-dynamic-array.html#4
    // https://www.p-programowanie.pl/cpp/tablice-dynamiczne
    int *results_array = new int [number_of_rolls];         
    cout << "Lets the magic begin! Look at the numbers I got in " << number_of_rolls << " rolls of the dice: " << endl;
    cout << endl;

    srand(time(0));                                         // Tworzę losową tablicę wyników rzutów kostką i ją wyświetlam
        for (int i = 0; i < number_of_rolls; i++) 
        {
            results_array[i] = rand() %6+1;
            cout << results_array[i] << ", " ;
        }

return results_array;                                       // Zwracam wskaźnik do tablicy
}


 // Część 5. Wyliczenie ilości wystapienia liczb 1-6 we wszystkich rzutach w celu zwiększenia czytelności.
 // Decyzja o wyświetleniu czytelniejszej listy należy do użytkownika.
 // Niezależnie od decyzji użytkownika - wskazanie ile razy wybrana przez użytkownika liczba (number_to_check) 
 // wypadła w wybranej liczbie rzutów kostką (number_of_rolls):

long long nice_look_of_array(int array_with_results_of_rolls[], long long number_of_rolls, int number_to_check) {

    cout << endl << endl;
    cout << "Looks bad? Do You want to see the results in other way?" << endl;
    cout << "I can show You how many times each number occured." << endl;
    cout << "Enter 'Y' to see that, or enter anything else to skip this view." << endl;
    
    string yes_or_no;
    cin >> yes_or_no;
   
    int array_how_many_times[6] = {0, 0, 0, 0, 0, 0};   // Utworzenie tablicy grupujacej krotność wyrzuconych oczek we wszystkich rzutach
                                                        // kolejne wyrazy tablicy to odpowiednio oczka: 1, 2, 3, 4, 5, 6.
    for (int i = 0; i < number_of_rolls; i++)       
    {                                               
         int x = array_with_results_of_rolls[i];        // W pętli jako zmienną x przyjmuję "i-ty" wyraz utworzonej w pkt 4 losowej tablicy.
         array_how_many_times[(x-1)] += 1;              // Ponieważ są to liczby przyjmujące wartość od 1 do 6, dokonuję inkrementacji odpowiedniego
    }                                                   // wyrazu (x-1) tablicy array_how_many_times.

    if (yes_or_no == "Y" || yes_or_no == "y")           // Przedstawienie powyższych wyników w przypadku wpisania Y/y przez użytkownika.
    {  
        cout << endl;
        cout << "In " << number_of_rolls << " rolls of the dice: " << endl;
            for (int i = 0; i < 6; i++) 
            {
                cout << "- number " << (i+1) << " rolls " << array_how_many_times[i] << " times," << endl;
            }
           
    }
    
    // Wskazanie ile razy wyrzucono wybraną przez użytkownika liczbę:
    
    long long how_many_times = array_how_many_times[(number_to_check - 1)];     

    cout << endl;
    cout << "As You can see number " << number_to_check << " appeared in rolls: ";
    cout << how_many_times << " time(s)." << endl;
    cout << endl;

return how_many_times;
}


// Część 6. Wyliczenie prawdopodobieństwa na podstawie powyższych obliczeń.
// W celu uzyskania poprawnych wyników zmieniam za pomocą 
// funkcji static_cast typ jednej zmiennej z integer na float,
// następnie pomijam wartości po przecinku za pomocą funkcji round(): 

void function_probability(int number_to_check, long long number_of_rolls, long long how_many_times) {
    
    float probability = static_cast<float>(how_many_times) / number_of_rolls * 100 ;

    cout << "The percentage of occurrence of number " << number_to_check;
    cout << " in " << number_of_rolls << " rolls of a dice is:  " << round(probability) << " %." << endl;
    cout << endl;
}

/* Projekt oceniam na 5. Program spełnia wszystkie założenia opisane w programie, działa poprawnie
zarówno dla prawidłowych jak i nieprawidłowych wartości. Plus za stworzenie funkcji, komenatrze
i czytelność kodu. Projekt bardzo dopracowany, nie mam żadnych uwag. */