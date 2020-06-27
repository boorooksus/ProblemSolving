#include <iostream>
#include <string.h>
using namespace std;

char board[16][16];

int dfs(int y, int x, char piece, int direc) {
	int dy[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
	int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

	int cnt = 1;
	int ny = y;
	int nx = x;
	while (1) {
		ny += dy[direc];
		nx += dx[direc];
		if (board[ny][nx] == piece) cnt++;
		else break;
	}

	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		int turn = 225;
		char winner = 0;
		int finish_cnt = 0;
		while (turn--) {
			int y, x;
			char piece;
			cin >> y >> x;

			if (finish_cnt) continue;

			if (turn % 2 == 0) {
				piece = 'B';
			}
			else {
				piece = 'W';
			}
			board[y][x] = piece;

			for (int i = 0; i < 4; i++) {
				if (dfs(y, x, piece, i) + dfs(y, x, piece, i + 4) - 1 == 5) {
					winner = piece;
					finish_cnt = 225 - turn;
				}
			}

		}

		cout << finish_cnt << " " << winner << "\n";

		memset(board, 0, sizeof(board));
	}
}