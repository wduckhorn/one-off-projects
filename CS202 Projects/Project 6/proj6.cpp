//Test driver for the ArrayList and NodeList class
#include <iostream>

#include "ArrayList.h"
#include "NodeList.h"

using namespace std;

const int DEFAULT_SIZE = 25;
int main(){
  //ArrayList Implementations
  cout << "Array Implementations:" << endl;
  DataType type(32, 77);
  DataType insert(11,22);
  ArrayList array1();
  ArrayList array2(DEFAULT_SIZE, type);
  ArrayList array3(array2);
  ArrayList array4(10, type);
  array4 = array3;
  cout << "Equality and insertion operator: " << array4 << endl;
  cout << "Empty test: " << boolalpha << array4.empty() << endl;
  cout << "Size test: " << array4.size() << endl;
  //Clear test
  array4.clear();
  cout << "First part of array: " <<*array2.first() << endl;
  cout << "Last part of array: " << array2.last() << endl;
  cout << "Reference operator: " << array2[0] << endl;
  cout << "Finder: ";
  array2.find(type);
  cout << "Insert after: " << array2.insertAfter(insert, type) << endl;
  DataType newInsert(22, 34);
  DataType newnewInsert(33, 44);
  cout << "Insert before: " << array2.insertBefore(newInsert, insert) << endl;
  cout << "New Insert after: " << array2.insertAfter(newnewInsert, insert) << endl;
  cout << "Remove forward: " << array2.removeForward(newInsert) << endl;
  cout << "Remove backward: " << array2.removeBackward(newnewInsert) << endl;

  //NodeList Implementations
  cout << endl << "Linked List Implementations:" << endl;
  NodeList node1();
  NodeList node2(DEFAULT_SIZE, type);
  NodeList node3(node2);
  NodeList node4(10, type);
  node4 = node2;
  cout << "Equality and insertion operator: " << node4 << endl;
  cout << "Empty Test: " << boolalpha << node2.empty() << endl;
  cout << "Size Test: " << node2.size() << endl;
  //Clear Test
  node4.clear();
  cout << "First part of array: " << node2.first() << endl;
  cout << "Last part of array: " << node3.last() << endl;
  cout << "Reference operator: " << node2[0] << endl;
  cout << "Finder: " << node2.find(type) << endl;
  cout << "Insert before: " << node2.insertAfter(type, insert) << endl;
  cout << "Insert after: " << node2.insertBefore(type, newInsert) << endl;
  cout << "Remove forward: " << node2.removeForward(newInsert) << endl;
  cout << "Remove Backward: " << node2.removeBackward(type) << endl;
  return 0;


}