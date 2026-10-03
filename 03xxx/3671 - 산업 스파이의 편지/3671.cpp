#include <iostream>
#include <memory.h>
#include <string>
using namespace std;

int t, cnt, number_size;
bool visit[11], check[11111111], prime[11111111] = {true, true, };
string number;

void findPrime(string now) {
    if(now != "") {
        if(prime[stoi(now)] == false && check[stoi(now)] == false) {
            check[stoi(now)] = true;
            cnt += 1;
        }
    }

    for(int i = 0; i < number_size; i++) {
        if(visit[i] == false) {
            visit[i] = true;
            findPrime(now+number[i]);
            visit[i] = false;
        }
    }

    return;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    for(int i = 2; i < 11111111; i++) {
        if(prime[i] == false) {
            for(int j = i*2; j < 11111111; j+=i) {
                prime[j] = true;
            }
        }
    }

    cin >> t;
    for(int _ = 0; _ < t; _++) {
        cin >> number;

        cnt = 0;
        number_size = number.size();
        memset(check, false, sizeof(bool)*11111111);
        memset(visit, false, sizeof(bool)*11);

        findPrime("");

        cout << cnt << "\n";
    }
}