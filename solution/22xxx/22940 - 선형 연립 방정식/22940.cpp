#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int

lli gcd(lli a, lli b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

lli lcm(lli a, lli b) {
    return a*b / gcd(a, b);
}

pair<lli, lli> deno(pair<lli, lli> a) {
    lli k = gcd(a.first, a.second);
    return {a.first/k, a.second/k};
}

pair<lli, lli> mul(pair<lli, lli> a, pair<lli, lli> b) {
    a = deno(a);
    b = deno(b);
    return {a.first*b.first, a.second*b.second};
}

pair<lli, lli> sub(pair<lli, lli> a, pair<lli, lli> b) {
    a = deno(a);
    b = deno(b);
    lli k = lcm(a.second, b.second);
    return {k/a.second*a.first - k/b.second*b.first, k};
}

vector<lli> solve() {
    lli n;
    cin >> n;
    vector<vector<pair<lli, lli>>> matrix(n, vector<pair<lli, lli>>(0));
    for(lli i = 0; i < n; i++) {
        for(lli j = 0; j < n+1; j++) {
            lli temp; cin >> temp;
            matrix[i].push_back({temp, 1});
        }
    }

    for(lli i = 0; i < n-1; i++) {
        for(lli j = i+1; j < n; j++) {
            pair<lli, lli> d = {matrix[i][i].second*matrix[j][i].first, matrix[i][i].first*matrix[j][i].second};
            for(lli k = i; k < n+1; k++) {
                matrix[j][k] = deno(sub(mul(matrix[i][k], d), matrix[j][k]));
            }
        }
    }

    for(lli i = n-1; i >= 1; i--) {
        for(lli j = i-1; j >= 0; j--) {
            pair<lli, lli> d = {matrix[i][i].second*matrix[j][i].first, matrix[i][i].first*matrix[j][i].second};
            matrix[j][n] = deno(sub(matrix[j][n], mul(matrix[i][n], d)));
            matrix[j][i] = {0, 1};
        }
    }
    
    for(lli i = 0; i < n; i++) {
        matrix[i][n] = deno({matrix[i][n].first*matrix[i][i].second, matrix[i][n].second*matrix[i][i].first});
        matrix[i][i] = {1, 1};
    }

    vector<lli> ret;
    for(lli i = 0; i < n; i++) ret.push_back(matrix[i][n].first);
    return ret;
}

int main() {
    FASTIO
    vector<lli> sol = solve();
    for(lli s : sol) cout << s << " ";
}