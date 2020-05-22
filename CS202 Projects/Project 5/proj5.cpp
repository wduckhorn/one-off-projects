//This is the test driver for the custom made string class
//Compile with "make"
#include<iostream>
#include "MyString.h"
using namespace std;


int main(){
  //(1) Default Constructor
  MyString string;
  //(2) Parameterized Constructor
  MyString string2("Physics is dumb");
  //(3) Copy Constructor
  MyString string3(string2);
  //(4) Destructor
  MyString* ms_ptr = new MyString("String to be deleted");
  delete ms_ptr;
  ms_ptr = NULL;
  //(5) Size, (6) Length
  MyString SizeLength("Size and length test");
  cout << "Size: " << SizeLength.size() << " Length: " << SizeLength.length() << endl;
  //(7) C Style String
  MyString ms_CString("This is a C style string");
  cout << ms_CString.c_str() << endl;
  //(8) Check for equality
  MyString Same1("Same string");
  MyString Same2("Same string");
  if(Same1 == Same2){
     cout << "Same Strings" << endl;
  }
  else{
    cout << "Different Strings" << endl;
  }
  MyString Dif1("Not the");
  MyString Dif2("same string");
    if(Dif1 == Dif2){
     cout << "Same Strings" << endl;
  }
  else{
    cout << "Different Strings" << endl;
  }
  //(9) Assigning a new string
  MyString NewString("Before Assignment");
  cout << NewString << endl;
  NewString = MyString("This is the new string");
  cout << NewString << endl;
  //(10) Appending string
  MyString Part1("The first part of the string");
  MyString Part2(" now the second");
  MyString Combined("?");
  Combined = Part1 + Part2;
  cout << Combined << endl;
  //(11) Accessing a specific element
  MyString Index("The third letter is 'e'");
  cout << Index[2] << endl;
  //(12) Printing out the string
  MyString stringPrint("String to print out");
  cout << stringPrint << endl;
  return 0;

}