#include "IntegerArray.h"
#include <iostream>

IntegerArray::IntegerArray(int length) : m_length(length)
{
    if (length <= 0)
    {
        throw Bad_length();
    }
    else
        m_data = new int[length] {};
}

IntegerArray::~IntegerArray()
{
    delete[] m_data;
}

//void integerarray::erase()
//{
//    delete[] m_data;
//    m_data = nullptr;
//    m_length = 0;
//}

int& IntegerArray::operator[](int index)
{
    if (index <= 0 && index > m_length)
    {
        throw Bad_range();
    }
    return m_data[index];
}

int IntegerArray::getLength() const
{
    return m_length;
}

void IntegerArray::show()
    {
        std::cout << m_length << std::endl;
    }

const char* Bad_length::what() const noexcept
{

    return "ERROR: giving the wrong length to an array!";

}

const char* Bad_range::what() const noexcept
{
    return "Error: length out of range!";
}
