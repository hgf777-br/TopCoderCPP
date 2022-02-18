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

class LoopsyDoopsy2 {
public:
    string getSmallestNumber(int loops){
        if (loops == 1)
            return "0";
        int dig[] = {1,0,0,0,1,0,1,0,2,1};
        int num = 8;
        while (true) {
            int nloops = 0;
            int tst = num;
            for (int k = log10(num)+1; k > 0; k--){
                for (int i=0; i < 10; i++)
                    if (i == (tst%10))
                        nloops += dig[i];
                tst /= 10;
            }
            if (nloops == loops)
                break;
            num++;
        }
        return to_string(num);
    }
};

class LoopsyDoopsy {
public:
    string getSmallestNumber(int loops){
        if (loops == 1)
            return "0";
        string res;
        if (IsEven(loops))
            for (int i=0; i < (loops/2); i++)
                res.push_back('8');
        else {
            res.push_back('4');
            for (int i=0; i < ((loops/2)-1); i++)
                res.push_back('8');
        }

        return res;
    }
};

int main(int argc, char* argv[]){

	setlocale(LC_ALL, "portuguese-brazilian");

    LoopsyDoopsy L;

    cout << "Resposta : " << L.getSmallestNumber(2);


    return 0;
}
