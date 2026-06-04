#include <cassert>
#include <iostream>

#include "bubblesort.hpp"
#include "qsort.hpp"

bool arraysEqual(const int actual[], const int expected[], int size) {
    for (int i = 0; i < size; ++i) {
        if (actual[i] != expected[i]) {
            return false;
        }
    }

    return true;
}

void testMixedPositiveNumbers() {
    int bubbleData[] = {64, 34, 25, 12, 22, 11, 90};
    int quickData[] = {64, 34, 25, 12, 22, 11, 90};
    int expected[] = {11, 12, 22, 25, 34, 64, 90};
    int size = sizeof(expected) / sizeof(expected[0]);

    bubbleSort(bubbleData, size);
    quickSort(quickData, 0, size - 1);

    assert(arraysEqual(bubbleData, expected, size));
    assert(arraysEqual(quickData, expected, size));
}

void testDuplicatesAndNegativeNumbers() {
    int bubbleData[] = {3, -1, 3, 0, -7, 8, -1};
    int quickData[] = {3, -1, 3, 0, -7, 8, -1};
    int expected[] = {-7, -1, -1, 0, 3, 3, 8};
    int size = sizeof(expected) / sizeof(expected[0]);

    bubbleSort(bubbleData, size);
    quickSort(quickData, 0, size - 1);

    assert(arraysEqual(bubbleData, expected, size));
    assert(arraysEqual(quickData, expected, size));
}

int main() {
    testMixedPositiveNumbers();
    testDuplicatesAndNegativeNumbers();

    std::cout << "All sorting tests passed\n";
    return 0;
}
