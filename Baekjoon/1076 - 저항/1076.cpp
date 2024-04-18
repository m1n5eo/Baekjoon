#include <iostream>
#include <string.h>

using namespace std;

int main() {
    string color[3];
    cin >> color[0] >> color[1] >> color[2];

    long long int res = 0;
    if(color[0] == "black") res = 0;
    else if(color[0] == "brown") res = 1;
    else if(color[0] == "red") res = 2;
    else if(color[0] == "orange") res = 3;
    else if(color[0] == "yellow") res = 4;
    else if(color[0] == "green") res = 5;
    else if(color[0] == "blue") res = 6;
    else if(color[0] == "violet") res = 7;
    else if(color[0] == "grey") res = 8;
    else if(color[0] == "white") res = 9;

    if(color[1] == "black") res = res*10 + 0;
    else if(color[1] == "brown") res = res*10 + 1;
    else if(color[1] == "red") res = res*10 + 2;
    else if(color[1] == "orange") res = res*10 + 3;
    else if(color[1] == "yellow") res = res*10 + 4;
    else if(color[1] == "green") res = res*10 + 5;
    else if(color[1] == "blue") res = res*10 + 6;
    else if(color[1] == "violet") res = res*10 + 7;
    else if(color[1] == "grey") res = res*10 + 8;
    else if(color[1] == "white") res = res*10 + 9;

    if(color[2] == "black") res *= 1;
    else if(color[2] == "brown") res *= 10;
    else if(color[2] == "red") res *= 100;
    else if(color[2] == "orange") res *= 1000;
    else if(color[2] == "yellow") res *= 10000;
    else if(color[2] == "green") res *= 100000;
    else if(color[2] == "blue") res *= 1000000;
    else if(color[2] == "violet") res *= 10000000;
    else if(color[2] == "grey") res *= 100000000;
    else if(color[2] == "white") res *= 1000000000;

    cout << res;

    return 0;
}