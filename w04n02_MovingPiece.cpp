#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int board[501][501];
int bfs(int, int, int, int, int);

int main() {
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		memset(board, 0, sizeof(board));
		int l;
		cin >> l;
		int curX, curY;
		cin >> curX >> curY;
		int destX, destY;
		cin >> destX >> destY;
		
		cout << bfs(l, curX, curY, destX, destY) << "\n";
	}
}

int bfs(int l, int curX, int curY, int destX, int destY) {
	queue<pair<int, int>> q;
	int row = curX;
	int col = curY;
	int cnt = 0;
	int nextX, nextY;
	int moveX[8] = { 2, 2, -2, -2, 1, 1, -1, -1 };
	int moveY[8] = { 1, -1, 1, -1, 2, -2, 2, -2 };

	if (row == destX && col == destY) {
		return 0;
	}

	q.push(make_pair(row, col));
	while (!q.empty()) {
		cnt++;
		int qlen = q.size();
		for (int j = 0; j < qlen; j++) {
			row = q.front().first;
			col = q.front().second;
			q.pop();
			for (int i = 0; i < 8; i++) {
				nextX = row + moveX[i];
				nextY = col + moveY[i];
				if (nextX >= 0 && nextX < l
					&& nextY >= 0 && nextY < l
					&& board[nextX][nextY] == 0) {
					board[nextX][nextY] = 1;
					q.push(make_pair(nextX, nextY));
					if (nextX == destX && nextY == destY) {
						return cnt;
					}
				}
			}
		}
	}
}
