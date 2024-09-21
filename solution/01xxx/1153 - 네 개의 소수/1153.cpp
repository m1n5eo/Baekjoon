#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1111111

int n;
bool prime[MAX] = {true, true, };
vector<int> result;

bool compare(int a, int b) {
    return a < b;
}

int main() {
    FASTIO

    for(int i = 2; i*i < MAX; i++) {
        if(prime[i] == false) {
            for(int j = i*2; j < MAX; j+=i) {
                prime[j] = true;
            }
        }
    }

    cin >> n;

    if(n < 8) {
        cout << -1;
        exit(0);
    }

    if(n%2 == 0) {
        result.push_back(2);
        result.push_back(2);

        for(int i = 2; i < n; i++) {
            if(prime[i] == false && prime[n-4-i] == false) {
                result.push_back(i);
                result.push_back(n-4-i);

                break;
            }
        }
    }
    else if(n%2 == 1) {
        result.push_back(2);
        result.push_back(3);

        for(int i = 2; i < n; i++) {
            if(prime[i] == false && prime[n-5-i] == false) {
                result.push_back(i);
                result.push_back(n-5-i);

                break;
            }
        }
    }

    sort(result.begin(), result.end(), compare);

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
}