#include "Array.h"
#include "Sorter.h"

/**
 * Write three sorting programs, i.e., insertion sort, merge sort, and quicksort, and run on randomly generated 100, 1,000, 5,000 and 10,000 integers to verify the complexity of algorithms. In details,
 * 1.       Write your own program in C or C++ and add step counting instructions at the instruction of comparison, swamping, and additional copying.
 * 2.       Print the sorted results of three algorithms for 100, and 1000 numbers.
 * 3.       Print the counted steps for sorting 100, 1,000, 5,000 and 10,000 numbers.
 * 4.       Record the computer times and print them for above running as well.
 * 5.       Plot the values of counted steps and computer times in a chart and connect them in curves by using Excel or other graph software.
 */

int main (int argc, char * argv[]) {
  Sorter sorter1 = Sorter ();
  /*
  Array mergeSortTest = Array (10);
  mergeSortTest.generateArray (mergeSortTest.size ());
  mergeSortTest.printArr ();
  sorter1.mergeSort (mergeSortTest, 0, mergeSortTest.size () - 1);
  mergeSortTest.printArr ();
  */
  Array arr100 = Array (100);
  arr100.generateArray (arr100.size ());
  Array arr100_2 = Array (arr100);
  std::cout << std::endl << std::endl << "Unsorted Array of size 100" << std::endl << std::endl;
  arr100.printArr ();
  sorter1.insertionSortTimed (arr100);
  sorter1.mergeSortTimed (arr100, 0, arr100.size () - 1);
  sorter1.quickSortTimed (arr100_2, 0, arr100_2.size ());
  Array arr1000 = Array (1000);
  arr1000.generateArray (arr1000.size ());
  Array arr1000_2 = Array (arr1000);
  std::cout << std::endl << std::endl << "Unsorted Array of size 1000" << std::endl << std::endl;
  arr1000.printArr ();
  sorter1.insertionSortTimed (arr1000);
  sorter1.mergeSortTimed (arr1000, 0, arr1000.size () - 1);
  sorter1.quickSortTimed (arr1000_2, 0, arr1000_2.size ());
  Array arr5000 = Array (5000);
  arr5000.generateArray (arr5000.size ());
  Array arr5000_2 = Array (arr5000);
  sorter1.insertionSortTimed (arr5000);
  sorter1.mergeSortTimed (arr5000, 0, arr5000.size () - 1);
  sorter1.quickSortTimed (arr5000_2, 0, arr5000_2.size ());
  Array arr10000 = Array (10000);
  arr10000.generateArray (arr10000.size ());
  Array arr10000_2 = Array (arr10000);
  sorter1.insertionSortTimed (arr10000);
  sorter1.mergeSortTimed (arr10000, 0, arr10000.size () - 1);
  sorter1.quickSortTimed (arr10000_2, 0, arr10000_2.size ());
  return (0);
}