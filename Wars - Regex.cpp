#include <iostream>
#include <clocale>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <cctype>
#include <numeric>
#include <algorithm>
#include <map>
#include <sstream>
#include <regex>


using namespace std;

bool IsOdd(int i) { return ((i%2)!=0); }
bool IsEven(int i) { return ((i%2)==0); }

bool ordem (int i, int j) {return (i<j);} // Reversa 1>j

typedef unsigned long long ull;

constexpr array<pair<int, int>, 8> adj8 {{
  {-1,-1}, {-1, 0}, {-1, 1},
  { 0,-1},/*{0,0},*/{ 0, 1},
  { 1,-1}, { 1, 0}, { 1, 1}
}};



int main(int argc, char* argv[]){

	setlocale(LC_ALL, "portuguese-brazilian");

    //const string m = "^[ \t]+|[ \t]+$";
    //const string m = "[0]*\\b11|110|1|100|111|010\\b";
    const string m = "(0|(1(01*0)*1)*)*";


    regex s(m);

    //string e = "this subject has a submarine as a subsequence";
    string e = "000010";

    smatch sm;

    //cout << regex_replace(e, s, "w");
    cout << regex_search(e, sm, s) << endl;
    //while (regex_search(e, sm, s)) {
        for (auto& x:sm)
            cout << x << " ";
        cout << endl;
    //    e = sm.suffix().str();
    //    cout << e << endl;
    //}
    //if (regex_match("0110", solution))
    //    cout << "ok";
    //else
    //    cout << "Fail";

    return 0;
}
