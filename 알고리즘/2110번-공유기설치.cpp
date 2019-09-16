#include <iostream>
#include <algorithm>

using namespace std;

int node[200001];
int maxNode;

int main() {
	int n, c;
	cin >> n >> c;

	for (int i = 0; i < n; i++) {
		cin >> node[i];
		maxNode = max(maxNode, node[i]);
	}
	sort(node, node + n);

	int low = 0;
	int high = maxNode;
	int result = 0;

	while (low <= high) {
		int dis = (high + low) / 2;
		int cnt = 1;
		int start = node[0];

		for (int i = 1; i < n; i++) {
			int d = node[i] - start;

			if (dis <= d) {
				cnt++;
				start = node[i];
			}
		}

		if (cnt < c) {
			high = dis - 1;
		}
		else {
			low = dis + 1;
			result = dis;
		}
	}

	cout << result << endl;
	return 0;
}