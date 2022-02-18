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
#include <set>
#include <stack>
#include <iomanip>

using namespace std;

bool IsOdd(int i) { return ((i%2)!=0); }
bool IsEven(int i) { return ((i%2)==0); }

bool ordem (int i, int j) {return (i<j);} // Reversa 1>j

typedef unsigned long long ull;
typedef long long ll;

vector<string> expr_fila (string sub) {
    vector<string> fi;

    for(size_t i=0; i < sub.size(); i++) {
        size_t j=0,k=0;
        string tmp;
        if (isspace(sub[i]))
            continue;
        if (isdigit(sub[i])) {
            j = i + 1;
            while(isdigit(sub[j]) || sub[j] == '.')
                j++;
            fi.push_back(sub.substr(i,j-i));
            i = j - 1;
            continue;
        }

        switch (sub[i]) {
            case '+':
                j = i + 1;
                while(isspace(sub[j]))
                    j++;
                k = j;
                if (sub[j] == '-' || isdigit(sub[j])) {
                    j++;
                    if (sub[j] == '-'){
                        j++;
                        k = j;
                    }
                    while(isdigit(sub[j]) || sub[j] == '.')
                        j++;
                }
                fi.push_back(sub.substr(k,j-k));
                fi.push_back("+");
                i = j - 1;
                break;

            case '-':
                j = i + 1;
                while(isspace(sub[j]))
                    j++;
                k = j;
                if (sub[j] == '-' || isdigit(sub[j])) {
                    j++;
                    while(isdigit(sub[j]) || sub[j] == '.')
                        j++;
                }
                if (k == i + 1 && sub[k] != '-') {
                    fi.push_back("-" + sub.substr(k,j-k));
                } else {
                    fi.push_back(sub.substr(k,j-k));
                    fi.push_back("-");
                }
                i = j - 1;
                break;

            case '*':
                j = i + 1;
                while(isspace(sub[j]))
                    j++;
                k = j;
                if (sub[j] == '-' || isdigit(sub[j])) {
                    j++;
                    if (sub[j] == '-'){
                        j++;
                        k = j;
                    }
                    while(isdigit(sub[j]) || sub[j] == '.')
                        j++;
                }
                tmp = fi.back();
                if (tmp == "+" || tmp == "-") {
                    fi.pop_back();
                    fi.push_back(sub.substr(k,j-k));
                    fi.push_back("*");
                    fi.push_back(tmp);
                } else {
                    fi.push_back(sub.substr(k,j-k));
                    fi.push_back("*");
                }
                i = j - 1;
                break;

             case '/':
                j = i + 1;
                while(isspace(sub[j]))
                    j++;
                k = j;
                if (sub[j] == '-' || isdigit(sub[j])) {
                    j++;
                    if (sub[j] == '-'){
                        j++;
                        k = j;
                    }
                    while(isdigit(sub[j]) || sub[j] == '.')
                        j++;
                }
                tmp = fi.back();
                if (tmp == "+" || tmp == "-") {
                    fi.pop_back();
                    fi.push_back(sub.substr(k,j-k));
                    fi.push_back("/");
                    fi.push_back(tmp);
                } else {
                    fi.push_back(sub.substr(k,j-k));
                    fi.push_back("/");
                }
                i = j - 1;
                break;
        }

    }
    return fi;
}

double rpn (vector<string> fi) {
    stack<double> st;
    double tmp, tmp2;
    for (auto& x : fi) {
        if (x == "*") {
            tmp = st.top();
            st.pop();
            tmp *= st.top();
            st.pop();
            st.push(tmp);
        } else if (x == "/") {
            tmp = st.top();
            st.pop();
            tmp2= st.top();
            st.pop();
            st.push(tmp2/tmp);
        } else if (x == "+") {
            tmp = st.top();
            st.pop();
            tmp += st.top();
            st.pop();
            st.push(tmp);
        } else if (x == "-") {
            tmp = st.top();
            st.pop();
            if (st.size() == 0) {
                st.push(-tmp);
            } else {
            tmp2 = st.top();
            st.pop();
            st.push(tmp2 - tmp);
            }
        } else {
            st.push(stod(x));
        }
    }
    if (st.size() > 1) {
        tmp = st.top();
        st.pop();
        return st.top() + tmp;
    } else
        return st.top();
}

double calc(string exp) {
    cout << exp << endl << endl;
    double res;
    string tmp;
    int pa = 0;
    stringstream stream;
    vector<pair<int,int>> par;
    vector<string> fila;
    size_t sz = exp.size();
    for(size_t i=0; i < sz; i++) {
        if(exp[i] == '(') {
            par.push_back({i,0});
        }
        if (exp[i] == ')') {
            pa = par.size()-1;
            while (par[pa].second != 0)
                pa--;
            par[pa].second = i;
        }
    }

    if (!par.empty()) {
        for (size_t i = 0; i < par.size(); i++)
            cout << i << " : " << par[i].first << " , " << par[i].second << endl;
        cout << endl;
        for (int i = (par.size()-1); i >= 0; i--) {
            int tam_par = par[i].second - (par[i].first + 1);
            fila = expr_fila(exp.substr((par[i].first + 1), tam_par));
            res = rpn(fila);
            stream << fixed << setprecision(12) << res;
            tmp = stream.str();
            stream.str("");
            cout << tmp.size() << endl;
            exp.replace(par[i].first, (tam_par + 2), tmp);
            for (int j = i-1; j >=0; j--) {
                if (par[j].first > par[i].first)
                    par[j].first += (tmp.size() - (tam_par + 2));
                if (par[j].second > par[i].second)
                    par[j].second += (tmp.size() - (tam_par + 2));
            }
            cout  << i << " : " << exp << endl;
        }
    }

    fila = expr_fila(exp);

    for(auto& x : fila)
        cout << x << endl;

    res = rpn(fila);




    return res;
}

int main(int argc, char* argv[]){

    //setlocale(LC_ALL, "portuguese-brazilian");

    //const char* e = "0000000011011010011100000110000001111110100111110011111100000000000111011111111011111011111000000101100011111100000111110011101100000100000";
    //string e2 = "less dangerous than coding";
    //vector<string> v {"I", "wish", "I", "hadn't", "come"};
    //int e = 1;

    string e1 = "10- 2- -5";

    cout << "Respota : " << fixed << setprecision(12) << calc(e1) << endl;

    return 0;
}

