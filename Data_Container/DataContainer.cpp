#include <iostream>
#include "IntegerArray.h"

using namespace std;

int main()
{
    IntegerArray array(10);

    for (int i = 0; i < 10; ++i)
        array[i] = i + 1;
    cout << "Print out all the numbers of array m_data[" << array.getLength() << "] = ";
    for (int i = 0; i < array.getLength(); ++i)
        cout << array[i] << ' ';
    cout << endl;

    //check exception
    try
    {
        IntegerArray array(-1);
    }
    catch (exception& e)
    {
        cout << e.what() << endl;
    }
 
    // Resize the array to 8 elements
    array.resize(8);

    cout << "Print out all the numbers of array m_data[" << array.getLength() <<"] = ";
    for (int i = 0; i < array.getLength(); ++i)
         cout << array[i] << ' ';
    cout << endl;

    // insert the value before

    try
    {
        array.insertBefore(20, -1);
    }
    catch (exception& e)
    {
        cout << e.what() << endl;
    }

    array.insertBefore(20, 5);

    cout << "Insert a new value to array m_data["<< array.getLength() << "] = ";
    for (int i = 0; i < array.getLength(); ++i)
        cout << array[i] << ' ';
        cout << endl;
   
    // remove value
    try
    {
        array.remove(-1);
    }
    catch (exception& e)
    {
        cout << e.what() << endl;
    }

    array.remove(3);

    cout << "Remove value at array m_data[" << array.getLength() << "] = ";
    for (int i = 0; i < array.getLength(); ++i)
        cout << array[i] << ' ';
    cout << endl;

    // insert 35 and 50 to the end and beginning of array 
    
    array.insertAtEnd(35);       

    array.insertAtBeginning(50);  


    // Print out all the numbers
    cout << "Print out all the numbers of array m_data[" << array.getLength() << "] = ";
    for (int i = 0; i < array.getLength(); i++)
        cout << array[i] << " ";
    cout << endl;

    // search in the element container by index.
    try
    {
        int index = -1;
        int arr = array.sercheValue(index);
        cout << "value by index " << index << " = " << arr << endl;

    }
    catch(exception& e)
    {
        cout << e.what() << endl;
    }
    int index = 9;
    int arr = array.sercheValue(index);
    cout << "value by index " << index << " = " << arr << endl;



 
	return 0;
}