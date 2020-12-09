//LStack.hpp
//Written by Ian Reitmaier
// 2/3/2020

#ifndef LSTACK_HPP
#define LSTACK_HPP
#include <iostream>
template <typename T>
class LStack
{
    private:

    // data array to hold ints (for now)
    T *parr;
    // the top of the stack, indexes the next available free spot
    std::size_t top;
    // current size of array
    std::size_t arraySize;

    public:

    //Ctor
    LStack();

    //dtor
    ~LStack();
    
    int Size();

    bool IsOdd(int num);
    
    //Methods for Stack ADT
    void Push(const T& x);
    T& Pop();
    const T& Top();
    bool IsEmpty();
    void PrettyPrint();
    

};


#endif //LSTACK_HPP

