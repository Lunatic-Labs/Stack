//LStack.cpp
// Written By Ian Reitmaier
// 02/03/2020

#include "LStack.hpp"
#include <iostream>
#include <stdexcept>

//Ctor
template <typename T>
LStack<T>::LStack()
{
    //Build the LStack Here....
    arraySize = 10;

    //Initialize Array of ints
    parr = new T [arraySize];

    //Set the top to Zero
    top = 0;
}

//Dtor
template <typename T>
LStack<T>::~LStack()
{
    //Delete the array here
    delete[] parr;
}
template <typename T>
bool LStack<T>::IsOdd(int num)
{
    if(num % 2 == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
template <typename T>
int LStack<T>::Size()
{
    return top;
}
//CTOR
template <typename T>
void LStack<T>::Push(const T& x)
{   
    if(top != arraySize)
    {
        if(top < arraySize)
        {
            parr[top++] = x;
        }
        else
        {
            size_t newArraysize = arraySize * 2;

            T *tmparr = new T [newArraysize];

            for(int i = 0; i < arraySize; i++){
                tmparr[i] = parr[i];
            }

            delete [] parr;
            
            parr = tmparr;

            arraySize = newArraysize;

            parr[top++] = x;
        }

    }
    
}

//CTOR
template <typename T>
T& LStack<T>::Pop()
{   
    if(top > 0)
    {
        return parr[--top];
    }
    else throw std::out_of_range("Called Pop on an empty LStack");
}

template <typename T>
const T& LStack<T>::Top()
{
    if(top > 0)
    {
        return parr[top-1];
    }
    else throw std::out_of_range("Called Top() on empty LStack");
}

template <typename T>
bool LStack<T>::IsEmpty()
{
    return !(top > 0);
    
}
template <typename T>
void LStack<T>::PrettyPrint()
{
    if (top > 0)
    {
        std::cout << "$<" << parr[top-1] << "<-- Top" << std::endl;

        for(int i = top-2; i >= 0; i--)
        {
            std::cout << "  " << parr[(size_t)i] << std::endl;
        }
    }
    
}

template class LStack<int>;
template class LStack<float>;
template class LStack<std::string>;
//one for each type of LStack we need to use later....