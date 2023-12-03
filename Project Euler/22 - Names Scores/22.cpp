#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

bool compare(string s1, string s2) {
    return s1 < s2;
}

int main() {
    int cnt = 0;
    string name[11111];
    ifstream file("0022_names.txt");
    for(int i = 0; !file.eof(); i++) {
        getline(file, name[i], ',');
        name[i].erase(name[i].begin());
        name[i].resize(name[i].size()-1);
        cnt++;
    }

    sort(name, name+cnt, compare);

    long long int sum = 0;
    for(int i = 0; i < cnt; i++) {
        int temp = 0;
        for(int j = 0; j < name[i].length(); j++) temp += int(name[i][j])-64;
        sum += temp*(i+1);
    }
    cout << sum;
}