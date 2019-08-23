// 비교부분 수행시간 축소 필요

#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int testNum;
	cin >> testNum;

	for (int i = 0; i < testNum; i++) {
		char record[100][100];
		bool isFox[100];
		int recordCnt = 0;
		char aniSound[3][100];

		for (int j = 0; j < 100; j++) {
			cin >> record[j];
			isFox[j] = true;
			recordCnt++;
			if (cin.get() == '\n') break;
		}

		do {
			for (int j = 0; j < 3; j++) {
				cin >> aniSound[j];
			}

			if (strcmp(aniSound[1], "does")) {
				for (int j = 0; j < recordCnt; j++) {
					if (!strcmp(record[j], aniSound[2])) {
						if (!isFox[j]) continue;
						else isFox[j] = false;
					}
				}
			}

		} while (strcmp(aniSound[1], "does"));

		for (int j = 0; j < recordCnt; j++) {
			if (j > 0 && isFox[j - 1])
				printf(" ");
			if (isFox[j])
				printf("%s", record[j]);
		}

		printf("\n");
	}

	return 0;
}