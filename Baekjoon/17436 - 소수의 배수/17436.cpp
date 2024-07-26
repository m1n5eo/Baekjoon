#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int

int n;
lli m, result;
vector<lli> prime;

int main() {
    FASTIO

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        lli num;
        cin >> num;

        prime.push_back(num);
    }

    for(int a0 = 0; a0 < n; a0++) {
        result += m/(prime[a0]);
        for(int a1 = a0+1; a1 < n; a1++) {
            result -= m/(prime[a0]*prime[a1]);
            for(int a2 = a1+1; a2 < n; a2++) {
                result += m/(prime[a0]*prime[a1]*prime[a2]);
                for(int a3 = a2+1; a3 < n; a3++) {
                    result -= m/(prime[a0]*prime[a1]*prime[a2]*prime[a3]);
                    for(int a4 = a3+1; a4 < n; a4++) {
                        result += m/(prime[a0]*prime[a1]*prime[a2]*prime[a3]*prime[a4]);
                        for(int a5 = a4+1; a5 < n; a5++) {
                            result -= m/(prime[a0]*prime[a1]*prime[a2]*prime[a3]*prime[a4]*prime[a5]);
                            for(int a6 = a5+1; a6 < n; a6++) {
                                result += m/(prime[a0]*prime[a1]*prime[a2]*prime[a3]*prime[a4]*prime[a5]*prime[a6]);
                                for(int a7 = a6+1; a7 < n; a7++) {
                                    result -= m/(prime[a0]*prime[a1]*prime[a2]*prime[a3]*prime[a4]*prime[a5]*prime[a6]*prime[a7]);
                                    for(int a8 = a7+1; a8 < n; a8++) {
                                        result += m/(prime[a0]*prime[a1]*prime[a2]*prime[a3]*prime[a4]*prime[a5]*prime[a6]*prime[a7]*prime[a8]);
                                        for(int a9 = a8+1; a9 < n; a9++) {
                                            result -= m/(prime[a0]*prime[a1]*prime[a2]*prime[a3]*prime[a4]*prime[a5]*prime[a6]*prime[a7]*prime[a8]*prime[a9]);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << result;
}