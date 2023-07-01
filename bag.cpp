#include "bag.h"
#include <algorithm>

/*******************************************************************************
 * Constructor Bag: Class Bag
 *______________________________________________________________________________
 * This constructor sets the bag's size as zero.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      N/A
 *
 * POST-CONDITIONS
 *      N/A
 ******************************************************************************/
bag::bag():used(0){}

/*******************************************************************************
 * Accessor Count: Class Bag
 *______________________________________________________________________________
 * This method retrieves the size of the bag. Returns the size.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      const value_type& target : number to enter
 *
 * POST-CONDITIONS
 *      size_type : the number
 ******************************************************************************/
bag::size_type bag::count(const value_type& target) const
{
    size_type answer;
    size_type i;
    answer = 0;
    for (i = 0; i < used; ++i)
        if(target == data[i])
            ++answer;
    return answer;
}

/*******************************************************************************
 * Mutator Insert: Class Bag
 *______________________________________________________________________________
 * Inserts the entry value into the bag
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      const value_type& entry : number to enter
 *
 * POST-CONDITIONS
 *      N/A
 ******************************************************************************/
void bag::insert(const value_type& entry)
{
    assert(size() < CAPACITY);
    data[used] = entry;
    ++used;
}

/*******************************************************************************
 * Mutator Erase_one: Class Bag
 *______________________________________________________________________________
 * Erases one instance of the target value from the bag.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      const value_type& target : number to erase
 *
 * POST-CONDITIONS
 *      bool
 ******************************************************************************/
bool bag::erase_one(const value_type& target)
{
    size_type index;

    index = 0;
    while((index < used) && (data[index] != target))
        ++index;

    if(index == used)
        return false;

    --used;
    data[index] = data[used];
    return true;
}

/*******************************************************************************
 * Mutator Erase: Class Bag
 *______________________________________________________________________________
 * Erases all instances of the target value from the bag.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      const value_type& target : number to erase
 *
 * POST-CONDITIONS
 *      size_type : number of instances erased
 ******************************************************************************/
bag::size_type bag::erase(const value_type& target)
{
    size_type index = 0;
    size_type many_removed = 0;

    while(index < used)
    {
        if(data[index] == target)
        {
            --used;
            data[index] = data[used];
            ++many_removed;
        }
        else
            ++index;
    }

    return many_removed;
}

/*******************************************************************************
 * Mutator operator+=: Class Bag
 *______________________________________________________________________________
 * Adds the right bag contents to the end of the left bag.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      const bag& add : bag to add
 *
 * POST-CONDITIONS
 *      N/A
 ******************************************************************************/
void bag::operator+=(const bag& add)
{
    assert(size() + add.size() <= CAPACITY);

    std::copy(add.data, add.data + add.used, data + used);
    used += add.used;
}

/*******************************************************************************
 * Mutator operator+: Class Bag
 *______________________________________________________________________________
 * Adds the right bag contents to the end of the left bag.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      const bag& add : bag to add
 *
 * POST-CONDITIONS
 *      bag : the sum
 ******************************************************************************/
bag bag::operator+(const bag& b)
{
    bag answer;

    assert(this->size() + b.size() <= bag::CAPACITY);

    answer += *this;
    answer += b;
    return answer;
}

/*******************************************************************************
 * Mutator operator-=: Class Bag
 *______________________________________________________________________________
 * Subtracts the right bag contents from the left bag.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      const bag& add : bag to add
 *
 * POST-CONDITIONS
 *      N/A
 ******************************************************************************/
void bag::operator-=(const bag &subtract)
{
    int target = 0;
    for(size_type i = 0; i < subtract.size(); i++)
    {
        target = subtract.data[i];
        for(size_type j = 0; j < this->size(); j++)
        {
            if(this->data[j] == target)
            {
                this->erase_one(target);
                break;
            }
        }
    }
}

/*******************************************************************************
 * Mutator operator-: Class Bag
 *______________________________________________________________________________
 * Subtracts the right bag contents from the left bag.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      const bag& add : bag to add
 *
 * POST-CONDITIONS
 *      bag : the difference
 ******************************************************************************/
bag bag::operator-(const bag& b)
{
    bag answer;

    answer += *this;
    answer -= b;
    return answer;
}

/*******************************************************************************
 * Accessor toString: Class Bag
 *______________________________________________________________________________
 * Displays the bag as a string.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      N/A
 *
 * POST-CONDITIONS
 *      string
 ******************************************************************************/
string bag::toString() const
{
    string result = "";
    for(size_type i = 0; i < this->used; i++)
    {
        result += to_string(this->data[i]) + " ";
    }
    return result;
}


