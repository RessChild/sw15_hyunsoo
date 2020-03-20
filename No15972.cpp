#include<iostream>
#include<tuple>
#include<queue>
#include<algorithm>
using namespace std;
// ����ũ
// ���� ������ ���� �ʿ��� ���� ������ �帣��,
// �ڽ��� ���� ���̿� ������ ���� ��, ���� ���� �Ѱ�ġ�� ���� ��
// so, �ܺο� ����� ���� ���������� �켱���� ť�� ����� �׸����� BFS �� ���

#define NUM 1000
#define X "0121"
#define Y "1210"
typedef tuple<int, int, int> bfs_info; // ��ǥ, ����� �ϴ� �� ����

struct func { // Ʃ���� �켱���� ť ���� ���� (���̰��� ���� ������ ����)
	bool operator()(bfs_info a, bfs_info b) {
		return get<2>(a) > get<2>(b);
	}
};

int N, M, H;
int wall[NUM * 2 + 1][NUM * 2 + 1]; // ����ũ ����
priority_queue<bfs_info, vector<bfs_info>, func> pq;
// BFS Ž���� �켱���� ť

int main() {
	cin >> N >> M >> H;
	for (int k = 0; k <= N; k++) { // ���� ��
		for (int m = 0; m < M; m++) {
			cin >> wall[2 * k][2 * m + 1];
			if (k == 0 || k == N) { // �ش� ���� ���̵��� ���
				if (wall[2 * k][2 * m + 1] < 0) continue; // ������ ���ٸ� ����

				// ���� ���̸� �Ʒ��� ����, �Ʒ� ���̸� ���� ����
				pq.emplace(k - (k != 0), m, wall[2 * k][2 * m + 1]);
			}
		}
	}
	for (int k = 0; k < N; k++) { // ���� ��
		for (int m = 0; m <= M; m++) {
			cin >> wall[2 * k + 1][2 * m];
			if (m == 0 || m == M) { // �ش� ���� ���̵��� ���
				if (wall[2 * k + 1][2 * m] < 0) continue;

				// ���� ���̸� ������ ����, ������ ���̸� ���� ����
				pq.emplace(k, m - (m != 0), wall[2 * k + 1][2 * m]);
			}
		}
	}

	int minus = 0; // ������ ���� �� ��
	while (!pq.empty()) { // �켱���� ť Ž��
		int x, y, v; // ��ǥ, ������ϴ� �� ����
		tie(x, y, v) = pq.top();
		pq.pop();

		x = 2 * x + 1;
		y = 2 * y + 1; // ������ ����� ��ǥ�� ��ȯ

		if (wall[x][y]) continue; // ����ũ�� �� ������ �湮 �� �Ǵ����� ���
		wall[x][y] = 1; // �湮��

		minus += H - v; // ���� �ϴ� �� ���
		for (int k = 0; k < 4; k++) { // 4 �������� Ž�� �õ�
			int x_dir = X[k] - '1', y_dir = Y[k] - '1'; // ���� ��
			if (wall[x + x_dir][y + y_dir] < 0) continue; // ������ ���ٸ� ����

			int n_x = x + 2 * x_dir, n_y = y + 2 * y_dir; // ���� ����ũ ��ġ
			if (n_x < 0 || n_x>2 * N || n_y < 0 || n_y >2 * M) continue; // ���ָ� �Ѿ�� ����

			pq.emplace(n_x / 2, n_y / 2, max(v, wall[x + x_dir][y + y_dir]));
			// ���� ��ġ�� ä�� �� vs ���� ��ġ�� �Ѿ ���� ���� �� ū ���� ���� (�Ѱ�ġ)
		}
	}
	cout << N * M * H - minus << endl; // ��ü ���ǿ��� �����ϴ� ���� ����
}