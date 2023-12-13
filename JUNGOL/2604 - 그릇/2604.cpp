#include <iostream>
#include <string>
using namespace std;

int main() {
    string bowl;
    cin >> bowl;

    int sum = 0, len = bowl.size();
    for(int i = 0; i < len; i++) {
        if(i == 0) sum += 10;
        else if(bowl[i] == bowl[i-1]) sum += 5;
        else if(bowl[i] != bowl[i-1]) sum += 10;
    }
    cout << sum;
}