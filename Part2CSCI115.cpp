#include <iostream>
using namespace std;
#define BruteMax 80000
//This is for the inefficient method/brute method to find all possible pair to the sum.
void bruteSum(int bruteArray[], int bruteS, int x) //bruteSum function is where it will find all possible numbers in the list that will equal to the user input for the sum.
{
	int total = 0; //Total for the amount of pairs there is
	for (int i = 0; i < bruteS; i++) //The first for loop function where it starts at the beginning of the list that it will go through
	{

		for (int a = i; a < bruteS; a++) //Second for loop function that will go through the list.
		{
			int sum = bruteArray[i] + bruteArray[a]; //Adding up from the first for loop and the second for loop to see if it equals to the sum.
			if (sum == x) //If the sum and x which is the sum the user input equals then enter in the function
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
int main()
{
	clock_t bruteTime;
	int xvalue; //The sum
	cout << endl << "In brute/inefficent method of sum, it will go through 80,000 numbers to find how many pairs there is for the sum. "; 
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
	return 0;
}
