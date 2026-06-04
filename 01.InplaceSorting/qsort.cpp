#include <iostream>
#include "qsort.hpp"
#include <algorithm>

using namespace std;

int temp(int m[], int left, int right) {
    int x = m[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (m[j] <= x) {
            i++;
            swap(m[i], m[j]);
        }
    }
    swap(m[i+1], m[right]);
    return i + 1;
}

void quickSort(int m[], int left, int right) {
    if (left < right) {
        int x = temp(m, left, right);

        quickSort(m, left, x - 1);
        quickSort(m, x + 1, right);
    }
}