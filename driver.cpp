#include "Array.h"
#include "Sorter.h"
#include <iostream>
#include <fstream>

/**
Chapter 7:

[x] 7.1   (2pt) Sort the sequence (3, 1, 4, 1, 5, 9, 2, 6, 5) using insertion sort

[x] 7.2 (1pt) What is the running time of insertion Sort if all elements are equal? O(N)

[] 7.11 (4pt: 1pt for building heap, 2pt for sort, 1pt for memory use) Show how heapsort processes the input (142, 543, 123, 65, 453, 879, 572, 434, 111, 242, 811, 102) 

[X] 7.12  (1pt) What is the running time of heapsort for presorted input? 

O(log(N)) to build heap * O(N) to evaluate each item. 
So the time complexity is O(Nlog(N))  

[x] 7.15 (2pt) Sort (3, 1, 4, 1, 5, 9, 2, 6) using mergesort

[X] 7.17 (3pt) Determine the running time of merge sort for
  [X] a. Sorted input: O(Nlog(N)) this is because it still divides the array log(N) times and makes N comparisons whether or not its sorted so O(log(N)) * O(N)
  [X] b. Reverse-Ordered Input: O(Nlog(N)) this is because it splits the Array log(N) times, makes N comparisons and N copies so O(log(N)) * O(N) + O(N)
  [X] c. Random input: O(Nlog(N)) is the average case, so this is for random input, but the same method for reverse order applies here as the comparisons and copying are still done

[x] Chapter 7 Bonus Homework

[x] 7.3 (1pt) Suppose we exchange elements a[i] and a[i+k] which were originally out of order. Prove that at least 1 and at most 2k-1 inversions are removed.

  We know that an inversion occurs only if an object is out of order. The best case scenario for this problem is if a[i] and a[i+k] are the only objects out of order.
  Average case is N(N-1)/4 inversions. If a[i] and a[i+k] are the only objects out of order this removes every inversion but the initial, 
  this is N(N-1)/4 - N-1((N-1)-1)/4 = N-1 inversions removed. 
  Therefore, there will be N-1 inversions removed.

  Now if Every object is out of order in the worst case
  There will be N(N-1)/4 - N(N-1)/4 + 1 = -1 = 1 inversion removed

  Therefore there will be at least 1 and at most 2k-1 inversions removed 

[x] 7.19 (1pt) Sort (3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5) using quicksort with median-of-three partitioning and a cutoff of 3. 
 */

int main (int argc, char * argv[]) {
  Sorter sorter1 = Sorter ();
  //std::ofstream outfile ("HW7_Sort.txt");
  Array problem7_1_Array = Array (9);
  int insertionsortArray [9] = {3, 1, 4, 1, 5, 9, 2, 6, 5};
  for (int i = 0; i < 9; i++) {
    int j = insertionsortArray[i];
    problem7_1_Array.set (i, j);
  }
  std::cout << std::endl << std::endl << "Unsorted Array Problem 7.1" << std::endl << std::endl;
  problem7_1_Array.printArr ();
  sorter1.insertionSortTimed (problem7_1_Array);
//////////////////////////////////////////////////////////////////////////////////////////////////////////
  Array problem7_15_Array = Array (8);
  int mergesortArray [8] = {3, 1, 4, 1, 5, 9, 2, 6};
  for (int i = 0; i < 8; i++) {
    int j = mergesortArray[i];
    problem7_15_Array.set (i, j);
  }
  std::cout << "Unsorted Array problem 7.15" << std::endl;
  problem7_15_Array.printArr ();
  sorter1.mergeSortTimed (problem7_15_Array, 0, 7);
/////////////////////////////////////////////////////////////////////////////////////////////////////////
  Array problem7_19_Array = Array (11);
  int quicksortArray[11] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
  for (int i = 0; i < 11; i++) {
    int j = quicksortArray[i];
    problem7_19_Array.set (i, j);
  }
  std::cout << std::endl << std::endl << "Unsorted Array Problem 7.19" << std::endl << std::endl;
  problem7_19_Array.printArr ();
  //int quickSort (Array & arr, int low, int high); cutoff set to 3 in implementation
  sorter1.quickSortTimed (problem7_19_Array, 0, 10);
  return (0);
}