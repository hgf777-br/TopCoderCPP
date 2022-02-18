#include <iostream>
#include <clocale>
#include <string>
#include <cstring>
#include <cfloat>

using namespace std;

class EvilCakeCutter {

public:
    double successProbability(int w, int h, int w1, int h1) {

    double resp = 0;
    double wc,hc;
    long cont = 0;
    long corte = 0;
        for (wc=0.0; wc <= (w-w1); wc+=0.0001)
            for (hc=0.0; hc <= (h-h1); hc+=0.0001){
                double cw = wc + w1;
                double ch = hc + h1;
                if (cw <= (double) w && ch <= (double) h) {
                    if ((cw+w1) <= (double) w && (ch) <= (double) h)
                        corte++;
                    if ((cw+w1) <= (double) w && (ch+h1) <= (double) h)
                        corte++;
                    if ((cw) <= (double) w && (ch+h1) <= (double) h)
                        corte++;
                    if ((wc-w1) >= 0.0 && (ch+h1) <= (double) h)
                        corte++;
                    if ((wc-w1) >= 0.0 && (ch) <= (double) h)
                        corte++;
                    if ((wc-w1) >= 0.0 && (hc-h1) >= 0.0)
                        corte++;
                    if ((cw) <= (double) w && (hc-h1) >= 0.0)
                        corte++;
                    if ((cw+w1) <= (double) w && (hc-h1) >= 0.0)
                        corte++;
                }
                cont++;
                cout << cw << " - " << ch << " - " << corte << " - " << cont << endl;
            }
    resp = (double) corte / cont;
    //if (resp < 0.01)
      //  resp = 0.0;

    return resp;
    }
};



int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "portuguese-brazilian");

    EvilCakeCutter E;

    double resp = E.successProbability(2,2,1,1);

    cout << resp << endl;

	return 0;
}
