// More Effecient.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
//void Function called sum_check that takes a vector of integers and the x, which is the sum integer
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

int main()
{
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
        
}

