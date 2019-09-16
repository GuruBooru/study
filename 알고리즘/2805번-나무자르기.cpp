#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
long long trees[1000001];
long long maxTree;
long output;

int main() {
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &trees[i]);
		maxTree = max(maxTree, trees[i]);
	}

	long long low = 0; long long high = maxTree;
	long long mid;
	long long result;

	while (low <= high) {
		mid = (low + high) / 2;
		result = 0;

		for (int i = 0; i < n; i++) {
			if (trees[i] > mid)
				result += trees[i] - mid;
		}

		if (result >= m) {
			if(output < mid)
				output = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}

	printf("%d\n", output);
	return 0;
}