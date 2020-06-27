#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
	int parent;
	int treesz;
};

int n;
int cost[1001];
int pakage[1001];
node nodes[1001];

int getParent(int x) {
	if (x == nodes[x].parent) return x;
	return nodes[x].parent = getParent(nodes[x].parent);
}

void unionParent(int x, int y) {
	x = getParent(x);
	y = getParent(y);
	if (x < y) {
		nodes[y].parent = x;
		nodes[x].treesz += nodes[y].treesz;
	}
	else {
		nodes[x].parent = y;
		nodes[y].treesz += nodes[x].treesz;
	}
}

int mst() {
	int product_cost = 0;
	for (int i = 1; i <= n; i++) {
		product_cost += cost[i];
	}

	for (int i = 0; i <= n; i++) {
		nodes[i].parent = i;
		nodes[i].treesz = 1;
	}

	vector <pair< int, pair< int, int> > > edges;

	for (int i = 1; i <= n; i++) {
		edges.push_back(make_pair(cost[i], make_pair(0, i)));

		if (i == 1) continue;

		edges.push_back(make_pair(pakage[i], make_pair(i - 1, i)));
	}

	sort(edges.begin(), edges.end());

	int sub_cost = 0;
	for (int i = 0; i < edges.size(); i++) {
		int u = edges[i].second.first;
		int v = edges[i].second.second;
		int u_parent = getParent(u);
		int v_parent = getParent(v);

		if (u_parent != v_parent) {
			unionParent(u_parent, v_parent);
			sub_cost += edges[i].first;
		}
	}

	return product_cost + sub_cost;
}

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> cost[i] >> pakage[i];
		}

		cout << mst() << "\n";

		fill_n(cost, 1001, 0);
		fill_n(pakage, 1001, 0);
	}
}