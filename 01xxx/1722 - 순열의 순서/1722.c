#include <stdio.h>

int main() {
    long long int gop[22] = {0, 1};
    for(int i = 2; i <= 20; i++) {
        gop[i] = gop[i-1]*i;
    }

    int n;
    scanf("%d", &n);

    int problem;
    scanf("%d", &problem);
    if(problem == 1) {
        long long int k;
        scanf("%lld", &k);

        int check[22] = {0, };
        int ans[22], ans_cnt = 0;

        for(int i = n; i >= 2; i--) {
            int cnt = 1;
            long long int num = (k-1)/gop[i-1]%i, brk = 0;

            while(1) {
                if(check[cnt] == 0 && num == brk) {
                    check[cnt] = 1;
                    ans[ans_cnt++] = cnt;
                    break;
                }
                else if(check[cnt] == 0) {
                    brk += 1;
                    cnt += 1;
                }
                else if(check[cnt] == 1) {
                    cnt += 1;
                }
            }
        }

        for(int i = 1; i <= n; i++) {
            if(check[i] == 0) {
                ans[ans_cnt++] = i;
                break;
            }
            else continue;
        }

        for(int i = 0; i < ans_cnt; i++) {
            printf("%d ", ans[i]);
        }
    }
    else if(problem == 2) {
        int arr[22];
        for(int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        int check[22] = {0, }, cnt = 0;
        long long int ans = 0;

        for(int i = 0; i < n; i++) {
            int cnt = 0;

            for(int j = 1; j < arr[i]; j++) {
                if(check[j] == 1) {
                    cnt += 1;
                }
            }

            check[arr[i]] = 1;
            ans += (arr[i]-cnt-1)*gop[n-i-1];
        }

        printf("%lld", ans+1);
    }
}