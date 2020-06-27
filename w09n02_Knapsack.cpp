#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int d[500][100001];

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> k;
		vector <pair<int, int > > val_wgt;
		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			val_wgt.push_back(make_pair(0, temp));
		}
		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			val_wgt[i].first = temp;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= k; j++) {
				if (i == 0) {
					for (int l = 0; l <= k; l++) {
						if (val_wgt[0].second <= l)
							d[0][l] = val_wgt[0].first;
					}
					continue;
				}

				if (val_wgt[i].second <= j) {
					d[i][j] = max(d[i - 1][j], d[i - 1][j - val_wgt[i].second] + val_wgt[i].first);
				}

				else {
					d[i][j] = d[i - 1][j];
				}
			}
		}

		cout << d[n - 1][k] << "\n";

		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= k; j++) {
				d[i][j] = 0;
			}
		}
	}
}