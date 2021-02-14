#include <iostream>
#include <string>
#include <queue>
using namespace std;

int T, res;
string s, r;
int cnt[58];

bool check() {
	for (int i = 0; i < 58; i++) {
		if (cnt[i] < 0)
			return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		res = 10000;
		fill_n(cnt, 58, 0);

		cin >> s >> r;

		for (int i = 0; r[i] != '\0'; i++)
			cnt[r[i] - 65]--;

		queue <char> window;
		int left = 0, right = 0;
		window.push(s[0]);
		cnt[s[0] - 65]++;

		while (true) {
			if (check()) {
				res = min(res, right - left + 1);
				left++;
				cnt[window.front() - 65]--;
				window.pop();
			}
			else {
				right++;
				if (right > s.length())
					break;

				cnt[s[right] - 65]++;
				window.push(s[right]);
			}
		}

		if (res == 10000)
			res = 0;

		cout << res << "\n";
	}
}