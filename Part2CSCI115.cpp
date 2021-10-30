#include <iostream>
using namespace std;
#define BruteMax 85000
//This is only for the brute force manner of part 2
void brute(int bruteArray[], int bruteS, int x)
{
	//int total = 0;
	for (int i = 0; i < bruteS; i++)
	{

		for (int a = i; a < bruteS; a++)
		{
			int sum = bruteArray[i] + bruteArray[a];
			if (sum == x)
			{
				//total++;
				//cout << "pairs that equal to 50: " << bruteArray[i] <<" "<< bruteArray[a];
				//cout << endl;
			}
		}
	}
	//cout << total << endl;
	//cout <<"total amount of pairs "<< total << endl;
}
int main()
{
	clock_t bruteTime;
	int BruteArray[BruteMax], BruteHalfArray[BruteMax], BruteReverse[BruteMax];
	int xvalue = 547;
	for (int i = 0; i < BruteMax; i++)
	{
		BruteArray[i] = i;
	}
	int bruteArraysize = sizeof(BruteArray) / sizeof(BruteArray[0]);
	cout << "In sorted already list:" << endl;
	bruteTime = clock();
	brute(BruteArray, bruteArraysize, xvalue);
	bruteTime = clock() - bruteTime;
	cout << "Execution time of bruteTime: " << (float)bruteTime / CLOCKS_PER_SEC << endl << endl << endl;

	for (int i = 0; i < BruteMax; i++)		// Half Sorted Array
	{
		if (i % 5 == 0 && i != 0)
		{
			BruteHalfArray[i] = rand() % 100;			// Random number inserted every 6th element.
		}
		else
		{
			BruteHalfArray[i] = i;
		}
	}
	int bruteHalfArraysize = sizeof(BruteHalfArray) / sizeof(BruteHalfArray[0]);
	cout << "In halfsorted list:" << endl;
	bruteTime = clock();
	brute(BruteHalfArray, bruteHalfArraysize, xvalue);
	bruteTime = clock() - bruteTime;
	cout << "Execution time of bruteTime: " << (float)bruteTime / CLOCKS_PER_SEC << endl << endl << endl;

	cout << "In reverse sorted list:" << endl;
	int b = 0;
	for (int i = BruteMax; i > 0; i--)		// Reversed Array
	{
		BruteReverse[b++] = i-1;
	}
	int bruteReverseArraysize = sizeof(BruteReverse) / sizeof(BruteReverse[0]);
	bruteTime = clock();
	brute(BruteReverse, bruteReverseArraysize, xvalue);
	bruteTime = clock() - bruteTime;
	cout << "Execution time of bruteTime: " << (float)bruteTime / CLOCKS_PER_SEC << endl;
}

