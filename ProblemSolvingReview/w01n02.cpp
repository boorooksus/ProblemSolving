#include <iostream>
#include <queue>
using namespace std;

int T, n, d, expen, res;
int expen_cnt[201];

double getMedian() {
	double median;
	int cnt = 0;
	if (d % 2 == 1) {
		for (int i = 1; i < 201; i++) {
			cnt += expen_cnt[i];
			if (cnt > d / 2) {
				median = (double)i;
				break;
			}
		}
	}
	else {
		int fs = 0;
		for (int i = 0; i < 201; i++) {
			cnt += expen_cnt[i];
			if (cnt == d / 2 && fs == 0) {
				fs = i;
			}
			else if (cnt > d / 2 && fs == 0) {
				median = (double)i;
				break;
			}
			else if (cnt > d / 2 && fs != 0) {
				median = (double)(i + fs) / 2.0;
				break;
			}
		}
	}

	return median;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		queue <int> q;
		res = 0;
		cin >> n >> d;

		for (int i = 0; i < n; i++) {
			cin >> expen;
			if (i >= d) {
				double median = getMedian();
				if (expen >= 2.0 * median) {
					res++;
				}
				expen_cnt[q.front()]--;
				q.pop();
			}
			expen_cnt[expen]++;
			q.push(expen);
		}

		cout << res << "\n";

		fill_n(expen_cnt, 201, 0);
	}
}