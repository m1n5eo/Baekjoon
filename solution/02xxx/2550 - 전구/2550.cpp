#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 11111

int n, connection1[MAX], connection2[MAX];
vector<int> arr, arr2, v, LIS, result;

bool compare(int a, int b) {
    return connection2[a] < connection2[b];
}

int main() {
    FASTIO

    cin >> n;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        arr2.push_back(temp);
        connection1[temp] = i;
        connection2[i] = temp;
    }

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        arr.push_back(connection1[temp]);
    }

    for(int i = 0; i < n; i++) {
        if(i == 0 || v.back() < arr[i]) {
            v.push_back(arr[i]);
            LIS.push_back(v.size());
        }
        else {
            int idx = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
            v[idx] = arr[i];
            LIS.push_back(idx+1);
        }
    }

    int key = v.size();

    for(int i = n-1; i >= 0; i--) {
        if(key == LIS[i]) {
            result.push_back(arr[i]);
            key -= 1;
        }
    }

    sort(result.begin(), result.end(), compare);

    cout << result.size() << "\n";

    for(int i = 0; i < result.size(); i++) {
        cout << connection2[result[i]] << " ";
    }
}