#include <iostream>
#define MAX 10000
using namespace std;

int getMin(string s, string r);

int main() {
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string s, r;
		cin >> s >> r;
		cout << getMin(s, r) << "\n";
	}

	return 0;
}

int getMin(string s, string r) {
	int window[58];
	fill_n(window, 58, 0);
	int rCnt[58];
	fill_n(rCnt, 55, 0);
	int min = MAX;
	int start = 0;
	int end = 0;
	int cnt = 0;

	for (int i = 0; r[i] != '\0'; i++) {
		rCnt[r[i] - 65]++;
	}

	while (end < s.length()) {
		window[s[end] - 65]++;
		if (window[s[end] - 65] <= rCnt[s[end] - 65]) {
			cnt++;
		}
		while (cnt == r.length()) {
			int len = end - start + 1;
			if (len < min) {
				min = len;
			}
			if (window[s[start] - 65] <= rCnt[s[start] - 65]) {
				cnt--;
			}
			window[s[start] - 65]--;
			start++;
		}
		end++;
	}
	if (min == MAX)
		return 0;
	return min;
}