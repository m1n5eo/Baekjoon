#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    int a, b, c;

    cin >> a >> b >> c;

    if(a == 60 && b == 60 && c == 60) cout << "Equilateral";
    else if(a+b+c == 180 && (a == b || b == c || c == a)) cout << "Isosceles";
    else if(a+b+c == 180 && !(a == b || b == c || c == a)) cout << "Scalene";
    else cout << "Error";
}