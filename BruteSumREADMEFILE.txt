In this ReadMe file it will explain how to run the Brute/Inefficent method of sum in the bruteSum.cpp file - by Group 7

Once in the file you code run it by simply executing the code as it already has a given set of intergers. 
Once executed it was ask for the user to input a value for the sum to find.

Example: "Enter a value for the sum: ___" <- is where the user will input the value

More details in the code and how to run it.
In the main function there will be a statement that will ask for the user input for a value for the sum.
Example:
Enter a value for the sum: 5

It will go into the bruteSum function with the array list, size, and value sum.

The total in the function is there to see if a pair is found and if no pair is found then the if(total==0) would be execute and would output:
"No possible pair to equal=" value sum.

The 1st for loop will start at the beginning of the list and then the 2nd for loop will be active by going through the whole list to try find the sum.
In the 2nd for loop there is a statement where the elements from the 1st and 2nd for loop current location is being added to the sum.
Which is then follow by a if(sum==x) where it will see if the sum equals to the user input value. If so then the total would increment by one meaning a pair has been found.

If the user would like to see what are the possible values that equal to the sum then the user has to remove the /**/ from the below code as it is optional to have.
(Warning, it could be a very long list that would take a while if the sum is a high value.)
/*cout << "pairs that equal to " << x << ": " << bruteArray[i] << " " << bruteArray[a] << endl;*/