// https://www.acmicpc.net/problem/2529
// Ǯ�̽ð� 1�ð� 10��. 
// ������ Ǯ��� �ϴµ� ó���� �������� �������Ͽ� �ð� �Һ��Ͽ���.
// make_permutation �����ϴµ� �����ŷȴ�. 

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
int n = 10; // 0 ~ 9 ������ �� �����̱⿡ n = 10���� �����Ѵ�. 
int k = 0;
char duengho[10];	// �ε�ȣ ���� �迭. 
string num_str;
vector<string> res; // string���� �����ؾ��Ѵ�. k = 9�� ��� 90�� ���� �����̹Ƿ� int�� �ʰ��̴�.

// ���� �� �����ߴ��� ����ϸ� Ȯ���غ���.
void printV(int r, vector<int>& v) {
	for (int i = 0; i < r; i++) {
		cout << v[i] << " ";
	}
	cout << "\n";
	return;
}
// ���� �� ������ �ε�ȣ�� �����ؼ� ������ �˻��ϱ�.
bool check(int r, vector<int> &v) {
	for (int i = 0; i < r - 1; i++) {
		if (duengho[i] == '<') {
			if (v[i] < v[i + 1]) { ; }
			else { return false; }
		}
		else if (duengho[i] == '>') {
			if (v[i] > v[i + 1]) { ; }
			else { return false; }
		}
		else { ; }
	}
	return true;
}
// ���� �����ϱ�.
void make_permutation(int depth, int r, vector<int> &v) {
	// �������
	if (depth == r) {
		//printV(k+1, v);

		// �˻� ���� �߰�. 
		if (check(r, v)) {
			num_str = ""; // �� ���ڿ��� �ʱ�ȭ
			for (int i = 0; i < r;i++) {
				num_str += to_string(v[i]);	// string���� ����ȯ.
			}
			res.push_back(num_str);
		}
		return;
	}

	for (int i = depth; i < n; i++) {
		swap(v[i], v[depth]);
		make_permutation(depth+1, r, v);
		swap(v[i], v[depth]);
	}
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> duengho[i];
	}
	
	vector<int> v = { 0,1,2,3,4,5,6,7,8,9 };
	make_permutation(0, k + 1, v);

	// ���ڿ� ��� �񱳴� ���ʺ��� �ƽ�Ű�ڵ� ������� ���Ѵ�.
	// ����, cmp ������Լ��� ����
	//							 1������ ���ڿ� ���̸� ���� ���ϰ�
	//							 2������ ���ʺ��� �ƽ�Ű �ڵ� ���ؾ��Ѵ�.
	
	// �׷���, �ش繮���� ���ڿ��� ���̰� �����ϱ⿡ �׳� sort �Լ��� ����ص� �ȴ�.
	sort(res.begin(), res.end());
	
	// �ִ밪 ���, �ּڰ� ���.
	cout << *(res.end() - 1) << "\n";
	cout << res[0] << "\n";

	return 0;
}