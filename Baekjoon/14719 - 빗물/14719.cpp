#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int n, m, arr[555];
vector<pair<int,int>> rain;

int main() {
    cin >> m >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        rain.push_back({0,0});
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(rain[i].first < arr[j]) {
                rain[i].first = arr[j];
            }
        }
        for(int j = i+1; j < n; j++) {
            if(rain[i].second < arr[j]) {
                rain[i].second = arr[j];
            }
        }
    }

    int sum = 0;
    for(int i = 0; i < n; i++) {
        if(rain[i].first > arr[i] && rain[i].second > arr[i]) {
            sum += min(rain[i].first, rain[i].second)-arr[i];
        }
    }
    cout << sum;
}