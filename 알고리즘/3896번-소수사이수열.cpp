#include <iostream>

using namespace std;

bool isPrime[1300000] = { true, true };

int main() {
	int testCnt;

	cin >> testCnt;

	for (int i = 2; i < 1141; i++) {
		for (int j = i * i; j < 1300000; j += i) {
			isPrime[j] = true;
		}
	}

	for (int i = 0; i < testCnt; i++) {
		int testCase;
		cin >> testCase;

		int startNum = testCase - 1;
		int endNum = testCase + 1;

		if (isPrime[testCase] == false)
			cout << 0 << endl;
		else {
			while (isPrime[startNum] || isPrime[endNum]) {
				if (isPrime[startNum])
					startNum--;
				if (isPrime[endNum])
					endNum++;
			}

			cout << endNum - startNum << endl;
		}
	}

	return 0;
}