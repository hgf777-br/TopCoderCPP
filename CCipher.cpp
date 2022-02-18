#include <iostream>
#include <clocale>
#include <string>
#include <vector>

using namespace std;

class CCipher {

public:
    string decode(string cT, int shift) {

		string resp;
		char t;
		int size = cT.size();

        for (int i=0; i < size; i++) {
            t = cT[i] - shift;
            if (t < 'A') t = t + 26;
            resp += t;
        }

        return resp;
    }
};



int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "portuguese-brazilian");



	return 0;
}
