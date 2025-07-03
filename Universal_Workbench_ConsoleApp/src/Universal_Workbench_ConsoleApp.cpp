// Universal_Workbench_ConsoleApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BasicChemistryBuildup/CalcInChem_basics.h"
#include "Interpreter/interpreter.h"

int main()
{
    std::string filename;
    std::cout << R"(
  _    _       _                          _             
 | |  | |     (_)                        | |            
 | |  | |_ __  ___   _____ _ __ ___  __ _| |            
 | |  | | '_ \| \ \ / / _ \ '__/ __|/ _` | |            
 | |__| | | | | |\ V /  __/ |  \__ \ (_| | |            
 _\____/|_| |_|_| \_/ \___|_|  |___/\__,_|_|      _     
 \ \        / /       | |  | |                   | |    
  \ \  /\  / /__  _ __| | _| |__   ___ _ __   ___| |__  
   \ \/  \/ / _ \| '__| |/ / '_ \ / _ \ '_ \ / __| '_ \ 
    \  /\  / (_) | |  |   <| |_) |  __/ | | | (__| | | |
     \/  \/ \___/|_|  |_|\_\_.__/ \___|_| |_|\___|_| |_|

)" << std::endl;
    std::cout << "File to run" << std::endl;
    getline(std::cin, filename);
    Interp::readScriptFile(filename);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
