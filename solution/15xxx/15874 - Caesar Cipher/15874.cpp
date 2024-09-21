#include <iostream>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int k, s;
string str;

int main() {
    FASTIO

    cin >> k >> s;
    cin.ignore();
    getline(cin, str);
    
    int str_size = str.size();

    for(int i = 0; i < str_size; i++) {
        if('A' <= str[i] && str[i] <= 'Z') cout << (char)((str[i]-'A'+k)%26+'A');
        else if('a' <= str[i] && str[i] <= 'z') cout << (char)((str[i]-'a'+k)%26+'a');
        else cout << (char)str[i];
    }

    return 0;
}