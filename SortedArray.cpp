#include "SortedArray.h"
#include "FoodItem.h"
#include <iostream>
using namespace std;

SortedArray::SortedArray() {
    array = nullptr;
    size = 0;
}

SortedArray::~SortedArray() {
    delete[] array;
}

void SortedArray::insert(FoodItem* value) {
    FoodItem** newArray = new FoodItem * [size + 1];
    int i = 0;

    while (i < size && *array[i] < *value) {
        newArray[i] = array[i];
        i++;
    }

    newArray[i] = value;

    while (i < size) {
        newArray[i + 1] = array[i];
        i++;
    }

    delete[] array;
    array = newArray;
    size++;
}

bool SortedArray::search(FoodItem* value) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (*array[mid] == *value) {
            return true;
        }
        else if (*array[mid] < *value) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return false;
}

void SortedArray::remove(FoodItem* value) {
    FoodItem** newArray = new FoodItem * [size - 1];
    int i = 0;

    while (i < size && *array[i] != *value) {
        newArray[i] = array[i];
        i++;
    }

    if (i < size) {
        i++;
    }

    while (i < size) {
        newArray[i - 1] = array[i];
        i++;
    }

    delete[] array;
    array = newArray;
    size--;
}

void SortedArray::print() {
    for (int i = 0; i < size; i++) {
        (*array[i]).printFoodItem();
    }
    cout << endl;
}