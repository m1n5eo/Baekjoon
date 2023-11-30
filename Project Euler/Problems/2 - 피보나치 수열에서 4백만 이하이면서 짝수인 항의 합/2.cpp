#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    int first = 1, second = 1;
    while(second <= 4000000) {
        if(second%2 == 0) sum += second;
        int temp = first+second;
        first = second;
        second = temp;
    }
    cout << sum;
}