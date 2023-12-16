#include <iostream>
#include <sstream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    ss.str(s);

    string word;
    stack<string> temp;
    while(ss >> word) {
        temp.push(word);
    }

    while(temp.size()) {
        if(temp.size()%2 == 0) cout << temp.top() << " ";
        temp.pop();
    }
}