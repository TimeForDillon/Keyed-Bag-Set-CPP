#ifndef KEYED_BAG_H
#define KEYED_BAG_H

#include <cassert>
#include <stddef.h>
#include <string>
#include <iostream>

using namespace std;

struct locked_bag
{
    int key;
    int value;
};

/*******************************************************************************
 * locked_bag Struct
 *  This struct holds a key and a value. The keyed_bag class uses this struct
 *  within the array of the bag itself.
 ******************************************************************************/

class keyed_bag
{
public:
    typedef int value_type;
    typedef size_t size_type;
    static const size_type CAPACITY = 30;

    /********************************
     ** CONSTRUCTORS & DESTRUCTORS **
     ********************************/
    keyed_bag();    // Constructor

    /***************
     ** ACCESSORS **
     ***************/
    size_type size() const{ return used; }
    string toString() const;

    /**************
     ** MUTATORS **
     **************/
    void insert(const value_type& entry, int key);

private:
    locked_bag data[CAPACITY]; // IN - array of structs
    size_type used;            // IN - positive number of used elements
};

#endif // KEYED_BAG_H

/*******************************************************************************
 * keyed_bag Class
 *  This class represents a container called a keyed-bag. This class is
 *  responsible for constructing a bag of numbers (max of 30). Each entry is
 *  locked with a key.
 ******************************************************************************/

/********************************
 ** CONSTRUCTORS & DESTRUCTORS **
 ********************************/

/*******************************************************************************
 * keyed_bag();
 * Constructor; Creates an empty keyed_bag.
 * Parameters: none
 * Return: none
 ******************************************************************************/

/***************
 ** ACCESSORS **
 ***************/

/*******************************************************************************
 * size_type size() const
 *
 * Accessor; Retrieves the size of the keyed_bag.
 * -----------------------------------------------------------------------------
 * Parameters: none
 * -----------------------------------------------------------------------------
 * Return: size_type (int)
 ******************************************************************************/

/*******************************************************************************
 * string toString() const;
 *
 * Accessor; Returns the keyed_bag contents in string form.
 * -----------------------------------------------------------------------------
 * Parameters: none
 * -----------------------------------------------------------------------------
 * Return: string
 ******************************************************************************/

/**************
 ** MUTATORS **
 **************/

/*******************************************************************************
 * void insert(const value_type& entry, int key);
 *
 * Mutator; Inserts the entry value into the keyed_bag with a unique key.
 * -----------------------------------------------------------------------------
 * Parameters: const value_type& entry, int key
 * -----------------------------------------------------------------------------
 * Return: none
 ******************************************************************************/

