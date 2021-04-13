#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <chrono>
#include <iostream>

/**
 * @class Array
 *
 * Basic implementation of a class for generating a random array of a given size
 */
class Array
{
public:

  ///Default constructor
  Array (void);

  /**
   * Initializing constructor
   * 
   * @param[in]     size     The size of the array to be generated
   */
  Array (const int size);

  ///Copy Constructor
  Array (const Array & arr);

  ///Destructor
  ~Array (void);

  /**
   * Retrieve the current size of the array.
   *
   * @return          The current size
   */
  int size (void) const;

  /**
   * Sets the size of the Array, used in assignment operation
   */
  void setSize (int size);

  /**
   * Assignment operator
   * 
   * @param[in]  rhs      The right hand side of the equation
   * @return     reference to self
   */
  const Array & operator = (const Array & rhs); 

  /**
   * Get the character at the specified index. If the index is not
   * within the range of the array, then std::out_of_range exception
   * is thrown.
   *
   * @param[in]       index               Zero-based location
   */
  int & operator [] (int index);

  /**
   * @overload
   *
   * The returned character is not modifiable.
   */
  const int & operator [] (int index) const;

  ///prints the array
  void printArr (void);

  ///Generates random ints to fill array
  void generateArray (int size);

  ///Sets an index of the array
  void set (int index, int element);

  ///Returns an index of the array
  int get (int index);

  ///Fills the array with the input int
  void fill (int element);

private:
  ///Pointer to array data
  int * data_;
  
  ///Size of the array
  int sizeArr_;
};

#endif // !defined _ARRAY_H__