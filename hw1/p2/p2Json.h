/****************************************************************************
  FileName     [ p2Json.h]
  PackageName  [ p2 ]
  Synopsis     [ Header file for class Json JsonElem ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2018-present DVLab, GIEE, NTU, Taiwan ]
****************************************************************************/
#ifndef P2_JSON_H
#define P2_JSON_H

#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class JsonElem
{
public:
   // TODO: define constructor & member functions on your own
   JsonElem() {}
   JsonElem(const string& k, int v): _key(k), _value(v) {}

   friend ostream& operator << (ostream&, const JsonElem&);
   friend class Json;

private:
   string  _key;   // DO NOT change this definition. Use it to store key.
   int     _value; // DO NOT change this definition. Use it to store value.
};

class Json
{
public:
   // TODO: define constructor & member functions on your own
   bool read(const string&);
   int sum(void) {
      int sum = 0;
      for (vector<JsonElem>::iterator it = _obj.begin(); it != _obj.end(); it++) {
         sum += it->_value;
      }
      return sum;
   }
   double ave(void) { return (static_cast<double>(sum())/_obj.size()); }
   void max(void) {
      size_t j = 0;
      for (size_t i = 1; i < _obj.size(); i++) {
         if (_obj[i]._value > _obj[j]._value)  { j = i; }
      }
      cout << "The maximum element is: { " << _obj[j] << " }." << endl;
   }
   void min(void) {
      size_t j = 0;
      for (size_t i = 1; i < _obj.size(); i++) {
         if (_obj[i]._value < _obj[j]._value)  { j = i; }
      }
      cout << "The minimum element is: { " << _obj[j] << " }." << endl;
   }
   void print(void) {
      cout << "{\n";
      for (vector<JsonElem>::iterator it = _obj.begin(); it != _obj.end(); it++) {
         cout << "  " << *(it);
         if (it != _obj.end()-1) cout << "," << endl;
      }
      cout << "\n}" << endl;
   }
   vector<string> token(string s) {
      vector<string> v;
      string const delims{ " " };
      size_t begin, pos = 0;

      while ((begin = s.find_first_not_of(delims, pos)) != std::string::npos) {
         pos = s.find_first_of(delims, begin + 1);
         v.push_back(s.substr(begin, pos - begin));
      }
      
      return v;
   }
   /*void add(string s) {

      string const delims{ " \t" };
      size_t begin, pos = 0;
      vector<string> v;

      while ((begin = s.find_first_not_of(delims, pos)) != std::string::npos) {
         pos = s.find_first_of(delims, begin + 1);
         v.push_back(s.substr(begin, pos - begin));
         //cerr << "v.push_back " << s.substr(begin, pos - begin) << endl;
      }
      for (size_t i = 1; i < v.size()-1; i+=2) {
         _obj.push_back(JsonElem(v[i], stoi(v[i+1])));
      }
   }*/
   size_t getSize(void) { return _obj.size(); }

   void add(string s) {
      vector<string> v = getToken(s);
      _obj.push_back(JsonElem(v[1], stoi(v[2])));
   }

   vector<string> getToken(string s) {
      string const delims{ " {,:\"\n\t}" };

      size_t begin, pos = 0;
      vector <string> v;
   
      while ((begin = s.find_first_not_of(delims, pos)) != std::string::npos) {
         pos = s.find_first_of(delims, begin + 1);
         v.push_back(s.substr(begin, pos - begin));
      }
      return v;
   }




private:
   vector<JsonElem>       _obj;  // DO NOT change this definition.
                                 // Use it to store JSON elements.
};

#endif // P2_TABLE_H
