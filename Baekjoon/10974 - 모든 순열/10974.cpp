#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 11

int n;
bool check[MAX];

void func(int* arr, int idx) {
    if(idx == n-1) {
        for(int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    for(int i = 1; i <= n; i++) {
        if(check[i] == false) {
            check[i] = true;
            arr[idx+1] = i;

            func(arr, idx+1);
            
            check[i] = false;
            arr[idx+1] = 0;
        }
    }
}

int main() {
    FASTIO

    cin >> n;
    
    int* arr;
    arr = new int[n];

    for(int i = 1; i <= n; i++) {
        arr[i] = 0;
    }

    func(arr, -1);
}