#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

string str, cmp;
vector<int> failure;

int main() {
    FASTIO

    cin >> str;
    cin >> cmp;

    int cmp_size = cmp.size();

    failure.push_back(-1);
    for(int i = 1; i < cmp_size; i++) {
        int j = failure[i-1];

        while(cmp[i] != cmp[j+1] && j >= 0) j = failure[j];

        if(cmp[i] == cmp[j+1]) failure.push_back(j+1);
        else failure.push_back(-1);
    }

    int i = 0, j = 0;
    int str_size = str.size();

    while(i < str_size && j < cmp_size) {
        if(str[i] == cmp[j]) {
            i += 1;
            j += 1;
        }
        else if(j == 0) {
            i += 1;
        }
        else {
            j = failure[j-1]+1;
        }

        if(j == cmp_size) {
            cout << 1;
            exit(0);
        }
    }

    cout << 0;
}