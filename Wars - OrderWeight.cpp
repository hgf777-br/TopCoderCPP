#include <iostream>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <cctype>
#include <numeric>
#include <algorithm>
#include <map>

using namespace std;

bool IsOdd(int i) { return ((i%2)!=0); }
bool IsEven(int i) { return ((i%2)==0); }

bool ordem (int i, int j) {
    return (IsEven(i) || IsEven(j)) ? false : (i<j);
}

typedef unsigned long long ull;

class WeightSort
{
public:
    static std::string orderWeight(const std::string &s) {

        if (s == "")
          return "";

        vector<ull> n;
        vector<ull> soma;
        string r = "";
        size_t i = s.find_first_not_of(" ");

        if (i == string::npos)
            return "";

        size_t p = s.find_first_not_of("1234567890",i);
        while (p != string::npos) {
            n.push_back(stoull(s.substr(i,(p-i))));
            i = s.find_first_not_of(" ",p);
            p = s.find_first_not_of("1234567890",i);
        }

        if (i < s.size())
            n.push_back(stoull(s.substr(i,(p-i))));

        for (auto x : n){
            int t=0;
            int log = (log10(x)+1);
            for (int i=0; i < log; i++) {
                t += x%10;
                x /= 10;
            }
            soma.push_back(t);
        }

        for(int i = (soma.size()-1); i >= 0; i--) {
            for(int j = 1; j <= i; j++) {
                if(soma[j - 1] > soma[j]) {
                    int aux = soma[j - 1];
                    soma[j - 1] = soma[j];
                    soma[j] = aux;
                    aux = n[j-1];
                    n[j - 1] = n[j];
                    n[j] = aux;
                }
                if(soma[j - 1] == soma[j]) {
                        string saux1 = to_string(n[j - 1]);
                        string saux2 = to_string(n[j]);
                        if ((saux1.compare(saux2)) > 0) {
                            int aux = soma[j - 1];
                            soma[j - 1] = soma[j];
                            soma[j] = aux;
                            aux = n[j-1];
                            n[j - 1] = n[j];
                            n[j] = aux;
                        }
                }
            }
        }


        for (size_t i=0; i < (n.size()-1); i++)
            r += to_string(n[i]) + " ";

        r += to_string(n[n.size()-1]);

       return r;
    }
};

int main(int argc, char* argv[]){

	setlocale(LC_ALL, "portuguese-brazilian");

	WeightSort W;

	string e = " 2000 10003 1234000 44444444 9999 11 11 22 123 ";

	string r = W.orderWeight(e);

    cout << "Respota : " << r;

    return 0;
}
