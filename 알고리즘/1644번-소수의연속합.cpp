#include <iostream>
#include<math.h>

using namespace std;

bool isPrime[4000001] = { true, true };
int primePool[300000];
int poolCnt;
int minPrime;
int testCase;
int tmp;
int output;

int main() {
	cin >> testCase;

	for (int i = 2; i < sqrt(testCase); i++) {
		for (int j = i * i; j < testCase + 1; j += i) {
			if (isPrime[j] == false) {
				isPrime[j] = true;
			}
		}
	}
	for (int i = 0; i < testCase; i++) {
		if (isPrime[i] == false)
			primePool[poolCnt++] = i;
	}

	if (isPrime[testCase] == false)
		output++;

	for (int i = 0; i < poolCnt; i++) {
		if (tmp < testCase) {
			tmp += primePool[i];
		}
		else {
			tmp -= primePool[minPrime++];
			i--;
		}

		if (tmp == testCase)
			output++;
	}

	cout << output << endl;

	return 0;
}