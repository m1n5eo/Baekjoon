#include <iostream> // BOJ 2536
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int
#define INF 1234567890
#define MAX 5555

struct type {
	int number;
	pair<lli, lli> left, right;
};

int n, m, k, temp, result = INF;
pair<int, int> s, e;
pair<lli, lli> temp1, temp2;
vector<type> route;
vector<int> a, b;
vector<vector<int>> graph(MAX, vector<int>(0));

int ccw(pair<lli, lli> x, pair<lli, lli> y, pair<lli, lli> z) {
	lli CrossProduct = (y.first - x.first) * (z.second - x.second) - (z.first - x.first) * (y.second - x.second);

	if(CrossProduct < 0) return -1;
	else if(CrossProduct > 0) return 1;
	else return 0;
}

bool cross(pair<lli, lli> a, pair<lli, lli> b, pair<lli, lli> c, pair<lli, lli> d) {
	int ABC = ccw(a, b, c);
	int ABD = ccw(a, b, d);
	int CDA = ccw(c, d, a);
	int CDB = ccw(c, d, b);

	if(ABC == 0 && ABD == 0 && CDA == 0 && CDB == 0) {
		if(a > b) swap(a, b);
		if(c > d) swap(c, d);

		if(a <= d && c <= b) return true;
		else return false;
	}
	else if(ABC == 0) {
		if(a > b) swap(a, b);
		
		if(a <= c && c <= b) return true;
		else return false;
	}
	else if(ABD == 0) {
		if(a > b) swap(a, b);

		if(a <= d && d <= b) return true;
		else return false;
	}
	else if(CDA == 0) {
		if(c > d) swap(c, d);

		if(c <= a && a <= d) return true;
		else return false;
	}
	else if(CDB == 0) {
		if(c > d) swap(c, d);

		if(c <= b && b <= d) return true;
		else return false;
	}
	else if(ABC * ABD < 0 && CDA * CDB < 0) {
		return true;
	}
	else {
		return false;
	}
}

int solve() {
	for(int i = 0; i < k; i++) {
		if(route[i].left.first == route[i].right.first) {
			if(route[i].left.first == s.first && route[i].left.second <= s.second && s.second <= route[i].right.second) a.push_back(route[i].number);
			if(route[i].left.first == e.first && route[i].left.second <= e.second && e.second <= route[i].right.second) b.push_back(route[i].number);
		}
		else if(route[i].left.second == route[i].right.second) {
			if(route[i].left.second == s.second && route[i].left.first <= s.first && s.first <= route[i].right.first) a.push_back(route[i].number);
			if(route[i].left.second == e.second && route[i].left.first <= e.first && e.first <= route[i].right.first) b.push_back(route[i].number);
		}
	}

	for(int i = 0; i < k; i++) {
		for(int j = i+1; j < k; j++) {
			if(cross(route[i].left, route[i].right, route[j].left, route[j].right) == true) {
				graph[route[i].number].push_back(route[j].number);
				graph[route[j].number].push_back(route[i].number);
			}
		}
	}

	for(int x : a) {
		for(int y : b) {
			if(x == y) {
				return 1;
			}

			queue<int> bfs;
			vector<bool> visit(k+1, false);
			int cnt = 1;
			bool check = false;

			bfs.push(x);
			visit[x] = true;

			while(bfs.size() && !check) {
				int bfs_size = bfs.size();

				for(int _ = 0; _ < bfs_size && !check; _++) {
					int now = bfs.front();
					int graph_size = graph[now].size();
					bfs.pop();

					for(int i = 0; i < graph_size && !check; i++) {
						if(graph[now][i] == y) {
							check = true;
							break;
						}
						if(visit[graph[now][i]] == false) {
							bfs.push(graph[now][i]);
							visit[graph[now][i]] = true;
						}
					}
				}

				cnt += 1;
			}

			if(check == true) {
				result = min(result, cnt);
			}
		}
	}

	return result;

}

int main() {
	FASTIO

	cin >> n >> m;
	cin >> k;

	for(int i = 0; i < k; i++) {
		cin >> temp >> temp1.first >> temp1.second >> temp2.first >> temp2.second;

		if(temp1.first == temp2.first && temp1.second > temp2.second) swap(temp1, temp2);
		else if(temp1.second == temp2.second && temp1.first > temp2.first) swap(temp1, temp2);

		route.push_back({temp, temp1, temp2});
	}

	cin >> s.first >> s.second >> e.first >> e.second;

	cout << solve();
}