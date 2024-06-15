#include <iostream>
using namespace std;

#define MAX 44

int n, m, r, c, result;
bool notebook[MAX][MAX], sticker[MAX][MAX], copy_sticker[MAX][MAX];

void rotation_sticker() {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            copy_sticker[j][r-i-1] = sticker[i][j];
        }
    }

    swap(r, c);

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            sticker[i][j] = copy_sticker[i][j];
        }
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int k;
    cin >> n >> m >> k;

    for(int _ = 0; _ < k; _++) {
        cin >> r >> c;

        int total = 0;

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                cin >> sticker[i][j];
                if(sticker[i][j] == true) total += 1;
            }
        }

        bool stop_point = true;

        for(int t = 0; t < 4 && stop_point; t++) {
            for(int i = 0; i <= n-r && stop_point; i++) {
                for(int j = 0; j <= m-c && stop_point; j++) {
                    int cnt = 0;

                    for(int x = 0; x < r; x++) {
                        for(int y = 0; y < c; y++) {
                            if(notebook[i+x][j+y] == false && sticker[x][y] == true) cnt += 1;
                            else if(notebook[i+x][j+y] == true && sticker[x][y] == true) break;
                        }
                    }

                    if(cnt == total) {
                        for(int x = 0; x < r; x++) {
                            for(int y = 0; y < c; y++) {
                                if(sticker[x][y] == true) {
                                    notebook[i+x][j+y] = 1;
                                    result += 1;
                                }
                            }
                        }
                        stop_point = false;
                    }
                }
            }

            rotation_sticker();
        }
    }

    cout << result;
}