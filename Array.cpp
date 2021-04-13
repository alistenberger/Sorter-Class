#include "Array.h"

Array::Array (void)
: data_ (new int[0]),
sizeArr_ (0)
{
  //Nothing here. Won't be using
}

Array::Array (const int size)
: data_ (new int[size]),
sizeArr_ (size)
{
  //Nothing here
}

Array::Array (const Array & arr)
: data_ (new int[arr.size ()]),
sizeArr_ (arr.size ())
{
  for (int i = 0; i < this->sizeArr_; i++) {
    int *thisLocation = &this->data_[i];
    int *arrayLocation = &arr.data_[i];
    *thisLocation = *arrayLocation;
  }
}

Array::~Array (void)
{
  //delete Array allocation
  delete [] this->data_;
}

int Array::size (void) const
{
  return this->sizeArr_;
}

void Array::setSize (int size)
{
  this->sizeArr_ = size;
}

const Array & Array::operator = (const Array & rhs)
{
  if (&(*this) == &(rhs)) {
    return *this;
  } else {
    this->setSize (rhs.size ());    
    for (int i = 0; i < this->sizeArr_; i++) {
      int thisLocation = this->data_[i];
      int rhsLocation = rhs.data_[i];
      thisLocation = rhsLocation;
    }
  return *this;
  }// end else
}

int & Array::operator [] (int index)
{
  return this->data_[index];
}

const int & Array::operator [] (int index) const
{
  return this->data_[index];
}

void Array::printArr (void)
{
  for (int i; i < this->size (); i++) {
    std::cout << "[" << i << "]: " << data_[i] << std::endl;
  }
}

void Array::generateArray (int size)
{
  for (int i = 0; i < this->size (); i++) {
    this->set (i, rand()%size);
  }
}

void Array::set (int index, int element)
{
  this->data_[index] = element;
}

int Array::get (int index)
{
  return this->data_[index];
}

void Array::fill (int element)
{
  for (int i = 0; i < this->sizeArr_; i++) {
    this->data_[i] = element;
  }
}