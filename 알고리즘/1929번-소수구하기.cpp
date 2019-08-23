#include <iostream>
#include <math.h>

using namespace std;

int minNum;
int maxNum;
bool isPrime[1000001];

int main() {
	cin >> minNum >> maxNum;

	for (int i = 2; i < sqrt(maxNum); i++) {
		for (int j = i * i; j < maxNum+1; j += i) {
			isPrime[j] = true;
		}
	}

	for (int i = minNum; i < maxNum + 1; i++) {
		if (isPrime[i] == false && i > 1) {
			// cout << i << endl;
			printf("%d\n", i);
		}
	}

	return 0;
}