#include <iostream>
using namespace std;

int cnt = 4;
int print[11111] = {2, 3, 5, 7, }, jari[11] = {0, 0, 4, };

bool isSosu(int num) {
    for(int i = 2; i <= num/2; i++) {
        if(num%i == 0) return false;
    }
    return true;
}

int main() {
    for(int i = 2; i <= 8; i++) {
        for(int j = jari[i-1]; j < jari[i]; j++) {
            for(int k = 1; k < 10; k+=2) {
                if(k == 5) continue;
                int temp = print[j]*10+k;
                if(isSosu(temp) == true) print[cnt++] = temp;
            }
        }
        jari[i+1] = cnt;
    }

    int n;
    cin >> n;
    for(int i = jari[n]; i < jari[n+1]; i++) cout << print[i] << "\n";
}
