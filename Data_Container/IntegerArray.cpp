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

void IntegerArray::erase()
{
    delete[] m_data;
    m_data = nullptr;
    m_length = 0;
}

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

void IntegerArray::reallocate(int newLength)
{
    erase();            // First we delete any existing elements

    if (newLength <= 0)        // If our array is going to be empty now, return here
        return;

    m_data = new int[newLength]; // Then we have to allocate new elements
    m_length = newLength;
}



void IntegerArray::resize(int newLength)
{
    if (newLength == m_length)  // if the array is already the right length, we're done    
        return;

    if (newLength <= 0)         // If we are resizing to an empty array, do that and return
    {
        erase();
        return;
    }
                                      
    int* data = new int[newLength];   // we have to allocate a new array

    if (m_length > 0)
    {
        int elementsToCopy = (newLength > m_length) ? m_length : newLength;

        for (int index = 0; index < elementsToCopy; ++index)   // Now copy the elements one by one
            data[index] = m_data[index];
    }

    delete[] m_data;

    m_data = data;
    m_length = newLength;

}

void IntegerArray::show()
{
      cout << m_length << endl;
}

const char* Bad_length::what() const noexcept
{

    return "ERROR: giving the wrong length to an array!";

}

const char* Bad_range::what() const noexcept
{
    return "Error: length out of range!";
}
