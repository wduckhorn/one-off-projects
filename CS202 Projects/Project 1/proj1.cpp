//This program takes a list of names from a file, arranges them alphabetically and prints the list on the screen and puts them in a new file

#include<iostream>
#include<fstream>
using namespace std;

int stringCompare(char string1[], char string2[]);
void stringCopy(char string1[], char string2[]);


int main()
{

  char nameList[10][10], tempName[10], fileIn[20], fileOut[20];
  int test, i;
  ifstream inputStream;
  ofstream outputStream;
  //Asking user to input a file name
  cout << "Enter a file for input: ";
  cin >> fileIn;
  
  inputStream.open(fileIn);
  //Reads names from the files
  for(i = 0; i < 10; i++)
  inputStream >> nameList[i];
  inputStream.close(); 
  cout << endl;
  cout << "Unsorted Names" << endl 
       << "--------------" << endl;
  //Prints the names out
  for(i = 0; i < 10; i++)
    cout << nameList[i] << endl;
  //Ordering the names by alphabetical order
  for(i = 1; i < 10; i++)
   {
     for(int j = 1; j < 10; j++)
      {
        if( stringCompare(nameList[j], nameList[j - 1]) == 1)
         {
           stringCopy(tempName, nameList[j - 1]);
           stringCopy(nameList[j - 1], nameList[j]);
           stringCopy(nameList[j], tempName);
         }
      }
    }
  //Prints the names in order
    cout << endl << "Sorted Names" << endl
         << "------------" << endl;
    for(int k = 0; k < 10; k++)
    {
      cout << nameList[k] << endl;
    }
  //Asks for an output filename
  
  cout << "Enter a name for the file output: ";\
  cin >> fileOut;

  //Outputs to the file
  
  outputStream.open(fileOut);

  for(i = 0; i < 10; i++)
  outputStream << nameList[i] << endl;

  outputStream.close();

  return 0;

}


/*

  Function: stringCompare
  Arguments: Two strings
  Purpose: Compares the two strings to see which one comes first in alphabetical order. It does this by comparing the ascii values of the two strings.
  Returns: A one or a zero depending on the alphabetical order

*/


int stringCompare(char string1[], char string2[])
{
    if(string1[0] < string2[0])
      return 1;
    else
    {
     for(int i = 1; i < 4; i++)
     {
       if(string1[i-1] == string2[i-1] && string1[i] < string2[i])
       {
         return 1;
         break;
       }
     }
    }
  return 0;

}


/*

  Function: stringCopy
  Arguments: Two strings
  Purpose: Copies the second string into the first string
  Returns: Nothing

*/

void stringCopy(char string1[], char string2[])
{

  for(int i = 0; i < 10; i++)
    {
      string1[i] = string2[i];
    }

}






