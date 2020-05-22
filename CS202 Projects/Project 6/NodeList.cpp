#include "NodeList.h"
//Function implementation for NodeList.h
#include<iostream>


const int DEFAULT_SIZE = 25;
//Default Constructor
NodeList::NodeList(){

  m_head = NULL;

}
//Parameterized Constructor
NodeList::NodeList(int size, const DataType& value){
  m_head = new Node;
  m_head->setData(value); 
  m_head->setNext(NULL);
  m_size = DEFAULT_SIZE;
}
//Copy Constructor
NodeList::NodeList(const NodeList& other){
  m_head = new Node [DEFAULT_SIZE];
  m_head[0] = other.m_head[0];
  m_size = DEFAULT_SIZE;
}
//Destructor
NodeList::~NodeList(){

  delete [] m_head;
}
//Insertion operator
std::ostream& operator<<(std::ostream& os,const NodeList& nodeList){
  os << nodeList.m_head->getData();
  return os;
}
//Finds the first part of the List
DataType NodeList::first(){    
  return m_head->getData();
}
//Finds the last part of the List
DataType NodeList::last(){
  DataType Zero(0, 0);
  m_head->setData(Zero);    
  return m_head->getData();
}
//Finds a specific part of the List
DataType NodeList::find(const DataType& target){
for (Node* curr = m_head; curr != NULL; curr = m_head->GetNext()) {
    if(m_head->getData() == target){
      return m_head->getData();
    }
}
     return target;

}
//Inserts a node after the target node
DataType NodeList::insertAfter(const DataType& target, const DataType& value){
  int i = 0;
  while(1){
    if(m_head->getData() == target){
      break;
    }
    i++;
  } 
  m_head->setData(value);
  return m_head->getData();


}
//Inserts a node before
DataType NodeList::insertBefore(const DataType& target, const DataType& value){
  m_head->setData(value);
  return m_head->getData();


}
//Removes a node after
DataType NodeList::removeForward(const DataType& target){
  DataType Zero(0, 0);
  while(1){
    if(m_head->getData() == target){
      break;
    }
  } 
  m_head->setData(Zero);
  return m_head->getData();


} 
//Removes a node before
DataType NodeList::removeBackward(const DataType& target){
  DataType Zero(0, 0);
  m_head->setData(Zero);
  return m_head->getData();
} 
//Assignment operator
NodeList& NodeList::operator= (const NodeList& other_nodeList){
    return *this;

}
//Indexing operator
DataType& NodeList::operator[] (int position){

  return m_head->getData();

}
//Returns the size of the List
int NodeList::size() const{
  return m_size;
}

//Checks if the list is clear
bool NodeList::empty() const{
  if(m_head == NULL){
    return 1;
  }
  else{
    return 0;
  }

}
//Clears the list
void NodeList::clear(){
  m_head = NULL;
}
