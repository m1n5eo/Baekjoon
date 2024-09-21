#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 111
#define INF 2100000000

struct type {
    string train_type, start_city, end_sity;
    int cost;
};

int city_size, sale_cost, travel_size, trans_size;
int origin[MAX][MAX], sale[MAX][MAX];
map<string, int> city;
vector<type> v;
vector<int> travel;

int main() {
    FASTIO

    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            origin[i][j] = INF;
            sale[i][j] = INF;
        }
    }

    cin >> city_size >> sale_cost;

    for(int i = 0; i < city_size; i++) {
        string _city;
        cin >> _city;
        
        city.insert({_city, i});
    }

    cin >> travel_size;

    for(int i = 0; i < travel_size; i++) {
        string _travel;
        cin >> _travel;

        travel.push_back(city[_travel]);
    }

    cin >> trans_size;

    for(int i = 0; i < trans_size; i++) {
        string _train_type, _start_city, _end_city;
        int _cost;

        cin >> _train_type >> _start_city >> _end_city >> _cost;

        int x = city[_start_city], y = city[_end_city];

        origin[x][y] = min(origin[x][y], _cost*2);
        origin[y][x] = min(origin[y][x], _cost*2);

        if(_train_type == "Mugunghwa" || _train_type == "ITX-Saemaeul" || _train_type == "ITX-Cheongchun") {
            sale[x][y] = min(sale[x][y], 0);
            sale[y][x] = min(sale[y][x], 0);
        }
        else if(_train_type == "S-Train" || _train_type == "V-Train") {
            sale[x][y] = min(sale[x][y], _cost);
            sale[y][x] = min(sale[y][x], _cost);
        }
        else {
            sale[x][y] = min(sale[x][y], _cost*2);
            sale[y][x] = min(sale[y][x], _cost*2);
        }
    }

    for(int k = 0; k < city_size; k++) {
        for(int i = 0; i < city_size; i++) {
            for(int j = 0; j < city_size; j++) {
                if(origin[i][k] != INF && origin[k][j] != INF) {
                    origin[i][j] = min(origin[i][j], origin[i][k]+origin[k][j]);
                }
                
                if(sale[i][k] != INF && sale[k][j] != INF) {
                    sale[i][j] = min(sale[i][j], sale[i][k]+sale[k][j]);
                }
            }
        }
    }

    int sum1 = 0, sum2 = sale_cost*2;

    for(int i = 0; i < travel_size-1; i++) {
        sum1 += origin[travel[i]][travel[i+1]];
        sum2 += sale[travel[i]][travel[i+1]];
    }

    if(sum1 > sum2) cout << "Yes";
    else cout << "No";

    return 0;
}