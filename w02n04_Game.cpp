#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		cin >> n;

		vector<pair<int, int> > end_start;
		for (int i = 0; i < n; i++) {
			string item_name;
			int end, start;
			cin >> item_name >> start >> end;

			end_start.push_back(make_pair(end, start));
		}

		sort(end_start.begin(), end_start.end());

		int cnt = 1;
		int cur = 0;
		for (int i = 1; i < end_start.size(); i++) {
			if (end_start[cur].first <= end_start[i].second) {
				cnt++;
				cur = i;
			}
		}

		cout << cnt << "\n";
	}
}