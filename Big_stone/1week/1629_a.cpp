// https://www.acmicpc.net/problem/1629
// �ð��ʰ��� ���̴� ��
// ���� ������ Ư���� Ȱ���Ͽ� Ǯ��. 

#include <iostream>
#include <algorithm>

typedef long long ll;
using namespace std;
ll a, b, c;

ll solve(ll a, ll b) {
	if (b == 1) {
		return a % c;
	}
	ll result = solve(a, b / 2);
	result = (result * result) % c;
	
	// Ȧ���� ���� �� ó�� b/2 ����ϸ鼭 �ѹ��� ���󰬱⿡ �߰��� �ѹ� ���ؼ� ������ ������ �߰��Ѵ�.
	if (b % 2 != 0) {
		result = (result * a) % c;
	}
	return result;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b >> c;
	cout << solve(a, b) << "\n";

	return 0;
}