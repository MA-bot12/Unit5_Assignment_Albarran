/*
	Input Validation with Ref Functions 
	A cleaner way to do input validation
	Validating input, an essential process.
	Source: http://stackoverflow.com/questions/514420/how-to-validate-numeric-input-c
	Keeping Dr. McMillan from breaking my code, defend against "dark side of the force",
	and/or legitimate user error. 
	//Try and Catch blocks are used in error checking
	Teacher: Dr. Tyson McMillan 
*/
#include <cstdlib>  // Provides EXIT_SUCCESS
#include <iostream>  // Provides cout, cerr, endl
#include "Input_Validation_Extended.h" // Provides getValidatedInput<T>(), a header File with a Template Class
                              // Extended 2-11-2016 by Dr. McMillan to add validation methods by datatype
#include<string> //for string manipulation
#include<sstream> //for string manipulation and comparison
using namespace std;

void printArray(int[], int); //pass array as parameter, and its size
void sortArrAsc(int[], int); 
void inputArrData(int[], int); 

int main()
{
  /* Working with arrays and vectors
	Teacher: Dr. Tyson McMillan */
  //an array called "numbers"
   int numbers[8] = {23, 46, 12, 24, 1}; //put 5 values of 8 in arr
   numbers[5] = 500; //assign value 500 to the 6th element
   numbers[6] = 1000; 
   numbers[7] = 89; 

   //get the size of numbers
   int numbers_array_size = sizeof(numbers) / sizeof(int); 
   cout << "\nNumbers[] array has " << numbers_array_size << " values. ";
   //print the current values in the numbers array
   printArray(numbers,numbers_array_size);
   sortArrAsc(numbers,numbers_array_size);
   inputArrData(numbers,numbers_array_size); 

    return 0;
}
//Function definitions 
void printArray(int array[], int size)
{
    //print the array values, 1 per line
    cout << "\nPrinted Values: " << endl; 
    for(int i = 0; i < size; i++)
    {
      cout << array[i] << endl; 
    }
}

void sortArrAsc(int array[], int size)
{
  int temp = 0; //needed for swap process
  for(int left = 0; left < size; left++) //number on the left
  {
    //the number on the right
    for(int right = left+1; right < size; right++)
    {
      //the swap magic happens here :)
      //Bubble sort: compare the left num to the right num
      //swap, if necessary.
      if(array[left] > array[right]) //hint > is ASC, < is DESC
      {
        temp = array[left]; 
        array[left] = array[right]; 
        array[right] = temp; 
      }
    }
  }

  printArray(array,size);//print the list after sorting the list ASC
}

void inputArrData(int array[], int size)
{
  //1 accept validated input into the array "size" values
  //2 sort that Array ASC
  //3 print the latest values in sorted order
  int input = 0; //my input storage variable 
  for(int i = 0; i < size; i++) //1
  {
    cout << "\nPlease input number " << (i + 1) << " of " << size <<":";
    input = validateInt(input); 
    array[i] = input; //store the validated values into the array
  }
  sortArrAsc(array,size); //2 and 3
  /*expand this code 
   sort the inputed list DESC
   and print that to the screen
   After you have sorted the array ASC

  */
  //call sortArrDesc(array, size); on this line
}