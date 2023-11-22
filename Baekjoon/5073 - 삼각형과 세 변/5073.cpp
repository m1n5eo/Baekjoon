#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int triangle[3];
    while(1) {
        for(int i = 0; i < 3; i++) cin >> triangle[i];
        if(!triangle[0]) break;
        sort(triangle, triangle+3);
        if(triangle[0]+triangle[1] <= triangle[2]) cout << "Invalid\n";
        else if(triangle[0] == triangle[2]) cout << "Equilateral\n";
        else if(triangle[0] == triangle[1]) cout << "Isosceles\n";
        else if(triangle[1] == triangle[2]) cout << "Isosceles\n";
        else cout << "Scalene\n";
    }
}
