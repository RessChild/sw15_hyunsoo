#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
// ȭ����
// ������ ������ ���� BFS Ž�� ���� (�켱���� ť ���)
// �� �����θ��� ������ �� �ִ� �ð��밡 �����ϸ�, �̸� Ȯ���ϴ� ������ ����� ���� 

#define NUM 20
#define X "1210"
#define Y "2101" // ��, ��, ��, ��
#define IMP "impossible"

typedef tuple<int, int, int, int> t; // ��ǥ, �ð�, �̵� ����

struct func { // �켱���� ť ���� ����
	bool operator()(t a, t b) {
		return get<2>(a) > get<2>(b);
	}
};

int N, M;
char map[NUM][NUM];
pair<int, int> s, e; // �����, ������
int cross[10][3]; // �ִ� 10���� ������, ���� ����, ���� (����), ���� (����)
priority_queue<t, vector<t>, func> pq;

int main() {
	do {
		cin >> N >> M;
		if (!N && !M) break; // ���ᰪ

		int cnt = 0, visit[NUM][NUM] = {}; // �湮 ���� ���
		for (int k = 0; k < N; k++) {
			for (int m = 0; m < M; m++) {
				cin >> map[k][m];
				if (map[k][m] == 'A') s = { k,m }; // �����
				if (map[k][m] == 'B') e = { k,m }; // ������
				if (map[k][m] >= '0' && map[k][m] <= '9') cnt++;
			}
		}
		for (int k = 0; k < cnt; k++) {
			int num;
			char ch;
			cin >> num >> ch; // ������ ��ȣ, ���� ����

			cross[num][0] = (ch != '-') + 1; // 1 �̸� ����, 2 �̸� ����
			cin >> cross[num][1] >> cross[num][2]; // ���� �ð� �Է�
		}

		pq.push({ s.first, s.second, 0, 0 }); // ���������� ���
		while (!pq.empty()) { // �����ο��� �߰�ó���� �ʿ���..
			int x, y, t, d;
			tie(x, y, t, d) = pq.top();
			pq.pop();

			if (visit[x][y]) continue; // �̹� �湮�ߴٸ� ����
			visit[x][y] = t;

			for (int k = 0; k < 4; k++) { // ¦�� : �¿�, Ȧ�� : ����
				int nx = x + X[k] - '1', ny = y + Y[k] - '1';
				if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue; // ���� �ʰ�

				if (map[nx][ny] == '.') continue; // ������ ��
				else if (map[nx][ny] >= '0' && map[nx][ny] <= '9') { // 0~9 ���� ��
					int number = map[nx][ny] - '0';
					int dir = cross[number][0]; // ���� ����
					int total = cross[number][1] + cross[number][2]; // ��ü ����Ŭ �ð�
					int delay = 1; // �⺻ ������ 1��

					if (t % total < cross[number][dir]) { // ���� ������ ����
						if (k % 2 + 1 != dir) { // ������ ��ġ���� ������ �ð��� ���̸�ŭ ������
							delay += cross[number][dir] - (t % total);
						}
					}
					else { // ������ ������ ����
						if (k % 2 + 1 == dir) { // ������ ��ġ���� ������ ó��
							delay += total - (t % total);
						}
					}
					pq.push({ nx, ny, t + delay, k % 2 }); // Ž�� �߰�
				}
				else pq.push({ nx, ny, t + 1, k % 2 }); // �ܼ��� ��
			}
		}
		if (visit[e.first][e.second]) cout << visit[e.first][e.second] << endl;
		else cout << IMP << endl;
	} while (true);
}