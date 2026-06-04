#include <iostream>
#include "qsort.hpp"
#include "bubblesort.hpp"

using namespace std;

int main() {

    int m[] = {64, 34, 25, 12, 22, 11, 90};
    int m2[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(m)/sizeof(m[0]);

    cout << "Исходный массив: ";
    for (int x : m) cout << x << " ";
    cout << endl;

    quickSort(m, 0, size - 1);
    cout << "qSort: ";
    for (int x : m) cout << x << " ";
    cout << endl;

    bubbleSort(m2, size);
    cout << "bubbleSort: ";
    for (int x : m2) cout << x << " ";
    cout << endl;    

}