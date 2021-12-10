#include "menu.hpp"

#include <iostream>
#include<cstdlib>
#include<vector>
#include <cmath>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define ARRAY_MAX_SIZE  90000

/*

#define Max1 100
#define Max2 10000
#define Max3 70000
#define CountMax1 100
#define countMax2 10000
#define CountMax3 70000
#define RadMax1 100
#define RadMax2 10000
#define RadMax3 45000
#define MergeMax1 100
#define MergeMax2 10000
#define MergeMax3 60000

*/


Menu::Menu()
{
}

Menu::~Menu()
{
}

int Menu::Start()
{
	return this->StartMenu();
}

void Menu::ShowMenu ()
{
	std::cout << "-------------------- PROJECT 7 ----------------------" << std::endl;
    std::cout << "Choose one of the following algorithm" << std::endl;
    std::cout << "1 - Insertion Sort." << std::endl;
    std::cout << "2 - Selection Sort." << std::endl;
    std::cout << "3 - Bubble Sort." << std::endl;
    std::cout << "4 - Merge Sort." << std::endl;
    std::cout << "5 - Quick Sort." << std::endl;
    std::cout << "6 - Heap Sort." << std::endl;
    std::cout << "7 - Couting Sort" << std::endl;
    std::cout << "8 - Radix Sort" << std::endl;
	std::cout << "9 - exit" << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl;
}

long long Menu::MeasureTime(vector<int>& elementToOrder, int choice)
{
    auto start = high_resolution_clock::now();
    switch (choice) {
    case 1:
        cout << "Show Insertion Sort Resolution";
        this->InsertionSort(elementsToOrder);
        break;
    case 2:
        cout << "Show Selection Sort Resolution";
        this->SelectionSort(elementsToOrder);
        break;
    case 3:
        cout << "Show Bubble Sort Resolution";
        this->BubbleSort(elementsToOrder);
        break;
    case 4:
        cout << "Show Merge Sort Resolution";
        this->MergeSort(0, elementsToOrder.size() - 1);
        break;
    case 5:
        cout << "Show Quick Sort Resolution";
        this->QuickSort(elementsToOrder, 0, elementsToOrder.size() - 1);
        break;
    case 6:
        cout << "Show Heap Sort Resolution" ;
        this->HeapSort(elementsToOrder, elementsToOrder.size());
        break;
    case 7:
        cout << "Show Counting Sort Resolution";
        this->CountingSort(elementsToOrder);
        break;
    case 8:
        cout << "Show Radix Sort Resolution";
        this->RadixSort(elementsToOrder);
        break;

    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    return duration.count();
}

int Menu::StartMenu()
{
	int choice = 0;

	this->ShowMenu();
    cout << " :> ";
	cin >> choice;

    cout << endl << endl;
    
    tempElement.resize(ARRAY_MAX_SIZE);
    output.resize(ARRAY_MAX_SIZE);

    long long timeBest = 0L, timeHalf = 0L, timeWorst = 0L;

    if (choice > 0 && choice < 9) {

        SortArray();
        elementsToOrder = randomItems;
        timeBest = MeasureTime(elementsToOrder, choice);
        cout << "  -> Sorted Array:\n";
        Print100Smallers(elementsToOrder);

        HalfSortArray();
        elementsToOrder = randomItems;
        timeHalf = MeasureTime(elementsToOrder, choice);
        cout << "  -> Half-Sorted Array:\n";
        Print100Smallers(elementsToOrder);

        ReversedArray();
        elementsToOrder = randomItems;
        timeWorst = MeasureTime(elementsToOrder, choice);
        cout << "  -> Reversed Array:\n";
        Print100Smallers(elementsToOrder);

        switch (choice) {
        case 1:
            printf("Insertion-Sort (Random) Time => %7d : Sorted: %lld milliseconds, Half-sorted: %lld milliseconds, Reversed: %lld milliseconds\n", ARRAY_MAX_SIZE, timeBest, timeHalf, timeWorst);
            break;
        case 2:
            printf("Selection-Sort (Random) Time => %7d : Sorted: %lld milliseconds, Half-sorted: %lld milliseconds, Reversed: %lld milliseconds\n", ARRAY_MAX_SIZE, timeBest, timeHalf, timeWorst);
            break;
        case 3:
            printf("Bubble-Sort (Random) Time => %7d : Sorted: %lld milliseconds, Half-sorted: %lld milliseconds, Reversed: %lld milliseconds\n", ARRAY_MAX_SIZE, timeBest, timeHalf, timeWorst);
            break;
        case 4:
            printf("Merge-Method (Random) Time => %7d : Sorted: %lld milliseconds, Half-sorted: %lld milliseconds, Reversed: %lld milliseconds\n", ARRAY_MAX_SIZE, timeBest, timeHalf, timeWorst);
            break;
        case 5:
            printf("Quick-Method (Random) Time => %7d : Sorted: %lld milliseconds, Half-sorted: %lld milliseconds, Reversed: %lld milliseconds\n", ARRAY_MAX_SIZE, timeBest, timeHalf, timeWorst);
            break;
        case 6:
            printf("Heap-Method (Random) Time => %7d : Sorted: %lld milliseconds, Half-sorted: %lld milliseconds, Reversed: %lld milliseconds\n", ARRAY_MAX_SIZE, timeBest, timeHalf, timeWorst);
            break;
        case 7:
            printf("Counting-Sort (Random) Time => %7d : Sorted: %lld milliseconds, Half-sorted: %lld milliseconds, Reversed: %lld milliseconds\n", ARRAY_MAX_SIZE, timeBest, timeHalf, timeWorst);
            break;
        case 8:
            printf("Radix-Method (Random) Time => %7d : Sorted: %lld milliseconds, Half-sorted: %lld milliseconds, Reversed: %lld milliseconds\n", ARRAY_MAX_SIZE, timeBest, timeHalf, timeWorst);
            break;
        }
    }
    else if (choice == 9)
        return 0;
    else{
        cout << "Error in input value" << endl;
        cout << "Choose one of the options in menu" << endl;
    }
    //waiting opertion to continue
    char nextchar;
    printf("\n\nPress <Enter> key to continue:");
    nextchar = getchar();
    scanf_s("%c", &nextchar);
    system("cls");
    
	this->StartMenu();

	return -1;
}

void Menu::FillData()
{
    for (int i=0; i<ARRAY_MAX_SIZE; i++) {
        randomItems.push_back(rand());
    }
}

void Menu::SortArray()
{
    randomItems.clear();
    for (int i = 0; i < ARRAY_MAX_SIZE; i++) {
        randomItems.push_back(i + 1);
    }
}

void Menu::HalfSortArray()
{
    randomItems.clear();
    for (int i = 0; i < ARRAY_MAX_SIZE; i++) {
        if (i % 6 == 0) {
            randomItems.push_back(rand());
        }
        else {
            randomItems.push_back(i);
        }
    }
}

void Menu::ReversedArray()
{
    randomItems.clear();
    for (int i = 0; i < ARRAY_MAX_SIZE; i++) {
        randomItems.push_back(ARRAY_MAX_SIZE - i);
    }
}

void Menu::Print100Smallers(vector<int>& elementsToPrint)
{
    int max_position = 50;
    cout << "[";
    for (int i=0; i<max_position; i++) {

        cout << elementsToPrint[i];

        if (i==(max_position-1))
            cout << "]\n";
        else
            cout << " , ";
    }
    cout << endl;
}

void Menu::InsertionSort(std::vector<int>& elementsToOrder)
{
   
    int i, k, temp;
    for (i = 1; i < elementsToOrder.size(); i++) {
        temp = elementsToOrder[i];
        k = i - 1;
        while ((k >= 0) && (temp < elementsToOrder[k]) ) {
            elementsToOrder[k + 1] = elementsToOrder[k];
            k = k - 1;
        }
        elementsToOrder[k + 1] = temp;
    }

}


void Menu::SelectionSort(std::vector<int>& elementsToOrder)//The selection sort list.
{
    int i, k, p;
    int x;
    for (i = 0; i < elementsToOrder.size() - 1; i++) {
        p = i;      //minimum of the starting index.
        for (k = i + 1; k < elementsToOrder.size(); k++) {  //Is one after the i point and will check upto the max size.
            if (elementsToOrder[k] < elementsToOrder[p])    //Checking if the a value is less than the min value
                p = k;  //If it is less than min value than the new min will be place
        }
        if (i != p) {   //This is to swap if min value is not starting point itself
            x = elementsToOrder[p];
            elementsToOrder[p] = elementsToOrder[i];
            elementsToOrder[i] = x;
        }
    }
}

void Menu::BubbleSort(std::vector<int>& elementsToOrder)
{
    int i, k;
    int x;
    for (i = 0; i < elementsToOrder.size(); i++)
        for (k = elementsToOrder.size() - 1; k > i; k--)
            if (elementsToOrder[k ] < elementsToOrder[i]) {
                x = elementsToOrder[k];
                elementsToOrder[k] = elementsToOrder[i];
                elementsToOrder[i] = x;
            }
}

void Menu::Merge(int i1, int p1, int i2, int p2)
{
    int i, p, k;
    i = i1;						//beginning of the first list
    p = i2;						//beginning of the second list
    k = 0;

    while (i <= p1 && p <= p2)	//while elements in both lists
    {
        if (elementsToOrder[i] < elementsToOrder[p])
            tempElement[k++] = elementsToOrder[i++];
        else
            tempElement[k++] = elementsToOrder[p++];
    }

    while (i <= p1)				//copy remaining elements of the first list
        tempElement[k++] = elementsToOrder[i++];

    while (p <= p2)				//copy remaining elements of the second list
        tempElement[k++] = elementsToOrder[p++];

    //Transfer elements from temp[] back to a[]
    for (i = i1, p = 0; i <= p2; i++, p++)
        elementsToOrder[i] = tempElement[p];
}

void Menu::MergeSort(int fir, int las)
{
    int mid;

    if (fir < las)
    {
        mid = (fir + las) / 2;
        MergeSort(fir, mid);		    //left recursion
        MergeSort(mid + 1, las);	    //right recursion
        Merge(fir, mid, mid + 1, las);	//merging of two sorted sub-arrays
    }
}

//Quicksort is a sorting algorithm which uses the divide and conquer approach to solve any given problem.
//It uses a pivot element, to determine the dividing point of the array.
//The pivot element here is chosen as the first element of the array
//and the partitioning is done in such a way that the pivot element will be placed in such a way that
//any element to the right of it will be larger than it and any element to its left will be smaller than it.
void Menu::QuickSort(std::vector<int>& elementsToOrder, int left, int right)
{
    int i = left, k = right;
    int tmp;
    int pivot = elementsToOrder[(left + right) / 2]; //choose mid element as pivot

    /* partition */
    // repeat the loop until i index becomes equal or greater than k
    while (i <= k) {
        //increment the i index until we find a number greater than or equal to the pivot or until we reach the end of the array
        while (elementsToOrder[i] < pivot) 
            i++;
        //decrement the k index until we find a number smaller than or equal to the pivot or until we reach the beginning of array
        while (elementsToOrder[k] > pivot)
            k--;
        //swap the numbers at index position i and k
        if (i <= k) {
            if (i != k) {
                tmp = elementsToOrder[i];
                elementsToOrder[i] = elementsToOrder[k];
                elementsToOrder[k] = tmp;
            }
            i++;
            k--;
        }
    }

    /* recursion */
    if (left < k)
        QuickSort(elementsToOrder, left, k);// sort the left part of the array
    if (i < right)
        QuickSort(elementsToOrder, i, right);// sort the right part of the array
}

void Menu::HeapSort(std::vector<int>& elementsToOrder, int no)
{
    int i, k, c, root, temp;
    for (i = 1; i < no; i++)
    {
        c = i;
        do
        {
            root = (c - 1) / 2;
            if (elementsToOrder[root] < elementsToOrder[c])		/* to create MAX number array */
            {
                temp = elementsToOrder[root];
                elementsToOrder[root] = elementsToOrder[c];
                elementsToOrder[c] = temp;
            }
            c = root;
        } while (c != 0);
    }

    for (k = no - 1; k >= 0; k--)
    {
        temp = elementsToOrder[0];
        elementsToOrder[0] = elementsToOrder[k];					  /* swap max element with rightmost leaf element */
        elementsToOrder[k] = temp;
        root = 0;
        do
        {
            c = 2 * root + 1;					  /* left node of root element */
            if (c > elementsToOrder.size() - 2)continue;
            if ((elementsToOrder[c] < elementsToOrder[c + 1]) && c < k - 1)
                c++;
            if (elementsToOrder[root] < elementsToOrder[c] && c < k)    /* again rearrange to max number array */
            {
                temp = elementsToOrder[root];
                elementsToOrder[root] = elementsToOrder[c];
                elementsToOrder[c] = temp;
            }
            root = c;
        } while (c < k);
    }
}

void Menu::CountingSort(std::vector<int>& elementsToOrder)
{
    int i;

    std::vector<int> count;

    int mx = GetMax(elementsToOrder);

    count.resize(mx + 1);

    int n = elementsToOrder.size();

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[elementsToOrder[i]]++;

    for (i = 1; i < mx+1; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[elementsToOrder[i]] - 1] = elementsToOrder[i];
        count[elementsToOrder[i]]--;
    }

    for (i = 0; i < n; i++)
        elementsToOrder[i] = output[i];
}

void Menu::RadixSort(std::vector<int>& elementsToOrder)
{
    int m = GetMax(elementsToOrder);

    int exp;
    int n = elementsToOrder.size();
    for (exp = 1; m / exp > 0; exp *= 10)
    {
        int i, count[10] = { 0 };

        // Store count of occurrences in count[]
        for (i = 0; i < n; i++)
            count[(elementsToOrder[i] / exp) % 10]++;

        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];

        // Build the output array
        for (i = n - 1; i >= 0; i--) {
            output[count[(elementsToOrder[i] / exp) % 10] - 1] = elementsToOrder[i];
            count[(elementsToOrder[i] / exp) % 10]--;
        }

        for (i = 0; i < n; i++)
            elementsToOrder[i] = output[i];
    }
        
}

int Menu::GetMax(std::vector<int>& elementsToOrder)
{
    int mx = elementsToOrder[0];
    int i;
    for (i = 1; i < elementsToOrder.size(); i++)
        if (elementsToOrder[i] > mx)
            mx = elementsToOrder[i];
    return mx;
}

void Menu::CalculateHFactors(vector<unsigned int>& h_factors, const vector<int>& elementsToOrder)
{
    int k=1;
    unsigned int h_factor=1;
    while (h_factor < elementsToOrder.size()) {
        h_factors.push_back(h_factor);
        if (k % 2 == 0) { //even
            h_factor = 9 * (pow(2, k) - pow(2, k/2)) + 1;
        }
        else { // odd
            h_factor = 8 * pow(2, k) - 6 * pow(2, (k+1)/2) + 1;
        }

        k++;
    }
}

