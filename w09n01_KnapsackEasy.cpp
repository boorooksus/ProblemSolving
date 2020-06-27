#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;
int weight[500];
int value[500];

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> weight[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> value[i];
		}

		vector <int> v;
		for (int i = 0; i < n; i++) {
			int temp = value[i] / weight[i];
			for (int j = 0; j < weight[i]; j++) {
				v.push_back(-temp);
			}
		}

		sort(v.begin(), v.end());

		int ans = 0;
		for (int i = 0; i < v.size(); i++) {
			if (i >= k) break;

			ans += -v[i];
		}

		cout << ans << "\n";
	}
}