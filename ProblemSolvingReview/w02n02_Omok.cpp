#include <iostream>
#include <string.h>
using namespace std;

int T, x, y, res, turn;
char board[16][16];
char color, winner;

int dfs(int y, int x, int direc, int color) {
	int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
	int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
	int cnt = 1;

	int cy = y;
	int cx = x;

	while (1) {
		cy += dy[direc];
		cx += dx[direc];

		if (board[cy][cx] != color)
			return cnt;
		else
			cnt++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		turn = 225;
		res = 0;
		for(turn = 1; turn <= 225; turn++) {
			cin >> x >> y;

			if (res) continue;

			if (turn % 2 == 1)
				color = 'B';
			else
				color = 'W';

			board[y][x] = color;

			for (int i = 0; i < 4; i++) {
				if (dfs(y, x, i, color) + dfs(y, x, i + 4, color) - 1 == 5) {
					res = turn;
					winner = color;
				}
			}
		}
		cout << res << " " << winner << "\n";
		memset(board, 0, sizeof(board));
	}
}