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

bool ordem_rev (int i, int j) {return (i<j);}

typedef unsigned long long ull;

constexpr array<pair<int, int>, 8> adj8 {{
  {-1,-1}, {-1, 0}, {-1, 1},
  { 0,-1},/*{0,0},*/{ 0, 1},
  { 1,-1}, { 1, 0}, { 1, 1}
}};

vector<int> Pendulum (vector<int> v) {
    int sz = v.size();
    vector<int> res(sz);
    sort(v.begin(), v.end());
    int pz = (sz-1)/2;
    int iv = -1;
    for (int i=0; i < sz; i++) {
        pz += (iv*i);
        res[pz] = v[i];
        iv = (iv<0)?1:-1;
    }
return res;
}

int main(int argc, char* argv[]){

	setlocale(LC_ALL, "portuguese-brazilian");

    vector<int> e = {-9, -2, -10, -6};

    vector<int> r = Pendulum(e);

    cout << "Resposta : ";

    for (auto& x : r)
        cout << x << ", ";

    return 0;
}
