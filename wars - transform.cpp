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

int op (int i) { return i*-1;}

vector<int> invert(vector<int> values) {
  transform(values.begin(), values.end(), values.begin(), op);
  return values;
}

int main(int argc, char* argv[]){

	setlocale(LC_ALL, "portuguese-brazilian");

    vector<int> e = {1,2,3,-4,-5};

    vector<int> r = invert(e);

    for (auto& x : r)
        cout << x << endl;
     for (auto& x : e)
        cout << x << endl;
    //cout << "Resposta : " << r;

    return 0;
}
