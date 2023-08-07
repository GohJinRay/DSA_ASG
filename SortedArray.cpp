#include "SortedArray.h"
#include <iostream>
using namespace std;

SortedArray::SortedArray() {
    size = 0;
}
 
SortedArray::~SortedArray() { }

bool SortedArray::insert(FoodItem newItem)  
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

FoodItem SortedArray::search(int foodID) 
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
    return FoodItem();
}

bool SortedArray::remove(int foodID) {
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

int SortedArray::getSize()
{
    return size;
}

void SortedArray::print() {
    for (int i = 0; i < size; i++) {
        foodItems[i].printFoodItem();
    }
    cout << endl;
}