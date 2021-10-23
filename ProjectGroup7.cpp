#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;
#define Max1 100
#define Max2 10000
#define Max3 70000
#define CountMax1 100
#define countMax2 10000
#define CountMax3 70000
#define RadMax1 100
#define RadMax2 10000
#define RadMax3 45000
void BBinsertion(int a[], int s) //This is the insertion Sort where the string of the input from the main will go in these void parameters. As insertion sort is to move the elements only one ahead of its position.
{
	for (int i = 0; i < s; i++) // function to move from left to right in the array of characters
	{
		for (int j = i; j > 0; j--) //where it will compare the next elements to the preivous elements
		{
            if(a[j] < a[j-1])
            {
                int temp; //temporary
				temp = a[j]; //the j will be at temp
				a[j] = a[j - 1]; //this is where it will start to swap
				a[j - 1] = temp; //swapping will each other
			}
			else
			{
				break; //if the elements is not less than the previous elements it breaks out the loop
			}
		}
		
	}
}
void BBselectionsorting(int numArr[], int val) //The selection sort list.
{
    for (int i = 0; i < val; i++) //The function to move one by one to the right.
    {
        int min; //This is the minimum.
        min = i; //minimum of the starting index.
        for (int a = i + 1; a < val; a++) //Is one after the i point and will check upto the max size. 
        {
            if (numArr[a] < numArr[min]) //Checking if the a value is less than the min value
            {
                min = a; //If it is less than min value than the new min will be place
            }
        }
        swap(numArr[min], numArr[i]); //This is to swap whatever is the minimum with the i is now to be in order
    }
}
void print(int numArr[], int s)
{
    fir(int i = 0; i < s; i++)
    {
        cout << numArr[i] << " ";
    }
}

void SKMerge(int arr[], int left, int mid, int right)		// Merge function
{
	int i = left;		// Declaring index which begins at the first array, and j at the beginning of second array
	int j = mid + 1;
	int k = left;		// k is the index at the beginnning of the result array (c)

	int c[20000];

	while (i <= mid && j <= right)		// While both indexes have not reached the end of either it's array, it continues to traverse the array
	{
		if (arr[i] < arr[j])		// If the element in the left array is less, it will be copied over to the result array (vice-versa)
		{
			c[k] = arr[i];
			i++;
			k++;
		}
		else
		{
			c[k] = arr[j];
			j++;
			k++;
		}
	}
	while (j <= right)		// If one array is cleared, the rest of the elements on the other side will be copied over to the result array.
	{
		c[k] = arr[j];
		j++;
		k++;
	}
	while (i <= mid)
	{
		c[k] = arr[i];
		i++;
		k++;
	}
	for (i = left; i < k; i++)		// Elements from the result array are copied over to the main array.
	{
		arr[i] = c[i];
	}
}

void SKbubbleSort(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void SKMergeSort(int arr[], int left, int right)		// MergeSort function
{
	if (left < right)
	{
		int mid = (left + right) / 2;		// Takes the mid by combining the beginning of the first array + end of second array divided by 2
		SKMergeSort(arr, left, mid);
		SKMergeSort(arr, mid + 1, right);
		SKMerge(arr, left, mid, right);
	}
}
void BBCountingSort(int A[], int s, int B[], int C[]) //This is the function to do the counting sort.
{
	int maxElement = A[0]; //To inital the max element.
	for (int i = 1; i < s; i++) //The function to find the largest element by going through the size.
	{
		if (A[i] > maxElement) //Comparing the current array to the last max element to see if its bigger.
		{
			maxElement = A[i]; //Making the current array i be the new max Element.
		}
	}
	for (int i = 0; i <= maxElement; i++) //To start all the count array to be zero.
	{
		C[i] = 0; //Having 0 through the whole count array at first.
	}
	for (int i = 0; i < s; i++) //This function is to store the count.
	{
		C[A[i]]++; //Adding it up by one.
	}
	for (int i = 1; i <= maxElement; i++) ///This is to loop through the auxiliary array.
	{
		C[i] =C[i] + C[i - 1]; // The equation here is where it is cumulatively adding the values of the array.
	}
	for (int i = s - 1; i >= 0; i--) //Placing the elements in the output array.
	{
		B[C[A[i]] - 1] = A[i]; //Where the current index which is A[i] is being placed.
		C[A[i]]--; //This is where it is decrementing by one.
	}
	for (int i = 0; i < s; i++) //Copy the sorts elements into original array which is A.
	{
		A[i] = B[i]; //Transfering it from the B array and placing it in the original A array.
	}
}
void printCountsort(int A[], int s) //This is to print the values out for counting sort.
{
	for (int i = 0; i < s; i++) //Going through the array.
	{
		cout << A[i] << " "; //Printing it out the values.
	}
}
void CountingSortRA(int A[], int s, int n) //Similar to the last function with counting sort but with divison and used for Radix sort instead. Which Radix sort used part of the counting sort in the function. Which is why I put RA in the end for Radix.
{
    int B[RadMax3]; //Placing the B and initalize it here which would be 10 as that is how many value is being sorted.
    int C[RadMax3] = { 0 }; //Where I was stucked for a bit where I had to initalize the C[10] to be 0. That is one of the difference for this Radix sort to work compare to just CountingSort. Took me an hour even with breakpoints as it wasn't picking it up as the problem. 
    for (int i = 0; i < s; i++) //This function is similar to where it will store the count 
    {
        C[(A[i] / n) % 10]++; //Instead that this function has the divsion with the module of 10 because the base decimal of being 10.
    }

    for (int i = 1; i < 10; i++) //This function would be the exact same as the last one in normal counting sort however with Radix the i is being check to 10 as that is the base decimal as well as other numbers lower or higher than 10 would not work. To see a place the proper digit in the right spot.
    {
        C[i] =C[i] + C[i - 1]; //Equation is the same as the counting sort just for a different purpose.
    }
    for (int i = s - 1; i >= 0; i--) //Again similar to the counting sort where this function is to build the output array.
    {
        B[C[(A[i] / n) % 10] - 1] = A[i]; //Difference is that this equation would have the divison and moduel by 10 for the decimal base being 10 and to check each digit with the other digits.
        C[(A[i] / n) % 10]--; //Decrementing by on.
    }
    for (int i = 0; i < s; i++) //This is exactly the same as counting sort to copy from the copy array and place it in th original where it will be output as sorted.
    {
        A[i] = B[i]; //This is where the equation is being place in the original array.
    }
}
void BBRadixSort(int A[], int s)
{
    int maxElement = A[0]; //Instead in the counting sort is now in the Radix sort to get the max element.
    for (int i = 1; i < s; i++) //Going through to find the max.
    {
        if (A[i] > maxElement) //Comparing to see if its bigger than the last max element.
        {
            maxElement = A[i]; //Changing the max element with a new higher max element.
        }
    }  
    for (int n = 1; maxElement / n > 0; n *= 10) //Having the function be cut in half and then increment by 10 multiplication of 10 as the decimal base is 10 to go higher in the digits of high value.
    {
        CountingSortRA(A, s, n); //Where the counting sort function is being called to be used for Radix. 
    }
}
void printRA(int A[], int s) //The print function to print.
{
    for (int i = 0; i < s; i++) //To go through the array.
    {
        cout << A[i] << " "; //Outputting the values in the array.
    }
}


//----------------------Start Daniel's code--------------
void daniel_merge(vector<int> &vec, int left, int mid, int right)
{	
	int i = left, j = mid + 1;              //i points to first index of left subvector, j to right subvector
	vector<int> aux(vec.size());            //aux vector to help with merging
	for (int k = left; k <= right; k++)     //copy passed vector into aux vector
	{
		aux[k] = vec[k];
	}
	for (int g = left; g <= right; g++)
	{
		if (i > mid) { vec[g] = aux[j]; j++; }                     //if left subvector is done
		else if (j > right) { vec[g] = aux[i]; i++; }              //if right subvector is done             
		else if (aux[i] <= aux[j]) { vec[g] = aux[i]; i++; }       //if i'th element is less than j's element
		else if (aux[i] > aux[j]) { vec[g] = aux[j]; j++; }        //if i'th element is greater than j's element
	}

}
void daniel_mergeSort(vector<int>& a, int left, int right)
{
	if (right <= left) { return; }
	else
	{
		int mid = (left + right) / 2;
		mergeSort(a, left, mid);
		mergeSort(a, mid + 1, right);
		merge(a, left, mid, right);
	}

}
void daniel_selectSort(vector<int> &a)
{
	int min;
	for (int i = 0; i < a.size(); i++)
	{
		min = i;
		for (int j = i + 1; j < a.size(); j++)
		{
			if (a.at(j) < a.at(min))
				min = j;
			continue;
		}
		std::swap(a[i], a[min]);
	}
}
void daniel_bubbleSort(vector<int> &a)
{
    int n = a.size();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n-2; j++)
        {
            if (a[j] < a[j+1])
                std::swap(a[j],a[j+1]);
        }
    }
}
class Danielheap
{
    public:
    vector<int> vect;
    Heap()
    {
        vect;
    }
    void printHeap(vector<int>& a)
    {
        int n = a.size();
        for (int i = 0; i < n; i++)
        {
            cout << a.at(i) << " ";
        }
    }

     //Max heap
    void modifyValMax (vector<int> &a, int index, int val) //Modify value
    {
        int n = a.size();
        int parent;
        a[index] = val;
        for (int i = n; i > 0; i--)
        {
            parent = (index - 1) / 2;
            if (a[index] > a[parent])
                std::swap(a[index], a[parent]);
            i = parent;
        }

    }
    void insert_value_maxHeap(vector<int> &a, int val, int n) //Adds value at the end of array and calls max_heapify
    {
        a.push_back(val);
        n++;
        int parent;
        for (int i = (n - 1); i > 0; i--)
        {
            parent = (i - 1) / 2;
            if (a[i] > a[parent])
            {
                std::swap(a[i], a[parent]);
                max_heapify(a, parent, n);
            }
            
            i = parent+1;    //the plus one is needed, because when the for loop iterates again it will decrease it by 1, causing it to assign the wrong parent
            
        }
        
    }
    void max_heapify(vector<int> &a, int i, int n)                 //Maintains the max heap property
    {
        int left = (2 * i) + 1, right = (2 * i) + 2;
        int largestNode = i;
        if (left < n && a[left] > a[i])
        {
            largestNode = left;
        }
        if (right < n && a[right] > a[largestNode])
        {
            largestNode = right;
        }
        if (largestNode != i)
        {
            std::swap(a[i],a[largestNode]);
            max_heapify(a, largestNode, n);
        }

    }


    int extract_maximum(vector<int> &a) //Return the maximum element in heap and swap last element with first element
    {
        int n = a.size();
        int temp = a[0];
        a[0] = a[n-1];
        a.pop_back(); //n --;
        max_heapify(a, 0, a.size());
        return temp;
    }
    void ascendingHeapSort(vector<int> &a)  //Prints the array in ascending order
    {
        vector<int> tempvec;
        tempvec = a;
        int n = tempvec.size();
        buildMaxHeap(tempvec);
        for (int i = (n - 1); i >= 0; i--)
        {
            std::swap(tempvec[i], tempvec[0]);
            max_heapify(tempvec, 0, i);
        }
        a = tempvec;

    }
    void buildMaxHeap(vector<int> &a)        //Heapifies entire list
    {
        int n = a.size();
        int lastnonleaf = (n / 2) - 1;
        for (int l = lastnonleaf; l >= 0; l--)
        {
            max_heapify(a, l, n);
        }

    }
    int extract_max_from_sorted_vec(vector<int>& a)  //This function is specifically used for extract max on an already sorted array
    {
        int n = a.size();
        int temp = a[n - 1]; //set temp to the node with the max element
        a.pop_back();
        return temp;

        /*
            The reason that this function is neccessary is because if extract_maximum is used in an already sorted vector/array
            it will return the smallest int, because the smallest int occupies a[0]. This is becuase, a[0] will have the largest int
            in a max heap, but not in a sorted vector. Its the opposite. So, modifying extract_maximum to work on this case would mess up
            the function for max heaps. This means that it is best to just make two different functions to make it less complicated.
        
        */
    
    }

}

int find_r(vector<int>& a) //basically a find max function
{
	int  max;
	max = a[0];
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] >= max)
			max = a[i];
	}
	return max;
}
void daniel_countSort(vector<int>& a, vector<int>& b)
{
	int r = find_r(a);    //find max element
	int n = a.size();
	vector<int> c(r + 1);    //initalize c with r + 1
	for (int i = 0; i < r; i++)   //make aux vec filled with 0s
	{
		c[i] = 0;
	}
	for (int j = 0; j < n; j++) //needed to initalize j to 0, instead of 1, because it wasn't counting the # in position 0
	{
		c[a[j]] = (c[a[j]] + 1);
	}
	for (int i = 1; i <= r; i++)   //cummalative sum
	{
		c[i] = (c[i] + c[i - 1]);
	}
	for (int j = (n - 1); j >= 0; j--)
	{
		b[(c[a[j]] - 1)] = a[j];  //Needed to decrement c, because it was updating b one position to the right 
		c[a[j]] = (c[a[j]] - 1);  //and was causing a "vector subscript out of range" error

	}
}
int find_d(vector<int>& a)  //this function gets the max of the passed array, and gets the length of that max
{
	int max = find_r(a);
	int size = trunc(log10(max)) + 1;
	return size;
}
void daniel_radixSort(vector<int>& a)
{
	int d = find_d(a);
	vector<int> b(a.size());
	for (int i = 1; i <= d; i++)
	{
		countSort(a, b);
	}
	a = b;
}
//------------End Daniel's code-------------------
void swap(int *a, int *b) 
{
   int temp;
   temp = *a;
   *a = *b;
   *b = temp;
}

int Partition(int a[], int l, int h) 
{
   int pivot, index, i;
   index = l;
   pivot = h;
   for(i = l; i < h; i++) {
      if(a[i] < a[pivot]) {
         swap(&a[i], &a[index]);
         index++;
      }
   }
   swap(&a[pivot], &a[index]);
   return index;
}
int RandomPivotPartition(int a[], int l, int h) 
{
   int pvt, n, temp;
   n = rand();
   pvt = l + n%(h-l+1);
   swap(&a[h], &a[pvt]);
   return Partition(a, l, h);
}
int MGQuickSort(int a[], int l, int h) 
{
   int pindex;
   if(l < h) {
      pindex = RandomPivotPartition(a, l, h);
      QuickSort(a, l, pindex-1);
      QuickSort(a, pindex+1, h);
   }
   return 0;
}
int main()
{
    /*-InsertionSort-*/
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
	
	int r = 0; //For reverse
	for (int i = Max1; i > 0; i--)	// Reversed Array
	{
		arrReversed1[r++] = i; //Place the values in reverse.
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

	int b = 0;
	for (int i = Max2; i > 0; i--)	// Reversed Array
	{
		arrReversed2[b++] = i; 
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

	int c = 0;
	for (int i = Max3; i > 0; i--)	// Reversed Array
	{
		arrReversed3[c++] = i;
	}
	int reversesize3 = sizeof(arrReversed3) / sizeof(arrReversed3[0]); //Getting the 
	insertionTime = clock();
	BBinsertion(arrReversed3, reversesize3);
	insertionTime = clock() - insertionTime;
	cout << "Execution time of reverse sorted list of 70000 elements: " << (float)insertionTime / CLOCKS_PER_SEC << endl;

    /*-SelectionSort-*/
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

	int r = 0;
	for (int i = Max1; i > 0; i--)		// Reversed Array
	{
		SelReversed1[r++] = i;
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

	int b = 0;
	for (int i = Max2; i > 0; i--)		// Reversed Array
	{
		SelReversed2[b++] = i;
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

	int c = 0;
	for (int i = Max3; i > 0; i--)		// Reversed Array
	{
		SelReversed3[c++] = i;
	}
	int Selreversesize3 = sizeof(SelReversed3) / sizeof(SelReversed3[0]);
	selectionTime = clock();
	BBselectionsorting(SelReversed3, Selreversesize3);
	selectionTime = clock() - selectionTime;
	cout << "Execution time of reverse sorted list of 70000: " << (float)selectionTime / CLOCKS_PER_SEC << endl;

    /*-CountingSort-*/
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
	cout << "Execution time of already sorted list of 1 million elements: " << (float)CountTime / CLOCKS_PER_SEC << endl;
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
	cout << "Execution time of half sorted list of 1 million elements: " << (float)CountTime / CLOCKS_PER_SEC << endl;

	int ccount = 0;
	for (int i = CountMax3; i > 0; i--)
	{
		CountReversed3[ccount++] = i;
	}
	int countReversesize3 = sizeof(CountReversed3) / sizeof(CountReversed3[0]);
	CountTime = clock(); //Start time
	BBCountingSort(CountReversed3, countReversesize3, count2B, count2C); //Calling the counting sort function to sort.
	CountTime = clock() - CountTime; //End time
	cout << "Execution time of reverse sorted list of 1 million elements: " << (float)CountTime / CLOCKS_PER_SEC << endl << endl;
    
    /*-Radix-*/
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
    return 0;
}