#include <iostream>
#include <stack>
using namespace std;

int n;
int nom[10001];
int team[10001];

int dfs(int start) {
	int visit[10001];
	fill_n(visit, 10001, 0);
	stack <int> s;
	int cnt = 0;
	s.push(start);
	visit[start]++;
	int cur = nom[start];
	while (team[cur] == 0) {
		if (visit[cur] != 0) {
			team[cur]++;
			cnt++;
			while (s.top() != cur) {
				team[s.top()]++;
				cnt++;
				s.pop();
			}
			break;
		}
		s.push(cur);
		visit[cur]++;
		cur = nom[cur];
	}
	return cnt;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> nom[i];
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (team[i] == 0) {
				ans += dfs(i);
			}
		}
		ans = n - ans;
		cout << ans << "\n";

		fill_n(nom, 10000, 0);
		fill_n(team, 10000, 0);
	}
}