#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void team(int n, int[]);

int main() {
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		//vector<int>* desig = new vector<int>[n + 1];
		int* desig = new int[n + 1];
		for (int j = 1; j < n + 1; j++) {
			cin >> desig[j];
		}
		team(n, desig);
	}
}

void team(int n, int desig[]) {
	int cnt = 0;
	int* check = new int[n + 1];
	fill_n(check, n + 1, 0);
	for (int i = 1; i <= n; i++) {
		if (check[i] == 1) continue;
		stack<int> s;
		int cur = i;
		bool cycle = false;
		//무한 반복 방지 위해 반복 제한 걸어둠 
		for (int j = 0; j < n + 1; j++) {
			int next = desig[cur];
			if (next == i) {
				check[cur] = 1;
				while (!s.empty()) {
					check[s.top()] = 1;
					s.pop();
				}
				break;
			}
			else if (check[next] == 1) {
				break;
			}
			s.push(cur);
			cur = next;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (check[i] == 0) {
			cnt++;
		}
	}
	cout << cnt << "\n";
}
