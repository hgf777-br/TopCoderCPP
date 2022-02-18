#include <iostream>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <cctype>

using namespace std;
// Mais lenta
std::vector<unsigned long long> partsSum(const std::vector<unsigned long long>& ls){
  int i=0;
  int tam = ls.size();
  std::vector<unsigned long long> r(tam);
  for (int j=0; j < tam; j++) {
    for (int k=i; k < tam; k++)
      r[j] += ls[k];
    i++;
  }

  return r;
}

 // Mais rapida
std::vector<unsigned long long> partsSum(const std::vector<unsigned long long>& ls){
  int tam = ls.size();
  std::vector<unsigned long long> r(tam+1);
  for (int j=0; j < tam; j++)
    r[0] += ls[j];
  for (int j=1; j < tam; j++)
      r[j] = r[j-1] - ls[j-1];
  r[tam] = 0;

  return r;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "portuguese-brazilian");

	std::vector<unsigned long long> e = {1, 2, 3, 4, 5, 6};

	std::vector<unsigned long long> r = partsSum(e);

    cout << "Respota : " << endl;

    for (auto x:r)
        cout << x << endl;

	return 0;
}
