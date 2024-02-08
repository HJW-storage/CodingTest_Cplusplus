// https://www.acmicpc.net/problem/14729

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// �Է� n <= 10,000,000     õ���̾ sort �� �ð��ʰ���. nlogn�� �ð��ʰ�.
// �Է� �޴� �л��� ������ �켱���� ť�� �̿��ؼ� �Է� �޴´�.
int n = 0;
int main() {
	priority_queue<float, vector<float>, greater<float>> pq;
	float sco = 0.0f;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> sco;
		pq.push(sco);
	}

	for (int i = 0; i < 7; i++) {
		float tmp = 0.0f;
		tmp = pq.top();
		//cout ǥ���Ϸ��� �߰������� ���� �� �۾��� �ʿ�.�׳� printf����.
		printf("%.3f\n", tmp); // �Ǽ��� printf �� �Ἥ �������. 
		pq.pop();
	}
	return 0;
}