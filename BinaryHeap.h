/*
 * Original Author: Elliot Yesmunt
 * Last Modified: 04/14/2021
 *
 * "heap.h"
 *
 * Modified by: Alston Listenberger for Sorter class method heapSort
 * 
 * Reference:
 * Weiss, Mark Allen, Florida International University.
 * Data Structures and Algorithms in C++ - Fourth Edition.
 * Upper Saddle River, NJ: Pearson Education, Inc., 2014.
 *
 */

#ifndef BINARY_HEAP_H_
#define BINARY_HEAP_H_
#include <string>
#include "Array.h"

using namespace std;

class BinaryHeap {
	protected:
		int length;
		Array heap;
		
	public:
		BinaryHeap(int heapSize);
		~BinaryHeap();
		void incrementLength();
		void decrementLength();
		int getLength();
		void percolateUp(int & heapElement, int position);
		void percolateDown(int & element, int hole);
		void insert(int & element);
		int deleteMin();
		void printHeap();
};//end BinaryHeap

#endif // !defined BINARY_HEAP_H_