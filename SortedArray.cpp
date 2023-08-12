#include "SortedArray.h"
#include <iostream>
using namespace std;

SortedArray::SortedArray() { // constructor
    size = 0;
}
 
SortedArray::~SortedArray() { } // deconstructor

bool SortedArray::insert(FoodItem newItem) // insert FoodItem based on their fooditem id
{
    if (size >= MAX_ITEMS)
    {
        cout << "Array is full. Cannot insert more items." << endl;
        return false;
    }

    int insertIndex = size;
    while (insertIndex > 0 && newItem.getFoodID() < foodItems[insertIndex - 1].getFoodID())
    {
        foodItems[insertIndex] = foodItems[insertIndex - 1];
        insertIndex--;
    }

    foodItems[insertIndex] = newItem;
    size++;
    return true;
}

void SortedArray::mergeSort() {}

FoodItem SortedArray::searchByFoodID(int foodID) // search the fooditem via their ID
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (foodItems[mid].getFoodID() == foodID)
            return foodItems[mid];
        if (foodItems[mid].getFoodID() < foodID)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return FoodItem(-1, "", -1.0);
}

FoodItem SortedArray::searchByFoodName(string foodName) // search the fooditem via their food name
{
    for (int i = 0; i < size; i++)
        if (foodItems[i].getFoodName() == foodName)
            return foodItems[i];

    return FoodItem(-1, "", -1.0);
}

FoodItem SortedArray::searchByIndex(int index) { // search the fooditem via index
    if (index >= 0 && index < size) {
        return foodItems[index];
    }
    else {
        cout << "Invalid index." << endl;
        return FoodItem(-1, "", -1.0);
    }
}


bool SortedArray::remove(int foodID) { // remove the fooditem via their ID
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (foodItems[mid].getFoodID() == foodID)
        {
            for (int i = mid; i < size - 1; i++)
            {
                foodItems[i] = foodItems[i + 1];
            }
            size--;
            return true;
        }
        if (foodItems[mid].getFoodID() < foodID)
            left = mid + 1;
        else
            right = mid - 1;
    }

    cout << "Food item with ID " << foodID << " not found." << endl;
    return false;
}

int SortedArray::getSize() // get size of array
{
    return size;
}

void SortedArray::print() { // print all the fooditems details in the array
    for (int i = 0; i < size; i++) {
        foodItems[i].printFoodItem();
    }
}