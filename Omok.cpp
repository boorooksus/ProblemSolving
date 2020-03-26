#include <iostream>
#include <vector>
using namespace std;


int board[16][16]; //오목판 위 오목 위치 저장
int check[16][16]; //dfs에서 지나간 노드인지 체크

void dfs(int, int, int, int&, int direc);

int main(){
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {

		bool isAns = false;
		char winner = 0;
		int ans = 0;

		for (int j = 1; j <= 225; j++) {
			int x, y;
			cin >> x >> y;
			//이미 승자가 있으면 continue
			if (isAns == true) continue;
			//검정이 둘 때
			if (j % 2 == 1) {
				int cnt = 0;
				board[x][y] = 1;
				//방향에 따라 5개가 연속으로 있는지 확인
				//k : 0일때 - 가로, k : 1일때 - 세로, 
				//k : 2일때 - 2에서 4사분면, k : 3일때 - 1에서 3사분면 방향
				for (int k = 0; k < 4; k++) {
					cnt = 0;
					dfs(x, y, 1, cnt, k);
					if (cnt == 5) {
						isAns = true;
						winner = 'B';
						ans = j;
					}
					//check 배열 0으로 초기화
					memset(check, 0, sizeof(check));
				}
			}
			//흰색이 둘 때
			else {
				int cnt = 0;
				board[x][y] = -1;
				for (int k = 0; k < 4; k++) {
					cnt = 0;
					dfs(x, y, -1, cnt, k);
					if (cnt == 5) {
						isAns = true;
						winner = 'W';
						ans = j;
					}
					memset(check, 0, sizeof(check));
				}
			}
		}
		//---***제출 전에 수정하자***---
	     cout << "                    " << ans << " " << winner << "\n";
		//cout << ans << winner << "\n";
		memset(board, 0, sizeof(board));
	}
	
	return 0;
}


//x, y : 시작 위치, BorW : 1이면 검정, -1이면 하양, cnt : 연속인 돌 개수
//direc - 0: 가로, 1 : 세로, 2 : (북서남동), 3 : 북동남서
void dfs(int x, int y, int BorW, int& cnt, int direc) {
	//이미 체크된 노드이면 리턴
	if (check[x][y] == 1) return;

	check[x][y] = 1;
	cnt++;
	//가로 방향
	if (direc == 0) {
		//좌측 확인
		if (x > 1 && board[x - 1][y] == BorW) {
			dfs(x - 1, y, BorW, cnt, 0);
		}
		//우측 확인
		if (x < 15 && board[x + 1][y] == BorW) {
			dfs(x + 1, y, BorW, cnt, 0);
		}
	}
	//세로 방향
	else if (direc == 1) {
		if (y > 1 && board[x][y - 1] == BorW) {
			dfs(x, y - 1, BorW, cnt, 1);
		}
		if (y < 15 && board[x][y + 1] == BorW) {
			dfs(x, y + 1, BorW, cnt, 1);
		}
	}
	//대각선 방향(2사분면 to 4사분면)
	else if (direc == 2) {
		if (x > 1 && y > 1 && board[x - 1][y - 1] == BorW) {
			dfs(x - 1, y - 1, BorW, cnt, 2);
		}
		if (x < 15 && y < 15 && board[x + 1][y + 1] == BorW) {
			dfs(x + 1, y + 1, BorW, cnt, 2);
		}
	}
	//대각선 방향(1사분면 to 3사분면)
	else if (direc == 3) {
		if (x < 15 && y > 1 && board[x + 1][y - 1] == BorW) {
			dfs(x + 1, y - 1, BorW, cnt, 3);
		}
		if (x > 1 && y < 15 && board[x - 1][y + 1] == BorW) {
			dfs(x - 1, y + 1, BorW, cnt, 3);
		}
	}
	return;	
}