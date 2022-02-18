#include <iostream>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <cctype>
#include <numeric>
#include <algorithm>

using namespace std;

bool IsOdd(int i) { return ((i%2)!=0); }
bool IsEven(int i) { return ((i%2)==0); }

int FindOutlier(std::vector<int> arr)
{
    vector<int>::iterator rs;

    int ct = count_if(arr.begin(), arr.end(), IsOdd);
    if (ct == 1)
        rs = find_if(arr.begin(), arr.end(), IsOdd);
    else
        rs = find_if(arr.begin(), arr.end(), IsEven);

    return *rs;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "portuguese-brazilian");

    vector<int> e = {2, -6, 8, -10, -3};
    //vector<int> e {4, 1, 3, 5, 9};

	int r = FindOutlier(e);

    cout << "Respota : " << r << endl;


	return 0;
}
