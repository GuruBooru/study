#include <iostream>

using namespace std;

bool calResult(int num) {
	int dec = num; int decResult = 0;
	int duo = num; int duoResult = 0;
	int hex = num; int hexResult = 0;

	while (dec != 0) {
		decResult += dec % 10;
		dec = dec / 10;
	}
	while (duo != 0) {
		duoResult += duo % 12;
		duo = duo / 12;
	}
	while (hex != 0) {
		hexResult += hex % 16;
		hex = hex / 16;
	}

	return (decResult == duoResult) && (duoResult == hexResult);
}
int main() {
	for (int i = 1000; i < 10000; i++) {
		if (calResult(i))
			cout << i << endl;
	}
	return 0;
}