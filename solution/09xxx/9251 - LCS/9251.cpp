#include <bits/stdc++.h>
using namespace std;

string str1, str2, temp;
int LCS[1001][1001];

int main() {
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
    cout << LCS[str1.size()-1][str2.size()-1];
}