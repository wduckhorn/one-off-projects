#ifndef VECTORRECURSION_H
#define VECTORRECURSION_H
//Header file for VectorRecursion
#include<iostream>
//using namespace std;
template<class T>
//Vector resort using quicksort
void vector_resort(std::vector<T>& array, int left, int right){
  int i = left;
  int j = right;
  int temp;
  int pivot = array[(left + right)/2];
  while(i <= j){
    while(array[i] < pivot){
      i++;
    }
    while(array[j] > pivot){
      j--;
    }
    if(i <= j){
      temp = array[i];
      array[i] = array[j];
      array[j] = temp;
      i++;
      j--;
    }
 }
    if(left < j){
      vector_resort(array, left, j);
    }
    if(i < right){
      vector_resort(array, i, right);
    }
}
template<class T>
//Vector binary search
int vector_research(std::vector<T>& array, int left, int right, int value){
  if(left <= right){
    int mid = (left + right) / 2;
    if(value == array[mid]){
      return mid;
    }
    else if(value < array[mid]){
      return vector_research(array, left, mid - 1, value);
    }
    else if(value > array[mid]){
      return vector_research(array, mid + 1, right, value);
    }
  }

  return -1;
}
#endif