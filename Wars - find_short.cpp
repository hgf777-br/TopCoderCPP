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
#include <sstream>
#include <functional>

using namespace std;

bool IsOdd(int i) { return ((i%2)!=0); }
bool IsEven(int i) { return ((i%2)==0); }

bool ordem (int i, int j) {return (i<j);} // Reversa 1>j

typedef unsigned long long ull;
typedef long long ll;

int find_short2(string str) {
  int res = (int) str.size();
  regex rex ("\\b(\\w*)\\b");
  regex_iterator<string::iterator> r (str.begin(), str.end(), rex);
  regex_iterator<string::iterator> e;
  while (r != e) {
    string t = r -> str();
    int s = (int) t.size();
    if (s < res and s != 0)
      res = s;
    r++;
  }
  return res;
}

int find_short(string str) {
  int res = (int) str.size();
  int i = 0;
  int f = str.find(" ");
  while (f != string::npos) {
    if ((f-i) < res)
      res = (f-i);
    i = f+1;
    f = str.find(" ",i);
  }
  return res;
}

int main(int argc, char* argv[]){

    setlocale(LC_ALL, "portuguese-brazilian");

    string e = "bitcoin take over the world maybe who knows perhaps";

    cout << "Resposta : " << find_short(e);

    return 0;
}
