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

int tv_remote(const string& word)
{
    map<char, pair<int,int>> m;
    string alfa = "abcde123fghij456klmno789pqrst.@0uvwxyz_/";
    int i=0, j=0;
    for (char& x : alfa) {
        m[x]= make_pair(i,j);
        if (++i > 7) {
            i=0;
            j++;
        }
    }

    int res=0;
    int xp=0, yp=0;
    for (const char& x : word){
        int xw = m[x].first - xp;
        xp += xw;
        if (xw >= 0)
            for (i=0; i < xw; i++)
                res++;
        else
            for (i=xw; i < 0; i++)
                res++;
        int yw = m[x].second - yp;
        yp += yw;
        if (yw >= 0)
            for (i=0; i < yw; i++)
                res++;
        else
            for (i=yw; i < 0; i++)
                res++;
        res++;
    }

    return res;
}


int main(int argc, char* argv[]){

	setlocale(LC_ALL, "portuguese-brazilian");

    string e = "codewars";

    int r = tv_remote(e);

    cout << "Resposta : " << r;

    return 0;
}
