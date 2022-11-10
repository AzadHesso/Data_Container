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

void IntegerArray::insertBefore(int value, int index)
{
    if (index < 0 || index > m_length)  // Sanity check our index value
    {
        throw Bad_range();
    }

    int* data = new int[m_length + 1];  // First create a new array one element larger than the old array

    for (int before = 0; before < index; ++before)  // Copy all of the elements up to the index
        data[before] = m_data[before];

    data[index] = value;     // Insert our new element into the new array

    for (int after = index ; after < m_length; ++after)      // Copy all of the values after the inserted element
        data[after + 1] = m_data[after];

    delete[] m_data;   // Finally, delete the old array, and use the new array instead
    m_data = data;
    ++m_length;
    
}

void IntegerArray::remove(int index)
{
  
    if (index < 0 || index > m_length)   // Sanity check our index value
    {
        throw Bad_length();
    }

    if (m_length == 1)    // If this is the last remaining element in the array, set the array to empty and bail out
    {
        erase();
        return;
    }

    int* data = new int[m_length - 1] ;                    // First create a new array one element smaller than the old array


    for (int before = 0 ; before < index; ++before)        // Copy all of the elements up to the index
        data[before] = m_data[before];

    for (int after{ index + 1 }; after < m_length; ++after) // Copy all of the values after the removed element
        data[after - 1] = m_data[after];

    delete[] m_data;   // Finally, delete the old array, and use the new array instead
    m_data = data;
    --m_length;
   
}

void IntegerArray::insertAtBeginning(int value)   
{
    insertBefore(value, 0);
}

void IntegerArray::insertAtEnd(int value) 
{
    insertBefore(value, m_length);
}

int IntegerArray::sercheValue(int index)
{
    
    
    for (int i = 0; i < m_length; i++)
    {     
        if (i == index)
        {
            return m_data[index];
        }
        if (index < 0 || index > m_length)   // Sanity check our index value
        {
            throw Bad_Value();
        }
        
    }
}




const char* Bad_length::what() const noexcept
{

    return "ERROR: giving the wrong length to an array!";

}

const char* Bad_range::what() const noexcept
{
    return "Error: length out of range!";
}

const char* Bad_Value::what() const noexcept
{
    return "this value does not exist";
}
