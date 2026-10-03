#include <iostream>
#include <string>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int n, result;
char save = '\0';
string str, num;
queue<int> q;

int main() {
    FASTIO

    cin >> n;
    cin >> str;

    int strSize = str.size();

    for(int i = 0; i < strSize; i++) {
        if('0' <= str[i] && str[i] <= '9') {
            num += str[i];
        }
        else {
            if(save == '\0') result = stoi(num);
            else if(save == 'S') result = result-stoi(num);
            else if(save == 'M') result = result*stoi(num);
            else if(save == 'U') result = result/stoi(num);
            else if(save == 'P') result = result+stoi(num);
            else if(save == 'C') q.push(result);

            num = "";
            save = str[i];
        }
    }

    if(save == 'C') q.push(result);

    if(q.size() == 0) cout << "NO OUTPUT\n";

    while(q.size()) {
        cout << q.front() << " ";
        q.pop();
    }
}