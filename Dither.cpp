#include <iostream>
#include <clocale>
#include <string>
#include <vector>

using namespace std;

class ImageDithering {

public:
    int count(string dithered, vector <string> screen) {
        int resp = 0;

        for (int i=0; i < screen.size(); i++)
            for(int j=0; j < screen[i].size(); j++)
                for (int k=0; k < dithered.size(); k++)
                    if (screen[i][j] == dithered[k])
                        resp++;


        return resp;
    }
};



int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "portuguese-brazilian");

	string dithered = "BW";

	vector <string> screen;
	screen.push_back("BBBBBBBB");
    screen.push_back("BBWBWBWB");
	screen.push_back("BWBWBWBB");
    screen.push_back("BBWBWBWB");
	screen.push_back("BWBWBWBB");
    screen.push_back("BBWBWBWB");
	screen.push_back("BWBWBWBB");
	screen.push_back("BBBBBBBB");

    ImageDithering Img;

    cout << "Cores = " << Img.count("BW", screen);
	return 0;
}
