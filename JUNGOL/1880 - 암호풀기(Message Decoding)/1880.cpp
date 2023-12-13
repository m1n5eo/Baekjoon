#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, sentence;
    char key[26];
    getline(cin, s);
    getline(cin, sentence, '\n');

    for(int i = 0; i < 26; i++) key[i] = s[i];

    int len = sentence.size();
    for(int i = 0; i < len; i++) {
        if('a' <= sentence[i] && sentence[i] <= 'z') {
            cout << key[sentence[i]-'a'];
        }
        else if('A' <= sentence[i] && sentence[i] <= 'Z') {
            cout << (char)(key[sentence[i]-'A']-('a'-'A'));
        }
        else {
            cout << sentence[i];
        }
    }
}