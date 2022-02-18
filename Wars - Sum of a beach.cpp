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

int sum_of_a_beach2(string s) {
    for (auto& x : s)
        x=tolower(x);
    cout << s << endl;
    int res=0;
    size_t pal;
    vector<string> name {"sand", "water", "fish", "sun"};
    for (auto& x : name) {
        int pos=0;
        while (true) {
            pal = s.find(x,pos);
            if (pal != string::npos){
                res++;
                s.erase(pal,x.size());
                pos = pal;
                cout << s << endl;
            } else {
                break;
            }
        }
    }
    return res;
}

int sum_of_a_beach(string s) {
    int res = 0;

    regex rex ("sand|Sun|water|fish", regex_constants::icase);

    regex_iterator<string::iterator> rit (s.begin(), s.end(), rex);
    regex_iterator<string::iterator> rend;

    while (rit!=rend) {
    cout << rit->str() << endl;
    rit++;
    res++;
  }
    return res;
}

int main(int argc, char* argv[]){

    setlocale(LC_ALL, "portuguese-brazilian");

    string e = "sandsandwaterwaterfishfishsunsunsandwater";

    cout << "Resposta : " << sum_of_a_beach(e);

    return 0;
}
