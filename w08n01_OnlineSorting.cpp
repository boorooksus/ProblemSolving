#include <iostream>
#include <algorithm>
using namespace std;

int m, n;
int slot[101];
int score[101];

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		cin >> m >> n;
		for (int i = 1; i <= m; i++) {
			cin >> score[i];
		}
		for (int i = 1; i <= m; i++) {
			int num, slot_num;
			cin >> num >> slot_num;
			slot[slot_num] = num;
		}

		int cnt = 1;
		int ans = 0;
		for (int i = 2; i <= m; i++) {
			if (slot[i - 1] > slot[i]) {
				ans += score[cnt];
				cnt = 1;
				//i++;
			}
			else {
				cnt++;
			}
		}
		ans += score[cnt];

		cout << ans << "\n";

		fill_n(slot, 101, 0);
		fill_n(score, 101, 0);
	}
}