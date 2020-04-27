#include <iostream>
#include <queue>
#include <string>
#include <string.h>
#include <bitset>
#include <cmath>
using namespace std;

char maze[20][20]; //�� ���� ���� ����
bool visit[20][20][64]; //�� ���� �湮 ���� ����(������ �ִ� Ű�� ���� ����)

//�� �� �ִ� ��� ������ Ȯ��
bool open(int lock, int key) {
	int temp = pow(10, lock);
	if ((key / temp) % 10 == 1) return true;
	else return false;
}

//sc, sr : ���� ����, m, n : �̷� ũ��, card : ã�ƾ��ϴ� Ű
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
					//��� ���� ���
					if (maze[ny][nx] > 64 && maze[ny][nx] < 91) {
						//��� ���� ���ϸ� continue
						if (!open(maze[ny][nx] - 65, ck)) {
							continue;
						}
						//��� ���� �����ϸ� �湮�ϰ� ť�� ����
						else {
							visit[ny][nx][ck] = true;
							q.push(make_pair(make_pair(ny, nx), ck));
						}
					}
					//Ű�� �ִ� ���� ���
					else if (maze[ny][nx] > 96) {
						//�̹� ������ �ִ� Ű���� Ȯ��(Ȯ�� ���ϸ� �ߺ����� �������� mask�� ���������� �ȳ��� ���� ����)
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