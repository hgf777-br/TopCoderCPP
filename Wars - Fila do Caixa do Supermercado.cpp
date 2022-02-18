#include <iostream>
#include <clocale>
#include <string>
#include <vector>

using namespace std;

long queueTime(std::vector<int> customers,int n) {
    int tam = customers.size();
    if (tam == 0 || n == 0)
        return 0;
    int tills[n];
    for (int i=0; i < n; i++)
        tills[i]=0;
    tills[0] = customers[0];
    long resp = customers[0];
    for (int i=1; i < tam; i++){
        if (n == 1)
            resp += customers[i];
        else {
            int till=0;
            int minimo = tills[0];
            for (int j=1; j < n; j++)
                if (tills[j] < minimo) {
                        till = j;
                        minimo = tills[j];
                }

        tills[till] += customers[i];
        }
    }
    if (n != 1) {
        resp = tills[0];
        for (int i=1; i < n; i++)
            if (resp < tills[i])
                resp = tills[i];
    }
  return resp;
}


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "portuguese-brazilian");



    cout << "Respota = " << queueTime({12,7,3,14,1,6,2,5,33,2,13,4,1,12},5);
	return 0;
}
