//https://www.acmicpc.net/problem/13913

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
#define prev aaa
#define next aaaa
const int max_n = 200004;
int visited[max_n], prev[max_n], n, k, ret, here, cnt, next;

int main() {
    vector<int> v;
    queue<int> q;
    cin >> n >> k;
    visited[n] = 1; // �湮ó��
    q.push(n);
    while (q.size()) {
        here = q.front();
        q.pop();
        if (here == k) {
            ret = visited[k];
            break;
        }

        for (int next : {here + 1, here - 1, 2 * here}) {
            if ((next >= 0 && next < max_n) && visited[next] == 0) {
                visited[next] = visited[here] + 1;  // �ּ� �Ÿ� �� �湮 ó��
                prev[next] = here;  // ��� ����
                q.push(next);
            }
        }
    }
    
    for (int i = k; i != n; i = prev[i]) {
        v.push_back(i);
    }
    v.push_back(n);

    cout << ret - 1 << '\n';
    reverse(v.begin(), v.end());
    for (int i : v) cout << i << ' ';
    return 0;
}