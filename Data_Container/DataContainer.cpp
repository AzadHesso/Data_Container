#include <iostream>
#include "IntegerArray.h"

using namespace std;

int main()
{
    try
    {
        IntegerArray ob1(10);
        ob1.show();
    }
    catch (exception& e)
    {
        cout << e.what();
    }
	

	return 0;
}