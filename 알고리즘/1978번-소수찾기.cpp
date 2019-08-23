#include <iostream>

using namespace std;

int prime[1001];
int output;

int main() {
	for (int i = 2; i < 32; i++) {
		if (prime[i] == 0) {
			for (int j = i * i; j < 1001; j += i) {
				prime[j] = 1;
			}
		}
	}

	int caseNum;
	cin >> caseNum;

	for (int i = 0; i < caseNum; i++) {
		int testCase;
		cin >> testCase;

		if (testCase == 1)
			continue;
		if (prime[testCase] == 0)
			output++;
	}

	cout << output << endl;

	return 0;
}