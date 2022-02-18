#include <iostream>
#include <clocale>
#include <cstring>
#include <vector>

using namespace std;

class DiskSpace {

public:
    int minDrives(vector <int> used, vector <int> total) {

		int resp = 0;
		long usado = 0;

		for (int i = 1; i < total.size(); i++) {
   			 for (int j = 0; j < i; j++) {
        		if (total[i] > total[j]) {
            		int temp = total[i];
            		total[i] = total[j];
            		total[j] = temp;
        		}
    		}
		}

        for (int i=0; i < total.size(); i++)
        	usado += used[i];

		for (int i=0; i < total.size(); i++)
			if (usado > 0 ) {
				resp++;
				usado -= total[i];
			}

        return resp;
    }
};



int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "portuguese-brazilian");

	DiskSpace D;
	vector <int> used;
	used.push_back(300);
    used.push_back(525);
	used.push_back(115);
	vector <int> totals;
	totals.push_back(350);
	totals.push_back(600);
	totals.push_back(120);
    cout << "Resposta: " << D.minDrives(used, totals) << endl;

	return 0;
}
