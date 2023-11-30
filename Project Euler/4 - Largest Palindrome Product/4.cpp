#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(int num) {
    string temp = to_string(num);
    int cnt = 0;
    for(int i = 0; i < temp.size()/2; i++) {
        if(temp[i] == temp[temp.size()-i-1]) cnt++;
        else break;
    }
    if(cnt == temp.size()/2) return true;
    else return false;
}

int main() {
    int maxPalindrome = 0, ii, jj;
    for(int i = 999; i >= 100; i--) {
        for(int j = 999; j >= i; j--) {
            if(isPalindrome(i*j) == true) {
                if(maxPalindrome < i*j) {
                    maxPalindrome = i*j;
                    ii = i;
                    jj = j;
                }
            }
        }
    }
    cout << ii << "*" << jj << " = " << maxPalindrome;
}