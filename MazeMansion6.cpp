#include <iostream>
#include <queue>
#include <string>
#include <string.h>
#include <bitset>
#include <cmath>
using namespace std;

char maze[20][20]; //각 방의 문자 저장
bool visit[20][20][64]; //각 방의 방문 여부 저장(가지고 있는 키에 따라 저장)

//들어갈 수 있는 잠긴 방인지 확인
bool open(int lock, int key) {
	int temp = pow(10, lock);
	if ((key / temp) % 10 == 1) return true;
	else return false;
}

//sc, sr : 시작 지점, m, n : 미로 크기, card : 찾아야하는 키
int bfs(int sc, int sr, int m, int n, int card) {
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };
	queue<pair<pair<int, int>, int> > q;
	q.push(make_pair(make_pair(sc, sr), 0));
	visit[sc][sr][0] = true;
	int ans = 0;
	while (!q.empty()) {
		ans++;
		int ql = q.size();
		for (int i = 0; i < ql; i++) {
			int cx, cy, ck;
			cy = q.front().first.first;
			cx = q.front().first.second;
			ck = q.front().second;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int nx, ny, nk = 0;
				ny = cy + dy[j];
				nx = cx + dx[j];
				if (ny >= 0 && ny < m && nx >= 0 && nx < n
					&& visit[ny][nx][ck] != true && maze[ny][nx] != '#') {
					//잠긴 방인 경우
					if (maze[ny][nx] > 64 && maze[ny][nx] < 91) {
						//잠금 해제 못하면 continue
						if (!open(maze[ny][nx] - 65, ck)) {
							continue;
						}
						//잠금 해제 가능하면 방문하고 큐에 삽입
						else {
							visit[ny][nx][ck] = true;
							q.push(make_pair(make_pair(ny, nx), ck));
						}
					}
					//키가 있는 방의 경우
					else if (maze[ny][nx] > 96) {
						//이미 가지고 있는 키인지 확인(확인 안하면 중복으로 더해져서 mask가 이진법으로 안나올 수도 있음)
						int temp = pow(10, maze[ny][nx] - 97);
						if ((ck / temp) % 10 == 0) {
							nk = ck + temp;
							visit[ny][nx][ck] = true;
							visit[ny][nx][nk] = true;
							if (nk == card) return ans;
							q.push(make_pair(make_pair(ny, nx), nk));
						}
						else {
							visit[ny][nx][ck] = true;
							q.push(make_pair(make_pair(ny, nx), ck));
						}
					}
					else {
						visit[ny][nx][ck] = true;
						q.push(make_pair(make_pair(ny, nx), ck));

					}
				}
			}

		}
	}
	return -1;
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int card = 0;
		int sc = 0, sr = 0;
		int m, n;
		cin >> m >> n;
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				cin >> maze[j][k];
				if (maze[j][k] == '@') {
					sc = j;
					sr = k;
				}
				if (maze[j][k] > 96) {
					card += pow(10, maze[j][k] - 97);
				}
			}
		}
		cout << bfs(sc, sr, m, n, card) << "\n";
		memset(maze, '0', sizeof(maze));
		memset(visit, 0, sizeof(visit));
	}
}