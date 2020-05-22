#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H
//Header File for the ArrayQueue class
#include "DataType.h"
#include<iostream>
const int ARRAY_MAX = 1000;
template <class T>
class ArrayQueue{   
public:
//Default Constructor  
  ArrayQueue(){
    m_front = -1;
    m_back = -1;
    m_size = 0;
  }
//Parameterized Constructor   
  ArrayQueue(int size, const T& value){
    m_size = size;
    m_front = size - 1;
    m_back = 0;
    for(int i = 0; i < size; i++){
      m_array[i] = value;
  }
  }
//Copy Constructor    
  ArrayQueue(const ArrayQueue& other){
  m_size = other.m_size;
  m_front = other.m_front;
  m_back = other.m_back;
  for(int i = 0; i < other.m_size; i++){
      m_array[i] = other.m_array[i];
  }

  }
//Destructor     
  ~ArrayQueue(){



  }
//Equality Operator
  ArrayQueue& operator= (const ArrayQueue& other_arrayQueue){  
  m_size = other_arrayQueue.m_size;
  m_front = other_arrayQueue.m_front;
  m_back = other_arrayQueue.m_back;
  for(int i = 0; i < other_arrayQueue.m_size; i++){
      m_array[i] = other_arrayQueue.m_array[i];
  }
 
  return *this;

  }
//Checks if the queue is empty
  bool empty() const{
    if(m_front == -1 && m_back == -1){
     return true;
    }
    else{
     return false;
   }

  }
//Checks if the queue is full    
  bool full() const{
    if(m_size == ARRAY_MAX){
     return true;
    }
    else
      return false;

  }
//Returns the front of the queue
  T& front(){
    return m_array[m_front];

  }
//Returns the back of the queue  
  T& back(){
    return m_array[m_back];
  }
//Adds an element to the back of the queue
  void push(const T& value){
  if(full()){
    return;
 }
    if(m_back > 99){
    m_back = (m_back + 1) % ARRAY_MAX;
    }
    m_array[m_back] = value;
    m_size += 1;
  }
//Removes the element in the front of the queue    
  void pop(){
  if(empty()){
    return;
  }
     if(m_front > 99)
       m_front = (m_front + 1) % ARRAY_MAX;
     m_front = m_front - 1;
     m_size -= 1;
  }
//Returns the size of the queue
  int size() const{
     return m_size;
  }                //(10)     
//Clears the queue   
  void clear(){
    for( int i = m_back; i <= m_front; i++){
     pop();
   }

  }           //(13)
private:     
  T m_array[ARRAY_MAX];     
  int m_front;
  int m_back;     
  int m_size; 
};
#endif