#include <iostream>
#include <algorithm>

using namespace std;

int arr[10001];
int maxBudget, minBudget;
int output;

int main() {
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		
		maxBudget = max(maxBudget, arr[i]);
		minBudget = min(minBudget, arr[i]);
	}
	scanf("%d", &m);

	int low = minBudget; int high = maxBudget;
	
	while (low <= high) {
		int limit = (low + high) / 2;
		int tmp = 0;

		for (int i = 0; i < n; i++) {
			tmp += min(arr[i], limit);
		}

		if (tmp <= m) {
			output = limit;
			low = limit + 1;
		}
		else
			high = limit - 1;
	}

	printf("%d\n", output);

	return 0;
}