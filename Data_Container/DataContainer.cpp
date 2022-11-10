#include <iostream>
#include "IntegerArray.h"

using namespace std;

int main()
{
    IntegerArray array(10);
    array.show();

    try
    {
        IntegerArray array(-1);
        array.show();
    }
    catch (exception& e)
    {
        cout << e.what() << endl;
    }
    //IntegerArray* ob2;
    //try
    //{
    //    ob2 = new IntegerArray[400000]; // попытка выделить 1280 √б байт пам€ти
    //}
    //catch (bad_alloc& ba)
    //{
    //    cout << "bad_alloc caught!" << endl;
    //    cout << ba.what() << endl;
    //}

    // Resize the array to 8 elements
   
    for (int i = 0 ; i < 10; ++i)
        array[i] = i + 1;

    array.resize(8);

    cout << "Print out all the numbers: ";
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

    cout << "Insert a new value: ";
    for (int i = 0; i < array.getLength(); ++i)
        cout << array[i] << ' ';
        cout << endl;

    

	

	return 0;
}