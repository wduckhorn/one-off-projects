#ifndef NODE_H
#define NODE_H
#include "DataType.h"
#include<iostream>
//Header file for the Node class
template<class T> class NodeQueue;

template <class T>
class Node{   
public:
//Default Constructor     
  Node(){

    m_next = NULL;

  }
//Parameterized Constructor    
  Node(const T& data, Node* next = NULL){
    
    m_next = next;
    m_data = data;

  }
//Sets the value of m_data
  void setData(const T& data){

    m_data = data;

  }
//Returns the value of m_data
  T& getData(){

    return m_data;

  }
//Sets the value of m_next
  void setNext(Node * next){

    m_next = next;

  }
//Returns the value of m_next
  Node * getNext(){

    return m_next;

  }   
  friend class NodeQueue<T>; 
private:     
  Node* m_next;     
  T m_data;      
};
#endif