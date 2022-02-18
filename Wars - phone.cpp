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

string phone(const string& dr, string num) {
        size_t f = dr.find(num);
        string res = "";
        if (f == string::npos)
          return "Error => Not found: " + num;
        size_t g = dr.find(num,f+1);
        if (g != string::npos)
          return "Error => Too many people: " + num;
        res += "Phone => " + num;
        size_t b = dr.find_last_of("/\n",f);
        size_t e = dr.find("\n",f);
        size_t n1 = dr.find("<",b);
        size_t n2 = dr.find(">",n1);
        res += ", Name => " + dr.substr(n1+1,n2-n1-1);
        string adr = dr.substr(b,e-b);
        //cout << "1 - " << adr<< endl;
        adr.erase(n1-b,n2-n1+2);
        //cout << "2 - " << adr<< endl;
        if (n1 < f)
            adr.erase(f-(n2-n1+2)-b-1,num.size()+1);
        else
            adr.erase(f-b-1,num.size()+1);
        //cout << "3 - " << adr<< endl;
        regex ei (";|\\$|\\?|,| _");
        adr = regex_replace(adr, ei, "");
        regex ex ("^[^\\w]+|[\\s]+$");
        adr = regex_replace(adr, ex, "");
        regex es ("\\s+|_");
        adr = regex_replace(adr, es, " ");
        //cout << "4 - " << adr<< endl;
        res += ", Address => " + adr;
        cout << b << " : " << f << " : " << e << endl;
        return res;
    }

int main(int argc, char* argv[]){

    setlocale(LC_ALL, "portuguese-brazilian");

    string e = "/+1-541-754-3010 156 Alphand_St. <J Steeve>\n 133, Green, Rd. <E Kustur> NY-56423 ;+1-541-914-3010\n"
    "+1-541-984-3012 <P Reed> /PO Box 530; Pollocksville, NC-28573\n :+1-321-512-2222 <Paul Dive> Sequoia Alley PQ-67209\n"
    "+1-741-984-3090 <Peter Reedgrave> _Chicago\n :+1-921-333-2222 <Anna Stevens> Haramburu_Street AA-67209\n"
    "+1-111-544-8973 <Peter Pan> LA\n +1-921-512-2222 <Wilfrid Stevens> Wild Street AA-67209\n"
    "<Peter Gone> LA ?+1-121-544-8974 \n <R Steell> Quora Street AB-47209 +1-481-512-2222\n"
    "<Arthur Clarke> San Antonio $+1-121-504-8974 TT-45120\n <Ray Chandler> Teliman Pk. !+1-681-512-2222! AB-47209,\n"
    "<Sophia Loren> +1-421-674-8974 Bern TP-46017\n <Peter O'Brien> High Street +1-908-512-2222; CC-47209\n"
    "<Anastasia> +48-421-674-8974 Via Quirinal Roma\n <P Salinger> Main Street, +1-098-512-2222, Denver\n"
    "<C Powel> *+19-421-674-8974 Chateau des Fosses Strasbourg F-68000\n <Bernard Deltheil> +1-498-512-2222; Mount Av.  Eldorado\n"
    "+1-099-500-8000 <Peter Crush> Labrador Bd.\n +1-931-512-4855 <William Saurin> Bison Street CQ-23071\n"
    "<P Salinge> Main Street, +1-098-512-2222, Denve\n"
    "<P Salinge> Main Street, +1-098-512-2222, Denve\n"
    "/+5-541-754-3010 156 Alphandria_Street. <Jr Part>\n 1333, Green, Road <F Fulgur> NW-46423 ;+6-541-914-3010!\n"
    "+5-541-984-3012 <Peter Reeves> /PO Box 5300; Albertville, SC-28573\n :+5-321-512-2222 <Paulo Divino> Boulder Alley ZQ-87209\n"
    "+3-741-984-3090 <F Flanaghan> _Chicago Av.\n :+3-921-333-2222 <Roland Scorsini> Bellevue_Street DA-67209\n"
    "+8-111-544-8973 <Laurence Pantow> SA\n +8-921-512-2222 <Raymond Stevenson> Joly Street EE-67209\n"
    "<John Freeland> Mantow ?+2-121-544-8974 \n <Robert Mitch> Eleonore Street QB-87209 +2-481-512-2222?\n"
    "<Arthur Paternos> San Antonio $+7-121-504-8974 TT-45121\n <Ray Charles> Stevenson Pk. !+7-681-512-2222! CB-47209,\n"
    "<JP Gorce> +9-421-674-8974 New-Bern TP-16017\n <P McDon> Revolution Street +2-908-512-2222; PP-47209\n"
    "<Elizabeth Corber> +8-421-674-8974 Via Papa Roma\n <C Saborn> Main Street, +15-098-512-2222, Boulder\n"
    "<Colin Marshall> *+9-421-674-8974 Edinburgh UK\n <Bernard Povit> +3-498-512-2222; Hill Av.  Cameron\n"
    "+12-099-500-8000 <Pete Highman> Ontario Bd.\n +8-931-512-4855 <W Mount> Oxford Street CQ-23071\n"
    "<Donald Drinkaw> Moon Street, +3-098-512-2222, Peterville\n";

    //int e = 1;

    cout << "Resposta : " << phone(e, "1-421-674-8974");

    return 0;
}