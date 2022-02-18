#include <iostream>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <cctype>
#include <numeric>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;

bool IsOdd(int i) { return ((i%2)!=0); }
bool IsEven(int i) { return ((i%2)==0); }

bool ordem (int i, int j) {
    return (IsEven(i) || IsEven(j)) ? false : (i<j);
}

typedef unsigned long long ull;

constexpr array<pair<int, int>, 8> adj8 {{
  {-1,-1}, {-1, 0}, {-1, 1},
  { 0,-1},/*{0,0},*/{ 0, 1},
  { 1,-1}, { 1, 0}, { 1, 1}
}};

int directions[8][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1},
                          {-1, -1}, {-1, 1}, {1, -1}, {1, 1}}

bool checar(const vector<vector<char>>& board, vector<vector<int>>& n, int i, int j, int xs, int ys, const string& word, int k) {
    //cout << "CH ->" << word[k] << " - " << board[i][j] << " - " << n[i][j] << endl;
    if (k+1 == (int) word.size())
        return true;

    if ((i+1) < xs && word[k+1] == board[i+1][j] && n[i+1][j] == 0) {
        n[i+1][j] = 1;
        if (checar(board,n,i+1,j,xs,ys,word,k+1))
            return true;
        else
           n[i+1][j] = 0;
    }
    if ((i+1) < xs && (j+1) < ys && word[k+1] == board[i+1][j+1] && n[i+1][j+1] == 0) {
        n[i+1][j+1] = 1;
        if (checar(board,n,i+1,j+1,xs,ys,word,k+1))
            return true;
        else
            n[i+1][j+1] = 0;
    }
    if ((j+1) < ys && word[k+1] == board[i][j+1] && n[i][j+1] == 0) {
        n[i][j+1] = 1;
        if (checar(board,n,i,j+1,xs,ys,word,k+1))
            return true;
        else
            n[i][j+1] = 0;
    }
    if ((i-1) >= 0  && (j+1) < ys && word[k+1] == board[i-1][j+1] && n[i-1][j+1] == 0) {
        n[i-1][j+1] = 1;
        if (checar(board,n,i-1,j+1,xs,ys,word,k+1))
            return true;
        else
            n[i-1][j+1] = 0;
    }
    if ((i-1) >= 0 && word[k+1] == board[i-1][j] && n[i-1][j] == 0) {
        n[i-1][j] = 1;
        if (checar(board,n,i-1,j,xs,ys,word,k+1))
            return true;
        else
            n[i-1][j] = 0;
    }
    if ((i-1) >= 0 && (j-1) >= 0 && word[k+1] == board[i-1][j-1] && n[i-1][j-1] == 0) {
        n[i-1][j-1] = 1;
        if (checar(board,n,i-1,j-1,xs,ys,word,k+1))
            return true;
        else
            n[i-1][j-1] = 0;
    }
    if ((j-1) >= 0 && word[k+1] == board[i][j-1] && n[i][j-1] == 0) {
        n[i][j-1] = 1;
        if (checar(board,n,i,j-1,xs,ys,word,k+1))
            return true;
        else
             n[i][j-1] = 0;
    }
    if ((i+1) < xs && (j-1) >= 0 && word[k+1] == board[i+1][j-1] && n[i+1][j-1] == 0){
        n[i+1][j-1] = 1;
        if (checar(board,n,i+1,j-1,xs,ys,word,k+1))
            return true;
        else
            n[i+1][j-1] = 0;
    }

    return false;
}


bool check_word(const vector<vector<char> > &board, const string &word) {

    bool ans = false;
    int xs = board[0].size();
    int ys = board.size();
    int k=0;

    vector<vector<int>>  n(xs, vector<int>(ys,0));
    for (int i=0; i < xs; i++) {
        for (int j=0; j < ys; j++){
                //cout << board[i][j] << " - " << n[i][j] << endl;
            if (word[k] == board[i][j] && !ans) {
                n[i][j] = 1;
                if (checar(board,n,i,j,xs,ys,word,k)) {
                    ans = true;
                    //cout << "--->" << board[i][j] << " - " << n[i][j] << endl;
                    break;
                } else {
                    n[i][j] = 0;
                }
            }
        }
        if (ans)
            break;
    }


    return ans;
}



int main(int argc, char* argv[]){

	setlocale(LC_ALL, "portuguese-brazilian");


	vector<vector<char> > tb = {{'T','T','M','D','A'},
                                {'G','Y','I','N','N'},
                                {'P','A','L','C','E'},
                                {'I','A','U','L','G'},
                                {'A','M','I','N','A'} };
    /*
    vector<vector<char> > tb = {{'A','B','A','B','A'},
                                {'B','A','B','A','B'},
                                {'A','B','A','B','A'},
                                {'B','A','B','A','B'},
                                {'A','B','A','B','A'} };
    */
    string e = "ANIMALITY";

	bool r = check_word(tb,e);

    cout << "Respota : " << r;

    return 0;
}
