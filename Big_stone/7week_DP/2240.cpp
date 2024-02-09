// https://www.acmicpc.net/problem/2240#include <iostream>#include <algorithm>
using namespace std;

#define MAX 1004

int plum[MAX][3];
int T, W;

//���� �ð� i, �̵� Ƚ�� j, ���� ��ġ k ��θ� ������ 3���� �迭 count[i][j][k]�� �̿��Ͽ� ���� ���� ������ ����.
//count[i][j][1] = max(count[i - 1][j][1], count[i - 1][j - 1][2]) + (plum[i] == 1)
//count[i][j][2] = max(count[i - 1][j - 1][1], count[i - 1][j][2]) + (plum[i] == 2)

int DP() {
    int result = 0; // ���� ���
    int count[MAX][32][3]; // �ڵ� ���� ���� �迭

    // �ʱ�ȭ
    fill(&count[0][0][0], &count[0][0][0] + MAX * 32 * 3, 0);
    
    // �ʱ� ���
    count[1][0][1] = plum[1][1];
    count[1][1][2] = plum[1][2];

    result = max(count[1][0][1], count[1][1][2]);

    for (int i = 2; i <= T; i++) {
        for (int j = 0; j <= W; j++) {
            if (j > i) continue;
            if (j == 0) { 
                // �Ʒ� �˻�� j==0 �϶�, [j-1] �ε����� ������ ���̴� ���� ����ó��.
                // �ڵ��� ������ġ�� 1�� ���� �����̹Ƿ�, count[i][0][2]�� ���� �������� �ʴ´�.
                //                                        �ּ� count[i][1][2] ���� ��찡 �����Ѵ�.
                count[i][j][1] = count[i - 1][j][1] + plum[i][1];
                result = max(result, count[i][j][1]);
                continue;
            }
            count[i][j][1] = max(count[i - 1][j][1], count[i - 1][j - 1][2]) + plum[i][1];
            count[i][j][2] = max(count[i - 1][j - 1][1], count[i - 1][j][2]) + plum[i][2];

            result = max(max(result, count[i][j][1]), count[i][j][2]);
        }
    }
    return result;
}

int main(void) {
    cin >> T >> W;

    for (int i = 1; i <= T; i++) {
        int num;
        cin >> num;
        plum[i][num] = 1;
    }

    cout << DP() << "\n";
    return 0;
}
