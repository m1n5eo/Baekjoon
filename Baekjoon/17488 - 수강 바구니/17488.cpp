#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1111

int n, m;
vector<int> limit, sugang[MAX], result[MAX];

bool compare(int a, int b) {
    return a < b;
}

int main() {
    FASTIO

    limit.push_back(0);

    cin >> n >> m;

    for(int i = 1; i <= m; i++) {
        int temp;
        cin >> temp;

        limit.push_back(temp);
    }

    for(int _ = 0; _ < 2; _++) {
        for(int i = 1; i <= n; i++) {
            while(true) {
                int k;
                cin >> k;

                if(k == -1) break;

                sugang[k].push_back(i);
            }
        }
    
        for(int i = 1; i <= m; i++) {
            int sugang_size = sugang[i].size();

            if(limit[i] >= sugang_size) {
                for(int j = 0; j < sugang_size; j++) {
                    result[sugang[i][j]].push_back(i);
                }
            }
            
            limit[i] = limit[i]-sugang_size;
            sugang[i].clear();
        }
    }

    for(int i = 1; i <= n; i++) {
        int result_size = result[i].size();

        if(result_size == 0) cout << "망했어요\n";
        else {
            sort(result[i].begin(), result[i].end(), compare);
            for(int j = 0; j < result_size; j++) {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }
    }
}