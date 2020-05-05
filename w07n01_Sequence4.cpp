#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int sq[9]; //N개의 자연수를 저장하는 수열
int cnt = 0; //조건을 만족하는 수열 개수
int n; //자연수의 개수(N)
int min_res, max_res, x; //특정 범위를 나타내는 수(a, b), 특정 수

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
	int T; //테스트 케이스
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