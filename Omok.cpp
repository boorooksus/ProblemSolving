#include <iostream>
#include <vector>
using namespace std;


int board[16][16]; //������ �� ���� ��ġ ����
int check[16][16]; //dfs���� ������ ������� üũ

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
			//�̹� ���ڰ� ������ continue
			if (isAns == true) continue;
			//������ �� ��
			if (j % 2 == 1) {
				int cnt = 0;
				board[x][y] = 1;
				//���⿡ ���� 5���� �������� �ִ��� Ȯ��
				//k : 0�϶� - ����, k : 1�϶� - ����, 
				//k : 2�϶� - 2���� 4��и�, k : 3�϶� - 1���� 3��и� ����
				for (int k = 0; k < 4; k++) {
					cnt = 0;
					dfs(x, y, 1, cnt, k);
					if (cnt == 5) {
						isAns = true;
						winner = 'B';
						ans = j;
					}
					//check �迭 0���� �ʱ�ȭ
					memset(check, 0, sizeof(check));
				}
			}
			//����� �� ��
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
		//---***���� ���� ��������***---
	     cout << "                    " << ans << " " << winner << "\n";
		//cout << ans << winner << "\n";
		memset(board, 0, sizeof(board));
	}
	
	return 0;
}


//x, y : ���� ��ġ, BorW : 1�̸� ����, -1�̸� �Ͼ�, cnt : ������ �� ����
//direc - 0: ����, 1 : ����, 2 : (�ϼ�����), 3 : �ϵ�����
void dfs(int x, int y, int BorW, int& cnt, int direc) {
	//�̹� üũ�� ����̸� ����
	if (check[x][y] == 1) return;

	check[x][y] = 1;
	cnt++;
	//���� ����
	if (direc == 0) {
		//���� Ȯ��
		if (x > 1 && board[x - 1][y] == BorW) {
			dfs(x - 1, y, BorW, cnt, 0);
		}
		//���� Ȯ��
		if (x < 15 && board[x + 1][y] == BorW) {
			dfs(x + 1, y, BorW, cnt, 0);
		}
	}
	//���� ����
	else if (direc == 1) {
		if (y > 1 && board[x][y - 1] == BorW) {
			dfs(x, y - 1, BorW, cnt, 1);
		}
		if (y < 15 && board[x][y + 1] == BorW) {
			dfs(x, y + 1, BorW, cnt, 1);
		}
	}
	//�밢�� ����(2��и� to 4��и�)
	else if (direc == 2) {
		if (x > 1 && y > 1 && board[x - 1][y - 1] == BorW) {
			dfs(x - 1, y - 1, BorW, cnt, 2);
		}
		if (x < 15 && y < 15 && board[x + 1][y + 1] == BorW) {
			dfs(x + 1, y + 1, BorW, cnt, 2);
		}
	}
	//�밢�� ����(1��и� to 3��и�)
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