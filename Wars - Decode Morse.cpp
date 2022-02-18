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

string decodeBitsAdvanced2 (const char *b) {
    //cout << b << endl;
    string res;
    vector<int> d,p;
    int x=0,y=0,i=0;
    double dm=0,pm=0;
    int sz = (int) strlen(b);

    if (sz == 0)
        return "";
    //cout << sz << endl;
    while (b[i] == '0') {
        i++;
        if (i == sz)
            return "";
    }
    for (;i < sz; i++) {
        if (b[i] == '1') {
            x++;
            if (b[i+1] == '0' || (i+1) == sz) {
                d.push_back(x);
                dm += x;
                x=0;
            }
        } else {
            y++;
            if (b[i+1] == '1' || (i+1) == sz) {
                p.push_back(y);
                pm += y;
                y=0;
            }
        }
    }

    dm /= (double) d.size();
    pm /= (double) p.size();
    cout << endl;
    cout << dm << ":" << d.size() << " | " << pm << ":" << p.size() << endl;
    x=y=0;
    while (x < d.size() && y < d.size()) {
        if(x < d.size()) {
            if(d[x] <= dm)
                res += ".";
            else
                res += "-";
            x++;
        }
        if(y < p.size()) {
            if(p[y] <= pm)
                res += "";
            else if (p[y] <= pm*2)
                res += "@";
            else
                res += "@@@";
            y++;
        }
    }

    for (auto& x:d)
        cout << x << "*";
    cout << endl;
    for (auto& x:p)
        cout << x << "#";
    cout << endl;
    cout << res << endl;
    return res;
}

string decodeBitsAdvanced (const char *b) {
    cout << "Teste :" << b << endl;
    string res;
    vector<int> d,p;
    int x=0,y=0,i=0;
    double dm=0,pm=0;
    int dp=1,dd=100;
    int sz = (int) strlen(b);

    if (sz == 0)
        return "";
    //cout << sz << endl;
    while (b[i] == '0') {
        i++;
        if (i == sz)
            return "";
    }
    for (;i < sz; i++) {
        if (b[i] == '1') {
            x++;
            if (b[i+1] == '0' || (i+1) == sz) {
                d.push_back(x);
                dm += x;
                x=0;
            }
        } else {
            y++;
            if (b[i+1] == '1' || (i+1) == sz) {
                p.push_back(y);
                pm += y;
                y=0;
            }
        }
    }

    dm /= (double) d.size();
    pm /= (double) p.size();
    cout << endl;
    if (d.size() > 1) {
        int sum = accumulate(d.begin(), d.end(), 0, [&dm](int x, int y) {return y<=dm ? x+y : x;});
        int cnt = count_if(d.begin(), d.end(), [&dm](int x) {return x<=dm;});
        dm = ceil((double) sum/cnt);
        cout << sum << " / " << cnt << " / " << dm <<  endl;
    }
    if (p.size() > 1) {
        int sum = accumulate(p.begin(), p.end(), 0, [&pm](int x, int y) {return y<=pm ? x+y : x;});
        int cnt = count_if(p.begin(), p.end(), [&pm](int x) {return x<=pm;});
        pm = ceil((double) sum/cnt);
        cout << sum << " / " << cnt << " / " << dm <<  endl;
    }
    cout << dm << ":" << d.size() << " | " << pm << ":" << p.size() << endl;
    x=y=0;
    while (x < d.size() && y < d.size()) {
        if(x < d.size()) {
            if(d[x] <= (dm+1))
                res += ".";
            else
                res += "-";
            x++;
        }
        if(y < p.size()) {
            if(p[y] <= (pm+1))
                res += "";
            else if (p[y] <= pm*3)
                res += " ";
            else
                res += "   ";
            y++;
        }
    }

    for (auto& x:d)
        cout << x << " ";
    cout << endl;
    for (auto& x:p)
        cout << x << " ";
    cout << endl;

    return res;
}


int main(int argc, char* argv[]){

    setlocale(LC_ALL, "portuguese-brazilian");

    const char* e = "0000000011011010011100000110000001111110100111110011111100000000000111011111111011111011111000000101100011111100000111110011101100000100000";
    //string e2 = "less dangerous than coding";
    //vector<string> v {"I", "wish", "I", "hadn't", "come"};
    //int e = 1;

    cout << "Resposta : " << decodeBitsAdvanced(e) << endl;


    return 0;
}
