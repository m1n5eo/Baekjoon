#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define pil pair<int, long long int>
#define lli long long int
#define coordinate first
#define people second

bool compare(pil x, pil y) {
    return x.coordinate < y.coordinate;
}

int main() {
    FASTIO
    
    int n;
    lli sum = 0;
    vector<pil> hometown;
    
    cin >> n;

    for(int i = 0; i < n; i++) {
        int a;
        lli b;
        
        cin >> a >> b;

        hometown.push_back({a, b});
        sum += hometown[i].people;
    }

    sort(hometown.begin(), hometown.end(), compare);

    lli temp = 0;

    for(int i = 0; i < n; i++) {
        temp += hometown[i].people;

        if(temp >= (sum+1)/2) {
            cout << hometown[i].coordinate;
            break;
        }
    }
}