#include <iostream>
#include <clocale>
#include <string>
#include <vector>

using namespace std;

int countSmileys(std::vector<std::string> arr) {
    int resp = 0;

    for (auto x : arr) {
        int sz = x.size();
        if ((sz == 3) && (x[0] == ':' || x[0] == ';') && (x[1] == '-' || x[1] == '~') && (x[2] == ')' || x[2] == 'D'))
            resp++;
        if ((sz == 2) && (x[0] == ':' || x[0] == ';') && (x[1] == ')' || x[1] == 'D'))
            resp++;
    }
    return resp;
  }


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "portuguese-brazilian");

    vector<string> fotos = {":D", ":~)", ";~)", ":)"};
    int resp = countSmileys(fotos);

    cout << "Respota : " << resp << endl;

	return 0;
}
