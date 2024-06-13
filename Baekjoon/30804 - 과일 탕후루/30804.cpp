#include <iostream>
#include <vector>
using namespace std;

int n, result, arr[11];
vector<int> v;

int cnt() {
    int rtn = 0;

    for(int i = 1; i <= 9; i++) {
        if(arr[i] > 0) rtn += 1;
    }

    return rtn;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        v.push_back(temp);
    }

    int start = 0, end = 0;
    arr[v[0]] += 1;

    while(end < n) {
        int temp = cnt();

        if(temp <= 2) {
            end += 1;
            if(end < n) arr[v[end]] += 1;
            result = max(result, end-start);
        }
        else {
            arr[v[start]] -= 1;
            start += 1;
        }
    }

    cout << result;
}