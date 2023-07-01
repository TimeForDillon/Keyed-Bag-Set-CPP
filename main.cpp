/*******************************************************************************
 * AUTHOR        : Dillon Welsh
 * LAB 2         : Bag Class
 * CLASS         : CS8
 * SECTION       : 33776
 * DUE DATE      : 02/26/2021
 ******************************************************************************/

#include <iostream>
#include <cstdlib>
#include "bag.h"
#include "keyed_bag.h"
#include "set.h"

using namespace std;

void get_ages(bag& ages);

void check_ages(bag& ages);

int main()
{
    bag bag_one;
    bag_one.insert(1);
    bag_one.insert(2);
    bag_one.insert(3);
    bag_one.insert(3);
    bag_one.insert(3);
    bag_one.insert(4);
    bag_one.insert(5);

    bag bag_two;
    bag_two.insert(12);
    bag_two.insert(8);
    bag_two.insert(9);
    bag_two.insert(11);

    bag bag_three;
    bag_three.insert(3);
    bag_three.insert(3);
    bag_three.insert(3);

    cout << "*******************************************************" << endl
         << " Displaying Bag Data" << endl
         << "*******************************************************" << endl
         << endl;

    cout << "Displaying bag1... " << endl
         << "bag1 size: " << bag_one.size() << endl
         << "bag1 should contain: 1 2 3 3 3 4 5" << endl
         << "bag1: " << bag_one.toString() << endl << endl;
    cout << "Displaying bag2... " << endl
         << "bag2 size: " << bag_two.size() << endl
         << "bag2 should contain: 12 8 9 11" << endl
         << "bag2: " << bag_two.toString() << endl << endl;
    cout << "Displaying bag3... " << endl
         << "bag3 size: " << bag_three.size() << endl
         << "bag3 should contain 3 3 3" << endl
         << "bag3: " << bag_three.toString() << endl << endl;

    //bag_one = bag_one + bag_two;
    bag_one += bag_two;
    cout << "Displaying bag1 + bag2... " << endl
         << "bag1 size: " << bag_one.size() << endl
         << "bag1 + bag2 should contain: 1 2 3 3 3 4 5 12 8 9 11" << endl
         << "bag1 + bag2: " << bag_one.toString() << endl << endl;


    //bag_one = bag_one - bag_two;
    bag_one -= bag_two;
    cout << "Displaying bag1 - bag2... " << endl
         << "bag1 size: " << bag_one.size() << endl
         << "bag1 - bag2 should contain: 1 2 3 3 3 4 5" << endl
         << "bag1 - bag2: " << bag_one.toString() << endl << endl;

    bag_one = bag_one - bag_three;
    cout << "Displaying bag1 - bag3... " << endl
         << "bag1 size: " << bag_one.size() << endl
         << "bag1 - bag3 should contain: 1 2 4 5" << endl
         << "bag1 - bag3: " << bag_one.toString() << endl << endl;

    set set_one;
    set_one.insert(1);
    set_one.insert(2);
    set_one.insert(3);

    set set_two;
    set_two.insert(3);
    set_two.insert(4);
    set_two.insert(5);
    set_two.insert(6);
    set_two.insert(7);

    set set_three;
    set_three.insert(1);
    set_three.insert(2);

    cout << "*******************************************************" << endl
         << " Displaying Set Data" << endl
         << "*******************************************************" << endl
         << endl;

    cout << "Displaying set1... " << endl
         << "set1 size: " << set_one.size() << endl
         << "set1 should contain: 1 2 3" << endl
         << "set1: " << set_one.toString() << endl << endl;

    cout << "Displaying set2... " << endl
         << "set2 size: " << set_two.size() << endl
         << "set2 should contain: 3 4 5 6 7" << endl
         << "set2: " << set_two.toString() << endl << endl;

    cout << "Displaying set3... " << endl
         << "set3 size: " << set_three.size() << endl
         << "set3 should contain: 1 2" << endl
         << "set3: " << set_three.toString() << endl << endl;

    //set_one = set_one + set_two;
    set_one += set_two;
    cout << "Displayig set1 + set2... " << endl
         << "set1 size: " << set_one.size() << endl
         << "set1 should contain: 1 2 3 4 5 6 7" << endl
         << "set1: " << set_one.toString() << endl << endl;

    set_one = set_one - set_two;
    //set_one -= set_two;
    cout << "Displayig set1 - set2... " << endl
         << "set1 size: " << set_one.size() << endl
         << "set1 should contain: 1 2" << endl
         << "set1: " << set_one.toString() << endl << endl;

    cout << "Testing the != operator... " << endl
         << "set1 != set3..." << endl
         << "expected: false" << endl
         << "result: ";
    if(set_one != set_three) cout << "true" << endl << endl;
    else cout << "false" << endl << endl;

    cout << "Testing the == operator... " << endl
         << "set1 == set3..." << endl
         << "expected: true" << endl
         << "result: ";
    if(set_one == set_three) cout << "true" << endl << endl;
    else cout << "false" << endl << endl;

    cout << "Testing the < operator... " << endl
         << "set1 < set3..." << endl
         << "expected: false" << endl
         << "result: ";
    if(set_one < set_three) cout << "true" << endl << endl;
    else cout << "false" << endl << endl;

    cout << "Testing the <= operator... " << endl
         << "set1 <= set3..." << endl
         << "expected: true" << endl
         << "result: ";
    if(set_one <= set_three) cout << "true" << endl << endl;
    else cout << "false" << endl << endl;

    cout << "Testing the > operator... " << endl
         << "set1 > set3..." << endl
         << "expected: false" << endl
         << "result: ";
    if(set_one > set_three) cout << "true" << endl << endl;
    else cout << "false" << endl << endl;

    cout << "Testing the >= operator... " << endl
         << "set1 >= set3..." << endl
         << "expected: true" << endl
         << "result: ";
    if(set_one >= set_three) cout << "true" << endl << endl;
    else cout << "false" << endl << endl;

    cout << "*******************************************************" << endl
         << " Displaying Keyed-Bag Data" << endl
         << "*******************************************************" << endl
         << endl;

    keyed_bag keyed_bag_one;
    keyed_bag_one.insert(1,0001);
    keyed_bag_one.insert(2,1234);
    keyed_bag_one.insert(3,1234);
    keyed_bag_one.insert(4,0002);

    cout << "Displaying keyed_bag1... " << endl
         << "bag1 size: " << keyed_bag_one.size() << endl
         << "bag1 should contain: 1 2 4" << endl
         << "bag1: " << keyed_bag_one.toString() << endl << endl;

}
