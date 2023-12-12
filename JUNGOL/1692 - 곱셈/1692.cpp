#include <iostream>
#include <string>
using namespace std;

int main() {
    string n, m;
    cin >> n >> m;
    int temp = stoi(n)*stoi(m);

    for(int i = 2; i >= 0; i--) {
        cout << stoi(n)*(m[i]-'0') << "\n";
    }
    cout << temp;
}