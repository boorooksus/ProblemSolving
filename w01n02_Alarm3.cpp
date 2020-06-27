#include <iostream>
#include <queue>
using namespace std;


int cntArr[201];
int n, d;

double getMedian() {
	int cur = 0;
	double median = 0.00;
	if (d % 2 == 1) {
		for (int i = 0; i < 201; i++) {
			cur += cntArr[i];
			if (cur > d / 2) {
				median = double(i);
				break;
			}
		}
	}
	else {
		int fs = 0;
		for (int i = 0; i < 201; i++) {
			cur += cntArr[i];

			if (cur == d / 2 && fs == 0) {
				fs = i;
			}

			if (cur > d / 2 && fs == 0) {
				median = double(i);
				break;
			}

			else if (cur > d / 2 && fs != 0) {
				median = (double(fs) + double(i)) / 2.00;
				break;
			}
		}

	
	}

	return median;
}

int main() {
	std::ios::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--) {
		queue <int> expen;
		int alarm_cnt = 0;

		cin >> n >> d;
		for (int i = 0; i < d; i++) {
			int temp = 0;
			cin >> temp;
			expen.push(temp);
			cntArr[temp]++;
		}

		for (int i = d; i < n; i++) {
			int temp = 0;
			cin >> temp;
			double median = getMedian();
			if (double(temp) >= median * 2.00) {
				alarm_cnt++;
			}

			expen.push(temp);
			cntArr[temp]++;
			cntArr[expen.front()]--;
			expen.pop();
		}

		cout << alarm_cnt << "\n";

		fill_n(cntArr, 201, 0);
	}

}