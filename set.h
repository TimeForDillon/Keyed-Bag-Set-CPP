#ifndef SET_H
#define SET_H

#include <cassert>
#include <stddef.h>
#include <string>
#include <iostream>

using namespace std;

class set
{
public:
    typedef int value_type;
    typedef size_t size_type;
    static const size_type CAPACITY = 30;

    /********************************
     ** CONSTRUCTORS & DESTRUCTORS **
     ********************************/
    set();

    /***************
     ** ACCESSORS **
     ***************/
    size_type size() const{ return used; }
    bool contains(const value_type& target) const;
    string toString() const;
    bool operator!=(const set& s) const;
    bool operator==(const set& s) const;
    bool operator<(const set& s) const;
    bool operator>(const set& s) const;
    bool operator<=(const set& s) const;
    bool operator>=(const set& s) const;

    /**************
     ** MUTATORS **
     **************/
    void insert(const value_type& entry);
    bool erase_one(const value_type& target);
    set operator+(const set& s);
    void operator+=(const set& s);
    set operator-(const set& s);
    void operator-=(const set& s);

private:
    value_type data[CAPACITY]; // IN - array of ints
    size_type used;            // IN - positive number of used elements
};

#endif // SET_H

/*******************************************************************************
 * set class
 *  This class represents a container called a set. This class is responsible
 *  for constructing a set of numbers (max of 30).
 ******************************************************************************/

/********************************
 ** CONSTRUCTORS & DESTRUCTORS **
 ********************************/

/*******************************************************************************
 * set();
 * Constructor; Creates an empty set.
 * Parameters: none
 * Return: none
 ******************************************************************************/

/***************
 ** ACCESSORS **
 ***************/

/*******************************************************************************
 * size_type size() const
 *
 * Accessor; Retrieves the size of the set.
 * -----------------------------------------------------------------------------
 * Parameters: none
 * -----------------------------------------------------------------------------
 * Return: size_type (int)
 ******************************************************************************/

/*******************************************************************************
 * bool contains(const value_type& target) const;
 *
 * Accessor; Looks in the set for the target value
 * -----------------------------------------------------------------------------
 * Parameters: const value_type& target
 * -----------------------------------------------------------------------------
 * Return: bool
 ******************************************************************************/

/*******************************************************************************
 * string toString() const;
 *
 * Accessor; Returns the set contents in string form.
 * -----------------------------------------------------------------------------
 * Parameters: none
 * -----------------------------------------------------------------------------
 * Return: string
 ******************************************************************************/

/*******************************************************************************
 * bool operator!=(const set& s) const;
 *
 * Accessor; compares the left set with the right set using the != operator
 * -----------------------------------------------------------------------------
 * Parameters: const set& s
 * -----------------------------------------------------------------------------
 * Return: bool
 ******************************************************************************/

/*******************************************************************************
 * bool operator==(const set& s) const;
 *
 * Accessor; compares the left set with the right set using the == operator
 * -----------------------------------------------------------------------------
 * Parameters: const set& s
 * -----------------------------------------------------------------------------
 * Return: bool
 ******************************************************************************/

/*******************************************************************************
 * bool operator<(const set& s) const;
 *
 * Accessor; compares the left set with the right set using the < operator
 * -----------------------------------------------------------------------------
 * Parameters: const set& s
 * -----------------------------------------------------------------------------
 * Return: bool
 ******************************************************************************/

/*******************************************************************************
 * bool operator>(const set& s) const;
 *
 * Accessor; compares the left set with the right set using the > operator
 * -----------------------------------------------------------------------------
 * Parameters: const set& s
 * -----------------------------------------------------------------------------
 * Return: bool
 ******************************************************************************/

/*******************************************************************************
 * bool operator<=(const set& s) const;
 *
 * Accessor; compares the left set with the right set using the <= operator
 * -----------------------------------------------------------------------------
 * Parameters: const set& s
 * -----------------------------------------------------------------------------
 * Return: bool
 ******************************************************************************/

/*******************************************************************************
 * bool operator>=(const set& s) const;
 *
 * Accessor; compares the left set with the right set using the >= operator
 * -----------------------------------------------------------------------------
 * Parameters: const set& s
 * -----------------------------------------------------------------------------
 * Return: bool
 ******************************************************************************/

/**************
 ** MUTATORS **
 **************/

/*******************************************************************************
 * void insert(const value_type& entry);
 *
 * Mutator; inserts the entry value into the array
 * -----------------------------------------------------------------------------
 * Parameters: const value_type& entry
 * -----------------------------------------------------------------------------
 * Return: none
 ******************************************************************************/

/*******************************************************************************
 * bool erase_one(const value_type& target);
 *
 * Mutator; removes one instance of the target value from the set
 * -----------------------------------------------------------------------------
 * Parameters: const value_type& target
 * -----------------------------------------------------------------------------
 * Return: bool
 ******************************************************************************/

/*******************************************************************************
 * set operator+(const set& s);
 *
 * Mutator; Adds the right set contents to the end of the left set.
 * -----------------------------------------------------------------------------
 * Parameters: const set& s
 * -----------------------------------------------------------------------------
 * Return: set
 ******************************************************************************/

/*******************************************************************************
 * void operator+=(const set& s);
 *
 * Mutator; Adds the right set contents to the end of the left set.
 * -----------------------------------------------------------------------------
 * Parameters: const set& s
 * -----------------------------------------------------------------------------
 * Return: none
 ******************************************************************************/

/*******************************************************************************
 * set operator-(const set& s);
 *
 * Mutator; Subtracts the right set contents from the left set.
 * -----------------------------------------------------------------------------
 * Parameters: const set& s
 * -----------------------------------------------------------------------------
 * Return: set
 ******************************************************************************/

/*******************************************************************************
 * void operator-=(const set& s);
 *
 * Mutator; Subtracts the right set contents from the left set.
 * -----------------------------------------------------------------------------
 * Parameters: const set& s
 * -----------------------------------------------------------------------------
 * Return: none
 ******************************************************************************/

