#include <iostream>
#include <clocale>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <cctype>
#include <numeric>
#include <algorithm>
#include <map>
#include <sstream>
#include <regex>
#include <sstream>
#include <functional>

using namespace std;

bool IsOdd(int i) { return ((i%2)!=0); }
bool IsEven(int i) { return ((i%2)==0); }

bool ordem (int i, int j) {return (i<j);} // Reversa 1>j

typedef unsigned long long ull;
typedef long long ll;


long parse_int2(string n) {
    long res = 0;
    vector<pair<string, long>> w {{"zero",0}, {"one",1}, {"two",2}, {"three",3}, {"four",4}, {"five",5}, {"six",6}, {"seven",7}, {"eight",8}, {"nine",9},
    {"ten",10}, {"twenty",20}, {"thirty",30}, {"forty",40}, {"fifty",50}, {"sixty",60}, {"seventy",70}, {"eighty",80}, {"ninety",90}, {"hundred", 100},
    {"thousand",1000}, {"million",1000000}, {"eleven",11}, {"twelve",12}, {"thirteen",13}, {"fourteen",14}, {"fifteen",15}, {"sixteen",16}, {"seventeen",17},
    {"eighteen",18}, {"nineteen",19}};

    regex e ("([a-z]+(?=[-]) )|([a-z]+)");
    smatch m;
    regex_iterator<string::iterator> rit ( n.begin(), n.end(), e );
    regex_iterator<std::string::iterator> rend;
    string tmp;
    long last;
    vector<pair<string,long>>::iterator it;

    while (rit!=rend) {
        tmp = rit->str();
        it = find_if( w.begin(), w.end(),[&tmp](const pair<string,long>& v){ return v.first == tmp;});
        if (tmp != "and") {
            if (tmp == "hundred" || tmp == "thousand" || tmp == "million") {
                res -=last;
                res += last*it->second;
            } else {
                res += it->second;
            }
        }
        last = it->second;
        ++rit;
    }
    return res;
}

long parse_int(string n) {
    long res = 0;
    vector<pair<string, long>> w {{"zero",0}, {"one",1}, {"two",2}, {"three",3}, {"four",4}, {"five",5}, {"six",6}, {"seven",7}, {"eight",8}, {"nine",9},
    {"ten",10}, {"twenty",20}, {"thirty",30}, {"forty",40}, {"fifty",50}, {"sixty",60}, {"seventy",70}, {"eighty",80}, {"ninety",90}, {"hundred", 100},
    {"thousand",1000}, {"million",1000000}, {"eleven",11}, {"twelve",12}, {"thirteen",13}, {"fourteen",14}, {"fifteen",15}, {"sixteen",16}, {"seventeen",17},
    {"eighteen",18}, {"nineteen",19}};
    string tmp;
    int mul=1;
    int p=(int) n.size();
    vector<pair<string,long>>::iterator it;

    for (int i= (int) n.size(); i > 0; i--) {
        if (n[i] == ' ' || n[i] == '-' || i == 1) {
            if (i==1) i = -1;
            tmp = n.substr(i+1,p-i);
            it = find_if( w.begin(), w.end(),[&tmp](const pair<string,long>& v){ return v.first == tmp;});
            //cout << tmp << ":" << it->second << endl;
            p = i-1;
            if (tmp != "and") {
                if (tmp == "hundred" || tmp == "thousand" || tmp == "million") {
                    if (it -> second > mul)
                        mul = it -> second;
                    else
                        mul *= it -> second;
                } else {
                    res+= it->second * mul;
                }
            }
        }
    }
    return res;
}

int main(int argc, char* argv[]){

    setlocale(LC_ALL, "portuguese-brazilian");

    string e = "six hundred sixty-six thousand six hundred sixty-six";
    //string e2 = "less dangerous than coding";
    //vector<string> v {"I", "wish", "I", "hadn't", "come"};
    //int e = 1;

    cout << "Resposta : " << parse_int(e) << endl;;


    return 0;
}
