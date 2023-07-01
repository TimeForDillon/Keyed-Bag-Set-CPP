#include "set.h"

/*******************************************************************************
 * Constructor Set: Class Set
 *______________________________________________________________________________
 * This constructor sets the set's size as zero.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      N/A
 *
 * POST-CONDITIONS
 *      N/A
 ******************************************************************************/
set::set():used(0){}

/*******************************************************************************
 * Mutator Insert: Class Set
 *______________________________________________________________________________
 * Inserts the entry value into the set
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      const value_type& entry : number to enter
 *
 * POST-CONDITIONS
 *      N/A
 ******************************************************************************/
void set::insert(const value_type &entry)
{
    if(!this->contains(entry))
    {
        this->data[used] = entry;
        ++used;
    }
    else cout << "That number is already in this set.";
}

/*******************************************************************************
 * Accessor Contains: Class Set
 *______________________________________________________________________________
 * Sees if the target value is in the set.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      const value_type& target : value we are looking for
 *
 * POST-CONDITIONS
 *      bool
 ******************************************************************************/
bool set::contains(const value_type& target) const
{
    for(size_type i = 0; i < this->size(); i++)
    {
        if(this->data[i] == target)
            return true;
    }
    return false;
}

/*******************************************************************************
 * Mutator Erase_one: Class Set
 *______________________________________________________________________________
 * Erases one instance of the target value from the set.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      const value_type& target : number to erase
 *
 * POST-CONDITIONS
 *      bool
 ******************************************************************************/
bool set::erase_one(const value_type& target)
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
 * Mutator operator+=: Class Set
 *______________________________________________________________________________
 * Adds the right set contents to the end of the left set.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      const set& s : set to add
 *
 * POST-CONDITIONS
 *      N/A
 ******************************************************************************/
void set::operator+=(const set& s)
{
    assert(size() + s.size() <= CAPACITY);

    for(size_type i = 0; i < s.size(); i++)
    {
        if(!this->contains(s.data[i]))
        {
            this->insert(s.data[i]);
        }
    }
}

/*******************************************************************************
 * Mutator operator+: Class Set
 *______________________________________________________________________________
 * Adds the right set contents to the end of the left set.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      const set& s : set to add
 *
 * POST-CONDITIONS
 *      set : sum
 ******************************************************************************/
set set::operator+(const set& s)
{
    set answer;

    assert(this->size() + s.size() <= set::CAPACITY);

    answer += *this;
    answer += s;
    return answer;
}

/*******************************************************************************
 * Mutator operator-=: Class Set
 *______________________________________________________________________________
 * Subtracts the right set contents from the left set.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      const set& s : bag to subtract
 *
 * POST-CONDITIONS
 *      N/A
 ******************************************************************************/
void set::operator-=(const set &s)
{
    int target;
    for(size_type i = 0; i < s.size(); i++)
    {
        target = s.data[i];
        for(size_type j = 0; j < this->size(); j++)
        {
            if(this->data[j] == target)
            {
                this->erase_one(this->data[j]);
                break;
            }
        }
    }
}

/*******************************************************************************
 * Mutator operator-: Class Set
 *______________________________________________________________________________
 * Subtracts the right set contents from the left set.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      const set& s : bag to subtract
 *
 * POST-CONDITIONS
 *      set : difference
 ******************************************************************************/
set set::operator-(const set &s)
{
    set answer;

    answer += *this;
    answer -= s;
    return answer;
}

/*******************************************************************************
 * Accessor operator!=: Class Set
 *______________________________________________________________________________
 * Compares the left and right set using != operator.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      const set &s : set to compare
 *
 * POST-CONDITIONS
 *      bool
 ******************************************************************************/
bool set::operator!=(const set &s) const
{
    if(*this == s) return false;
    else return true;
}

/*******************************************************************************
 * Accessor operator==: Class Set
 *______________________________________________________________________________
 * Compares the left and right set using == operator.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      const set &s : set to compare
 *
 * POST-CONDITIONS
 *      bool
 ******************************************************************************/
bool set::operator==(const set &s) const
{
    if(this->size() == s.size())
    {
        int num = this->size();
        int count = 0;
        for(size_type i = 0; i < this->size(); i++)
        {
            if(this->data[i] == s.data[i])
            {
                count++;
            }
        }
        if(count == num) return true;
        else return false;
    }
    else return false;
}

/*******************************************************************************
 * Accessor operator<: Class Set
 *______________________________________________________________________________
 * Compares the left and right set using < operator.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      const set &s : set to compare
 *
 * POST-CONDITIONS
 *      bool
 ******************************************************************************/
bool set::operator<(const set &s) const
{
    if(this->size() >= s.size()) return false;
    else return true;
}

/*******************************************************************************
 * Accessor operator<=: Class Set
 *______________________________________________________________________________
 * Compares the left and right set using <= operator.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      const set &s : set to compare
 *
 * POST-CONDITIONS
 *      bool
 ******************************************************************************/
bool set::operator<=(const set &s) const
{
    if(this->size() > s.size()) return false;
    else return true;
}

/*******************************************************************************
 * Accessor operator>: Class Set
 *______________________________________________________________________________
 * Compares the left and right set using > operator.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      const set &s : set to compare
 *
 * POST-CONDITIONS
 *      bool
 ******************************************************************************/
bool set::operator>(const set &s) const
{
    if(this->size() <= s.size()) return false;
    else return true;
}

/*******************************************************************************
 * Accessor operator>=: Class Set
 *______________________________________________________________________________
 * Compares the left and right set using >= operator.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      const set &s : set to compare
 *
 * POST-CONDITIONS
 *      bool
 ******************************************************************************/
bool set::operator>=(const set &s) const
{
    if(this->size() < s.size()) return false;
    else return true;
}

/*******************************************************************************
 * Accessor toString: Class Set
 *______________________________________________________________________________
 * Displays the set as a string.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      N/A
 *
 * POST-CONDITIONS
 *      string
 ******************************************************************************/
string set::toString() const
{
    string result = "";
    for(size_type i = 0; i < this->used; i++)
    {
        result += to_string(this->data[i]) + " ";
    }
    return result;
}


