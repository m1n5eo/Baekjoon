#include <iostream>
#include <string>
#include <map>
using namespace std;

string str;
map<string, bool> m;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> str;

    int str_size = str.size();

    for(int i = 0; i < str_size; i++) {
        string temp = "";

        for(int j = i; j < str_size; j++) {
            temp += str[j];

            if(m.find(temp) == m.end()) m.insert({temp, true});
        }
    }

    cout << m.size();
}