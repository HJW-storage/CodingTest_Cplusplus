// https://www.acmicpc.net/problem/10709

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int h = 0, w = 0, cnt = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> h >> w;
	//ó���� ���� �̵��� ���� 2���� ���� �ϳ� ��ȸ���� ������ �ϳ� ä���, ������ �ϳ� ��ȸ���� ������ �ϳ� ä���
	//�� �����ߴ��� �޸� �ʰ�..... 
	//vector<pair<int, int>> pos_vec;
	//vector<pair<int, int>> next_pos_vec;
	
	//�׷���, ť�� ��ü�ؼ� �����Ͽ���. -> ���ѵ� �޸� �ȿ� �ذᰡ��!!
	queue<pair<int, int>> q;

	vector<vector<int>> res_vec(h, vector<int>(w, -1));

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			char temp = ' ';
			cin >> temp;
			if (temp == 'c') {
				q.push({ i, j });
				//pos_vec.push_back({ i, j });
				res_vec[i][j] = 0;	// �� �� ���� 0���� �ʱ�ȭ.
			}
			else { ; }
		}
	}

	for (int i = 0; i < w - 1; i++) {
		cnt++;
		int q_size = q.size();
		for(int j = 0; j < q_size; j++) {
			int next_row = q.front().first;
			int next_col = q.front().second;
			next_col++;

			if (next_col <= w - 1) {
				q.push({ next_row, next_col });
				// �̹� ������ �������� ���� �� ����Ǹ� �ȵȴ�.
				if (res_vec[next_row][next_col] == -1) {
					res_vec[next_row][next_col] = cnt;
				}
				else { ; }
			}
			q.pop();
		}
	}

	// ���� ���
	for (int i = 0; i < res_vec.size(); i++) {
		for (int j = 0; j < res_vec[0].size(); j++) {
			cout << res_vec[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}