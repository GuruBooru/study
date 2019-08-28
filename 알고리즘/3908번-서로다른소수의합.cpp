#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

bool isPrime[1121];
int sizeMax = 1120;

int prime[1121] = { 0 };
int primeCnt = 1;

int pCnt[1130][15] = { 1 };

void eratosthenes() {
	memset(isPrime, 1, sizeof(isPrime));

	isPrime[0] = isPrime[1] = false;
	int sqrtMax = int(sqrt(sizeMax));

	for (int i = 2; i <= sqrtMax; i++) {
		if(isPrime[i])
			for (int j = i * i; j <= sizeMax; j += i) {
				isPrime[j] = false;
			}
	}

	for (int i = 2; i <= sizeMax; i++) {
		if (isPrime[i])
			prime[primeCnt++] = i;
	}
}

int main() {
	eratosthenes();

	for (int i = 1; i < primeCnt; i++) {
		for (int j = sizeMax; j >= prime[i]; j--) {
			for (int k = 1; k <= 14; k++) {
				pCnt[j][k] += pCnt[j - prime[i]][k - 1];
			}
		}
	}

	int testCnt;
	cin >> testCnt;

	for (int i = 0; i < testCnt; i++) {
		int n; int k;
		cin >> n >> k;

		cout << pCnt[n][k] << endl;
	}

	return 0;
}