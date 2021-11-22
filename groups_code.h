#pragma once
#include<iostream>
#include<vector>
using namespace std;

void BBinsertion(int a[], int s) //This is the insertion Sort where the string of the input from the main will go in these void parameters. As insertion sort is to move the elements only one ahead of its position.
{
	for (int i = 0; i < s; i++) // function to move from left to right in the array of characters
	{
		for (int j = i; j > 0; j--) //where it will compare the next elements to the preivous elements
		{
			if (a[j] < a[j - 1])
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
void BBprint(int numArr[], int s)
{
	for (int i = 0; i < s; i++)
	{
		cout << numArr[i] << " ";
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
		C[i] = C[i] + C[i - 1]; // The equation here is where it is cumulatively adding the values of the array.
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
void CountingSortRA(int A[], int s, int n) //Similar to the last function with counting sort but with divison and used for Radix sort instead. Which Radix sort used part of the counting sort in the function. Which is why I put RA in the end for Radix.
{
	int B[45000]; //Placing the B and initalize it here which would be 10 as that is how many value is being sorted.   45000 derived from RadMax3 from main
	int C[45000] = { 0 }; //Where I was stucked for a bit where I had to initalize the C[10] to be 0. That is one of the difference for this Radix sort to work compare to just CountingSort. Took me an hour even with breakpoints as it wasn't picking it up as the problem. 
	for (int i = 0; i < s; i++) //This function is similar to where it will store the count 
	{
		C[(A[i] / n) % 10]++; //Instead that this function has the divsion with the module of 10 because the base decimal of being 10.
	}

	for (int i = 1; i < 10; i++) //This function would be the exact same as the last one in normal counting sort however with Radix the i is being check to 10 as that is the base decimal as well as other numbers lower or higher than 10 would not work. To see a place the proper digit in the right spot.
	{
		C[i] = C[i] + C[i - 1]; //Equation is the same as the counting sort just for a different purpose.
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
void printRA(int A[], int s) //The print function to print.
{
	for (int i = 0; i < s; i++) //To go through the array.
	{
		cout << A[i] << " "; //Outputting the values in the array.
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


void SKMerge(int arr[], int left, int mid, int right)		// Merge function
{
	int i = left;		// Declaring index which begins at the first array, and j at the beginning of second array
	int j = mid + 1;
	int k = left;		// k is the index at the beginnning of the result array (c)

	int c[60000];     //100 derived from Max1 from main

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





class Danielheap
{
public:
	vector<int> vect;
	Danielheap() { vect; }
	~Danielheap() { vect.clear(); }
	void printHeap(vector<int>& a)
	{
		int n = a.size();
		for (int i = 0; i < n; i++)
		{
			cout << a.at(i) << " ";
		}
	}

	//Max heap
	void modifyValMax(vector<int>& a, int index, int val) //Modify value
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
	void insert_value_maxHeap(vector<int>& a, int val, int n) //Adds value at the end of array and calls max_heapify
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

			i = parent + 1;    //the plus one is needed, because when the for loop iterates again it will decrease it by 1, causing it to assign the wrong parent

		}

	}
	void max_heapify(vector<int>& a, int i, int n)                 //Maintains the max heap property
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
			std::swap(a[i], a[largestNode]);
			max_heapify(a, largestNode, n);
		}

	}
	int extract_maximum(vector<int>& a) //Return the maximum element in heap and swap last element with first element
	{
		int n = a.size();
		int temp = a[0];
		a[0] = a[n - 1];
		a.pop_back(); //n --;
		max_heapify(a, 0, a.size());
		return temp;
	}
	void ascendingHeapSort(vector<int>& a)  //Prints the array in ascending order
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
	void buildMaxHeap(vector<int>& a)        //Heapifies entire list
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

		
		//	The reason that this function is neccessary is because if extract_maximum is used in an already sorted vector/array
		//	it will return the smallest int, because the smallest int occupies a[0]. This is becuase, a[0] will have the largest int
		//	in a max heap, but not in a sorted vector. Its the opposite. So, modifying extract_maximum to work on this case would mess up
		//	the function for max heaps. This means that it is best to just make two different functions to make it less complicated.
		

	}

};

void MGswap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
int MGPartition(int a[], int l, int h)
{
	int pivot, index, i;
	index = l;
	pivot = h;
	for (i = l; i < h; i++) {
		if (a[i] < a[pivot]) {
			MGswap(&a[i], &a[index]);
			index++;
		}
	}
	MGswap(&a[pivot], &a[index]);
	return index;
}

int MGQuickSort(int a[], int l, int h)
{
	int pindex;
	if (l < h) {
		pindex = MGPartition(a, l, h);
		MGQuickSort(a, l, pindex - 1);
		MGQuickSort(a, pindex + 1, h);
	}
	return 0;
}

void bruteSum(int bruteArray[], int bruteS, int x) //bruteSum function is where it will find all possible numbers in the list that will equal to the user input for the sum.
{
	int total = 0; //Total for the amount of pairs there is
	for (int i = 0; i < bruteS; i++) //The first for loop function where it starts at the beginning of the list that it will go through.
	{

		for (int a = i; a < bruteS; a++) //Second for loop function that will go through the list.
		{
			int sum = bruteArray[i] + bruteArray[a]; //Adding up from the first for loop and the second for loop to see if it equals to the sum.
			if (sum == x) //If the sum and x which is the sum the user input equals then enter in the function.
			{
				total++; //The total will increment for every sum it finds.

				//Below function is optional where if the user wants to see all the values that are added to see the sum. If want to see it remove the /**/ which is at the beginning and end. 

				/*cout << "pairs that equal to " << x << ": " << bruteArray[i] << " " << bruteArray[a] << endl;*/ 
			}
		}
	}
	cout << "total amount of pairs " << total << endl;
	if (total == 0) //If there is no pair through the whole list then enter the function
	{
		cout << "No possible pair to equal= " << x << endl; //Outputting that there is no pairs that equals to the sum.
	}
}
void sum_check(vector<int> list, int x) {
    //boolean to switch if a pair is found
    bool found_pair = false;
    //integers to hold the sum pair
    int num1 = 0;
    int num2 = 0;
    //unordered_set called HashTable because it's basically a hash table
    unordered_set<int> HashTable;
    //for loop - iterates from 0 to size of list vector
    for (int i = 0; i < list.size(); i++) {
        //x holds the sum that we want to find a pair for
        //list.at(i) is an element in the list vector
        //Ex:
        //x = 5, so we want a pair that sums to 5
        //List vector = (0, 1, 4)
        //First iteration: y = 5 - 0, so y = 0
        //then we check the hashtable, is there a 5 to make 0+5 = 5? No.
        //We store the zero and move on
        //Second iteration: y = 5 - 1, so y = 4
        //then we check the hashtable again, is there a 1 to make 4+1 = 5 in the hashtable? No.
        //We stroe the 4 in the hash table and move on
        //Third iteration: y = 5 - 4, so y = 1
        //Check the hashtable again, is there a 4 to make 1 + 4 = 5 in the hashtable? YES
        //Set found pair to true because we found a pair from the array
        //Then print out the we found it and the pair!
        //-----------------
        //Get the potential pair number
        int y = x - list.at(i);
        //Check the hashtable for the other number we need to make the sum
        if (HashTable.find(y) != HashTable.end()) {
            //if the list.at(i) + y = x then we found a pair!
            if (list.at(i) + y == x) {
                //set the boolean to true
                found_pair = true;
                //copy the pair for printing
                num1 = list.at(i);
                num2 = y;
                }
        }
        //Insert the last number we tried in the hashtable to keep checking potential pairs
        HashTable.insert(list.at(i));
    }
    //If we found a pair print we did and the pair
    if (found_pair == true) {
        cout << "There exist two elements in the array whose sum is exactly x\n";
        cout << num1 << " + " << num2 << " = " << x << endl;
    }
    //else we did NOT find a pair
    else {
        "There does NOT exist two elements in the array whose sum is exactly x\n";
    }
}

#define HeapMax1 10000
#define HeapMax2 100000
#define HeapMax3 1000000

//max1 vectors
vector<int> max1_vec_sorted()   //returns sorted vector of size Max1
{
	vector<int> returnVec(HeapMax1);
	for (int i = 0; i < HeapMax1;i++)
	{
		returnVec.push_back(i);
	}
	return returnVec;
}
vector<int> max1_vec_reversed()   //returns reverse order vector of size Max1
{
	vector<int> returnVec(HeapMax1);
	for (int i = HeapMax1; i >= 0; i--)
	{
		returnVec.push_back(i);
	}
	return returnVec;
}
vector<int> max1_vec_halfSorted()    //returns half sorted vector of size Max1
{
	vector<int> returnVec(HeapMax1);
	int n;
	for (int i = 0; i < (HeapMax1 / 2); i++)   //goes to half of the vector
	{
		returnVec.push_back(i);
	}
	for (int i = (HeapMax1 / 2) + 1; i < HeapMax1; i++)  //second half of vector
	{
		n = rand() % 100;
		returnVec.push_back(n);
	}

	return returnVec;
}

//max2 vectors
vector<int> max2_vec_sorted()   //returns sorted vector of size Max2
{
	vector<int> returnVec(HeapMax2);
	for (int i = 0; i < HeapMax2;i++)
	{
		returnVec.push_back(i);
	}
	return returnVec;
}
vector<int> max2_vec_reversed()   //returns reverse order vector of size Max2
{
	vector<int> returnVec(HeapMax2);
	for (int i = HeapMax2; i >= 0; i--)
	{
		returnVec.push_back(i);
	}
	return returnVec;
}
vector<int> max2_vec_halfSorted()    //returns half sorted vector of size Max2
{
	vector<int> returnVec(HeapMax2);
	int n;
	for (int i = 0; i < (HeapMax2 / 2); i++)   //goes to half of the vector
	{
		returnVec.push_back(i);
	}
	for (int i = (HeapMax2 / 2) + 1; i < HeapMax2; i++)  //second half of vector
	{
		n = rand() % 100;
		returnVec.push_back(n);
	}

	return returnVec;
}

//max3 vectors
vector<int> max3_vec_sorted()   //returns sorted vector of size Max3
{
	vector<int> returnVec(HeapMax3);
	for (int i = 0; i < HeapMax3;i++)
	{
		returnVec.push_back(i);
	}
	return returnVec;
}
vector<int> max3_vec_reversed()   //returns reverse order vector of size Max3
{
	vector<int> returnVec(HeapMax3);
	for (int i = HeapMax3; i >= 0; i--)
	{
		returnVec.push_back(i);
	}
	return returnVec;
}
vector<int> max3_vec_halfSorted()    //returns half sorted vector of size Max3
{
	vector<int> returnVec(HeapMax3);
	int n;
	for (int i = 0; i < (HeapMax3 / 2); i++)   //goes to half of the vector
	{
		returnVec.push_back(i);
	}
	for (int i = (HeapMax3 / 2) + 1; i < HeapMax3; i++)  //second half of vector
	{
		n = rand() % 100;
		returnVec.push_back(n);
	}

	return returnVec;
}


