// ISTP(15) ISTJ(14) ISFP(13) ISFJ(12) INTP(11) INTJ(10) INFP(9) INFJ(8)
// ESTP(7) ESTJ(6) ESFP(5) ESFJ(4) ENTP(3) ENTJ(2) ENFP(1) ENFJ(0)

// ISFP(13 -> 1101), ENTP(3 -> 0011)

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dist[22][22];

int two_gop(int n) {
    int rtn = 1;

    for(int i = 0; i < n; i++) rtn *= 2;

    return rtn;
}

void init() {
    for(int i = 0; i < 16; i++) {
        for(int j = i+1; j < 16; j++) {
            int ii = i, jj = j;

            for(int k = 3; k >= 0; k--) {
                int temp = two_gop(k);

                if(ii/temp != jj/temp) {
                    dist[i][j] += 1;
                    dist[j][i] += 1;
                }

                ii = ii-ii/temp*temp, jj = jj-jj/temp*temp;
            }
        }
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    init();

    int t;

    cin >> t;
    for(int testcase = 0; testcase < t; testcase++) {
        int n, res = 1234567890, mbti[22] = {0, };

        cin >> n;
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            string str;

            cin >> str;

            if(str[0] == 'I') cnt += 8;
            if(str[1] == 'S') cnt += 4;
            if(str[2] == 'T') cnt += 2;
            if(str[3] == 'P') cnt += 1;

            mbti[cnt] += 1;
        }

        for(int i = 0; i < 16; i++) {
            if(mbti[i] == 0) continue;

            if(mbti[i] >= 3) {
                res = 0;
                break;
            }
            else if(mbti[i] >= 2) {
                for(int j = 0; j < 16; j++) {
                    if(i != j && mbti[j] >= 1) {
                        res = min(res, dist[i][j]*2);
                    }
                }
            }
            else if(mbti[i] >= 1) {
                for(int j = 0; j < 16; j++) {
                    if(i != j && mbti[j] >= 1) {
                        for(int k = 0; k < 16; k++) {
                            if(i != k && j != k && mbti[k] >= 1) {
                                res = min(res, dist[i][j]+dist[j][k]+dist[k][i]);
                            }
                        }
                    }
                }
            }
        }

        if(res == 1234567890) cout << "0\n";
        else cout << res << "\n";
    }

    return 0;
}