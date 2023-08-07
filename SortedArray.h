#pragma once
#include "FoodItem.h"

const int MAX_ITEMS = 25;

class SortedArray {
private:
    FoodItem foodItems[MAX_ITEMS];
    int size;

public:
    // Constructor
    SortedArray();

    // Destructor
    ~SortedArray();

    // Methods
    bool insert(FoodItem);
    FoodItem search(int);
    bool remove(int);
    int getSize();
    void print();
};

