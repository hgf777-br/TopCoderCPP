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
#include <stack>
#include <iomanip>

using namespace std;

bool IsOdd(int i) { return ((i%2)!=0); }
bool IsEven(int i) { return ((i%2)==0); }

bool ordem (int i, int j) {return (i<j);} // Reversa 1>j

typedef unsigned long long ull;
typedef long long ll;

string fSub (string x, string y) {
    //cout << x << "," << y << endl;
    size_t i=0,j=0;
    string r;
    bool ok = false;
    while(i < x.size()) {
        j=0;
        while (j < y.size()) {
            if(x[i] == y[j]) {
                r += x[i] + fSub(x.substr(i+1, string::npos),y.substr(j+1, string::npos));
                ok = true;
                break;
            }
            j++;
        }
        if (ok)
            break;
        i++;
    }
    return r;
}

#define MAX(a, b) (a > b ? a : b)

string lcs(const string& x, const string& y){
    string res;

    if (x == "" || y == "")
        return "";
    vector<int> m(y.size()+1,0);
    vector<vector<int>> n(x.size()+1,m);

    for (size_t i=0; i < x.size(); i++)
        for (size_t j=0; j < y.size(); j++)
            if (x[i] == y[j])
                n[i+1][j+1] = 1 + n[i][j];
            else
                n[i+1][j+1] = MAX(n[i+1][j], n[i][j+1]);

    for (size_t i=0; i < x.size()+1; i++){
        for (size_t j=0; j < y.size()+1; j++)
            cout << n[i][j] << " : ";
         cout << endl;
    }
    for (int i = x.size(), j = y.size(); i > 0 && j > 0; ) {
        if (x[i - 1] == y[j - 1]) {
            res += x[i - 1];
            i--;
            j--;
        } else
            if (n[i][j - 1] < n[i - 1][j])
                i--;
            else
                j--;
    }

    reverse(res.begin(), res.end());

    return res;
}
/*string lcs(const string& x, const string& y) {
    cout << "------------------------" << endl;
    cout << ">" << x << endl << endl << ">" << y << endl << endl;
    if (x == "" || y == "")
        return "";

    //bool ok = false;
    string res="";

    for (size_t i=0; i < x.size(); i++) {
        if ((x.substr(i,string::npos)).size() < res.size())
            break;
        size_t j=0;
        while(x[i] != y[j] && j < y.size())
            j++;
        if (j != y.size()) {
            if (x.size() == 1)
                res = x[i];
            for (size_t k=i+1; k < x.size(); k++) {
                string r = x[i] + fSub(x.substr(k,string::npos), y.substr(j,string::npos));
                cout << " x " << i << " : " << j << " : " << k << " : " << r << endl;
                if (r.size() > res.size())
                    res = r;
            }
        }
    }

    cout << "------------------------" << endl;
    cout << ">" << x << endl << endl << ">" << y << endl << endl;
    for (size_t i=0; i < y.size(); i++) {
        if ((y.substr(i,string::npos)).size() < res.size())
            break;
        size_t j=0;
        while(y[i] != x[j] && j < x.size())
            j++;
        if (j != x.size()) {
            if (y.size() == 1)
                res = y[i];
            for (size_t k=i+1; k < y.size(); k++) {
                string r = y[i] + fSub(y.substr(k,string::npos), x.substr(j+1,string::npos));
                cout << " y " << i << " : " << j << " : " << k << " : " << r << endl;
                if (r.size() > res.size())
                    res = r;
            }
        }
    }

    cout << res << " = " << endl << endl;
    return res;
}*/

int main(int argc, char* argv[]){

    //setlocale(LC_ALL, "portuguese-brazilian");

    //const char* e = "0000000011011010011100000110000001111110100111110011111100000000000111011111111011111011111000000101100011111100000111110011101100000100000";
    string e2 = "abcdef";//"apcdefghijklmnobq";
    //vector<string> v {};
    //int e = 1;

    string e1 = "abc";//"abcdefghijklmnopq";

    cout << "Respota : " << lcs(e1, e2) << endl;

    return 0;
}

