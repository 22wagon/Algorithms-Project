The Following README file will explain how to run More Effecient.cpp by Group 7

When the program is started you will first be prompted with: 
"Please enter a size that you would like for a randomly generated array."
The number you enter will determine the size of the array that the the algorithm will use.
It will also generate a random array of that size.
For example:
If you enter 5.
A random array of size 5 will generate and look something like this:

[4][3][1][10][8]

The program also has the capability of showing you the array if you would like.
For this, simply go into the .cpp file and look for this code snippet:
    //Outputs generated array - UNCOMMENT to see it 
   /* 
   cout << "Generated Array:\n";
    //for loop that prints the generated array
    for (int i = 0; i < size; i++) {
        cout << list.at(i) << " ";
    }
    */
To have your generated array print, uncomment the code snippet by removing /* */
After uncommmenting it should look like this:
 //Outputs generated array - UNCOMMENT to see it 
   cout << "Generated Array:\n";
    //for loop that prints the generated array
    for (int i = 0; i < size; i++) {
        cout << list.at(i) << " ";
    }
The program will now show you the generated array. This part was commented out because the user can choose a very large array - there is NO cap. 
This avoids the users screen being flooded with numbers if they choose a particularly large array.
Keep in mind the larger the array the longer the runtime.

Moving on.
Once the random array is generated, the program will the prompt you with the following:
"Please enter the integer X you would like to use"

This integer is the SUM you would like to check for in the array.
So if you want to check if there is a pair of numbers that add up to 5 then you would enter 5 here.
If the algorithm finds a pair, it will output something similar to this:

Ex Output:
There exist two elements in the array whose sum is exactly x
3 + 2 = 5

If the program fails to find a pair it will output somehting similar to this:

Ex Output:
There does NOT exist two elements in the array whose sum is exactly x

The program will also ouput the time in seconds the algorithm took to find a pair or fail to find a pair.
That is the complete guide to this program! 
Below are some sample runs and the outputs to showcase what the program looks like:

Example Run with no found pair:
Please enter a size that you would like for a randomly generated array.
5
Generated Array:
1 0 3 1 3
Please enter the integer X you would like to use
0
There does NOT exist two elements in the array whose sum is exactly x

Time: 0.00s

Example Run with found pair:
Please enter a size that you would like for a randomly generated array.
10
Generated Array:
7 3 6 5 7 5 1 7 1 5
Please enter the integer X you would like to use
7
There exist two elements in the array whose sum is exactly x
1 + 6 = 7

Time: 0.00s

Example run with LARGE array just for fun!
Please enter a size that you would like for a randomly generated array.
600000

Please enter the integer X you would like to use
3500
There exist two elements in the array whose sum is exactly x
2159 + 1341 = 3500

Time: 1.05s
As we can see, the large array of size 600,000 elements made the algorithm take a whole second! Interesting!