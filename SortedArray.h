#pragma once
#include "FoodItem.h"

class SortedArray {
private:
    FoodItem** array;
    int size;

public:
    // Constructor
    SortedArray();

    // Destructor
    ~SortedArray();

    // Methods
    void insert(FoodItem* value);
    bool search(FoodItem* value);
    void remove(FoodItem* value);
    void print();
};

