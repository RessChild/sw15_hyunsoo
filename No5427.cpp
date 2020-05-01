#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
// ��
// �Ұ� ����� ������ ���� BFS Ž���� �ʿ�
// �ʱⰪ���� ���� ������ ������ �߻��Ͽ� ������ ��µǴ� ������ �־���

#define NUM 1000
#define X "1210"
#define Y "2101"
#define IMP "IMPOSSIBLE"

int W, H, time[NUM + 1][NUM + 1], visit[NUM + 1][NUM + 1]; // ����, ����, ���� �ɸ� �ð�, �湮����
char map[NUM + 1][NUM + 1]; // ����

int main() {
	int N;
	cin >> N;
	while (N--) { // �׽�Ʈ ���̽�
		cin >> W >> H;

		queue<tuple<int, int, int>> q[2]; // BFS �� ť (��, ���)
		for (int k = 1; k <= H; k++) {
			for (int m = 1; m <= W; m++) {
				cin >> map[k][m];
				time[k][m] = visit[k][m] = 0;


				if (map[k][m] == '*') q[0].emplace(k, m, 0);
				if (map[k][m] == '@') q[1].emplace(k, m, 0); // ���� ����
			}
		}

		while (!q[0].empty()) { // ���� �̵��� ���� ��ó��
			int x, y, v;
			tie(x, y, v) = q[0].front();
			q[0].pop();

			if (time[x][y]) continue; // �湮�� ���̸� ����
			time[x][y] = v; // �ش� ��ϱ��� ���� ������ �ּ� �ð�

			for (int k = 0; k < 4; k++) {
				int nx = x + X[k] - '1', ny = y + Y[k] - '1';
				if (nx < 1 || nx > H || ny < 1 || ny > W) continue; // ���� ���̸� ����
				if (map[nx][ny] == '#' || map[nx][ny] == '*') continue; // ���̰ų�, �̹� ���� ��쵵 ����
				q[0].push({ nx,ny, v + 1 }); // �̵� ���� ����
			}
		}

		int ans = 0;
		while (!q[1].empty()) { // ��� ��츦 ���캽
			int x, y, v;
			tie(x, y, v) = q[1].front();
			q[1].pop();

			if (visit[x][y]) continue; // �湮�� ���̸� ����
			if (time[x][y] && v >= time[x][y]) continue; // ���� ��� �ð����� ���� ��� �Ұ���
			// �ɸ��� �ð��� �ʱ� ���� 0 �̹Ƿ�, ����ó�� �ʿ�
			visit[x][y] = 1;

			for (int k = 0; k < 4; k++) {
				int nx = x + X[k] - '1', ny = y + Y[k] - '1';
				if (nx < 1 || nx > H || ny < 1 || ny > W) { // ���� �Ѿ�� Ż�� ����
					ans = v + 1; // �ʿ��� �ּ� �ð�
					break; // �ݺ��� ����
				}
				if (map[nx][ny] == '#' || map[nx][ny] == '*') continue; // ��, ���̸� �̵� �Ұ�
				q[1].push({ nx,ny, v + 1 }); // �̵� ���� ����
			}
			if (ans) break; // ���� �ִٸ� �ݺ��� ����
		}
		if (ans) cout << ans << endl;
		else cout << IMP << endl; // ���� �� ���ٸ� �Ұ���
	}
}