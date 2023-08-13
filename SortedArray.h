#pragma once
#include "FoodItem.h"

const int MAX_ITEMS = 25;

class SortedArray {
private:
    FoodItem foodItems[MAX_ITEMS];
    int size;

    void merge(int, int, int);
    void mergeSort(int, int);

public:
    SortedArray();
    ~SortedArray();

    bool insert(FoodItem);

    void sortPriceAscending();

    FoodItem searchByFoodID(int);

    FoodItem searchByFoodName(string);

    FoodItem searchByIndex(int);

    bool remove(int);

    int getSize();

    void print();
};

