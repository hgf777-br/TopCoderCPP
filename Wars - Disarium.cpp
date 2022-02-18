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

string disariumNumber (int n )
{
  int x = n;
  vector<int> v;
  int r=0;
  while (x > 0) {
    v.push_back(x%10);
    x = x/10;
  }
  int sz = v.size();
  for (int i=sz; i > 0; i--) {
    r += pow(v[sz-i],i);
  }

  return n == r ? "Disarium !!" : "Not !!" ;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "portuguese-brazilian");



	string r = disariumNumber(89);

    cout << "Respota : " << r << endl;

    int i=1;
    while (i < 1000000000) {
        int l = log10(i) + 1;
        cout << i << " = "<< l << endl;
        i += 5*i;
    }
	return 0;
}
