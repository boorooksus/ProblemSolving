#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

string s, r;
int d[1001][1001];

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		cin >> s >> r;

		for (int i = 1; i <= s.length(); i++) {
			for (int j = 1; j <= r.length(); j++) {
				if (s[i - 1] == r[j - 1]) {
					d[i][j] = max(d[i - 1][j], max(d[i][j - 1], d[i - 1][j - 1] + 1));
				}
				else {
					d[i][j] = max(d[i - 1][j], max(d[i][j - 1], d[i - 1][j - 1]));
				}
			}
		}

		cout << d[s.length()][r.length()] << "\n";
	}
}

//    a a c
//  0 0 0 0
//d 0 0 0 0
//a 0 1 1 1
//f
