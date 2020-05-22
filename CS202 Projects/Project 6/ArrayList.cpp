//Function implementations for ArrayList.h
#include "ArrayList.h"
#include<iostream>


const int DEFAULT_SIZE = 25;
const int DEFAULT_MAXSIZE = 100;
//Default Constructor
ArrayList::ArrayList(){

  m_array = NULL;
  m_size = (int) DEFAULT_SIZE;
  m_maxsize = (int) DEFAULT_MAXSIZE;

}
//Parameterized constructor
ArrayList::ArrayList(int size, DataType& value){
  m_array = new DataType [size];
  m_array[0] = value;
  m_size = size;
  m_maxsize = (int) DEFAULT_MAXSIZE;

}
//Copy Constructor
ArrayList::ArrayList(const ArrayList& other){
  m_array = new DataType [other.m_size];
  m_array[0] = other.m_array[0];
  m_size = (int)other.m_size;
  m_maxsize = (int)other.m_maxsize;
}
//Destructor
ArrayList::~ArrayList(){

  delete [] m_array;
}
// Assignment operator
ArrayList& ArrayList::operator= (const ArrayList& other_arrayList){
  
  m_size = other_arrayList.m_size;
  m_maxsize = other_arrayList.m_maxsize;
  return *this; 


}
// Insertion operator
std::ostream& operator<<(std::ostream& os, const ArrayList& arrayList){
	os << *arrayList.m_array;
	return os;
}
// Finds the first part of the array
DataType* ArrayList::first(){
  if(m_array != NULL)
    return m_array;
  else
    return NULL;


}
// Finds the last part of the array
DataType& ArrayList::last(){
    return m_array[m_size - 1];



}
//Finds a specific point in the array
void ArrayList::find(DataType& target){
  for(int i = 0; i < m_size; i++){
    if(target == m_array[i]){
      std::cout << m_array[i] << std::endl;
      return;
    }
  }
  std::cout << "Not found" << std::endl; 
}
//Inserts a Datatype after a specific target
DataType& ArrayList::insertAfter(const DataType& target,const DataType& value){
  int i = 0;
  while(1){
    if(m_array[i] == value){
      break;
    }
    i++;
  } 
  m_array[i + 1] = target;
  return m_array[i + 1];



}
//Inserts a DataType before a specific target
DataType& ArrayList::insertBefore(const DataType& target,const DataType& value){
  int i = 0;
  while(1){
    if(m_array[i] == value){
      break;
    }
    i++;
  } 
  m_array[i - 1] = target;
  return m_array[i - 1];



}
//Removes the DataType after the target
DataType& ArrayList::removeForward(const DataType& target){
  int i = 0;
  while(1){
    if(m_array[i] == target){
      break;
    }
    i++;
  } 
  DataType Zero(0, 0);
  m_array[i + 1] = Zero;
  return m_array[i + 1];

}
//Removes the DataType before the target
DataType& ArrayList::removeBackward(const DataType& target){
  int i = 0;
  while(1){
    if(m_array[i] == target){
      break;
    }
    i++;
  } 
  DataType Zero(0, 0);
  m_array[i - 1] = Zero;
  return m_array[i - 1];

}
//Checks if the array is empty	
bool ArrayList::empty() const{
  if(m_array == NULL){
    return 1;
  }
  else{
    return 0;
  }

}
//Retuns the size of the array
int ArrayList::size() const{
  return m_size;
}
//Clears the array
void ArrayList::clear(){
  m_array = NULL;
}
//Indexing operator
DataType& ArrayList::operator[] (int position){

  return m_array[position];
}
//Makes the array larger
void ArrayList::grow(int addsize){
   m_size += addsize;
}
//Makes the array smaller
void ArrayList::trim(int remsize){
   m_size += remsize;
}