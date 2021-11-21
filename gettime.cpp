#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include "Datetime.h"

using namespace std;

#define BILLION 1000000000L

struct timespec start_time;
struct timespec stop_time;

int index[6] = { 10, 100, 1000, 10000, 100000, 1000000 };//numbers for sorting
int number[1000000];		//variable for sorting numbers
int temp[1000000];			// array used for merging
int output[1000000];        // array used for Radix-sort

//function to put the random numbers to number variable
void SimpleRandDemo(int n)
{
	for (int i = 0; i < n; i++) 
		number[i] = rand();
}

void SortedArrayDemo(int n)
{
	for (int i = 0; i < n; i++)
		number[i] = i;
}

void HalfSortedArrayDemo(int n)
{
	for (int i = 0; i < n; i++) {
		if (i % 6 == 0)number[i] = rand();
		else number[i] = i;
	}
}

void ReversedArrayDemo(int n)
{
	for (int i = 0; i < n; i++) {
		number[i] = n - i;
	}
}

//function for insert sorting
void insert_sort(int n)
{
	int i, k, temp;
	for (i = 1; i < index[n]; i++) {
		temp = number[i];
		k = i - 1;
		while ((temp < number[k]) && (k >= 0)) {
			number[k + 1] = number[k];
			k = k - 1;
		}
		number[k + 1] = temp;
	}
}

//Function using Selection Sort Method
void selectionsort(int number[], int n) {
	int i, k, p;
	int x;
	for (i = 0; i < n - 1; i++) {
		p = i;
		for (k = i + 1; k < n; k++) {
			if (number[k] < number[p])p = k;
		}
		if (i != p) {
			x = number[p];
			number[p] = number[i];
			number[i] = x;
		}
	}
}

//Function using Bubble Sort Method
void bubblesort(int number[], int n) {
	int i, k;
	int x;
	for (i = 1; i < n; i++)
		for (k = n - 1; k > i; k--)
			if (number[k - 1] > number[i]) {
				x = number[k - 1];
				number[i - 1] = number[i];
				number[i] = x;
			}
}

//function to merge two arrays
void merge(int i1, int p1, int i2, int p2)
{
	int i, p, k;
	i = i1;						//beginning of the first list
	p = i2;						//beginning of the second list
	k = 0;

	while (i <= p1 && p <= p2)	//while elements in both lists
	{
		if (number[i]<number[p])
			temp[k++] = number[i++];
		else
			temp[k++] = number[p++];
	}

	while (i <= p1)				//copy remaining elements of the first list
		temp[k++] = number[i++];

	while (p <= p2)				//copy remaining elements of the second list
		temp[k++] = number[p++];

	//Transfer elements from temp[] back to a[]
	for (i = i1, p = 0; i <= p2; i++, p++)
		number[i] = temp[p];
}

//function for merge sort(recursive)
void merge_sort(int i, int k)
{
	int mid;

	if (i < k)
	{
		mid = (i + k) / 2;
		merge_sort(i, mid);		    //left recursion
		merge_sort(mid + 1, k);	    //right recursion
		merge(i, mid, mid + 1, k);	//merging of two sorted sub-arrays
	}
}

//Heap Sort Function
void heap_sort(int no)
{
	int i, k, c, root, temp;
	for (i = 1; i < no; i++)
	{
		c = i;
		do
		{
			root = (c - 1) / 2;
			if (number[root] < number[c])		/* to create MAX number array */
			{
				temp = number[root];
				number[root] = number[c];
				number[c] = temp;
			}
			c = root;
		} while (c != 0);
	}

	for (k = no - 1; k >= 0; k--)
	{
		temp = number[0];
		number[0] = number[k];					  /* swap max element with rightmost leaf element */
		number[k] = temp;
		root = 0;
		do
		{
			c = 2 * root + 1;					  /* left node of root element */
			if ((number[c] < number[c + 1]) && c < k - 1)
				c++;
			if (number[root]<number[c] && c<k)    /* again rearrange to max number array */
			{
				temp = number[root];
				number[root] = number[c];
				number[c] = temp;
			}
			root = c;
		} while (c < k);
	}
}

//QuickSort Functions
void quicksort(int arr[], int left, int right) {
	int i = left, k = right;
	int tmp;
	int pivot = arr[(left + right) / 2];

	/* partition */
	while (i <= k) {
		while (arr[i] < pivot)
			i++;
		while (arr[k] > pivot)
			k--;
		if (i <= k) {
			tmp = arr[i];
			arr[i] = arr[k];
			arr[k] = tmp;
			i++;
			k--;
		}
	};

	/* recursion */
	if (left < k)
		quicksort(arr, left, k);
	if (i < right)
		quicksort(arr, i, right);
}

//Function to get max number in number array
int getMax(int number[], int n) {
	int mx = number[0];
	int i;
	for (i = 1; i < n; i++)
		if (number[i] > mx)
			mx = number[i];
	return mx;
}

//Function that sorts number[] of size n using Count Sort
void countSort(int number[], int n, int exp=2) {

	int i, count[10] = { 0 };

	// Store count of occurrences in count[]
	for (i = 0; i < n; i++)
		count[(number[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array
	for (i = n - 1; i >= 0; i--) {
		output[count[(number[i] / exp) % 10] - 1] = number[i];
		count[(number[i] / exp) % 10]--;
	}

	for (i = 0; i < n; i++)
		number[i] = output[i];
}

// function to sort number[] of size n using Radix Sort
void radixsort(int number[], int n) {
	int m = getMax(number, n);

	int exp;
	for (exp = 1; m / exp > 0; exp *= 10)
		countSort(number, n, exp);
}


void make_index(int *p, int index_number)
{
	static int k = 0;
	for (int i = 0; i < index_number; i++)
	{
		p[i] = k;
		k += (1000000 / index_number);
	}

}

double MeasureSortingTime(int number[], int n, int choice)
{
	double duration;
	clock_gettime_monotonic(&start_time);		//Measuring start

	switch (choice) {
	case 1:
		insert_sort(n);
		break;
	case 2:

		selectionsort(number, index[n]);
		break;
	case 3:

		bubblesort(number, index[n]);
		break;
	case 4:

		merge_sort(0, index[n]);
		break;
	case 5:

		quicksort(number, 0, index[n] - 1);
		break;
	case 6:

		heap_sort(index[n]);
		break;
	case 7:

		countSort(number, index[n]);
		break;
	case 8:
		radixsort(number, index[n]);
		break;

	}

	clock_gettime_monotonic(&stop_time);		//Measuring stop

	double dSeconds = (stop_time.tv_sec - start_time.tv_sec);
	double dNanoSeconds = (double)(stop_time.tv_nsec - start_time.tv_nsec) / BILLION;

	duration = (dSeconds + dNanoSeconds);		//nanoseconds
	return duration;
}

int main() {

	int n, index_number = 6;
	srand((unsigned)time(NULL));
	int choice = 0;

	while (1) {
		//Display Main Menu
		cout << "-------------------- PROJECT 7 ----------------------" << endl;
		cout << "Choose one of the following algorithm" << endl;
		cout << "1 - Insertion Sort." << endl;
		cout << "2 - Selection Sort." << endl;
		cout << "3 - Bubble Sort." << endl;
		cout << "4 - Merge Sort." << endl;
		cout << "5 - Quick Sort." << endl;
		cout << "6 - Heap Sort." << endl;
		cout << "7 - Couting Sort" << endl;
		cout << "8 - Radix Sort" << endl;
		cout << "9 - exit" << endl;
		cout << "-----------------------------------------------------" << endl;

		cout << " :> ";
		//scanf_s("%d", &choice);
		cin >> choice;
		

		cout << endl << endl;

		//doing sort using variable index number
		for (n = 0; n < index_number; n++)
		{

			double timeBest=0, timeHalf=0, timeWorst=0;
			//fill random number to number array variable as much as index number
			if (choice > 0 && choice < 9) {
				//SimpleRandDemo(index[n]);
				//Calculate the average time of 10 measures
				//for (int i = 0; i < 10; i++) {	//delete this line to rapid the calculating speed
					SortedArrayDemo(index[n]);
					timeBest += MeasureSortingTime(number, n, choice);

					HalfSortedArrayDemo(index[n]);
					timeHalf += MeasureSortingTime(number, n, choice);

					ReversedArrayDemo(index[n]);
					timeWorst += MeasureSortingTime(number, n, choice);
				//}	//delete this line to rapid the calculating speed
				//timeBest /= 10;	 //delete this line to rapid the calculating speed
				//timeHalf /= 10;	 //delete this line to rapid the calculating speed
				//timeWorst /= 10; //delete this line to rapid the calculating speed

			}
			else if (choice == 9)
				return 0;
			else {
				//if invalid number is inputed then break loop and goto main menu
				cout << "Error in input value" << endl;
				cout << "Choose one of the options in menu" << endl;
				break;
			}
			
			switch (choice) {
			case 1:
				printf("Insertion-Sort (Random) Time => %7d : Sorted: %f seconds, Half-sorted: %f seconds, Reversed: %f seconds\n", index[n], timeBest, timeHalf, timeWorst);
				break;
			case 2:
				printf("Selection-Sort (Random) Time => %7d : Sorted: %f seconds, Half-sorted: %f seconds, Reversed: %f seconds\n", index[n], timeBest, timeHalf, timeWorst);
				break;
			case 3:
				printf("Bubble-Sort (Random) Time => %7d : Sorted: %f seconds, Half-sorted: %f seconds, Reversed: %f seconds\n", index[n], timeBest, timeHalf, timeWorst);
				break;
			case 4:
				printf("Merge-Method (Random) Time => %7d : Sorted: %f seconds, Half-sorted: %f seconds, Reversed: %f seconds\n", index[n], timeBest, timeHalf, timeWorst);
				break;
			case 5:
				printf("Quick-Method (Random) Time => %7d : Sorted: %f seconds, Half-sorted: %f seconds, Reversed: %f seconds\n", index[n], timeBest, timeHalf, timeWorst);
				break;
			case 6:
				printf("Heap-Method (Random) Time => %7d : Sorted: %f seconds, Half-sorted: %f seconds, Reversed: %f seconds\n", index[n], timeBest, timeHalf, timeWorst);
				break;
			case 7:
				printf("Counting-Sort (Random) Time => %7d : Sorted: %f seconds, Half-sorted: %f seconds, Reversed: %f seconds\n", index[n], timeBest, timeHalf, timeWorst);
				break;
			case 8:
				printf("Radix-Method (Random) Time => %7d : Sorted: %f seconds, Half-sorted: %f seconds, Reversed: %f seconds\n", index[n], timeBest, timeHalf, timeWorst);
				break;
			}
		}
		//waiting opertion to continue
		char nextchar;
		printf("\n\nPress <Enter> key to continue:");
		nextchar=getchar();
		scanf_s("%c", &nextchar);
		system("cls");

	}
	//End of the main function
	return 0;
}

