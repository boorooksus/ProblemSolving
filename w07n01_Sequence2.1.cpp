#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

int sq[9]; //N���� �ڿ����� �����ϴ� ����
int new_sq[9]; //���� ������ ����
int used[9]; //���� ������ ���Ұ� ���ο� ������ ���ƴ��� ����(0�̸� �̻��, 1�̸� ���)
int cnt = 0; //������ �����ϴ� ������ ������
//n : ������ �ڿ��� ����, min_res : ���� ������ �ּҰ�, max_res : ���� ������ �ִ밪, x : Ư�� �� x
int n, min_res, max_res, x; 


//���� ������� ������ ������ �����ϴ��� Ȯ���ϴ� �Լ�
void isValid() {
	//������ ���ǿ� ���� ���ڷ� ��ȯ
	int res = 0;
	for (int i = 0; i < n; i++) {
		res = (res + (new_sq[i] * (int(pow(x, i)) % 1013)) % 1013) % 1013;
	}

	//��ȯ�� ���ڰ� Ư�� ���� �ȿ� ������ cnt�� 1�� ���Ѵ�
	if (res >= min_res && res <= max_res) {
		cnt++;
	}

	return;
}

//dfs�� �̿��� ��Ʈ��ŷ���� ������ ���ϱ�
//idx : sq�� ���� �ε���, lv : ���� �ܰ�
void dfs(int idx, int lv) {
	//�̹� ����� �����̸� ����
	if (used[idx] != 0) return;

	//������ �ܰ��� ��
	if (lv == n - 1) {
		new_sq[n - 1] = sq[idx];
		//������ �����ϴ� �������� Ȯ��
		isValid();
		return;
	}

	used[idx] = 1; //���� ��� ���� 1�� ����
	new_sq[lv] = sq[idx]; //���ο� ���� �迭�� ����

	//��͸� ���� ���ο� ������ ���� ���� ���ϱ�
	for (int i = 0; i < n; i++) {
		dfs(i, lv + 1);
	}

	//���� �ܰ谡 ������ ���� ������ ��� ���� 0���� �ʱ�ȭ
	used[idx] = 0;

	return;
}

int main() {
	std::ios::sync_with_stdio(false);
	int T; //�׽�Ʈ ���̽�
	cin >> T;
	while (T--) {
		cin >> n; //�ڿ��� ���� �Է�

		//������ ���� �Է�
		for (int i = 0; i < n; i++) {
			cin >> sq[i];
		} 
		//���� ������ Ư�� �� x �Է�
		cin >> min_res >> max_res >> x;

		//��Ʈ��ŷ�� ���� ���� ����
		for (int i = 0; i < n; i++) {
			dfs(i, 0);
		}
		//������ �����ϴ� ���� ���� ���
		cout << cnt << "\n";

		//sq, cnt�� 0���� �ʱ�ȭ
		fill_n(sq, 9, 0);
		cnt = 0;
	}
}