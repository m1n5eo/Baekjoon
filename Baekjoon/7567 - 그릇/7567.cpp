#include <iostream>
#include <string>
using namespace std;

int main() {
    int sum = 10;
    string bowl;
    cin >> bowl;
    int len = bowl.length();
    for(int i = 1; i < len; i++) {
        if(bowl[i] == bowl[i-1]) sum += 5;
        else sum += 10;
    }
    cout << sum;
}
