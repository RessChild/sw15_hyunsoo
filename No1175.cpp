#include<iostream>
#include<queue>
#include<tuple>
#include<vector>
using namespace std;
// ���
// �� ���� ������ �ٲ�� �� + �̹� �湮�� ���� �ٽ� �湮�� �� ����
// so, ���� ����, ��� ������ ������ ���� ������ �����Ͽ� ����, �����ؾ���
// BFS �� �ܼ� 2���� �迭�� �ƴ�, 4���� �迭�� �䱸

#define NUM 50
#define X "0121"
#define Y "1210" // �Ʒ��ʺ��� �ݽð� ����

int N, M, step[NUM][NUM][4][4]; // �� ��ǥ, ���� ����, ��� ����
char map[NUM][NUM];
pair<int, int> from; // ��� ��ǥ
vector<pair<int,int>> to; // ������ ��ǥ (2��)

int main() {
	cin >> N >> M; // �� ũ�� �Է�

	// ���� �Է�
	for (int k = 0; k < N; k++) { 
		for (int m = 0; m < M; m++) {
			cin >> map[k][m];
			if (map[k][m] == 'S') from = pair<int, int>(k, m);
			if (map[k][m] == 'C') to.emplace_back(k, m);
		}
	}

	int ans = -1; // ���� ���� -1
	queue<tuple<int, int, int, int, int>> q; // BFS �� ť

	// �������� ������ ������ ���� �����Ƿ�, 4 ������ ��� ����
	for (int k = 0; k < 4; k++) { 
		q.emplace(from.first, from.second, k, 0, 0);
	}

	while (!q.empty()) { // BFS Ž��
		int x, y, dir, bit, val; // ��ǥ, �ش� �������� �� ����, �湮 ��Ʈ, �̵���
		tie(x, y, dir, bit, val) = q.front();
		q.pop();

		if (map[x][y] == '#') continue; // �������� �� ����
		if (step[x][y][dir][bit]) continue; // �̹� �Դ� �� ����
		for (int k = 0; k < to.size(); k++) {
			if (x == to[k].first && y == to[k].second) { // ������ �� �� ���� �����ߴٸ�,
				bit |= (1 << k); // ������ ���� ���θ� ����
			}
		}

		step[x][y][dir][bit] = val; // ���� ��ġ�� �����ϴµ� ���� ��

		if (bit == 3) { // ��� �������� ������ ���
			ans = val;
			break; // ���� �����ϰ� ����
		}

		for (int k = 0; k < 4; k++) {
			if (dir == k) continue; // ������ �������� 1�� �̻� ���� �Ұ�

			int n_x = x + X[k] - '1', n_y = y + Y[k] - '1'; // �̵��� ��ǥ
			if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= M) continue; // ���ָ� ����� ����
			q.emplace(n_x, n_y, k, bit, val + 1); // Ž�� ť�� ����
		}
	}
	cout << ans << endl; // ���� ���
}