#include <string>
#include <iostream>
#include "BinaryHeap.h"
#include "Array.h"

BinaryHeap::BinaryHeap(int heapSize) {
	length = 0;
	heap = Array (heapSize);
}//end BinaryHeap constructor

BinaryHeap::~BinaryHeap()
{
  //Nothing allocated
}

void BinaryHeap::incrementLength() 
{
	length++;
}//end incrementLength function

void BinaryHeap::decrementLength() {
	length--;
}//end decrementLength function

int BinaryHeap::getLength() {
	return length;
}//end getLength function

void BinaryHeap::percolateUp(int & heapElement, int position) {
	if (position == 1) {
		heap[position] = heapElement;
	}//end if statement
	else if (heap[position / 2] > heapElement) {
		heap[position] = heap[position / 2];
		position = position / 2;
		percolateUp(heapElement, position);
	}//end else if statement
	else {
		heap[position] = heapElement;
	}//end else statement
}//end percolateUp function

void BinaryHeap::percolateDown(int & heapElement, int hole) {
	int temp;
	int length = getLength();
	if (length == 0) {
		cout << "The heap is empty." << endl;
		cout << endl;
	}//end if statement
	else if ((hole * 2) > length) {
		heap[hole] = heapElement;
	}//end else if statement
	else {
		if ((hole * 2) == length) {
			temp = hole * 2;
		}//end if statement
		else if (heap[hole * 2] > heap[(hole * 2) + 1]) {
			temp = (hole * 2) + 1;
		}//end else if statement
		else {
			temp = hole * 2;
		}//end else statement
		if (heapElement > heap[temp]) {
			heap[hole] = heap[temp];
			percolateDown(heapElement, temp);
		}//end if statement
		else if (heapElement <= heap[temp]) {
			heap[hole] = heapElement;
		}//end else if statement
	}//end else statement
}//end percolateDown function

void BinaryHeap::insert(int & element) {
	incrementLength();
	int position = getLength();
	percolateUp(element, position);
	cout << "Enqueued Element: " << element << endl;
	cout << endl;
}//end insert function

int BinaryHeap::deleteMin() {
	int deletedElement = heap[1];
	int element = heap[getLength()];
	heap[getLength()] = NULL;
	decrementLength();
	percolateDown(element, 1);
	return deletedElement;
}//end deleteMin function

void BinaryHeap::printHeap() {
	std::cout << "Binary Heap Data" << endl;
	this->heap.printArr ();
}//end printHeap function