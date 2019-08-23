#include <iostream>

using namespace std;

bool isPrime[1121] = {true, true};
int prime[190];
int primeCnt;

int main() {
	for (int i = 2; i < 34; i++) {
		for (int j = i * i; j < 1121; j += i) {
			isPrime[j] = true;
		}
	}
	for(int i = 0; i < 1120; i++) {
		if (isPrime[i] == false) prime[primeCnt++];
	}
	
	int testCnt;
	cin >> testCnt;

	for (int i = 0; i < testCnt; i++) {
		int n; int k;
		cin >> n >> k;



	}

	return 0;
}