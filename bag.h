#ifndef BAG_H
#define BAG_H

#include <cassert>
#include <stddef.h>
#include <string>

using namespace std;

class bag
{
public:
    typedef int value_type;
    typedef size_t size_type;
    static const size_type CAPACITY = 30;

    /********************************
     ** CONSTRUCTORS & DESTRUCTORS **
     ********************************/
    bag();  // Constructor

    /***************
     ** ACCESSORS **
     ***************/
    size_type size() const{ return used; }
    size_type count(const value_type& target) const;
    string toString() const;

    /**************
     ** MUTATORS **
     **************/
    void insert(const value_type& entry);
    bool erase_one(const value_type& target);
    size_type erase(const value_type& target);
    bag operator+(const bag& b);
    void operator+=(const bag& add);
    bag operator-(const bag& b);
    void operator-=(const bag& subtract);

private:
    value_type data[CAPACITY]; // IN - array of ints
    size_type used;            // IN - positive number of used elements
};

#endif

/*******************************************************************************
 * Bag Class
 *  This class represents a container called a bag. This class is responsible
 *  for constructing a bag of numbers (max of 30).
 ******************************************************************************/

/********************************
 ** CONSTRUCTORS & DESTRUCTORS **
 ********************************/

/*******************************************************************************
 * Bag();
 * Constructor; Creates an empty bag.
 * Parameters: none
 * Return: none
 ******************************************************************************/

/***************
 ** ACCESSORS **
 ***************/

/*******************************************************************************
 * size_type size() const
 *
 * Accessor; Retrieves the size of the bag.
 * -----------------------------------------------------------------------------
 * Parameters: none
 * -----------------------------------------------------------------------------
 * Return: size_type (int)
 ******************************************************************************/

/*******************************************************************************
 * size_type count(const value_type& target) const;
 *
 * Accessor; Retrieves the amount of time the targer number is in the bag.
 * -----------------------------------------------------------------------------
 * Parameters: const value_type& target
 * -----------------------------------------------------------------------------
 * Return: size_type (int)
 ******************************************************************************/

/*******************************************************************************
 * string toString() const;
 *
 * Accessor; Returns the bag contents in string form.
 * -----------------------------------------------------------------------------
 * Parameters: none
 * -----------------------------------------------------------------------------
 * Return: string
 ******************************************************************************/

/**************
 ** MUTATORS **
 **************/

/*******************************************************************************
 * void insert(const value_type& entry);
 *
 * Mutator; Inserts the entry value into the bag.
 * -----------------------------------------------------------------------------
 * Parameters: const value_type& entry
 * -----------------------------------------------------------------------------
 * Return: none
 ******************************************************************************/

/*******************************************************************************
 * bool erase_one(const value_type& target);
 *
 * Mutator; Erases one instance of the target value from the bag.
 * -----------------------------------------------------------------------------
 * Parameters: const value_type& target
 * -----------------------------------------------------------------------------
 * Return: bool
 ******************************************************************************/

/*******************************************************************************
 * size_type erase(const value_type& target);
 *
 * Mutator; Erases all instances of the target value from the bag.
 * -----------------------------------------------------------------------------
 * Parameters: const value_type& target
 * -----------------------------------------------------------------------------
 * Return: size_type
 ******************************************************************************/

/*******************************************************************************
 * bag operator+(const bag& b);
 *
 * Mutator; Adds the right bag contents to the end of the left bag.
 * -----------------------------------------------------------------------------
 * Parameters: const bag& b
 * -----------------------------------------------------------------------------
 * Return: bag
 ******************************************************************************/

/*******************************************************************************
 * void operator+=(const bag& b);
 *
 * Mutator; Adds the right bag contents to the end of the left bag.
 * -----------------------------------------------------------------------------
 * Parameters: const bag& b
 * -----------------------------------------------------------------------------
 * Return: none
 ******************************************************************************/

/*******************************************************************************
 * bag operator-(const bag& b);
 *
 * Mutator; Subtracts the right bag contents from the left bag.
 * -----------------------------------------------------------------------------
 * Parameters: const bag& b
 * -----------------------------------------------------------------------------
 * Return: bag
 ******************************************************************************/

/*******************************************************************************
 * void operator-=(const bag& b);
 *
 * Mutator; Subtracts the right bag contents from the left bag.
 * -----------------------------------------------------------------------------
 * Parameters: const bag& b
 * -----------------------------------------------------------------------------
 * Return: none
 ******************************************************************************/
