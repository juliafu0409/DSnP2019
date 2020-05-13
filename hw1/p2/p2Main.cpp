/****************************************************************************
  FileName     [ p2Main.cpp ]
  PackageName  [ p2 ]
  Synopsis     [ Define main() function ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2016-present DVLab, GIEE, NTU, Taiwan ]
****************************************************************************/
#include <iostream>
#include <string>
#include <iomanip>
#include "p2Json.h"

using namespace std;

int main()
{
   Json json;

   // Read in the csv file. Do NOT change this part of code.
   string jsonFile;
   cout << "Please enter the file name: ";
   cin >> jsonFile;
   if (json.read(jsonFile))
      cout << "File \"" << jsonFile << "\" was read in successfully." << endl;
   else {
      cerr << "Failed to read in file \"" << jsonFile << "\"!" << endl;
      exit(-1); // jsonFile does not exist.
   }
   // TODO read and execute commands
   //cout << "Enter command: ";
   cin.ignore();
   while (true) {      
      cout << "Enter command: ";
      string cmd;
      
      getline(cin, cmd);
      //cout << cmd;

      if (cmd == "SUM" || cmd == "AVE" || cmd == "MAX" || cmd == "MIN") {
         if (json.getSize() == 0) cout << "Error: No element found!!" << endl;
         else {
            if (cmd == "SUM") cout << "The summation of the values is: " << json.sum() << "." << endl;
            else if (cmd == "AVE") cout << "The average of the values is: " << fixed << setprecision(1) << json.ave() << "." << endl;
            else if (cmd == "MAX") json.max();
            else if (cmd == "MIN") json.min();
         }
      }
      else if (cmd == "PRINT") json.print();
      else if (cmd == "EXIT") exit(-1);
      else if (cmd.substr(0,3) == "ADD") json.add(cmd);

   }

   
}
