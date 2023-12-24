// https://www.acmicpc.net/problem/4375

#include <iostream>
#include <algorithm>

typedef long long ll;

using namespace std;
int n;

int main() {
	while (scanf("%d", &n) != EOF) {
		ll ret = 1, multi_n = 1;
		while(1) {
			if (multi_n % n == 0) {
				cout << ret << "\n";
				break;
			}
			// multi_n = multi_n * 10 + 1;  // �����÷ο찡 �߻�. ��ⷯ ���� Ư���� �̿��Ѵ�.
			multi_n = (multi_n % n) * (10 % n) + (1 % n);
			ret++;
		}
	}

	return 0;
}