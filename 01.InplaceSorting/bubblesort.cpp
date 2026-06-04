#include <iostream>
#include "bubblesort.hpp"
#include <algorithm>

using namespace std;

void bubbleSort(int m[], int size) {
    int n = size;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (m[j] > m[j + 1]) {
                swap(m[j], m[j + 1]);
            }
        }
    }
}