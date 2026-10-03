#include <iostream>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO

    for(int testcase = 1; ; testcase++) {
        string str;

        cin >> str;

        if(str == "0") break;

        while(true) {
            int strSize = str.size();
            string next = "";

            if(str == "22" || strSize%2 == 1) break;

            for(int i = 0; i < strSize; i+=2) {
                for(int j = 0; j < str[i]-'0'; j++) {
                    next += str[i+1];
                }
            }

            str = next;
        }
        
        cout << "Test " << testcase << ": " << str << "\n";
    }
}