#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int listN[100100];

void findTarget(int start, int end, int target) {
	while (end - start >= 0) {
		int index = (start + end) / 2;

		if (listN[index] == target) {
			printf("1\n");
			return;
		}
		else if (listN[index] < target) {
			start = index + 1;
		}
		else {
			end = index - 1;
		}
	}

	printf("0\n");
}

int main() {
	int n, m, target;

	//cin >> n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &listN[i]);

	sort(listN, listN + n);

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &target);

		findTarget(0, n, target);
	}

	return 0;
}