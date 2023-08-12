#pragma once
#include "FoodItem.h"

const int MAX_ITEMS = 25;

class SortedArray {
private:
    FoodItem foodItems[MAX_ITEMS];
    int size;

    void merge(int left, int middle, int right);
    void mergeSort(int left, int right);

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

