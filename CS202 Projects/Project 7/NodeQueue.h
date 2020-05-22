#ifndef NODEQUEUE_H
#define NODEQUEUE_H
#include "DataType.h"
#include "Node.h"
#include<iostream>
//Header File for the NodeQueue and Node class
const int MAX_SIZE = 1000;
template <class T>
class NodeQueue{   
public:
//Default Constructor     
NodeQueue(){

  m_front = NULL;
  m_back = NULL;
  m_size = 0;

}
//Parameterized Constructor    
NodeQueue(int size, const T& value){

  m_size = size;
  m_front = new Node<T>;
  m_front->setData(value);
  m_back = new Node<T>;
  m_back -> setData(value);

}
//Copy Constructor   
NodeQueue(const NodeQueue& other){

  m_size = other.m_size;
  m_front = other.m_front;
  m_back = other.m_back;

}
//Destructor     
~NodeQueue(){

}
//Equality Operator
NodeQueue& operator= (const NodeQueue& other_nodeQueue){

  m_size = other_nodeQueue.m_size;
  m_front = other_nodeQueue.m_front;
  m_back = other_nodeQueue.m_back;
  return *this;

}
//Returns the front of the list
DataType& front(){

  return m_front->getData();

}
//Returns the back of the list 
DataType& back(){

  return m_back->getData();

}
//Adds a node to the back of the list   
void push(const DataType& value){

  Node<T> * temp = new Node<T>;
  m_size += 1;
  temp->setData(value);
  temp->setNext(NULL);
  if(m_front == NULL){
    m_front = temp;
  }
  else{
   m_back->setNext(temp);
  }
  delete temp;

}
//Deletes the node from the front of the list 
void pop(){

  m_size -= 1;
  Node<T> * temp = new Node<T>;
  temp = m_front;
  m_front = m_front->getNext();
  delete temp;

}
//Returns the size of the queue
int size() const{

   return m_size;

}
//Checks if the queue is empty    
bool empty() const{

  if(m_front == NULL && m_back == NULL)
    return true;
  return false;

}
//Checks if the queue is full   
bool full() const{

  if(m_size == MAX_SIZE)
    return true;
  return false;

}
//Clears the queue  
void clear(){

  m_front = NULL;
  m_back = NULL;

}

private:
Node<T> *m_front;     
Node<T> *m_back;
int m_size;
};
#endif