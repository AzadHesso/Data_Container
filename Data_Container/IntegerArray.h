#pragma once
//class IntegerArray
//{
//private:
//    int m_length;
//    int* m_data[];
//
//public:
//    IntegerArray() = default;
//    IntegerArray(int Lenght) : m_length(Lenght) {}
//
//    ~IntegerArray();
//};

#include <iostream>

using namespace std;

class Bad_length : public exception
{
public:
    Bad_length() = default;
   ~Bad_length() = default;

    virtual const char* what() const noexcept override;
};

class IntegerArray
{
private:
    int m_length{};
    int* m_data{};

public:
    IntegerArray() = default;

    IntegerArray(int length);
   
    void show();
  

};