#include <iostream>
#include <vector>
using namespace std;

struct item {
	//string name;
	int start = 10000;
	int end = 0;
};

int dfs(item[], int start, int n, int deadline, int[]);

int main() {
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n; //n : number of items
		cin >> n;
		item* items = new item[n + 1];
		//latest : 가장 마지막에 개발 시작하하는 아이템 시작일
		int latest = 0;
		for (int j = 1; j <= n; j++) {
			string name;
			int start, end;
			cin >> name >> start >> end;
			items[j] = { start, end };
			if (start > latest) {
				latest = start;
			}
		}
		//dynamic : start 인자에 따른 dfs함수 값 저장
		//int* dynamic = new int[deadline + 1];
		int dynamic[10001];
		//fill_n(dynamic, deadline + 1, 0);
		fill_n(dynamic, 10001, 0);
		//출력
		//cout << "============================" << dfs(items, 0, n, deadline, dynamic) << "\n";
		cout << dfs(items, 0, n, latest, dynamic) << "\n";
	}

	return 0;
}

int dfs(item items[], int start, int n, int latest, int dynamic[]) {
	//이미 계산되어 있으면 리턴
	if (dynamic[start] != 0) {
		return dynamic[start];
	}

	if (start > latest) return 0;

	int max = 0;
	for (int i = 1; i <= n; i++) {
		if (items[i].start >= start) {
			//cnt++;
			int get = dfs(items, items[i].end, n, latest, dynamic) + 1;
			if (max < get) {
				max = get;
			}
		}
	}

	dynamic[start] = max;

	return max;
}
