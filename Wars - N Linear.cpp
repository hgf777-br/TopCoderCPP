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

uint32_t n_linear(const set<uint32_t>& m, size_t n) {
    set<uint64_t> v {1};
    set<uint64_t>::iterator it;
    //pair<set<uint32_t>::iterator,bool> ret;
    it = v.begin();
    //uint64_t tmp;
    size_t r = n < 2000 ? n : n/2 + n/8;
    cout << r << endl;
    for (size_t i=0; i < r; i++) {
        for (const uint32_t& x:m) {
            //tmp = x * *it + 1;
            v.insert(x * *it + 1);
            //cout << tmp << endl;
        }
        it++;
        v.erase(v.begin());
    }
    //int i=0;
    //for (auto& x:v) {
    //    cout << i++ << ":" << x << endl;
    //}
    for (size_t i =0; i < (n-r); i++)
            it++;
    return *it;

}

int main(int argc, char* argv[]){

    setlocale(LC_ALL, "portuguese-brazilian");

    //const char* e = "0000000011011010011100000110000001111110100111110011111100000000000111011111111011111011111000000101100011111100000111110011101100000100000";
    //string e2 = "less dangerous than coding";
    //vector<string> v {"I", "wish", "I", "hadn't", "come"};
    //int e = 1;
    set<uint32_t> m {2,3,10000002};
    size_t n = 2000000;
    //set<uint32_t> m {8,12,14};
    //size_t n = 297;
    cout << "Resposta : " << n_linear(m,n) << endl;


    return 0;
}

