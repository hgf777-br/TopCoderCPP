#include <iostream>
#include <clocale>
#include <cstring>
#include <vector>

using namespace std;

class RectangularGrid {

public:
    long long countRectangles(int width, int height){

        long long resp = 0;

            for (int i=1; i <= width; i++)
                for (int j=1; j <= height; j++)
                        if (i != j)
                            resp += (width - i + 1) * (height -j +1);

        return resp;
    }
};


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "portuguese-brazilian");

	RectangularGrid R;
	int x,y;

	while (true) {
	cout << "x: ";
	cin >> x;
	cout << "y: ";
	cin >>
	 y;

    cout << "Resposta: " << R.countRectangles(x,y) << endl;

	};
	return 0;
};
