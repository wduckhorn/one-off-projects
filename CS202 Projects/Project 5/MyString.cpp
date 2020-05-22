//This file includes all the function codes for MyString.h
#include<iostream>
#include "MyString.h"
using namespace std;

const int DEFAULT_SIZE = 50;
void MyString::buffer_allocate(int size){
 
  m_buffer = new char [size];
  if(!m_buffer){
    delete [] m_buffer;
    m_buffer = NULL;	
  }
  m_size = size;
  buffer_deallocate();

}
void MyString::buffer_deallocate(){
 
 delete [] m_buffer;

}
//(1) Default Constructor
MyString::MyString(){
  buffer_allocate((int)DEFAULT_SIZE);
  char c_str[15] = "Default";
  m_buffer = c_str;

}
//(2) Paramaterized Constructor
MyString::MyString(const char * str){
  buffer_allocate((int)DEFAULT_SIZE);
  m_buffer = (char *)str;
}
//(3) Copy Constructor
MyString::MyString(const MyString& other_myStr){
  buffer_allocate((int)DEFAULT_SIZE);
  m_buffer = (char *)other_myStr.m_buffer;
}
//(4) Destructor
MyString::~MyString(){

  
}
/*(5) Size
  Purpose: Determines the size of the string
  Parameters: None
  Returns: the size, an const int
*/
int MyString::size() const{

  return m_size;

}
/*(6) Length
  Purpose: Determines the length of the string
  Parameters: None
  Returns: the length, a const int
*/
int MyString::length() const{

  int count = 0;
  int i = 0;
  while(m_buffer[i] != '\0'){
  count++;
  i++;
  }
  return count;

}

/*(7) C_str
  Purpose: Converts the dynamically allocated string into a C style string
  Parameters: None
  Returns: CString, a const char array
*/
const char * MyString::c_str() const{
  
  char * CString;
  CString = m_buffer;
  return CString;

}

/*(8) == operator
  Purpose: Checks if the two strings are equal
  Parameters: other_myStr, A const Mystring class
  Returns: a bool value if the strings are equal or not
*/ 
bool MyString::operator== (const MyString& other_myStr) const{

  for( int i = 0; i < m_size; i++){
    if(m_buffer[i] != other_myStr.m_buffer[i]){
       return 0;
    }
  }
  return 1;
}

/*(9) = operator
  Purpose: Assigns the value of one string to another
  Parameters: other_myStr, A const Mystring class
  Returns: this, a MyString class
*/
MyString& MyString::operator= (const MyString& other_myStr){

  m_buffer = other_myStr.m_buffer;
  return *this;
}
/*(10) + operator
  Purpose: Concatenates the second string to the first string
  Parameters: other_myStr, A const Mystring class
  Returns: the newly concatenated string, a char pointer
*/
char * MyString::operator+ (const MyString& other_myStr){
  MyString ConCat;
  int i = 0;
  while(m_buffer[i] != '\0'){
  ConCat.m_buffer = m_buffer;
  i++;
  }
  cout << ConCat.m_buffer;
  int j = 0;
  while(other_myStr.m_buffer[j] != '\0'){
  ConCat.m_buffer = other_myStr.m_buffer;
  j++;
  } 

  return ConCat.m_buffer;
}
/*(11) [] operator
  Purpose: Retrieves a specific character in the string
  Parameters: The position of what to access, a int
  Returns: The specific character wanting to be accessed, a char
*/
char& MyString::operator[] (int position){

  return m_buffer[position];
}
/*(12) << operator
  Purpose: Outputs the string to the terminal
  Parameters: os, a ostream class, and myStr, a Mystring class
  Returns: the os, an ostream class
*/
ostream& operator<<(ostream& os, const MyString& myStr){
  os << myStr.m_buffer;
  return os;
}
