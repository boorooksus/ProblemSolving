#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int l, sx, sy, ex, ey;
int visit[500][500];

int bfs() {
	if (sx == ex && sy == ey) {
		return 0;
	}

	int dy[8] = { 1, -1, 1, -1, 2, -2, 2, -2 };
	int dx[8] = { 2, 2, -2, -2, 1, 1, -1, -1 };

	int ans = 0;
	queue<pair <int, int > > q;
	q.push(make_pair(sy, sx));

	while (!q.empty()) {
		int ql = q.size();
		ans++;
		while (ql--) {
			int cy = q.front().first;
			int cx = q.front().second;
			q.pop();

			for (int i = 0; i < 8; i++) {
				int ny = cy + dy[i];
				int nx = cx + dx[i];

				if (ny >= 0 && ny < l && nx >= 0 && nx < l && visit[ny][nx] == 0) {
					if (ny == ey && nx == ex) return ans;

					visit[ny][nx]++;
					q.push(make_pair(ny, nx));
				}
			}
		}
	}

	return 0;
	
}

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		cin >> l >> sx >> sy >> ex >> ey;
		cout << bfs() << "\n";
		memset(visit, 0, sizeof(visit));
	}
}