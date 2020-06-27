#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int m, n, sy, sx;
char maze[20][20];
int visit[20][20][128];
int mask = 0;

int bfs() {
	int dy[4] = { 1, -1, 0, 0 };
	int dx[4] = { 0, 0, 1, -1 };

	queue< pair <pair<int, int>, int > > q;

	int move = 0;
	q.push(make_pair(make_pair(sy, sx), 0));

	while (!q.empty()) {
		int ql = q.size();
		move++;
		while (ql--) {
			int cy = q.front().first.first;
			int cx = q.front().first.second;
			int ckey = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int ny = cy + dy[i];
				int nx = cx + dx[i];

				if (ny < 0 || ny >= m || nx < 0 || nx >= n || visit[ny][nx][ckey] != 0 || maze[ny][nx] == '#') continue;

				if (maze[ny][nx] >= 'a' && maze[ny][nx] <= 'f') {
					int temp = 1;
					temp <<= maze[ny][nx] - 'a';
					int nkey = ckey | temp;

					if (mask == nkey) return move;

					visit[ny][nx][nkey]++;
					q.push(make_pair(make_pair(ny, nx), nkey));
				}

				else if (maze[ny][nx] >= 'A' && maze[ny][nx] <= 'F') {
					int lock = 1;
					lock <<= maze[ny][nx] - 'A';
					if (ckey & lock) {
						visit[ny][nx][ckey]++;
						q.push(make_pair(make_pair(ny, nx), ckey));
					}
				}

				else {
					visit[ny][nx][ckey]++;
					q.push(make_pair(make_pair(ny, nx), ckey));
				}
			}
		}
	}

	return -1;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> m >> n;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> maze[i][j];
				if (maze[i][j] == '@') {
					sy = i;
					sx = j;
				}
				if (maze[i][j] >= 'a' && maze[i][j] <= 'f') {
					int temp = 1;
					temp <<= maze[i][j] - 'a';
					mask |= temp;
				}
			}
		}

		cout << bfs() << "\n";

		memset(maze, 0, sizeof(maze));
		memset(visit, 0, sizeof(visit));
		mask = 0;
	}
}