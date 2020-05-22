#include<iostream>
#include<vector>
#include<tuple>
#include<queue>
#include<algorithm>
using namespace std;
// Gaaaaaaaaaarden
// ���Ǵ� ������ ������ 2�� ���̸�, �ش� ������ ������ ����Ǵ� ������ '����'
// so, �ߺ��Ǵ� ���� �̸�������̼����� ó���Ͽ� �ð� ������ ����
// ����, �� ������ ���� ���� �� ������ Ȯ���� �Ұ����ϹǷ� ����ó���� �ʿ�

#define NUM 50
#define BIT ( 1 << 10 ) // �̸�������̼� �䱸 ũ�Ⱚ
#define X "0121"
#define Y "1210"

int N, M, G, R;
int map[NUM][NUM], cnt[BIT][BIT]; // ����, Ž���� stack ����
vector<pair<int, int>> spot; // ������ ���� �� �ִ� ���

int DFS(int c, int idx, int g_bit, int r_bit) { // ���� ���� �� BFS Ž�� �Լ�
	if (!c) { // 0�� ��� (�ʷϻ�)
		if (idx == G) { // ��� �ʷϻ��� �� ������ ���
			int ans = 0;
			for (int k = 0; k < spot.size(); k++) {
				if ((g_bit | r_bit) & (1 << k)) continue; // �̹� ����� ������ �ǳʰ�
				ans = max(ans, DFS(1, 1, g_bit, r_bit | (1 << k)));
			}
			return ans;
		}
		int ans = 0;
		for (int k = 0; k < spot.size(); k++) { // ���� �ʷϻ��� ���� ���� ���
			if ((g_bit | r_bit) & (1 << k)) continue; // �̹� ����� ������ �ǳʰ�
			ans = max(ans, DFS(c, idx + 1, g_bit | (1 << k), r_bit));
		}
		return ans;
	}

	if (idx == R) { // ��� �������� �� ������ ���
		if (cnt[g_bit][r_bit]) return cnt[g_bit][r_bit]; // ������ ó���� ���� �ִٸ� �� ���� ��ȯ

		int bfs[NUM][NUM][2] = {};
		queue<tuple<int, int, int, int>> q; // BFS �� ť
		queue<tuple<int, int, int, int>> s_q; // Ȯ��� ť

		int s_bit = g_bit; // ����� ��Ʈ
		for (int k = 0; s_bit != 0;k++) { // �ʷ� ������ ���� �ڸ�
			if (s_bit % 2) { // �ش� ��ȣ�� �ڸ��� ����� ���
				int x, y;
				tie(x, y) = spot[k];
				q.emplace(x, y, 0, 1); // BFS ť�� ����
			}
			s_bit /= 2;
		}

		s_bit = r_bit;
		for (int k = 0; s_bit != 0; k++) { // ���� ������ ���� �ڸ�
			if (s_bit % 2) {
				int x, y;
				tie(x, y) = spot[k];
				q.emplace(x, y, 1, 1);
			}
			s_bit /= 2;
		}
		
		while (q.size() || s_q.size()) { // �� ��� ������� �� ���� �ݺ�
			while (!q.empty()) { // BFS Ž��
				int x, y, c, v;
				tie(x, y, c, v) = q.front();
				q.pop();

				if (!map[x][y]) continue; // �� �� ���� ���� ��� ����

				if (bfs[x][y][c]) continue; // �̹� �湮�� �� ����
				bfs[x][y][c] = v; // �ش� ������ �湮���� ǥ��

				if (bfs[x][y][!c]) continue; // �� ���⵵ �̹� �湮�� ����� Ȯ�� ť�� ���� x (�ߺ� ����)
				s_q.emplace(x, y, c, v);
			}

			while (!s_q.empty()) { // �ش� �������� �ٸ� ������ Ȯ���� ���ΰ�?
				int x, y, c, v;
				tie(x, y, c, v) = s_q.front();
				s_q.pop();

				if (bfs[x][y][!c]) { // �ٸ� ���� �̹� ������ ���
					if (bfs[x][y][!c] == bfs[x][y][c]) cnt[g_bit][r_bit] += 1; // ���� �ð��뿡 �����ϸ� ���� �ǿ�
					continue; // ���� ���ο� ������� �� �̻� Ȯ�� �Ұ�
				}

				for (int k = 0; k < 4; k++) { // �� �������� Ȯ��
					int n_x = x + X[k] - '1', n_y = y + Y[k] - '1';
					if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= M) continue; // ���ָ� ����� ����
					q.emplace(n_x, n_y, c, v + 1);
				}
			}
		}
		return cnt[g_bit][r_bit] = cnt[g_bit][r_bit] ? cnt[g_bit][r_bit] : -1; // ���� �ƿ� ������ -1
	}

	int ans = 0;
	for (int k = 0; k < spot.size(); k++) { // ���� �������� ���� ���� ���
		if ((g_bit | r_bit) & (1 << k)) continue; // �̹� ����� ������ �ǳʰ�
		ans = max(ans, DFS(c, idx + 1, g_bit, r_bit | (1 << k)));
	}
	return ans;
}

int main() {
	cin >> N >> M >> G >> R;

	for (int k = 0; k < N; k++) {
		for (int m = 0; m < M; m++) { // �� �Է�
			cin >> map[k][m];
			if (map[k][m] == 2) spot.emplace_back(k, m); // ������ �Ѹ� �� �ִ� ��
		}
	}

	int ans = DFS(0, 0, 0, 0);
	cout << (ans < 0 ? 0 : ans) << endl; // ������ ���, 0���� ��� ( ���� ���� ���� )
}