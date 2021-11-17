#include<iostream>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<unordered_set>
#include"groups_code.h"
using namespace std;



#define Max1 100
#define Max2 10000
#define Max3 70000
#define CountMax1 100
#define CountMax2 10000
#define CountMax3 70000
#define RadMax1 100
#define RadMax2 10000
#define RadMax3 45000
#define MergeMax1 100
#define MergeMax2 10000
#define MergeMax3 60000
#define BruteMax 80000







int main()
{
	
	//-InsertionSort-
	clock_t insertionTime;
	int arrSorted1[Max1], arrHalf1[Max1], arrReversed1[Max1], arrSorted2[Max2], arrHalf2[Max2], arrReversed2[Max2], arrSorted3[Max3], arrHalf3[Max3], arrReversed3[Max3]; //All different size of list.
	cout << "-Insertion sort-" << endl << endl;
	for (int i = 0; i < Max1; i++)	// Sorted Array
	{
		arrSorted1[i] = i; //Having the elements be place in the array in order already
	}
	int sorted1 = sizeof(arrSorted1) / sizeof(arrSorted1[0]); //Getting the size of the list
	insertionTime = clock(); //Start time
	BBinsertion(arrSorted1, sorted1); //Calling insertion function
	insertionTime = clock() - insertionTime; //End time
	cout << "Execution time of already sorted list of 100 elements: " << (float)insertionTime / CLOCKS_PER_SEC << endl; //Getting the execution time.

	for (int i = 0; i < Max1; i++)	// Half Sorted Array
	{
		if (i % 6 == 0 && i != 0)
		{
			arrHalf1[i] = rand() % 100;		// Random number inserted every 6th element.
		}
		else
		{
			arrHalf1[i] = i;
		}
	}
	int halfsize1 = sizeof(arrHalf1) / sizeof(arrHalf1[0]); //Getting the size of the list.
	insertionTime = clock(); //Start time
	BBinsertion(arrHalf1, halfsize1); //Calling insertion function
	insertionTime = clock() - insertionTime; //End time
	cout << "Execution time of half sorted list of 100 elements: " << (float)insertionTime / CLOCKS_PER_SEC << endl; //Getting the execution time.

	int ra = 0; //For reverse
	for (int i = Max1; i > 0; i--)	// Reversed Array
	{
		arrReversed1[ra++] = i; //Place the values in reverse.
	}
	int reversesize1 = sizeof(arrReversed1) / sizeof(arrReversed1[0]); //Getting the size
	insertionTime = clock(); //Start time
	BBinsertion(arrReversed1, reversesize1); //Calling insertion function.
	insertionTime = clock() - insertionTime; //End time
	cout << "Execution time of reverse sorted list of 100 elements: " << (float)insertionTime / CLOCKS_PER_SEC << endl << endl << endl; //Getting the execution time.

	/////////////////////////////////////////////////////////////
	for (int i = 0; i < Max2; i++)	// Sorted Array
	{
		arrSorted2[i] = i;
	}
	int sorted2 = sizeof(arrSorted2) / sizeof(arrSorted2[0]); //Getting the size of the list.
	insertionTime = clock(); //Start time
	BBinsertion(arrSorted2, sorted2); //Calling insertion function.
	insertionTime = clock() - insertionTime; //End time
	cout << "Execution time of already sorted list of 10000 elements: " << (float)insertionTime / CLOCKS_PER_SEC << endl; //Getting the execution time.

	for (int i = 0; i < Max2; i++)	// Half Sorted Array
	{
		if (i % 6 == 0 && i != 0)
		{
			arrHalf2[i] = rand() % 10000;	// Random number inserted every 6th element.
		}
		else
		{
			arrHalf2[i] = i;
		}
	}
	int halfsize2 = sizeof(arrHalf2) / sizeof(arrHalf2[0]); //Getting the size
	insertionTime = clock(); //Start time
	BBinsertion(arrHalf2, halfsize2); //Calling the insertion funcion.
	insertionTime = clock() - insertionTime; //End time
	cout << "Execution time of half sorted list of 10000 elements: " << (float)insertionTime / CLOCKS_PER_SEC << endl; //Getting the execution time.

	int ba = 0;
	for (int i = Max2; i > 0; i--)	// Reversed Array
	{
		arrReversed2[ba++] = i;
	}
	int reversesize2 = sizeof(arrReversed2) / sizeof(arrReversed2[0]); //Getting the size of the list.
	insertionTime = clock(); //Start time
	BBinsertion(arrReversed2, reversesize2); //Calling the insertion function.
	insertionTime = clock() - insertionTime; //End time
	cout << "Execution time of reverse sorted list of 10000 elements: " << (float)insertionTime / CLOCKS_PER_SEC << endl << endl << endl; //Getting the execution time.

	/////////////////////////////////////////////////////////////
	for (int i = 0; i < Max3; i++)	// Sorted Array
	{
		arrSorted3[i] = i;
	}
	int sorted3 = sizeof(arrSorted3) / sizeof(arrSorted3[0]); //Getting the size of the list.
	insertionTime = clock(); //Start time
	BBinsertion(arrSorted3, sorted3); //Calling insertion function.
	insertionTime = clock() - insertionTime; //End time
	cout << "Execution time of already sorted list of 70000 elements: " << (float)insertionTime / CLOCKS_PER_SEC << endl; //Getting the execution time.

	for (int i = 0; i < Max3; i++)	// Half Sorted Array
	{
		if (i % 6 == 0 && i != 0)
		{
			arrHalf3[i] = rand() % 70000;	// Random number inserted every 6th element.
		}
		else
		{
			arrHalf3[i] = i;
		}
	}
	int halfsize3 = sizeof(arrHalf3) / sizeof(arrHalf3[0]);  //Getting the size of the list.
	insertionTime = clock(); //Start time
	BBinsertion(arrHalf3, halfsize3); //Calling insertion function.
	insertionTime = clock() - insertionTime; //End time
	cout << "Execution time of half sorted list of 700000 elements: " << (float)insertionTime / CLOCKS_PER_SEC << endl; //Getting the execution time.

	int ca = 0;
	for (int i = Max3; i > 0; i--)	// Reversed Array
	{
		arrReversed3[ca++] = i;
	}
	int reversesize3 = sizeof(arrReversed3) / sizeof(arrReversed3[0]); //Getting the 
	insertionTime = clock();
	BBinsertion(arrReversed3, reversesize3);
	insertionTime = clock() - insertionTime;
	cout << "Execution time of reverse sorted list of 70000 elements: " << (float)insertionTime / CLOCKS_PER_SEC << endl << endl;

	//-SelectionSort-
	clock_t selectionTime;
	int SelSorted1[Max1], SelHalf1[Max1], SelReversed1[Max1], SelSorted2[Max2], SelHalf2[Max2], SelReversed2[Max2], SelSorted3[Max3], SelHalf3[Max3], SelReversed3[Max3];
	cout << "-Selection sort- " << endl << endl;
	for (int i = 0; i < Max1; i++)		// Sorted Array
	{
		SelSorted1[i] = i;
	}
	int Selsorted1 = sizeof(SelSorted1) / sizeof(SelSorted1[0]);
	selectionTime = clock();
	BBselectionsorting(SelSorted1, Selsorted1);
	selectionTime = clock() - selectionTime;
	cout << "Execution time of already sorted list of 100 elements: " << (float)selectionTime / CLOCKS_PER_SEC << endl;

	for (int i = 0; i < Max1; i++)		// Half Sorted Array
	{
		if (i % 6 == 0 && i != 0)
		{
			SelHalf1[i] = rand() % 100;			// Random number inserted every 6th element.
		}
		else
		{
			SelHalf1[i] = i;
		}
	}
	
	int Selhalfsize1 = sizeof(SelHalf1) / sizeof(SelHalf1[0]);
	selectionTime = clock();
	BBselectionsorting(SelHalf1, Selhalfsize1);
	selectionTime = clock() - selectionTime;
	cout << "Execution time of half sorted list of 100 elements: " << (float)selectionTime / CLOCKS_PER_SEC << endl;

	int rb = 0;
	for (int i = Max1; i > 0; i--)		// Reversed Array
	{
		SelReversed1[rb++] = i;
	}
	int Selreversesize1 = sizeof(SelReversed1) / sizeof(SelReversed1[0]);
	selectionTime = clock();
	BBselectionsorting(SelReversed1, Selreversesize1);
	selectionTime = clock() - selectionTime;
	cout << "Execution time of reverse sorted list of 100 elements: " << (float)selectionTime / CLOCKS_PER_SEC << endl << endl << endl;

	/////////////////////////////////////////////////////////////
	for (int i = 0; i < Max2; i++)		// Sorted Array
	{
		SelSorted2[i] = i;
	}
	int Selsorted2 = sizeof(SelSorted2) / sizeof(SelSorted2[0]);
	selectionTime = clock();
	BBselectionsorting(SelSorted2, Selsorted2);
	selectionTime = clock() - selectionTime;
	cout << "Execution time of already sorted list of 10000 elements: " << (float)selectionTime / CLOCKS_PER_SEC << endl;

	for (int i = 0; i < Max2; i++)		// Half Sorted Array
	{
		if (i % 6 == 0 && i != 0)
		{
			SelHalf2[i] = rand() % 10000;			// Random number inserted every 6th element.
		}
		else
		{
			SelHalf2[i] = i;
		}
	}
	int Selhalfsize2 = sizeof(SelHalf2) / sizeof(SelHalf2[0]);
	selectionTime = clock();
	BBselectionsorting(SelHalf2, Selhalfsize2);
	selectionTime = clock() - selectionTime;
	cout << "Execution time of half sorted list of 10000 elements: " << (float)selectionTime / CLOCKS_PER_SEC << endl;

	int bb = 0;
	for (int i = Max2; i > 0; i--)		// Reversed Array
	{
		SelReversed2[bb++] = i;
	}
	int Selreversesize2 = sizeof(SelReversed2) / sizeof(SelReversed2[0]);
	selectionTime = clock();
	BBselectionsorting(SelReversed2, Selreversesize2);
	selectionTime = clock() - selectionTime;
	cout << "Execution time of reverse sorted list of 10000 elements: " << (float)selectionTime / CLOCKS_PER_SEC << endl << endl << endl;

	/////////////////////////////////////////////////////////////
	for (int i = 0; i < Max3; i++)		// Sorted Array
	{
		SelSorted3[i] = i;
	}
	int Selsorted3 = sizeof(SelSorted3) / sizeof(SelSorted3[0]);
	selectionTime = clock();
	BBselectionsorting(SelSorted3, Selsorted3);
	selectionTime = clock() - selectionTime;
	cout << "Execution time of already sorted list of 70000 elements: " << (float)selectionTime / CLOCKS_PER_SEC << endl;

	for (int i = 0; i < Max3; i++)		// Half Sorted Array
	{
		if (i % 6 == 0 && i != 0)
		{
			SelHalf3[i] = rand() % 50000;			// Random number inserted every 6th element.
		}
		else
		{
			SelHalf3[i] = i;
		}
	}
	int Selhalfsize3 = sizeof(SelHalf3) / sizeof(SelHalf3[0]);
	selectionTime = clock();
	BBselectionsorting(SelHalf3, Selhalfsize3);
	selectionTime = clock() - selectionTime;
	cout << "Execution time of half sorted list of 70000 elements: " << (float)selectionTime / CLOCKS_PER_SEC << endl;

	int cb = 0;
	for (int i = Max3; i > 0; i--)		// Reversed Array
	{
		SelReversed3[cb++] = i;
	}
	int Selreversesize3 = sizeof(SelReversed3) / sizeof(SelReversed3[0]);
	selectionTime = clock();
	BBselectionsorting(SelReversed3, Selreversesize3);
	selectionTime = clock() - selectionTime;
	cout << "Execution time of reverse sorted list of 70000: " << (float)selectionTime / CLOCKS_PER_SEC << endl;

	//-CountingSort-
	clock_t CountTime;
	int count0B[CountMax1];
	int count0C[CountMax1 + 1];
	int CountSorted1[CountMax1], CountHalf1[CountMax1], CountReversed1[CountMax1], CountSorted2[CountMax2], CountHalf2[CountMax2], CountReversed2[CountMax2], CountSorted3[CountMax3], CountHalf3[CountMax3], CountReversed3[CountMax3];
	for (int i = 0; i < CountMax1; i++)
	{
		CountSorted1[i] = i;
	}
	int countsize1 = sizeof(CountSorted1) / sizeof(CountSorted1[0]);
	CountTime = clock(); //Start time
	BBCountingSort(CountSorted1, countsize1, count0B, count0C); //Calling the counting sort function to sort.
	CountTime = clock() - CountTime; //End time
	cout << "-COUNTING SORT-" << endl << endl;
	cout << "Execution time of already sorted list of 100 elements: " << (float)CountTime / CLOCKS_PER_SEC << endl;

	for (int i = 0; i < CountMax1; i++)
	{
		if (i % 6 == 0 && i != 0)
		{
			CountHalf1[i] = rand() % 100;
		}
		else
		{
			CountHalf1[i] = i;
		}
	}
	int counthalfsize1 = sizeof(CountHalf1) / sizeof(CountHalf1[0]);
	CountTime = clock(); //Start time
	BBCountingSort(CountHalf1, counthalfsize1, count0B, count0C); //Calling the counting sort function to sort.
	CountTime = clock() - CountTime; //End time
	cout << "Execution time of half sorted list of 100 elements: " << (float)CountTime / CLOCKS_PER_SEC << endl;

	int aCount = 0;
	for (int i = CountMax1; i > 0; i--)
	{
		CountReversed1[aCount++] = i;
	}
	int countReversesize = sizeof(CountReversed1) / sizeof(CountReversed1[0]);
	CountTime = clock(); //Start time
	BBCountingSort(CountReversed1, countReversesize, count0B, count0C); //Calling the counting sort function to sort.
	CountTime = clock() - CountTime; //End time
	cout << "Execution time of reverse sorted list of 100 elements: " << (float)CountTime / CLOCKS_PER_SEC << endl << endl << endl;
	///////////////////////////////////////////////////////////////////////////////////////////////////
	int count1B[CountMax2];
	int count1C[CountMax2 + 1];
	for (int i = 0; i < CountMax2; i++)
	{
		CountSorted2[i] = i;
	}
	int countsize2 = sizeof(CountSorted2) / sizeof(CountSorted2[0]);
	CountTime = clock(); //Start time
	BBCountingSort(CountSorted2, countsize2, count1B, count1C); //Calling the counting sort function to sort.
	CountTime = clock() - CountTime; //End time
	cout << "Execution time of already sorted list of 100000 elements: " << (float)CountTime / CLOCKS_PER_SEC << endl;

	for (int i = 0; i < CountMax2; i++)
	{
		if (i % 6 == 0 && i != 0)
		{
			CountHalf2[i] = rand() % 10000;
		}
		else
		{
			CountHalf2[i] = i;
		}
	}
	int counthalfsize2 = sizeof(CountHalf2) / sizeof(CountHalf2[0]);
	CountTime = clock(); //Start time
	BBCountingSort(CountHalf2, counthalfsize2, count1B, count1C); //Calling the counting sort function to sort.
	CountTime = clock() - CountTime; //End time
	cout << "Execution time of half sorted list of 100000 elemetns: " << (float)CountTime / CLOCKS_PER_SEC << endl;

	int bcount = 0;
	for (int i = CountMax2; i > 0; i--)
	{
		CountReversed2[bcount++] = i;
	}
	int countReversesize2 = sizeof(CountReversed2) / sizeof(CountReversed2[0]);
	CountTime = clock(); //Start time
	BBCountingSort(CountReversed2, countReversesize2, count1B, count1C); //Calling the counting sort function to sort.
	CountTime = clock() - CountTime; //End time
	cout << "Execution time of reverse sorted list of 100000 elements: " << (float)CountTime / CLOCKS_PER_SEC << endl << endl << endl;

	/////////////////////////////////////////////////////////////////////////////////////////////////
	int count2B[CountMax3];
	int count2C[CountMax3 + 1];
	for (int i = 0; i < CountMax3; i++)
	{
		CountSorted3[i] = i;
	}
	int countsize3 = sizeof(CountSorted3) / sizeof(CountSorted3[0]);
	CountTime = clock(); //Start time
	BBCountingSort(CountSorted3, countsize3, count2B, count2C); //Calling the counting sort function to sort.
	CountTime = clock() - CountTime; //End time
	cout << "Execution time of already sorted list of 70000 elements: " << (float)CountTime / CLOCKS_PER_SEC << endl;
	for (int i = 0; i < CountMax3; i++)
	{
		if (i % 6 == 0 && i != 0)
		{
			CountHalf3[i] = rand() % 41000;
		}
		else
		{
			CountHalf3[i] = i;
		}
	}
	int counthalfsize3 = sizeof(CountHalf3) / sizeof(CountHalf3[0]);
	CountTime = clock(); //Start time
	BBCountingSort(CountHalf3, counthalfsize3, count2B, count2C); //Calling the counting sort function to sort.
	CountTime = clock() - CountTime; //End time
	cout << "Execution time of half sorted list of 70000 elements: " << (float)CountTime / CLOCKS_PER_SEC << endl;

	int ccount = 0;
	for (int i = CountMax3; i > 0; i--)
	{
		CountReversed3[ccount++] = i;
	}
	int countReversesize3 = sizeof(CountReversed3) / sizeof(CountReversed3[0]);
	CountTime = clock(); //Start time
	BBCountingSort(CountReversed3, countReversesize3, count2B, count2C); //Calling the counting sort function to sort.
	CountTime = clock() - CountTime; //End time
	cout << "Execution time of reverse sorted list of 70000 elements: " << (float)CountTime / CLOCKS_PER_SEC << endl << endl;




	//-Radix-//
	clock_t radixTime;
	int RadixSorted1[RadMax1], RadixHalf1[RadMax1], RadixReversed1[RadMax1], RadixSorted2[RadMax2], RadixHalf2[RadMax2], RadixReversed2[RadMax2], RadixSorted3[RadMax3], RadixHalf3[RadMax3], RadixReversed3[RadMax3];
	cout << "-Radix sort-" << endl << endl;
	for (int i = 0; i < RadMax1; i++)		// Sorted Array
	{
		RadixSorted1[i] = i;
	}
	int sorted1 = sizeof(RadixSorted1) / sizeof(RadixSorted1[0]);
	radixTime = clock();
	BBRadixSort(RadixSorted1, sorted1);
	radixTime = clock() - radixTime;
	cout << "Execution time of already sorted list of 100 elements: " << (float)radixTime / CLOCKS_PER_SEC << endl;

	for (int i = 0; i < RadMax1; i++)		// Half Sorted Array
	{
		if (i % 6 == 0 && i != 0)
		{
			RadixSorted1[i] = rand() % 100;			// Random number inserted every 6th element.
		}
		else
		{
			RadixSorted1[i] = i;
		}
	}
	int halfsize1 = sizeof(RadixHalf1) / sizeof(RadixHalf1[0]);
	radixTime = clock();
	BBRadixSort(RadixHalf1, halfsize1);
	radixTime = clock() - radixTime;
	cout << "Execution time of half sorted list of 100 elements: " << (float)radixTime / CLOCKS_PER_SEC << endl;

	int r = 0;
	for (int i = RadMax1; i > 0; i--)		// Reversed Array
	{
		RadixReversed1[r++] = i;
	}
	int reversesize1 = sizeof(RadixReversed1) / sizeof(RadixReversed1[0]);
	radixTime = clock();
	BBRadixSort(RadixReversed1, reversesize1);
	radixTime = clock() - radixTime;
	cout << "Execution time of reverse sorted list of 100 elements: " << (float)radixTime / CLOCKS_PER_SEC << endl << endl << endl;

	/////////////////////////////////////////////////////////////
	for (int i = 0; i < RadMax2; i++)		// Sorted Array
	{
		RadixSorted2[i] = i;
	}
	int sorted2 = sizeof(RadixSorted2) / sizeof(RadixSorted2[0]);
	radixTime = clock();
	BBRadixSort(RadixSorted2, sorted2);
	radixTime = clock() - radixTime;
	cout << "Execution time of already sorted list of 10000 elements: " << (float)radixTime / CLOCKS_PER_SEC << endl;

	for (int i = 0; i < RadMax2; i++)		// Half Sorted Array
	{
		if (i % 6 == 0 && i != 0)
		{
			RadixHalf2[i] = rand() % 10000;			// Random number inserted every 6th element.
		}
		else
		{
			RadixHalf2[i] = i;
		}
	}
	int halfsize2 = sizeof(RadixHalf2) / sizeof(RadixHalf2[0]);
	radixTime = clock();
	BBRadixSort(RadixHalf2, halfsize2);
	radixTime = clock() - radixTime;
	cout << "Execution time of half sorted list of 10000 elements: " << (float)radixTime / CLOCKS_PER_SEC << endl;

	int b = 0;
	for (int i = RadMax2; i > 0; i--)		// Reversed Array
	{
		RadixReversed2[b++] = i;
	}
	int reversesize2 = sizeof(RadixReversed2) / sizeof(RadixReversed2[0]);
	radixTime = clock();
	BBRadixSort(RadixReversed2, reversesize2);
	radixTime = clock() - radixTime;
	cout << "Execution time of reverse sorted list of 10000 elements: " << (float)radixTime / CLOCKS_PER_SEC << endl << endl << endl;

	/////////////////////////////////////////////////////////////
	for (int i = 0; i < RadMax3; i++)		// Sorted Array
	{
		RadixSorted3[i] = i;
	}
	int sorted3 = sizeof(RadixSorted3) / sizeof(RadixSorted3[0]);
	radixTime = clock();
	BBRadixSort(RadixSorted3, sorted3);
	radixTime = clock() - radixTime;
	cout << "Execution time of already sorted list of 45000 elements: " << (float)radixTime / CLOCKS_PER_SEC << endl;

	for (int i = 0; i < RadMax3; i++)		// Half Sorted Array
	{
		if (i % 6 == 0 && i != 0)
		{
			RadixHalf3[i] = rand() % 45000;			// Random number inserted every 6th element.
		}
		else
		{
			RadixHalf3[i] = i;
		}
	}
	int halfsize3 = sizeof(RadixHalf3) / sizeof(RadixHalf3[0]);
	radixTime = clock();
	BBRadixSort(RadixHalf3, halfsize3);
	radixTime = clock() - radixTime;
	cout << "Execution time of half sorted list of 45000 elements: " << (float)radixTime / CLOCKS_PER_SEC << endl;

	int c = 0;
	for (int i = RadMax3; i > 0; i--)		// Reversed Array
	{
		RadixReversed3[c++] = i;
	}
	int reversesize3 = sizeof(RadixReversed3) / sizeof(RadixReversed3[0]);
	radixTime = clock();
	BBRadixSort(RadixReversed3, reversesize3);
	radixTime = clock() - radixTime;
	cout << "Execution time of reverse sorted list of 45000 elements: " << (float)radixTime / CLOCKS_PER_SEC << endl;
	
	/////////////////////////////////////// Merge Sort

	clock_t MergeTime;
	int MergeSorted1[MergeMax1], MergeHalf1[MergeMax1], MergeReversed1[MergeMax1], MergeSorted2[MergeMax2], MergeHalf2[MergeMax2], MergeReversed2[MergeMax2], MergeSorted3[MergeMax3], MergeHalf3[MergeMax3], MergeReversed3[MergeMax3];

	//////////////////////////////////////
	for (int i = 0; i < MergeMax1; i++)	// Sorted Array
	{
		MergeSorted1[i] = i; //Having the elements be place in the array in order already
	}
	int sorted1 = sizeof(MergeSorted1) / sizeof(MergeSorted1[0]); //Getting the size of the list

	MergeTime = clock();
	SKMergeSort(MergeSorted1, 0, (sorted1 - 1));
	MergeTime = clock() - MergeTime;
	cout << "Execution time of already sorted list of 100 elements: " << (float)MergeTime / CLOCKS_PER_SEC << endl; //Getting the execution time.

	///////////////////////////////////////
	for (int i = 0; i < MergeMax1; i++)	// Half Sorted Array
	{
		if (i % 6 == 0 && i != 0)
		{
			MergeHalf1[i] = rand() % 100;		// Random number inserted every 6th element.
		}
		else
		{
			MergeHalf1[i] = i;
		}
	}

	int halfsize1 = sizeof(MergeHalf1) / sizeof(MergeHalf1[0]);
	MergeTime = clock();
	SKMergeSort(MergeHalf1, 0, (halfsize1 - 1));
	MergeTime = clock() - MergeTime;
	cout << "Execution time of half sorted list of 100 elements: " << (float)MergeTime / CLOCKS_PER_SEC << endl;

	///////////////////////////////////////
	int rd = 0; //For reverse
	for (int i = MergeMax1; i > 0; i--)	// Reversed Array
	{
		MergeReversed1[rd++] = i; //Place the values in reverse.
	}

	int reversesize1 = sizeof(MergeReversed1) / sizeof(MergeReversed1[0]);
	MergeTime = clock();
	SKMergeSort(MergeReversed1, 0, (reversesize1 - 1));
	MergeTime = clock() - MergeTime;
	cout << "Execution time of reverse sorted list of 100 elements: " << (float)MergeTime / CLOCKS_PER_SEC << endl << endl << endl; //Getting the execution time.

	//////////////////////////////////////
	for (int i = 0; i < MergeMax2; i++)	// Sorted Array
	{
		MergeSorted2[i] = i; //Having the elements be place in the array in order already
	}
	int sorted2a = sizeof(MergeSorted2) / sizeof(MergeSorted2[0]); //Getting the size of the list

	MergeTime = clock();
	SKMergeSort(MergeSorted2, 0, (sorted2a - 1));
	MergeTime = clock() - MergeTime;
	cout << "Execution time of already sorted list of 10000 elements: " << (float)MergeTime / CLOCKS_PER_SEC << endl; //Getting the execution time.

	///////////////////////////////////////
	for (int i = 0; i < MergeMax2; i++)	// Half Sorted Array
	{
		if (i % 6 == 0 && i != 0)
		{
			MergeHalf2[i] = rand() % 100;		// Random number inserted every 6th element.
		}
		else
		{
			MergeHalf2[i] = i;
		}
	}

	int halfsize2 = sizeof(MergeHalf2) / sizeof(MergeHalf2[0]);
	MergeTime = clock();
	SKMergeSort(MergeHalf2, 0, (halfsize2 - 1));
	MergeTime = clock() - MergeTime;
	cout << "Execution time of half sorted list of 10000 elements: " << (float)MergeTime / CLOCKS_PER_SEC << endl;

	///////////////////////////////////////
	int re = 0; //For reverse
	for (int i = MergeMax2; i > 0; i--)	// Reversed Array
	{
		MergeReversed2[re++] = i; //Place the values in reverse.
	}

	int reversesize2 = sizeof(MergeReversed2) / sizeof(MergeReversed2[0]);
	MergeTime = clock();
	SKMergeSort(MergeReversed2, 0, (reversesize2 - 1));
	MergeTime = clock() - MergeTime;
	cout << "Execution time of reverse sorted list of 10000 elements: " << (float)MergeTime / CLOCKS_PER_SEC << endl << endl << endl; //Getting the execution time.

		//////////////////////////////////////
	for (int i = 0; i < MergeMax3; i++)	// Sorted Array
	{
		MergeSorted3[i] = i; //Having the elements be place in the array in order already
	}
	int sorted2b = sizeof(MergeSorted3) / sizeof(MergeSorted3[0]); //Getting the size of the list

	MergeTime = clock();
	SKMergeSort(MergeSorted3, 0, (sorted2b - 1));
	MergeTime = clock() - MergeTime;
	cout << "Execution time of already sorted list of 60000 elements: " << (float)MergeTime / CLOCKS_PER_SEC << endl; //Getting the execution time.

	///////////////////////////////////////
	for (int i = 0; i < MergeMax3; i++)	// Half Sorted Array
	{
		if (i % 6 == 0 && i != 0)
		{
			MergeHalf3[i] = rand() % 100;		// Random number inserted every 6th element.
		}
		else
		{
			MergeHalf3[i] = i;
		}
	}

	int halfsize3 = sizeof(MergeHalf3) / sizeof(MergeHalf3[0]);
	MergeTime = clock();
	SKMergeSort(MergeHalf3, 0, (halfsize3 - 1));
	MergeTime = clock() - MergeTime;
	cout << "Execution time of half sorted list of 60000 elements: " << (float)MergeTime / CLOCKS_PER_SEC << endl;

	///////////////////////////////////////
	int rf = 0; //For reverse
	for (int i = MergeMax3; i > 0; i--)	// Reversed Array
	{
		MergeReversed3[rf++] = i; //Place the values in reverse.
	}

	int reversesize3 = sizeof(MergeReversed3) / sizeof(MergeReversed3[0]);
	MergeTime = clock();
	SKMergeSort(MergeReversed3, 0, (reversesize3 - 1));
	MergeTime = clock() - MergeTime;
	cout << "Execution time of reverse sorted list of 60000 elements: " << (float)MergeTime / CLOCKS_PER_SEC << endl << endl << endl; //Getting the execution time.

	/////////////////////////////////////// Bubble Sort

	clock_t BubbleTime;
	int arrSorted1[Max1], arrHalf1[Max1], arrReversed1[Max1], arrSorted2[Max2], arrHalf2[Max2], arrReversed2[Max2], arrSorted3[Max3], arrHalf3[Max3], arrReversed3[Max3]; //All different size of list.

	///////////////////////////////////
	for (int i = 0; i < Max1; i++)	// Sorted Array
	{
		arrSorted1[i] = i; //Having the elements be place in the array in order already
	}
	int sorted1c = sizeof(arrSorted1) / sizeof(arrSorted1[0]); //Getting the size of the list

	BubbleTime = clock();
	SKbubbleSort(arrSorted1, sorted1c);
	BubbleTime = clock() - BubbleTime;
	cout << "Execution time of already sorted list of 100 elements: " << (float)BubbleTime / CLOCKS_PER_SEC << endl; //Getting the execution time.

	///////////////////////////////////
	for (int i = 0; i < Max1; i++)	// Half Sorted Array
	{
		if (i % 6 == 0 && i != 0)
		{
			arrHalf1[i] = rand() % 100;		// Random number inserted every 6th element.
		}
		else
		{
			arrHalf1[i] = i;
		}
	}

	int halfsize1c = sizeof(arrHalf1) / sizeof(arrHalf1[0]);
	BubbleTime = clock();
	SKbubbleSort(arrHalf1, halfsize1c);
	BubbleTime = clock() - BubbleTime;
	cout << "Execution time of half sorted list of 100 elements: " << (float)BubbleTime / CLOCKS_PER_SEC << endl;

	////////////////////////////////////
	int rg = 0; //For reverse
	for (int i = Max1; i > 0; i--)	// Reversed Array
	{
		arrReversed1[rg++] = i; //Place the values in reverse.
	}

	int reversesize1y = sizeof(arrReversed1) / sizeof(arrReversed1[0]);
	BubbleTime = clock();
	SKbubbleSort(arrReversed1, reversesize1y);
	BubbleTime = clock() - BubbleTime;
	cout << "Execution time of reverse sorted list of 100 elements: " << (float)BubbleTime / CLOCKS_PER_SEC << endl << endl << endl; //Getting the execution time.
	
		///////////////////////////////////
	for (int i = 0; i < Max2; i++)	// Sorted Array
	{
		arrSorted2[i] = i; //Having the elements be place in the array in order already
	}
	int sorted2d = sizeof(arrSorted2) / sizeof(arrSorted2[0]); //Getting the size of the list

	BubbleTime = clock();
	SKbubbleSort(arrSorted2, sorted2d);
	BubbleTime = clock() - BubbleTime;
	cout << "Execution time of already sorted list of 10000 elements: " << (float)BubbleTime / CLOCKS_PER_SEC << endl; //Getting the execution time.

	///////////////////////////////////
	for (int i = 0; i < Max2; i++)	// Half Sorted Array
	{
		if (i % 6 == 0 && i != 0)
		{
			arrHalf2[i] = rand() % 100;		// Random number inserted every 6th element.
		}
		else
		{
			arrHalf2[i] = i;
		}
	}

	int halfsize2d = sizeof(arrHalf2) / sizeof(arrHalf2[0]);
	BubbleTime = clock();
	SKbubbleSort(arrHalf2, halfsize2d);
	BubbleTime = clock() - BubbleTime;
	cout << "Execution time of half sorted list of 10000 elements: " << (float)BubbleTime / CLOCKS_PER_SEC << endl;

	////////////////////////////////////
	int rh = 0; //For reverse
	for (int i = Max2; i > 0; i--)	// Reversed Array
	{
		arrReversed2[rh++] = i; //Place the values in reverse.
	}

	int reversesize2t = sizeof(arrReversed2) / sizeof(arrReversed2[0]);
	BubbleTime = clock();
	SKbubbleSort(arrReversed2, reversesize2t);
	BubbleTime = clock() - BubbleTime;
	cout << "Execution time of reverse sorted list of 10000 elements: " << (float)BubbleTime / CLOCKS_PER_SEC << endl << endl << endl; //Getting the execution time.

		///////////////////////////////////
	for (int i = 0; i < Max3; i++)	// Sorted Array
	{
		arrSorted3[i] = i; //Having the elements be place in the array in order already
	}
	int sorted3e = sizeof(arrSorted3) / sizeof(arrSorted3[0]); //Getting the size of the list

	BubbleTime = clock();
	SKbubbleSort(arrSorted3, sorted3e);
	BubbleTime = clock() - BubbleTime;
	cout << "Execution time of already sorted list of 70000 elements: " << (float)BubbleTime / CLOCKS_PER_SEC << endl; //Getting the execution time.

	///////////////////////////////////
	for (int i = 0; i < Max3; i++)	// Half Sorted Array
	{
		if (i % 6 == 0 && i != 0)
		{
			arrHalf3[i] = rand() % 100;		// Random number inserted every 6th element.
		}
		else
		{
			arrHalf3[i] = i;
		}
	}

	int halfsize3e = sizeof(arrHalf3) / sizeof(arrHalf3[0]);
	BubbleTime = clock();
	SKbubbleSort(arrHalf3, halfsize3e);
	BubbleTime = clock() - BubbleTime;
	cout << "Execution time of half sorted list of 70000 elements: " << (float)BubbleTime / CLOCKS_PER_SEC << endl;

	////////////////////////////////////
	int ri = 0; //For reverse
	for (int i = Max3; i > 0; i--)	// Reversed Array
	{
		arrReversed3[ri++] = i; //Place the values in reverse.
	}

	int reversesize3w = sizeof(arrReversed3) / sizeof(arrReversed3[0]);
	BubbleTime = clock();
	SKbubbleSort(arrReversed3, reversesize3w);
	BubbleTime = clock() - BubbleTime;
	cout << "Execution time of reverse sorted list of 70000 elements: " << (float)BubbleTime / CLOCKS_PER_SEC << endl << endl << endl; //Getting the execution time.

	////////////////////////////////////
	clock_t bruteTime;
	int xvalue; //The sum
	cout << endl << "In brute/inefficent method of sum, it will go through the 80,000 listed numbers to find how many pairs there is for the sum. "; 
	int BruteArray[BruteMax]; //Max size of the list is 80,000 which is going through.
	cout << endl << "Enter a value for the sum: ";
	cin >> xvalue; //User input a value for the sum that will be looking for.
	cout << endl;
	for (int i = 0; i < BruteMax; i++) //Making the list with the numbers
	{
		BruteArray[i] = i;
	}
	int bruteArraysize = sizeof(BruteArray) / sizeof(BruteArray[0]); //Getting the size of the array.
	cout << "In sorted already list:" << endl;
	bruteTime = clock(); //Start time
	bruteSum(BruteArray, bruteArraysize, xvalue); //Calling the function
	bruteTime = clock() - bruteTime; //End time
	cout << "Execution time of bruteSum time: " << (float)bruteTime / CLOCKS_PER_SEC << endl << endl << endl; //Output the time to execute.

	//Vector to hold the array
    vector<int> list;
    //int to hold the user selected size of the array
    int size = 0;
    //int to hold the sum integer
    int x = 0;
    //user prompt
    cout << "Please enter a size that you would like for a randomly generated array.\n";
    //array size input from user
    cin >> size;
    //for loop that generates random array of size that the user enetered
    for (int i = 0; i < size; i++) {
        //Pushes the generated elements in the vector named list
        list.push_back(rand() % size);
    }
    //Outputs generated array - uncommment to see it 
   /* 
   cout << "Generated Array:\n";
    //for loop that prints the generated array
    for (int i = 0; i < size; i++) {
        cout << list.at(i) << " ";
    }
    */
    //Endline
    cout << endl;
    //User input for integer x
        cout << "Please enter the integer X you would like to use\n";
        //takes the input
        cin >> x;
        //start the clock timer
        clock_t StartTime = clock();
        //calls the sum_check function that hold the algorithm
        sum_check(list, x);
        //print the time
        printf("\nTime: %.2fs\n", (float)(clock() - StartTime) / CLOCKS_PER_SEC);
	
	/*
	
	//Create all heaps needed
	Danielheap max1_sortedVec_heap;
	Danielheap max1_reverVec_heap;
	Danielheap max1_halfSortedVec_heap;

	Danielheap max2_sortedVec_heap;
	Danielheap max2_reverVec_heap;
	Danielheap max2_halfSortedVec_heap;

	Danielheap max3_sortedVec_heap;
	Danielheap max3_reverVec_heap;
	Danielheap max3_halfSortedVec_heap;

	//----------For max1-------------------
	vector<int> max1_sorted_vec = max1_vec_sorted();
	max1_sortedVec_heap.buildMaxHeap(max1_sorted_vec);
	//start timer
	max1_sortedVec_heap.ascendingHeapSort(max1_sorted_vec);
	//end timer

	vector<int> max1_rever_vec = max1_vec_reversed();
	max1_reverVec_heap.buildMaxHeap(max1_rever_vec);
	//start timer
	max1_reverVec_heap.ascendingHeapSort(max1_rever_vec);
	//end timer

	vector<int> max1_halfSorted_vec = max1_vec_halfSorted();
	max1_halfSortedVec_heap.buildMaxHeap(max1_halfSorted_vec);
	//start timer
	max1_halfSortedVec_heap.ascendingHeapSort(max1_halfSorted_vec);
	//end timer

	cout << "done max 1" << endl;

	//----------For max2-------------------
	vector<int> max2_sorted_vec = max2_vec_sorted();
	max2_sortedVec_heap.buildMaxHeap(max2_sorted_vec);
	//start timer
	max2_sortedVec_heap.ascendingHeapSort(max2_sorted_vec);
	//end timer

	vector<int> max2_rever_vec = max2_vec_reversed();
	max2_reverVec_heap.buildMaxHeap(max2_rever_vec);
	//start timer
	max2_reverVec_heap.ascendingHeapSort(max2_rever_vec);
	//end timer

	vector<int> max2_halfSorted_vec = max2_vec_halfSorted();
	max2_halfSortedVec_heap.buildMaxHeap(max2_halfSorted_vec);
	//start timer
	max2_halfSortedVec_heap.ascendingHeapSort(max2_halfSorted_vec);
	//end timer

	cout << "done max 2" << endl;

	//----------For max3-------------------
	vector<int> max3_sorted_vec = max3_vec_sorted();
	max3_sortedVec_heap.buildMaxHeap(max3_sorted_vec);
	//start timer
	max3_sortedVec_heap.ascendingHeapSort(max3_sorted_vec);
	//end timer

	vector<int> max3_rever_vec = max3_vec_reversed();
	max3_reverVec_heap.buildMaxHeap(max3_rever_vec);
	//start timer
	max3_reverVec_heap.ascendingHeapSort(max3_rever_vec);
	//end timer

	vector<int> max3_halfSorted_vec = max3_vec_halfSorted();
	max3_halfSortedVec_heap.buildMaxHeap(max3_halfSorted_vec);
	//start timer
	max3_halfSortedVec_heap.ascendingHeapSort(max3_halfSorted_vec);
	//end timer

	cout << "done max 3" << endl;
	
	
	
	*/
	

	return 0;
}
