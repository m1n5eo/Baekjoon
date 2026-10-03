#include <bits/stdc++.h>
using namespace std;

int LCS[1001][1001];
string str1, str2, temp;
stack<char> print;

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    str1.push_back(0); str2.push_back(0);
    cin >> temp; for(int i = 0; i < temp.size(); i++) str1.push_back(temp[i]);
    cin >> temp; for(int i = 0; i < temp.size(); i++) str2.push_back(temp[i]);
    for(int i = 0; i < str1.size(); i++) {
        for(int j = 0; j < str2.size(); j++) {
            if(i == 0 || j == 0) LCS[i][j] = 0;
            else if(str1[i] == str2[j]) LCS[i][j] = LCS[i-1][j-1]+1;
            else LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
        }
    }
    int x = str1.size()-1, y = str2.size()-1, k = LCS[str1.size()-1][str2.size()-1];
    while(k != 0) {
        if(LCS[x-1][y] == k) x--;
        else if(LCS[x][y-1] == k) y--;
        else {
            print.push(str1[x]);
            x--;
            y--;
            k--;
        }
    }
    cout << print.size() << "\n";
    while(print.size()) {
        cout << print.top();
        print.pop();
    }
}