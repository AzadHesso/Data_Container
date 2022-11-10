#include "IntegerArray.h"
#include <iostream>
//#include <cassert> // for assert()

const char* Bad_length::what() const noexcept
{

    return "ERROR: Index is out of Range!";

}

IntegerArray::IntegerArray(int length) : m_length(length)
{
    //assert(length >= 0);
    if (length <= 0)
    {
        throw Bad_length();
    }
    else
        m_data = new int[length] {};
}

void IntegerArray::show()
    {
        std::cout << m_length << std::endl;
    }


