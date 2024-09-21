#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 22

int main() {
    FASTIO
    
    int n, array[MAX][MAX], array2[MAX][MAX];

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> array[i][j];
            array2[i][j] = array[i][j];
        }
    }

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j || j == k || k == i) continue;
                else if(array[i][j] == array[i][k]+array[k][j]) array2[i][j] = 0;
                else if(array[i][j] > array[i][k]+array[k][j]) {
                    cout << -1;
                    exit(0);
                }
            }
        }
    }

    int result = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            result += array2[i][j];
        }
    }

    cout << result;
}