//
//  Logger.cpp
//
//  Created by Nordstrom, Steve (Faculty - nordstrosg) on 9/5/19.
//  Updated on 1/15/2020.
//  Copyright © 2020 Nordstrom, Steve (Faculty - nordstrosg). All rights reserved.
//

#include "Logger.hpp"
/// <summary>
/// Constructor to start a logger using a specified file name
/// </summary>
/// <param name="fileName">A string containing path for file</param>
Logger::Logger(std::string fileName)
{
    //store the name of the file for later
    logFileName = fileName;
    //turn the console on by default 
    consoleEnabled = true;
    //no need to open file yet
    fileEnabled = false;

}

/// <summary>
/// Destructor to tear down a logger
/// </summary>
Logger::~Logger()
{
    // close file (if it is open)
    if(myFile.is_open()){
        myFile.close();
        fileEnabled = false;
    }
}

/// <summary>
/// Method to log some string data
/// </summary>
/// <param name="line">A string to put as a line of text in the log</param>
/// <returns>True if line was logged properly, false otherwise</returns>
bool Logger::Log(std::string line)
{
    if(fileEnabled){
        //check to see if file is open, open if not and log line
        myFile << line << std::endl;
    }
    // Log to each target if enabled.
    if(consoleEnabled){
        std::cout << line << std::endl;
    }
    return true;

}

/// <summary>
/// Control method to turn on file-based logging
/// </summary>
void Logger::EnableFileLogging()
{
    if(!myFile.is_open())
    {
        myFile.open(logFileName);
        fileEnabled = true;
    }

    else{
        fileEnabled = true;
    }
    

}

/// <summary>
/// Control method to turn off file-based logging
/// </summary>
void Logger::DisableFileLogging()
{
    fileEnabled = false;
}

/// <summary>
/// Control method to turn on console-based logging
/// </summary>
void Logger::EnableConsoleLogging()
{
    consoleEnabled = true;
}

/// <summary>
/// Control method to turn off console-based logging
/// </summary>
void Logger::DisableConsoleLogging()
{
    consoleEnabled = false;
}

/// <summary>
/// String property to view details of the implementation
/// </summary>
std::string Logger::GetInfo()
{
    // return the version number of your Logger
    return "Logger V 0.0.1";
}

/// <summary>
/// Boolean property which reflects if the log is currently logging to a file
/// </summary>
bool Logger::IsFileLogEnabled()
{
    return fileEnabled;
}

/// <summary>
/// Boolean property which reflects if the log is currently logging to the console
/// </summary>
bool Logger::IsConsoleLogEnabled()
{
    return consoleEnabled;
}
