#include <iostream>
#include <string>

using namespace std;

long long int func(int num) {
    int rtn = 1;
    
    for(int i = 0; i < num; i++) {
        rtn = rtn*10;
    }

    return rtn;
}

int main() {
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    string a, b, c, d;

    cin >> a >> b >> c >> d;

    int b_length = b.length(), d_length = d.length();

    cout << (stoi(a)*func(b_length)+stoi(b)) + (stoi(c)*func(d_length)+stoi(d));
}