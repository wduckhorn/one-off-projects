//Test driver for the ArrayQueue and NodeQueue header files
#include<iostream>
#include"ArrayQueue.h"
#include"NodeQueue.h"
using namespace std;

int main(){
  DataType type(11, 34);
  cout << "Array based queue testing" << endl;
  ArrayQueue<int> queue1;
  ArrayQueue<int> queue2(5, 20);
  ArrayQueue<int> queue3(queue2);
  ArrayQueue<int> queue4(12, 30);
  queue4 = queue3;
  cout << queue3.front() << endl;
  cout << queue3.back() << endl;
  DataType type2(33, 32);
  queue3.push(40);
  queue3.pop();
  cout << queue3.size() << endl;
  cout << boolalpha << queue1.empty() << endl;
  cout << boolalpha << queue3.full() << endl;
  queue4.clear();
  cout << "Linked list queue testing" << endl;
  NodeQueue<DataType> NQ1;
  NodeQueue<DataType> NQ2(3, type);
  NodeQueue<DataType> NQ3(NQ2);
  NodeQueue<DataType> NQ4(12, type2);
  NQ4 = NQ3;
  cout << NQ2.front() << endl;
  cout << NQ2.back() << endl;
  NQ1.push(type2);
  NQ1.pop();
  cout << NQ2.size() << endl;
  cout << NQ2.empty() << endl;
  cout << NQ2.full() << endl;
  NQ2.clear();
  return 0; 
}