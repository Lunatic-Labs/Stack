//Main.cpp
// Written by Ian Reitmaier
// 2/3/2020

#include <iostream>
//#include "Logger.hpp"
#include "LStack.hpp"

int main()
{
    std::cout << "Hello World" << std::endl;

    //Instantiate an LStack object
    LStack<int> myStack;
    myStack.Push(10);
    myStack.Push(20);

    std::cout << myStack.Top()<< std::endl;
    
    myStack.Pop();

    std::cout << myStack.Top() << std::endl;

    myStack.Push(25);
    myStack.Push(15);
    
    //Print the stack
    if(!myStack.IsEmpty())
    {
        myStack.PrettyPrint();
    }
    

}