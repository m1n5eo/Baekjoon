#include <bits/stdc++.h>
using namespace std;

string str1, str2, str3, temp;
int LCS[101][101][101];

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    str1.push_back(0); str2.push_back(0); str3.push_back(0);
    cin >> temp; for(int i = 0; i < temp.size(); i++) str1.push_back(temp[i]);
    cin >> temp; for(int i = 0; i < temp.size(); i++) str2.push_back(temp[i]);
    cin >> temp; for(int i = 0; i < temp.size(); i++) str3.push_back(temp[i]);
    for(int i = 0; i < str1.size(); i++) {
        for(int j = 0; j < str2.size(); j++) {
            for(int k = 0; k < str3.size(); k++) {
                if(i == 0 || j == 0 || k == 0) LCS[i][j][k] = 0;
                else if(str1[i] == str2[j] && str2[j] == str3[k]) LCS[i][j][k] = LCS[i-1][j-1][k-1]+1;
                else {
                    LCS[i][j][k] = max(LCS[i-1][j][k], LCS[i][j-1][k]);
                    LCS[i][j][k] = max(LCS[i][j][k], LCS[i][j][k-1]);
                }
            }
        }
    }
    cout << LCS[str1.size()-1][str2.size()-1][str3.size()-1];
}