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


void SortedArray::merge(int first, int mid, int last) {
    FoodItem tempArray[MAX_ITEMS]; // temp array

    // Initialize the local indexes to indicate the subarrays
    int first1 = first;         // beginning of first subarray
    int last1 = mid;           // end of first subarray
    int first2 = mid + 1;       // beginning of second subarray
    int last2 = last;          // end of second subarray

    // While both subarrays are not empty, copy the smaller item into the temporary array
    int index = first1; // next available location in tempArray
    for (; (first1 <= last1) && (first2 <= last2); index++) {
        if (foodItems[first1].getPrice() < foodItems[first2].getPrice()) { // ascending
            tempArray[index] = foodItems[first1];
            first1++;
        }
        else {
            tempArray[index] = foodItems[first2];
            first2++;
        }
    }   

    // Finish off the nonempty subarray
    // Finish off the first subarray, if necessary
    for (; first1 <= last1; ++first1, index++)
        tempArray[index] = foodItems[first1];
    // Finish off the second subarray, if necessary
    for (; first2 <= last2; ++first2, index++)
        tempArray[index] = foodItems[first2];
    // Copy the result back into the original array
    for (index = first; index <= last; index++)
        foodItems[index] = tempArray[index];
}

void SortedArray::mergeSort(int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(left, middle);
        mergeSort(middle + 1, right);

        merge(left, middle, right);
    }
}

void SortedArray::sortPriceAscending() {
    mergeSort(0, size - 1);
}

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
    int left = 0;
    int right = size - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (foodItems[mid].getFoodName() == foodName)
            return foodItems[mid];
        if (foodItems[mid].getFoodName()< foodName)
            left = mid + 1;
        else
            right = mid - 1;
    }
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