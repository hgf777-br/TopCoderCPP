#include <iostream>
#include <clocale>
#include <string>
#include <vector>

using namespace std;

std::string likes(const std::vector<std::string> &names) {

  std::string resp;
  int sz = names.size();
  if (sz == 0)
    return "no one likes this";
  switch (sz) {
    case 1: resp = names[0] + " likes this";
            break;
    case 2: resp = names[0] + " and " + names[1] + " like this";
            break;
    case 3: resp = names[0] + ", " + names[1] + " and " + names[2] + " like this";
            break;
    //default: resp = names[0] + ", " + names[1] + " and " + to_string(sz-2) + " others like this";
  }
  return resp; // Do your magic!
}


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "portuguese-brazilian");

    vector<string> names = {"Peter"};
    string resp = likes(names);

    cout << "Respota : " << resp << endl;

	return 0;
}
