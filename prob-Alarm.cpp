#include <iostream>
using namespace std;

bool median(int, int d, int*);

int main() {
	std::ios::sync_with_stdio(false);
	int t; //t : test cases
	cin >> t;
	for (int i = 0; i < t; i++) {
		int cnt = 0; //cnt : �˶� Ƚ��
		int n, d; //n : �� �� ¥ ��, d : ����� ���� ������
		cin >> n >> d;
		//save expenditure by day
		int* expenDay = new int[n + 1];
		//int expenDay[200000];
		int expenCnt[201]; //save expenditure by count
		fill_n(expenCnt, 201, 0);

		for (int j = 1; j <= n; j++) {
			cin >> expenDay[j];

			//���� ��� ���� ������ �����̸� continue
			if (j < d + 1) {
				expenCnt[expenDay[j]]++;
				continue;
			}
			//��� ���� ���� ���� �� ��
			else {
				//������ �߾Ӱ��� �� �� �̻��̸� �˶� ī��Ʈ �߰�
				if (median(expenDay[j], d, expenCnt) == true) 
					cnt++;
			}
			//������ ���� ���� ���� �� ���̰� ���ο� �� �߰�
			expenCnt[expenDay[j - d]]--;
			expenCnt[expenDay[j]]++;
		}
		cout << cnt << "\n";
	}
}

//������ �߾Ӱ��� �� �� �̻��̸� True ����
bool median(int expen, int d, int* expenCnt) {
	int cnt = 0; //���� ī��Ʈ ����
	//d�� Ȧ���� ��
	if (d % 2 == 1) {
		for (int i = 0; i < 201; i++) {
			cnt += expenCnt[i];
			if (cnt >= (d / 2 + 1)) {
				if(expen >= 2 * i) return true;
				else return false;
			}
		}
	}
	//d�� ¦���� ��
	else {
		for (int i = 0; i < 201; i++) {
			int save = 0;
			cnt += expenCnt[i];
			if (cnt >= d / 2) {
				//�߰����� ������ ���� ���̿� ���� ��
				//ex) 1 2 <3> <4> 5 6
				if (cnt == d / 2) {
					//�߰��� �ٷ� ���� ���� �����ϰ� ��Ƽ��
					save = i;
					continue;
				}
				else if (save != 0) {
					//�߰��� �ٷ� ���� ���ڿ� ���� ���� ���� ���� 2�� �̻� �Ǵ��� Ȯ��
					//as int((double(save + i) / 2) * 2) == save + i
					if (expen >= save + i) return true;
					else return false;
				}
				//�߰����� ������ ���� ���̿� ���� ��
				//ex) 1 2 <2> <2> 3 4
				else {
					if (expen >= 2 * i) return true;
					else return false;
				}
			}
		}
	}
	return false; //�ǹ� ����
}
