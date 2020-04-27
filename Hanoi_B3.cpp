#include <iostream>
#define MAX 10002
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int t = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n = 0;
		int cnt = 0;
		cin >> n;
		int block_arr[MAX];
		fill_n(block_arr, MAX, 0);
		for (int j = 0; j < n; j++) {
			int block;
			cin >> block;
			if (block_arr[block + 1] == 0) {
				cnt++;
				block_arr[block]++;
			}
			else {
				block_arr[block + 1]--;
				block_arr[block]++;
			}
		}
		cout << cnt << "\n";

	}
}
