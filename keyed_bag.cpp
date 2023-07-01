#include "keyed_bag.h"

/*******************************************************************************
 * Constructor Keyed_Bag: Class Keyed_Bag
 *______________________________________________________________________________
 * This constructor sets the keyed_bag's size as zero.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      N/A
 *
 * POST-CONDITIONS
 *      N/A
 ******************************************************************************/
keyed_bag::keyed_bag():used(0){}

/*******************************************************************************
 * Mutator Insert: Class Keyed_Bag
 *______________________________________________________________________________
 * Inserts the entry value into the bag and sets the key if the key is unique.
 * Otherwise the entry is rejected.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      const value_type& entry : entry for bag
 *      int key : unique key
 *
 * POST-CONDITIONS
 *      N/A
 ******************************************************************************/
void keyed_bag::insert(const value_type& entry, int key)
{
    int count = 0;
    for(size_type i = 0; i < this->size(); i++)
    {
        if(this->data[i].key != key) count++;
    }
    if(size_type(count) == this->size())
    {
        this->data[this->used].key = key;
        this->data[this->used].value = entry;
        ++used;
    }
    else cout << "This key has already been entered." << endl
              << "This entry was rejected." << endl << endl;
}

/*******************************************************************************
 * Accessor toString: Class Keyed_Bag
 *______________________________________________________________________________
 * Displays the keyed_bag as a string.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      N/A
 *
 * POST-CONDITIONS
 *      string
 ******************************************************************************/
string keyed_bag::toString() const
{
    string result = "";
    for(size_type i = 0; i < this->used; i++)
    {
        result += to_string(this->data[i].value) + " ";
    }
    return result;
}
