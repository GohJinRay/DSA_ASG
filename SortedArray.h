#pragma once
#include "FoodItem.h"

const int MAX_ITEMS = 25;

class SortedArray {
private:
    FoodItem foodItems[MAX_ITEMS];
    int size;

public:
    SortedArray();
    ~SortedArray();

    bool insert(FoodItem);

    FoodItem search(int);

    bool remove(int);

    int getSize();

    void print();
};

