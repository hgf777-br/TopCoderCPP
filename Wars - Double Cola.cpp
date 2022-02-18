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


string who_is_next2(vector<string> names, long long r) {
    //cout << r << endl;
    int sz = names.size();
    vector<long long> qt(sz,1);
    long long i;
    int res=0;
    while(r > 0) {
        cout << res << " : " << qt[res] << endl;
        r -= qt[res];
        if (r<=0) {
            r += qt[res];
            i = qt[res];
            while(i > 0){
                r--;
                i--;
                if (r==0) {
                    if (res == 0)
                    res = sz-1;
                    else
                        res--;
                    break;
                }
            }
        }
        qt[res] *=2;
        res++;
        if (res == sz)
            res=0;
    }
  for (auto& x:qt)
        cout << x << endl;
  return names[res];
}

string who_is_next(vector<string> names, long long r) {
    int sz = names.size();
    int res=0;
    int i=0;
    while (r > 0) {
        r -= sz*pow(2,i);
        i++;
    }
    i--;
    r += sz*pow(2,(i));
    while (r > 0) {
        r-=pow(2,i);
        res++;
    }

  return names[--res];
}



int main(int argc, char* argv[]){

    setlocale(LC_ALL, "portuguese-brazilian");

    cout << "Resposta : " << who_is_next({ "Sheldon", "Leonard",
                                         "Penny", "Rajesh", "Howard" }, 7);

    return 0;
}
