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

bool ordem (int i, int j) {
    return (IsEven(i) || IsEven(j)) ? false : (i<j);
}

typedef unsigned long long ull;

constexpr array<pair<int, int>, 8> adj8 {{
  {-1,-1}, {-1, 0}, {-1, 1},
  { 0,-1},/*{0,0},*/{ 0, 1},
  { 1,-1}, { 1, 0}, { 1, 1}
}};


string disemvowel(string str) {

    regex r ("[aeiouAEIOU]");

    return regex_replace(str,r,"");
}

int main(int argc, char* argv[]){

	setlocale(LC_ALL, "portuguese-brazilian");

    string e = "This website is for losers LOL!";

    string r = disemvowel(e);

    cout << "Resposta : " << r << endl;

    return 0;
}
