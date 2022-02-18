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

class ProdFib {
public:
  static std::vector<ull> productFib(ull prod) {

      vector<ull> Fib;

      Fib.push_back (0);
      Fib.push_back (1);
      ull i = 2;

      while (true) {

        Fib.push_back(Fib[i-1] + Fib[i-2]);

        if ((Fib[i]*Fib[i-1]) == prod)
            return {Fib[i], Fib [i-1], 1};

        if ((Fib[i]*Fib[i-1]) > prod)
            return {Fib[i], Fib [i-1], 0};

        i++;
      }
    return -1;
  }

};

int main(int argc, char* argv[]){

	setlocale(LC_ALL, "portuguese-brazilian");

	ProdFib F;

	vector<ull> r = F.productFib(714);

    cout << "Respota : ";

    for (auto& x : r)
        cout << x << " - ";

	return 0;
}
