#include <iostream>

using namespace std;

/*
Budujemy dwa drzewa:
    1. Drzewo posortowane pod względem zawodów
        a) Każdy węzeł to:
            - Nazwa zawodu
            - Drzewo dla zawodu posortowane względem objawów, gdzie każdy węzeł to:
                * Nazwa objawu
                * Ilość chłopów ilość chłopów z danym objawem o danym zawodzie
    2. Drzewo posortowane pod względem objawów
        a) Każdy węzeł to:
            - Nazwa objawu
            - Drzewo dla objawu posortowane względem zawodów, gdzie każdy węzeł to:
                * Nazwa zawodu
                * Ilość chłopów danego zawodu z objawe

Template:
Node:
    string key - to jest nazwa objawu lub zawodu
    T value - to będzie drzewo lub licznik w int
    Node* left
    Node* right
*/

// insert()
// find()
// print()
// splay() wykonujemy przy każdym dodaniu i zczytaniu elementu

int main() {
    unsigned int numberOfOperations;

    for (int i=0; i<numberOfOperations; i++) {
        char operation;
        cin >> operation;
        fflush(stdin);
        if (operation == 'd') {
            string profession, symptom;
            cin >> profession >> symptom;
            // Add peasant to database

        } else if (operation == 's') {
            string symptom;
            cin >> symptom;
            // Write peasants of symptoms
        } else if (operation == 'p') {
            string profession;
            cin >> profession;
            // Write peasants of professions
        }
    }

    return 0;
}