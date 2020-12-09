//Created by Ian Reitmaier

#include "LStack.cpp"
#include "Logger.cpp"
#include <fstream>
#include <string>
#include <istream>

//Creating the validate function
bool Validate(std::string fileName);

int main(){
    Logger logger("./test.txt");
    std::string file;
    std::cout << "Enter File Name: ";
    std::cin >> file;
    logger.EnableConsoleLogging();
    if(Validate(file)){
        logger.Log("File is Valid");

    }
    else{
        logger.Log("File is not valid Syntax Error");
    }


}

bool Validate(std::string fileName){
    int tracker;
    char chr;
    LStack <char> myStack;
    std::fstream fin(fileName, std::fstream::in);
    std::string trash;
    getline(fin, trash);
    while(fin >> chr){
        if(chr == '<' ){
            tracker = 1;
            continue;
        }
        else if((tracker == 1) && (chr != '/')){
            tracker = 0;
            myStack.Push(chr);
            continue;
        }
        else if(chr == '/'){
            tracker = 2;
            continue;
        }
        else if(tracker == 2){
            if(myStack.Top() != chr){
                return false;
            }
            else{
                myStack.Pop();
                tracker = 0;
                continue;
            }
        }
    }
    return true;
}

