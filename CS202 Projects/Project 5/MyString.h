#ifndef MYSTRING_INCLUDED
#define MYSTRING_INCLUDED

//This is the header file and function prototypes for MyString.cpp
#include<iostream>
using namespace std;

class MyString{   
public:     
  MyString();            
  MyString(const char* str);    
  MyString(const MyString& other_myStr);       
  ~MyString();             
  int size() const;               
  int length() const;           
  const char* c_str() const;          
  bool operator== (const MyString& other_myStr) const;     
  MyString& operator= (const MyString& other_myStr);      
  char * operator+ (const MyString& other_myStr);      
  char& operator[] (int position);          
  friend ostream& operator<<(ostream& os, const MyString& myStr); 
private:     
  void buffer_deallocate();          
  void buffer_allocate(int size);         
  char *m_buffer;     
  int m_size; 
};

#endif