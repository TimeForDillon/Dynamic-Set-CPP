/*******************************************************************************
 * AUTHOR        : Dillon Welsh
 * LAB 3         : Dynamic Set
 * CLASS         : CS8
 * SECTION       : 33776
 * DUE DATE      : 03/06/2021
 ******************************************************************************/

#include <iostream>
#include <cstdlib>

using namespace std;

// Global variables
typedef int value_type;
typedef size_t size_type;
size_type CAPACITY = 30;

/*******************************************************************************
 * size
 *      This function returns the size of the data pointer.
 ******************************************************************************/
size_type size(size_type used);

/*******************************************************************************
 * toString
 *      This function returns the data as a string.
 ******************************************************************************/
string toString(value_type *data,
                size_type used);

/*******************************************************************************
 * menu
 *      This function receives twos sets of a data (pointer) and used.
 *      The function will serve as a menu to allow the user to manipulate
 *      data.
 ******************************************************************************/
void menu(value_type *&data,
          size_type &used);

/*******************************************************************************
 * insert
 *      This function receives an entry, data (pointer), and used.
 *      The function will insert an entry into the data dynamic array.
 *      The data and used variable will be adjusted if the entry is valid.
 ******************************************************************************/
void insert(const value_type entry,
            value_type *&data,
            size_type &used);

/*******************************************************************************
 * erase_one
 *      This function receives an target, data (pointer), and used.
 *      The function will remove the target from the data dynamic array.
 *      The data and used variable will be adjusted if the target is found.
 ******************************************************************************/
bool erase_one(const value_type target,
               value_type *&data,
               size_type &used);

/*******************************************************************************
 * contains
 *      This function receives the target, data (pointer), and used. The
 *      function will check if the target is in the dynamic array.
 *      None of the variables should change. It will return true if the
 *      target is found; otherwise return false.
 ******************************************************************************/
bool contains(const value_type target,
              value_type *data,
              size_type used);

/*******************************************************************************
 * add
 *      This function receives the data1 (pointer), used1, data2 (pointer),
 *      used2. The function will add the sum of data1 and data2 to data1.
 ******************************************************************************/
void add(value_type *&data,
         size_type &used,
         value_type *&data2,
         size_type &used2);

/*******************************************************************************
 * subtract
 *      This function receives the data1 (pointer), used1, data2 (pointer),
 *      used2. The function will subtract the difference of data1
 *      and data2 to data1.
 ******************************************************************************/
void subtract(value_type *&data,
              size_type &used,
              value_type *&data2,
              size_type &used2);

/*******************************************************************************
 * not_equal
 *      This function receives the data1 (pointer), used1, data2 (pointer), and
 *      used2. The function will compare two pointers and determines if
 *      both pointers don't have the exact same items. Nothing should be
 *      changed in this function. It will true if they're not equivalent;
 *      otherwise false.
 ******************************************************************************/
bool not_equal(value_type *&data,
               size_type &used,
               value_type *&data2,
               size_type &used2);

/*******************************************************************************
 * is_equal
 *      This function receives the data1 (pointer), used1, data2 (pointer), and
 *      used2. The function will compare two pointers and determines if
 *      both pointers have the exact same items. Nothing should be
 *      changed in this function. It will true if they're equivalent;
 *      otherwise false.
 ******************************************************************************/
bool is_equal(value_type *&data,
              size_type &used,
              value_type *&data2,
              size_type &used2);

/*******************************************************************************
 * less_than
 *      This function receives used1 and used2. The function will compare
 *      two pointers and determines if data1's size is less than data2's size.
 *      Nothing should be changed in this function. It will true if data1 is
 *      less than data2; otherwise false.
 ******************************************************************************/
bool less_than(size_type &used,
               size_type &used2);

/*******************************************************************************
 * less_than_equal
 *      This function receives used1 and used2. The function will compare
 *      two pointers and determines if data1's size is less than or equal to
 *      data2's size.
 *      Nothing should be changed in this function. It will true if data1 is
 *      less than or equal to data2; otherwise false.
 ******************************************************************************/
bool less_than_equal(size_type &used,
                     size_type &used2);

/*******************************************************************************
 * greater_than
 *      This function receives used1 and used2. The function will compare
 *      two pointers and determines if data1's size is greater than data2's size.
 *      Nothing should be changed in this function. It will true if data1 is
 *      greater than data2; otherwise false.
 ******************************************************************************/
bool greater_than(size_type &used,
                  size_type &used2);

/*******************************************************************************
 * greater_than_equal
 *      This function receives used1 and used2. The function will compare
 *      two pointers and determines if data1's size is greater than or equal to
 *      data2's size.
 *      Nothing should be changed in this function. It will true if data1 is
 *      greater than or equal to data2; otherwise false.
 ******************************************************************************/
bool greater_than_equal(size_type &used,
                        size_type &used2);

/*******************************************************************************
 * Dynamic Set
 *______________________________________________________________________________
 * This program has an interactive menu to manipulate dynamic array.
 *  Also, it will provide a test function to demonstrate that the program
 *  works. It is based on the set class from Lab 2. You can insert, remove,
 *  compare, and display the dynamic array.
 *______________________________________________________________________________
 * INPUT:
 *  Insert elements into the dynamic array.
 *
 * OUTPUT:
 *  Modify the dynamic array by adding, removing, changing, and showing
 *      what's contained in the array.
 ******************************************************************************/

int main()
{
    value_type *data = new value_type[CAPACITY];
    value_type *data2 = new value_type[CAPACITY];
    size_type used = 0;
    size_type used2 = 0;

    insert(1,data,used);
    insert(2,data,used);
    insert(3,data,used);
    insert(4,data,used);

    insert(1,data2,used2);
    insert(2,data2,used2);
    insert(3,data2,used2);
    insert(4,data2,used2);

    cout << "This is a test of the dynamic set!" << endl << endl;

    cout << "Displaying dynamic set data1:" << endl;
    cout << "size: " << size(used) << endl;
    cout << "data: " << toString(data, used) << endl << endl;

    cout << "Displaying dynamic set data2:" << endl;
    cout << "size: " << size(used2) << endl;
    cout << "data: " << toString(data2, used2) << endl << endl;

    cout << "Inserting 5, 6, and 7 into data1..." << endl;
    insert(5,data,used);
    insert(6,data,used);
    insert(7,data,used);
    cout << "Displaying dynamic set data1:" << endl;
    cout << "size: " << size(used) << endl;
    cout << "data: " << toString(data, used) << endl << endl;

    cout << "Removing 1, 2, and 3 from data1..." << endl;
    erase_one(1,data,used);
    erase_one(2,data,used);
    erase_one(3,data,used);
    cout << "Displaying dynamic set data1:" << endl;
    cout << "size: " << size(used) << endl;
    cout << "data: " << toString(data, used) << endl << endl;

    cout << "Adding data1 to data2..." << endl;
    add(data, used, data2, used2);
    cout << "Displaying dynamic set data1:" << endl;
    cout << "size: " << size(used) << endl;
    cout << "data: " << toString(data, used) << endl << endl;

    cout << "Subtracting data2 from data1..." << endl;
    subtract(data, used, data2, used2);
    cout << "Displaying dynamic set data1:" << endl;
    cout << "size: " << size(used) << endl;
    cout << "data: " << toString(data, used) << endl << endl;

    cout << "Testing data1 == data2..." << endl;
    if(is_equal(data,used,data2,used2))
        cout << "data1 is equal to data2" << endl << endl;
    else cout << "data1 is not equal to data2" << endl << endl;

    cout << "Testing data1 != data2..." << endl;
    if(not_equal(data,used,data2,used2))
        cout << "data1 is not equal to data2" << endl << endl;
    else cout << "data1 is equal to data2" << endl << endl;

    cout << "Testing data1 < data2..." << endl;
    if(less_than(used, used2))
        cout << "data1 is less than data2" << endl << endl;
    else cout << "data1 is not less than data2" << endl << endl;

    cout << "Testing data1 > data2..." << endl;
    if(greater_than(used, used2))
        cout << "data1 is greater than data2" << endl << endl;
    else cout << "data1 is not greater than data2" << endl << endl;

    cout << "Testing data1 <= data2..." << endl;
    if(less_than_equal(used, used2))
        cout << "data1 is less than or equal to data2" << endl << endl;
    else cout << "data1 is not less than or equal to data2" << endl << endl;

    cout << "Testing data1 >= data2..." << endl;
    if(greater_than_equal(used, used2))
        cout << "data1 is greater than or equal to data2" << endl << endl;
    else cout << "data1 is not greater than or equal to data2" << endl << endl;

    menu(data,used);

    delete[] data;
    delete[] data2;
}

/*******************************************************************************
 * menu
 *      This function receives twos sets of a data (pointer) and used.
 *      The function will serve as a menu to allow the user to manipulate
 *      data.
 * _____________________________________________________________________________
 * INPUT:
 *  Insert elements into the dynamic array.
 *        value_type *&data,
 *        size_type &used,
 * OUTPUT:
 *  Displays a menu for data input.
 ******************************************************************************/
void menu(value_type *&data,
          size_type &used)
{
    int input = 0;
    while(input != -1)
    {
        cout << "Please make a selection..." << endl;
        cout << "(1) Add a number to set" << endl;
        cout << "(2) Remove a number from set" << endl;
        cout << "(3) Retrieve size of set" << endl;
        cout << "(4) Print out set data" << endl;
        cout << "(-1) Quit" << endl;
        cin >> input;

        int num = 0;
        switch(input)
        {
        case 1:
            cout << "What number would you like to add" << endl;
            cin >> num;
            insert(num,data,used);
            break;
        case 2:
            cout << "What number would you like to remove" << endl;
            cin >> num;
            erase_one(num,data,used);
            break;
        case 3:
            cout << "The size is " << size(used) << endl;
            break;
        case 4:
            cout << "The set data is: " << toString(data,used) << endl;
            break;
        case -1:
            cout << "You quit!" << endl;
            break;
        }

    }
}

/*******************************************************************************
 * size
 *      This function returns the size of the data pointer.
 * _____________________________________________________________________________
 * INPUT:
 *  Insert elements into the dynamic array.
 *        size_type used,
 * OUTPUT:
 *  This function returns the size of the data pointer.
 ******************************************************************************/
size_type size(size_type used)
{
    return used;
}

/*******************************************************************************
 * toString
 *      This function returns the data as a string.
 * _____________________________________________________________________________
 * INPUT:
 *  Insert elements into the dynamic array.
 *        value_type *data,
          size_type used
 * OUTPUT:
 *  This function returns the data as a string.
 ******************************************************************************/
string toString(value_type *data,
                size_type used)
{
    string output = "";
    for(int i = 0; i < int(used); i++)
    {
        output += to_string(int(data[i])) + " ";
    }
    return output;
}

/*******************************************************************************
 * insert
 *      This function receives an entry, data (pointer), and used.
 *      The function will insert an entry into the data dynamic array.
 *      The data and used variable will be adjusted if the entry is valid.
 * _____________________________________________________________________________
 * INPUT:
 *  Insert elements into the dynamic array.
 *        const value_type entry,
          value_type *&data,
          size_type &used
 * OUTPUT:
 *  N/A
 ******************************************************************************/
void insert(const value_type entry,
            value_type *&data,
            size_type &used)
{
    if(used == CAPACITY)
    {
         cout << "doubling capacity... " << endl;
         CAPACITY *= 2;
         cout << "new cap: " << CAPACITY << endl;
         value_type *temp = new value_type[CAPACITY];

         for(int i = 0; i < int(used); i++)
         {
             temp[i] = data[i];
         }

         delete[] data;
         data = temp;
    }

    if(!contains(entry, data, used))
    {
        data[used] = entry;
        ++used;
    }
}

/*******************************************************************************
 * erase_one
 *      This function receives an target, data (pointer), and used.
 *      The function will remove the target from the data dynamic array.
 *      The data and used variable will be adjusted if the target is found.
 * _____________________________________________________________________________
 * INPUT:
 *  Insert elements into the dynamic array.
 *        const value_type target,
          value_type *&data,
          size_type &used
 * OUTPUT:
 *  N/A
 ******************************************************************************/
bool erase_one(const value_type target,
               value_type *&data,
               size_type &used)
{
    size_type index;

    index = 0;
    while((index < used) && (data[index] != target))
        ++index;

    if(index == used) return false;

    --used;
    data[index] = data[used];
    return true;
}

/*******************************************************************************
 * contains
 *      This function receives the target, data (pointer), and used. The
 *      function will check if the target is in the dynamic array.
 *      None of the variables should change. It will return true if the
 *      target is found; otherwise return false.
 * _____________________________________________________________________________
 * INPUT:
 *  Insert elements into the dynamic array.
 *        const value_type target,
          value_type *data,
          size_type used
 * OUTPUT:
 *  N/A
 ******************************************************************************/
bool contains(const value_type target,
              value_type *data,
              size_type used)
{
    size_type i;
    for (i = 0; i < used; i++)
    {
        if(target == data[i])
            return true;
    }
    return false;
}

/*******************************************************************************
 * add
 *      This function receives the data1 (pointer), used1, data2 (pointer),
 *      used2. The function will add the sum of data1 and data2 to data1.
 * _____________________________________________________________________________
 * INPUT:
 *  Insert elements into the dynamic array.
 *       value_type *&data,
 *       size_type &used,
 *       value_type *&data2,
 *       size_type &used2
 * OUTPUT:
 *  N/A
 ******************************************************************************/
void add(value_type *&data,
         size_type &used,
         value_type *&data2,
         size_type &used2)
{
    for(int i = 0; i < int(used2); i++)
    {
        insert(data2[i], data, used);
    }
}

/*******************************************************************************
 * subtract
 *      This function receives the data1 (pointer), used1, data2 (pointer),
 *      used2. The function will subtract the difference of data1
 *      and data2 to data1.
 * _____________________________________________________________________________
 * INPUT:
 *  Insert elements into the dynamic array.
 *       value_type *&data,
 *       size_type &used,
 *       value_type *&data2,
 *       size_type &used2
 * OUTPUT:
 *  N/A
 ******************************************************************************/
void subtract(value_type *&data,
              size_type &used,
              value_type *&data2,
              size_type &used2)
{
    for(int i = 0; i < int(used2); i++)
    {
        if(contains(data2[i], data, used))
        {
            erase_one(data2[i], data, used);
        }
    }
}

/*******************************************************************************
 * not_equal
 *      This function receives the data1 (pointer), used1, data2 (pointer), and
 *      used2. The function will compare two pointers and determines if
 *      both pointers don't have the exact same items. Nothing should be
 *      changed in this function. It will true if they're not equivalent;
 *      otherwise false.
 * _____________________________________________________________________________
 * INPUT:
 *  Insert elements into the dynamic array.
 *       value_type *&data,
 *       size_type &used,
 *       value_type *&data2,
 *       size_type &used2
 * OUTPUT:
 *  N/A
 ******************************************************************************/
bool not_equal(value_type *&data,
               size_type &used,
               value_type *&data2,
               size_type &used2)
{
    if(used != used2) return true;
    else if(used == used2)
    {
        int num = 0;
        for(int i = 0; i < int(used); i++)
        {
            if(contains(data2[i],data,used)) num++;
        }
        if(num == int(used)) return false;
        else return true;
    }
    else return true;
}

/*******************************************************************************
 * is_equal
 *      This function receives the data1 (pointer), used1, data2 (pointer), and
 *      used2. The function will compare two pointers and determines if
 *      both pointers have the exact same items. Nothing should be
 *      changed in this function. It will true if they're equivalent;
 *      otherwise false.
 * _____________________________________________________________________________
 * INPUT:
 *  Insert elements into the dynamic array.
 *       value_type *&data,
 *       size_type &used,
 *       value_type *&data2,
 *       size_type &used2
 * OUTPUT:
 *  N/A
 ******************************************************************************/
bool is_equal(value_type *&data,
              size_type &used,
              value_type *&data2,
              size_type &used2)
{
    if(used != used2) return false;
    else if(used == used2)
    {
        int num = 0;
        for(int i = 0; i < int(used); i++)
        {
            if(contains(data2[i],data,used)) num++;
        }
        if(num == int(used)) return true;
        else return false;
    }
    else return false;
}

/*******************************************************************************
 * less_than
 *      This function receives used1 and used2. The function will compare
 *      two pointers and determines if data1's size is less than data2's size.
 *      Nothing should be changed in this function. It will true if data1 is
 *      less than data2; otherwise false.
 * _____________________________________________________________________________
 * INPUT:
 *  Insert elements into the dynamic array.
 *       size_type &used,
 *       size_type &used2
 * OUTPUT:
 *  N/A
 ******************************************************************************/
bool less_than(size_type &used,
               size_type &used2)
{
    if(used < used2) return true;
    else return false;
}

/*******************************************************************************
 * less_than_equal
 *      This function receives used1 and used2. The function will compare
 *      two pointers and determines if data1's size is less than or equal to
 *      data2's size.
 *      Nothing should be changed in this function. It will true if data1 is
 *      less than or equal to data2; otherwise false.
 * _____________________________________________________________________________
 * INPUT:
 *  Insert elements into the dynamic array.
 *       size_type &used,
 *       size_type &used2
 * OUTPUT:
 *  N/A
 ******************************************************************************/
bool less_than_equal(size_type &used,
                     size_type &used2)
{
    if(used <= used2) return true;
    else return false;
}

/*******************************************************************************
 * greater_than
 *      This function receives used1 and used2. The function will compare
 *      two pointers and determines if data1's size is greater than data2's size.
 *      Nothing should be changed in this function. It will true if data1 is
 *      greater than data2; otherwise false.
 * _____________________________________________________________________________
 * INPUT:
 *  Insert elements into the dynamic array.
 *       size_type &used,
 *       size_type &used2
 * OUTPUT:
 *  N/A
 ******************************************************************************/
bool greater_than(size_type &used,
                  size_type &used2)
{
    if(used > used2) return true;
    else return false;
}

/*******************************************************************************
 * greater_than_equal
 *      This function receives used1 and used2. The function will compare
 *      two pointers and determines if data1's size is greater than or equal to
 *      data2's size.
 *      Nothing should be changed in this function. It will true if data1 is
 *      greater than or equal to data2; otherwise false.
 * _____________________________________________________________________________
 * INPUT:
 *  Insert elements into the dynamic array.
 *       size_type &used,
 *       size_type &used2
 * OUTPUT:
 *  N/A
 ******************************************************************************/
bool greater_than_equal(size_type &used,
                        size_type &used2)
{
    if(used >= used2) return true;
    else return false;
}

