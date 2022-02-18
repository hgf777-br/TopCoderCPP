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
#include <set>

using namespace std;

bool IsOdd(int i) { return ((i%2)!=0); }
bool IsEven(int i) { return ((i%2)==0); }

bool ordem (int i, int j) {return (i<j);} // Reversa 1>j

typedef unsigned long long ull;
typedef long long ll;

string encode_rail_fence_cipher(string str, int n) {
    cout << str << endl << endl;
    if (str.empty())
        return "";
    int i = 0;
    int j = 1;
    vector<string> s(n);
    string res;

    for (auto& x : str) {
        s[i] += x;
        i += j;
        if (i == n) {
            j=-1;
            i -= 2;;
        }
        if (i == -1) {
            j=1;
            i += 2;
        }
    }

    for (auto& x : s)
      res += x;

    return res;
}

string decode_rail_fence_cipher(string str, int n) {
    if (str.empty())
        return "";
    int sz = str.size();
    int i = 0;
    int j = 1;
    vector<pair<string,int>> s(n,{"",0});
    string res;

    for (int c=0; c < sz; c++) {
        s[i].second++;
        i += j;
        if (i == n) {
            j=-1;
            i -= 2;
        }
        if (i == -1) {
            j=1;
            i += 2;
        }
    }
    i = 0;
    int pi = 0;
    int pf;
    while (i < n) {
        pf = s[i].second;
        s[i].second = 0;
        s[i].first = str.substr(pi,pf);
        i++;
        pi += pf;
    }
    i=0;
    j=1;
    for (int c=0; c < sz; c++) {
        res += s[i].first[s[i].second];
        s[i].second++;
        i += j;
        if (i == n) {
            j=-1;
            i -= 2;
        }
        if (i == -1) {
            j=1;
            i += 2;
        }
    }

    for (auto& x : s)
        cout << x.first << endl;

    return res;
}

int main(int argc, char* argv[]){

    setlocale(LC_ALL, "portuguese-brazilian");

    //const char* e = "0000000011011010011100000110000001111110100111110011111100000000000111011111111011111011111000000101100011111100000111110011101100000100000";
    string e2 = "less dangerous than coding";
    //vector<string> v {"I", "wish", "I", "hadn't", "come"};
    //int e = 1;

    string e1 = encode_rail_fence_cipher("Hello, World!", 3);

    cout << "Respota : " << e1 << endl;

    cout << "Respota : " << decode_rail_fence_cipher(e1,3) << endl;

    return 0;
}

