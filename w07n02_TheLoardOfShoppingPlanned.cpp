#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int cost[1001];
int package[1001];
int parent[1001];
int treesize[1001];
int product_cost, sub_cost;


int findRoot(int u) {
	if (parent[u] == u) return u;
	return parent[u] = findRoot(parent[u]);
}

void updateRoot(int root_u, int root_v) {
	if (treesize[root_u] < treesize[root_v]) {
		parent[root_u] = root_v;
		treesize[root_v] += treesize[root_u];
	}
	else {
		parent[root_v] = root_u;
		treesize[root_u] += treesize[root_v];
	}
}

void mst() {
	vector<pair< int, pair<int, int> > > edgesVector;
	product_cost = 0;
	sub_cost = 0;

	for (int i = 0; i <= n; i++) {
		parent[i] = i;
		treesize[i] = 1;
	}

	for (int i = 1; i <= n; i++) {
		product_cost += cost[i];
		edgesVector.push_back(make_pair(cost[i], make_pair(i, 0)));
		if (i == 1) continue;
		edgesVector.push_back(make_pair(package[i], make_pair(i - 1, i)));
	}

	sort(edgesVector.begin(), edgesVector.end());

	for (int i = 0; i < edgesVector.size(); i++) {
		int u = edgesVector[i].second.first;
		int v = edgesVector[i].second.second;
		int cost = edgesVector[i].first;
		int root_u = findRoot(u);
		int root_v = findRoot(v);

		if (root_u != root_v) {
			updateRoot(root_u, root_v);
			sub_cost += cost;
		}
	}

	cout << product_cost + sub_cost << "\n";

}

int main() {
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> cost[i] >> package[i];
		}
		mst();
	}
}