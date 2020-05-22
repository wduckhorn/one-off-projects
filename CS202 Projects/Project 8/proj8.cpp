//This program reads in a set of 100 random integers and performs a quicksort along with a binary search
#include<iostream>
#include<vector>
#include "VectorRecursion.h"
#include<fstream>


int main(){
  std::vector<int> vecInt(100);
  std::vector<int> vecIntCopy(100);
  int test, search;
  std::ifstream inputStream;
  inputStream.open("RandomData.txt");
  for(int i = 0; i < 100; i++){
    inputStream >> vecInt[i];
  }
  vector_resort(vecInt, 0, 100);
  for(int i = 0; i < 100; i++){
     vecIntCopy[i] = vecInt[i];
  }
  std::cout << "Please enter a value for the search: ";
  std::cin >> search;
  for(int i = 0; i < 100; i++){
     std::cout << vecInt[i] << std::endl;
  }
  test = vector_research(vecInt, 0, 100, search);
  if(test != -1){
  std::cout << search << " was found at element " << test + 1 << std::endl;
  }
  else{
  std::cout << search << " was not found" << std::endl;
  }
  return 0;
}