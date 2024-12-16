#include <iostream>

using namespace std;

// insert()
// find()
// print()

/*
Budujemy dwa drzewa:
    1. Drzewo posortowane pod względem zawodów
        a) Każdy węzeł to drzewo dla zawodu posortowane względem objawów
            - Każdy węzeł drzewa to objaw z ilością chłopów
    2. Drzewo posortowane pod względem objawów
        a) Każdy węzeł to drzewo dla objawu posortowane względem zawodów
            - Każdy węzeł drzewa to zawód z ilościa chłopów
*/

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