#include <iostream>
#include <clocale>
#include <string>
#include <vector>

using namespace std;

std::vector<int> deleteNth(std::vector<int> arr, int n) {
    std::vector<int> resp = arr;
    int rep;
    int tam_arr = arr.size();
    int tot=0;
    if (n==0)
     return {};
    for (int i :arr){
        rep = 0;
        int tam_resp = resp.size();
        for (int j=0; j < (int) tam_resp; j++)
            if (i == resp[j]){
                if(rep < n)
                    rep++;
                else {
                    resp.erase(resp.begin()+(j-tot));
                    tot++;
                }
            }
    }

  return resp;
}



int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "portuguese-brazilian");

    vector<int> fotos = {1,2,3,1,2,1,2,3};
    vector<int> resp = deleteNth(fotos, 2);

    cout << "Respota" << endl;

    for (int i=0; i < (int) resp.size(); i++)
        cout << resp[i] << " - ";

	return 0;
}
