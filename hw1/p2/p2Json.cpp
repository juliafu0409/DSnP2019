/****************************************************************************
  FileName     [ p2Json.cpp ]
  PackageName  [ p2 ]
  Synopsis     [ Define member functions of class Json and JsonElem ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2018-present DVLab, GIEE, NTU, Taiwan ]
****************************************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "p2Json.h"

using namespace std;

// Implement member functions of class Row and Table here
bool
Json::read(const string& jsonFile)
{
   ifstream fin;
   fin.open(jsonFile);
   
   if (!fin) return false;
   stringstream ss;
   ss << fin.rdbuf();
   string s = ss.str();
   string const delims{ " {,:\"\n\t}" };

   size_t begin, pos = 0;
   vector <string> v;
   
   while ((begin = s.find_first_not_of(delims, pos)) != std::string::npos) {
      pos = s.find_first_of(delims, begin + 1);
      v.push_back(s.substr(begin, pos - begin));
   }
   for (size_t i = 0; i < v.size()-1; i+=2) {
   	  _obj.push_back(JsonElem(v[i], stoi(v[i+1])));
   	  //cerr << _obj[_obj.size()-1];
   }

   return true; // TODO
}

ostream&
operator << (ostream& os, const JsonElem& j)
{
   return (os << "\"" << j._key << "\" : " << j._value);
}

