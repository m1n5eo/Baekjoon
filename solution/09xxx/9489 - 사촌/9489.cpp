#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1111111

int main() {
	FASTIO

	int n, k;

	while(cin >> n >> k) {
		if(n == 0 && k == 0) {
			break;
		}

		int temp, index = 0;
		vector<int> vec;
		map<int, int> parent;
		queue<int> root;
		
		for(int i = 0; i < n; i++) {
			cin >> temp;
			vec.push_back(temp);
		}

		while(index < n) {
			if(parent.size() == 0) {
				parent[vec[index]] = 0;
				root.push(vec[index]);
			}
			else {
				while(vec[index] + 1 == vec[index+1]) {
					parent[vec[index]] = root.front();
					root.push(vec[index]);
					index += 1;
				}

				parent[vec[index]] = root.front();
				root.push(vec[index]);
				root.pop();
			}

			index += 1;
		}

		int result = 0;
		map<int, vector<int>> tree;

		for(pair<int, int> p : parent) {
			tree[p.second].push_back(p.first);
		}

		for(int tg : tree[parent[parent[k]]]) {
			if(tg != parent[k]) {
				result += tree[tg].size();
			}
		}

		cout << result << "\n";
	}
}