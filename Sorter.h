#ifndef _SORTER_H_
#define _SORTER_H_

#include <chrono>
#include <iostream>
#include "Array.h"

/**
 * @class Sorter
 *
 * Basic implementation of a class for sorting array inputs of various sizes for int types specifically
 */

class Sorter 
{
public:

  // Default constructor
  Sorter (void);

  /**
   * Insertion Sort
   * 
   * @param[in]     arr          The array to be insertion sorted
   * @param[in]     sizeSort     The number of elements to be sorted
   */
  void insertionSort (Array & arr, int sizeSort);

  ///Wrapper method for insertion sort with time keeping, sorted array, and operations output
  void insertionSortTimed (Array & arr);

  /**
   * Merge (to be used with merge sort)
   * 
   * @param[in]     left      The left bound
   * @param[in]     right     The right bound
   * @param[in]     end       The end of the array
   * @param[in]     arr       The array
   */
  void merge (int left, int right, int end, Array & arr);

  /**
   * Split Sort
   * 
   * @param[in]     arr     The array to be merge sorted
   * @param[in]     low     The lower bound of the array
   * @param[in]     high    The upper bound of the array
   */
  void mergeSort (Array & arr, int low, int high);

  /**
   * Merge Sort
   * 
   * @param[in]     arr     The array to be merge sorted
   * @param[in]     low     The lower bound of the array
   * @param[in]     high    The upper bound of the array
   */
  void mergeSortTimed (Array & arr, int low, int high);
  
  /**
   * Quick Sort
   * 
   * @param[in]     arr     The array to be sorted
   * @param[in]     low     The lower bound of the array
   * @param[in]     high    The upper bound of the array
   * @param[in]     cutoff     The cutoff value for insertion sort
   */
  int quickSort (Array & arr, int low, int high);

  ///Wrapper function for quicksort with time keeping, sorted array, and operations output
  void quickSortTimed (Array & arr, int low, int high);

  //Prints the array
  void printArray (Array & arr);

  //Swaps the input variables
  void swap (int & a, int & b);

  //Compares two values and returns true if a > b
  bool compare (int a, int b);

  //Copies the int at a to b
  void copy (int & a, int & b);

  ///Sets the number of swap operations
  void setSwapOperations (int number);

  ///Gets the number of swap operations
  int getSwapOperations (void);
  
  ///Sets the number of comparison operations
  void setComparisonOperations (int number);
  
  ///Sets the number of swap operations
  int getComparisonOperations (void);

  ///Resets comparisonOperations_ and swapOperations_ to 0
  void resetOperations (void);

private:
  int swapOperations_;
  int comparisonOperations_;
  int copyOperations_;
};

#endif // !defined _SORTER_H_