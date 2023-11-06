// Kevin Bui
// HW3.cpp
// 11/11/22

// Purpose: recursively sort an array of integers using mergesort

// Input: a number n for array size and n integers

// Processing: recursion

// Output: a sorted array of integers

#include <iostream>

using namespace std;

void mergeSort(int [], int, int); // mergesort function
void merge(int [], int, int, int); // combines the split arrays into one

int main()
{
    int size = 0;
    int *array; // pointer for variable size array

    cout << "\n\nPlease input the array size: " ;
    cin >> size;
    array = new int[size];

    cout << "\n\nPlease input the integers for the list: " ;

    for(int x = 0; x < size; x++){ // stores n user inputs
        cin >> array[x];
        cout << endl;
    }

    mergeSort(array, 0, (size - 1)); // mergesort, size - 1 for the 0th element

    cout << "\n\nHere is the sorted array: " ;
    
    for(int x = 0; x < size; x++){ // prints the sorted array to the screen
        cout << array[x] << " " ;
    }

    cout << endl << endl;

    delete [] array; // pointer delete

    return 0;
}

void mergeSort(int arr[], int start, int end){
    if(start < end){ // base case
        int middle = (start + end)/2; // finds middle index of array
        mergeSort(arr, start, middle); // splits array into 2
        mergeSort(arr, middle + 1, end); 
        merge(arr, start, middle, end); // combines the array
    }
}

void merge(int arr[], int start, int middle, int end){
    int leftSize = middle - start + 1;
    int rightSize = end - middle;
    int *left = new int[leftSize]; // splits the original array into 2
    int *right = new int[rightSize];
    
    // creates the 2 new arrays to be sorted
    for(int x = 0; x < leftSize; x++){ 
        left[x] = arr[start + x];
    }

    for(int x = 0; x < rightSize; x++){
        right[x] = arr[middle + x + 1];
    }
    
    // sorts the arrays until one side is empty
    int leftIndex = 0, rightIndex = 0, mainIndex = start;
    while(leftIndex < leftSize && rightIndex < rightSize){
        if(left[leftIndex] <= right[rightIndex]){
            arr[mainIndex] = left[leftIndex];
            leftIndex++;
        }else{
            arr[mainIndex] = right[rightIndex];
            rightIndex++;
        }
        mainIndex++;
    }
    // fills in the rest of the array with remaining elements
    while(leftIndex < leftSize){
        arr[mainIndex] = left[leftIndex];
        leftIndex++;
        mainIndex++;
    }

    while(rightIndex < rightSize){
        arr[mainIndex] = right[rightIndex];
        rightIndex++;
        mainIndex++;
    }

    delete [] left;
    delete [] right;
}
