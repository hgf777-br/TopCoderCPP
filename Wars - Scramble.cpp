#include <iostream>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <cctype>
#include <numeric>
#include <algorithm>
#include <map>

using namespace std;

bool IsOdd(int i) { return ((i%2)!=0); }
bool IsEven(int i) { return ((i%2)==0); }

bool scramble(const std::string& s1, const std::string& s2){
  map <char, int> m;
  for (auto& i : s1)
    m[i] = count(s1.begin(), s1.end(), i);
  for (auto& x : s2) {
    if (m[x]) {
        if (m[x] > 0)
            m[x]--;
        else
            return false;
    } else
            return false;
  }
  return true;
}

/*
bool scramble(const std::string& s1, const std::string& s2){
string p1 = s1;
  size_t sz = p1.size();
  size_t r = s2.size();
  for (const char& x : s2) {
      for (size_t i=0; i < sz; i++) {
          if (x == p1[i]) {
              //p1[i] = ' ';
              p1.erase(i,1);
              r--;
              break;
          }
      }
  }
  if (r == 0)
      return true;
*/
/*
size_t f = s1.find_first_of(s2);
    while (f != string::npos) {
        cout << s1[f] << endl;
        f = s1.find_first_of(s2, f+1);
*/
/*
bool scramble(const std::string& s1, const std::string& s2){

    string s3 = s1;
    string s4 = s2;
    sort(s3.begin(),s3.end());
    sort(s4.begin(),s4.end());
    s3 = s3.substr(0,s4.size());
    cout << s3 << endl;
    cout << s4 << endl;

    return (s3 == s4);
}
*/

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "portuguese-brazilian");

    //vector<int> e = {2, -6, 8, -10, -3};
    //vector<int> e {4, 1, 3, 5, 9};
    //scramble("rkqodlw", "world"), Equals(true));
    //scramble("cedewaraaossoqqyt", "codewars"), Equals(true));
    //scramble("katas", "steak"), Equals(false));
    //scramble("scriptjavx", "javascript"), Equals(false));
    //scramble("scriptingjava", "javascript"), Equals(true));
    //scramble("scriptsjava", "javascript"), Equals(true));
    //scramble("javscripts", "javascript"), Equals(false));
    //scramble("aabbcamaomsccdd", "commas"), Equals(true));
    //scramble("commas", "commas"), Equals(true));
    //scramble("sammoc", "commas"), Equals(true));


	bool r = scramble("rkqodlw", "world");

    cout << "Respota : " << r << endl;


	return 0;
}
