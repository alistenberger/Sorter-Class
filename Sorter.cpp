#include "Sorter.h"

Sorter::Sorter (void)
: comparisonOperations_ (0),
swapOperations_ (0),
copyOperations_ (0)
{
  
}

void Sorter::insertionSort (Array & arr, int sizeSort)
{
  for (int i = 1; i < sizeSort; i++) {
    int temp = arr[i];
    int j = i - 1;
    while (j >= 0 && this->compare (arr[j], temp)) {
      this->swap (arr[j+1], arr[j]);
      j = j-1;
    } 
    this->swap (arr[j+1], temp);
  }
}

void Sorter::insertionSortTimed (Array & arr)
{
  this->resetOperations ();
  auto startTime = std::chrono::high_resolution_clock::now ();
  insertionSort (arr, arr.size ());
  auto stopTime = std::chrono::high_resolution_clock::now ();
  auto totalTime = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);
  std::cout << "The duration of an insertion sort for an Array of size " << arr.size () <<
  " is: " << totalTime.count () << " microseconds" << std::endl;
  std::cout << "Number of comparison operations for an insertion sort on Array of size "
  << arr.size () << ": " << this->comparisonOperations_ << std::endl;
  std::cout << "Number of swap operations for an insertion sort on Array of size "
  << arr.size () << ": " << this->swapOperations_ << std::endl;
  std::cout << "Number of copy operations for an insertion sort on Array of size "
  << arr.size () << ": " << this->copyOperations_ << std::endl;
  if (arr.size () <= 1000) {
    std::cout << "Sorted Array: " << std::endl;
    arr.printArr ();
  }
}

void Sorter::merge (int left, int right, int end, Array & arr)
{
  int leftPosition = left;
  int rightPosition = right;
  int position = left;
  Array tempArr = Array (arr.size ());
  bool keepGoing = true;
  while (keepGoing) {
    //Conditional: If the left position is NOT greater than the right position
    if (!this->compare (arr[leftPosition], arr[rightPosition])) {
      this->copy (arr[leftPosition], tempArr[position]);
      leftPosition++;
      position++;
    } else {
      this->copy (arr[rightPosition], tempArr[position]);
      rightPosition++;
      position++;
    }
    if (leftPosition == right || rightPosition > end) {
      keepGoing = false;
    }
  } // end while
  for (leftPosition; leftPosition < right; leftPosition ++, position ++) {
    this->copy (arr[leftPosition], tempArr[position]);
  }
  for (rightPosition; rightPosition <= end; rightPosition++, position ++) {
    this->copy (arr[rightPosition], tempArr[position]);
  }
  for (position = left; position <= end; position++) {
    this->copy(tempArr[position], arr[position]);
  }
}

//Essentially the merge sort function
void Sorter::mergeSort (Array & arr, int low, int high)
{
  //base case in which array is 2 elements long
  if (high - low == 1) {
    if (this->compare (arr[low], arr[high])) {
      this->swap (arr[low], arr[high]);
    }
  } else if (high - low == 2) {  //Now evaluate for an array of length 3
    this->mergeSort (arr, low, low + 1);
    this->mergeSort (arr, low + 1, low + 2);
    this->merge (low, (low + 1), high, arr);
  } else if (low < high) { //Now the remainder of cases are evaluated and recursion is applied
    int center = (low + high)/2;
    this->mergeSort (arr, low, center);
    this->mergeSort (arr, (center+1), high);
    this->merge (low, center + 1, high, arr);
  }
} 

//Essentially a wrapper function for mergeSort to include time
void Sorter::mergeSortTimed (Array & arr, int low, int high)
{
  this->resetOperations ();
  auto startTime = std::chrono::high_resolution_clock::now ();
  this->mergeSort (arr, low, high);
  auto stopTime = std::chrono::high_resolution_clock::now ();
  auto totalTime = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);
  std::cout << "The duration of a merge sort for an Array of size " << arr.size () <<
  " is: " << totalTime.count () << " microseconds" << std::endl;
  std::cout << "Number of comparison operations for a merge sort on Array of size "
  << arr.size () << ": " << this->comparisonOperations_ << std::endl;
  std::cout << "Number of swap operations for a merge sort on Array of size "
  << arr.size () << ": " << this->swapOperations_ << std::endl;
  std::cout << "Number of copy operations for a merge sort on Array of size "
  << arr.size () << ": " << this->copyOperations_ << std::endl;
  if (arr.size () <= 1000) {
    std::cout << "Sorted Array: " << std::endl;
    arr.printArr ();
  }
}

int Sorter::quickSort (Array & arr, int low, int high)
{
  if (high - low <= 3) {
    insertionSort (arr, high);
    return (0);
  }
  Array pivotFinder = Array (3);
  pivotFinder.set (0, arr[low]);
  pivotFinder.set (1, arr[(high+low)/2]);
  pivotFinder.set (2, arr[high]);
  insertionSort (pivotFinder, 3);
  int beginning = pivotFinder[0];
  int pivot = pivotFinder[1];
  int end = pivotFinder[2];
  this->copy (arr[high-1], arr[(high+low)/2]);
  this->copy (beginning, arr[low]);
  this->copy (pivot, arr[high-1]);
  this->copy (end, arr[high]);
  int pivotValue = arr[high-1];
  int i = low;
  int j = high - 2;
  while (i < j) {
    if (!this->compare (arr[i], pivotValue)) {
      i++;
    }
    if (this->compare (arr[j], pivotValue)) {
      j--;
    } else if (this->compare (arr[i], pivotValue)) {
      if (!this->compare (arr[j], pivotValue)) {
        this->swap (arr[i], arr[j]);
        i++;
        j--;
      }
    }
  } //end while
  if (this->compare (pivotValue, arr[j])) {
    //this->copy (arr[j], arr[high-1]);
    //this->copy (pivotValue, arr[j]);
    this->swap (arr[high-1], arr[j]);
    pivotValue = arr[high-1];
    quickSort (arr, low, j-1);
    quickSort (arr, j+1, high);
  } else if (!this->compare (pivotValue, arr[j])) {
    //pivotValue = arr[j+1];
    //this->copy (arr[j+1], arr[high-1]);
    //this->copy (pivotValue, arr[j+1]);
    this->swap (arr[j+1], arr[high-1]);
    pivotValue = arr[high-1];
    quickSort (arr, low, j);
    quickSort (arr, j+2, high);
  }
  return (0);
}

//Wrapped method for quicksort with time
void Sorter::quickSortTimed (Array & arr, int low, int high)
{
  this->resetOperations ();
  auto startTime = std::chrono::high_resolution_clock::now ();
  this->quickSort (arr, low, high);
  auto stopTime = std::chrono::high_resolution_clock::now ();
  auto totalTime = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);
  std::cout << "The duration of a quick sort for an Array of size " << arr.size () <<
  " is: " << totalTime.count () << " microseconds" << std::endl;
  std::cout << "Number of comparison operations for a quick sort on Array of size "
  << arr.size () << ": " << this->comparisonOperations_ << std::endl;
  std::cout << "Number of swap operations for a quick sort on Array of size "
  << arr.size () << ": " << this->swapOperations_ << std::endl;
  std::cout << "Number of copy operations for a quick sort on Array of size "
  << arr.size () << ": " << this->copyOperations_ << std::endl;
  if (arr.size () <= 1000) {
    std::cout << "Sorted Array: " << std::endl;
    arr.printArr ();
  }
}

void Sorter::heapSort (BinaryHeap heapSort, Array & dataArray, int heapLength)
{
  //Insert all values in dataArray into the binary heap
	for (int i = 0; i < heapLength; i++) {
 		int element = dataArray[i];
 		heapSort.insert(element);
		heapSort.printHeap();
 	}
 	//Run deleteMin for the number of nodes in binary heap
 	//Place node in next available spot in dataArray, filling in from the end
	for (int i = 0; i < heapLength; i++){
		dataArray[i] = heapSort.deleteMin();
	}
}

void Sorter::printArray (Array & arr)
{
  arr.printArr ();
}

void Sorter::swap(int & a, int & b) {
  int temp = std::move(a);
  a = std::move(b);
  b = std::move(temp);
  this->swapOperations_ += 1;
}

bool Sorter::compare (int a, int b) {
  if (a > b) {
    this->comparisonOperations_ += 1;
    return true;
  }
  this->comparisonOperations_ += 1;
  return false;
}

void Sorter::copy (int & a, int & b)
{
  b = std::move (a);
  this->copyOperations_ += 1;
}

void Sorter::setSwapOperations (int number)
{
  this->swapOperations_ = number;
}

int Sorter::getSwapOperations (void)
{
  return this->swapOperations_;
}

void Sorter::setComparisonOperations (int number)
{
  this->comparisonOperations_ = number;
}

int Sorter::getComparisonOperations (void)
{
  return this->comparisonOperations_;
}

void Sorter::resetOperations (void)
{
  this->swapOperations_ = 0;
  this->comparisonOperations_ = 0;
  this->copyOperations_ = 0;
}