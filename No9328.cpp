#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
// ����
// ��� ���ǿ� ���� ��üŽ���� �ϴ� ���, �ð��ʰ��� �߻� ( ����� ���� ������ �ʹ� ���� )
// so, BFS �� ���� �� ������ ���� �ߺ� Ž���� ���ֱ� ����

// �ٱ����� ������ ��� ������ Ž���ϸ�,
// Ž���ϴ� ������ ������ ���� �ൿ�� �з�

#define ALP 26 // ���ĺ�  a~z ���� 26��
#define NUM 100 // ���̰�
#define X "0121"
#define Y "1210"

int main() {	int T, N, M;
	cin >> T;
	while (T--) {
		int ans = 0, keySet = 0; // ���� ��, ���� �ִ� ���� 
		bool visit[NUM][NUM] = {}; // �湮 ����
		char map[NUM][NUM] = {};
		queue<pair<int, int>> bfs;
		queue<pair<int, int>> door[ALP]; // �� ���踦 �䱸�ϴ� ���� ��ǥ

		cin >> N >> M;
		for (int k = 0; k < N; k++) {
			for (int m = 0; m < M; m++) {
				cin >> map[k][m];
				if (k == 0 || k == N - 1 || m == 0 || m == M - 1) {
					// ��� �𼭸� ��ġ�� ���, ���� �������� Ȯ��
					if (map[k][m] != '*') bfs.emplace(k, m); // ���� �ƴϸ� Ž�� �õ�
				}
			}
		}

		string keys;
		cin >> keys;
		keys = (keys == "0") ? "" : keys; // "0" �� ���� ���, ���� Ű�� ����
		for (int k = 0; k < keys.length(); k++) {
			int k_idx = keys[k] - 'a';
			keySet |= (1 << k_idx); // ���� ���踦 ��Ʈ����ŷ���� ǥ��
		}

		while (!bfs.empty()) { // BFS Ž�� ����
			int x, y;
			tie(x, y) = bfs.front();
			bfs.pop();
			
			if (visit[x][y]) continue; // �̹� �ѷ��� ���̸� ����

			// �� ������ ��ġ�� ������ ���� �����Ͽ� ó��
			if (map[x][y] == '*') continue; // ��
			if (map[x][y] == '$') ans += 1; // ����
			if (map[x][y] >= 'a' && map[x][y] <= 'z') { // ����
				int k_idx = map[x][y] - 'a';
				keySet |= 1 << k_idx; // ���踦 ������

				// ������� ������ �� ��, �ش� ���踦 ���� �� �� �ִ� ���� ���� ť�� ����
				while (!door[k_idx].empty()) {
					bfs.push(door[k_idx].front());
					door[k_idx].pop();
				}
			}
			if (map[x][y] >= 'A' && map[x][y] <= 'Z') { // ��
				int d_idx = map[x][y] - 'A';
				if (!(keySet & 1 << d_idx)) {
					// �ش� ���� �� �� �ִ� Ű�� �������� �ʴٸ�
					door[d_idx].emplace(x, y); // �ش� ��ǥ�� ������ ����ص�
					continue; // �ǳʰ�
				}
			}
			visit[x][y] = true; // �湮��

			for (int k = 0; k < 4; k++) { // �� ���⿡ ���� Ž��
				int n_x = x + X[k] - '1', n_y = y + Y[k] - '1';
				if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= M) continue; // ���ָ� ��� ���
				bfs.emplace(n_x, n_y);
			}
		}
		cout << ans << endl;
	}
}