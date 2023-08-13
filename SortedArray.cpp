#include "SortedArray.h"
#include <iostream>
using namespace std;

// Constructor for SortedArray class
SortedArray::SortedArray() { 
    size = 0;
}
 // Deconstructor for SortedArray class
SortedArray::~SortedArray() { }

/*
   Add a food item to the Sorted Array

   Parameters:
   - newItem: Reference to the FoodItem object to be added.

   Return Value: True if the food item is successfully added, false otherwise.
*/
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

    // Insert the new item at the correct position
    foodItems[insertIndex] = newItem;
    size++;
    return true;
}


/*
    Merge two subarrays to sort the elements between them.

    Parameters:
    - first: indicates the beginning of the first subarray
    - mid:   indicates the end of the first subarray
    - last:  indicates the end of second subarray
*/
void SortedArray::merge(int first, int mid, int last) {
    FoodItem tempArray[MAX_ITEMS]; // temp array

    // Initialize the local indexes to indicate the subarrays
    int first1 = first;   
    int last1 = mid;         
    int first2 = mid + 1;       // beginning of second subarray
    int last2 = last;     

    // While both subarrays are not empty, copy the smaller item into the temporary array
    int index = first1; 
    for (; (first1 <= last1) && (first2 <= last2); index++) {
        if (foodItems[first1].getPrice() < foodItems[first2].getPrice()) { // ascending order
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


/*
    It will recursively sort the left half of the array
    and the right half of the array and will merge it back
    together by using the merge function

    Parameters:
    - left:  the start of the array that you want to sort
    - right: the end of the array that you want to sort
*/
void SortedArray::mergeSort(int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(left, middle);
        mergeSort(middle + 1, right);

        merge(left, middle, right);
    }
}

// sort the array via ascending order for the prices of the food
void SortedArray::sortPriceAscending() {
    mergeSort(0, size - 1);
}


/*
    Search the fooditem via their ID, using binary search

    Parameters:
    - foodID: The ID of the FoodItem to search for

    Return Value:
    - The FoodItem with the specified ID, or a default FoodItem if not found.
*/
FoodItem SortedArray::searchByFoodID(int foodID) 
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
    return FoodItem(-1, "", -1.0); // Not Found
}


/*
    Search the fooditem via their Food Name
    used sequential search as it is sorted based off their Food ID and not Food Name

    Parameters:
    - foodName: The name of the FoodItem to search for

    Return Value:
    - The FoodItem with the specified food name, or a default FoodItem if not found.
*/
FoodItem SortedArray::searchByFoodName(string foodName) // search the fooditem via their food name
{
    for (int i = 0; i < size; i++) {
        if (foodItems[i].getFoodName() == foodName) {
            return foodItems[i];
        }
    }
    return FoodItem(-1, "", -1.0); // Not found
}


/*
    Search the fooditem via their position in the array

    Parameters:
    - index: The position of the food item in the array.

    Return Value:
    - The FoodItem at the specified index, or a default FoodItem if not found.
*/
FoodItem SortedArray::searchByIndex(int index) { // search the fooditem via index
    if (index >= 0 && index < size) {
        return foodItems[index];
    }
    else {
        cout << "Invalid index." << endl;
        return FoodItem(-1, "", -1.0);
    }
}


/*
    Remove the fooditem by using its ID

    Paremeters:
    - foodID: The ID of the fooditem

    Return Value:
    - True: when its successfully removed
    - False: when the ID of the fooditem is not found
*/
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