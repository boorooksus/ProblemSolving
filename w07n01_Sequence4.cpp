#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int sq[9]; //N���� �ڿ����� �����ϴ� ����
int cnt = 0; //������ �����ϴ� ���� ����
int n; //�ڿ����� ����(N)
int min_res, max_res, x; //Ư�� ������ ��Ÿ���� ��(a, b), Ư�� ��

void isValid() {
	int res = 0;
	for (int i = 0; i < n; i++) {
		res = (res + (sq[i] * (int (pow(x, i)) % 1013)) % 1013) % 1013;
	}
	if (res >= min_res && res <= max_res) cnt++;

	return;
}


int main() {
	std::ios::sync_with_stdio(false);
	int T; //�׽�Ʈ ���̽�
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> sq[i];
		}
		
		cin >> min_res >> max_res >> x;

		sort(sq, sq + n);
		do {
			isValid();
		} while ( next_permutation(sq, sq + n) );

		cout << cnt << "\n";

		fill_n(sq, 9, 0);
		cnt = 0;
	}
}