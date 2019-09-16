#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int k, n;
int maxSize = INT_MAX;
int output;

int main() {
	scanf("%d %d", &k, &n);
	int* arr = new int[k + 1];
	for (int i = 0; i < k; i++) {
		scanf("%d", &arr[i]);
	}

	long long limit;
	long long low = 0; long long high = maxSize;

	while (low <= high) {
		limit = (low + high) / 2;
		int tmp = 0;
		
		for (int i = 0; i < k; i++) {
			tmp += arr[i] / limit;
		}

		if (tmp >= n) {
			if(limit > output)
				output = limit;
			low = limit + 1;
		}
		else {
			high = limit - 1;
		}
	}

	cout << output << endl;
	delete[] arr;
	return 0;
}