#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 2222

int n, m, a, result;
int clap[MAX][MAX], clap_sum[MAX];

int main() {
    FASTIO

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> clap[i][j];
            clap_sum[j] = clap_sum[j]+clap[i][j];
        }
    }

    cin >> a;

    for(int i = 0; i < m-a+1; i++) {
        int sum = 0;

        for(int j = i; j < i+a; j++) {
            sum += clap_sum[j];
        }

        result = max(result, sum);
    }

    cout << result;
}