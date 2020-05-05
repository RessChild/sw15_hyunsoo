#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
// ��!
// BFS Ž�� ����

#define NUM 1000
#define X "1210"
#define Y "2101"

int R, C, visit[NUM][NUM];
char map[NUM][NUM];
pair<int, int> J;
queue<tuple<int, int, int, bool>> q; // ��ǥ, �ð�, ������ or ��

int main() {
	cin >> R >> C;
	for (int k = 0; k < R; k++) {
		for (int m = 0; m < C; m++) {
			cin >> map[k][m];
			if (map[k][m] == 'J') J = { k,m }; // �������� ���, ��ǥ ���
			if (map[k][m] == 'F') q.push({ k,m,0,false }); // ���� ���, ť�� ����
		}
	}
	q.push({ J.first,J.second,0,true });
	// ���� �켱������ ������ ��, �����̰� ������ �� ����

	int ans = 0; // �ʱ� ���� 0
	while (!q.empty()) {
		int x, y, v;
		bool f;
		tie(x, y, v, f) = q.front();
		q.pop();

		if (visit[x][y]) continue; // �̹� �湮�� ���̸� �Ѿ
		visit[x][y] = 1;

		for (int k = 0; k < 4; k++) {
			int nx = x + X[k] - '1', ny = y + Y[k] - '1';
			if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
				if (f) { // �����̰� ���� ������ �����ٸ� ����
					ans = v + 1;
					break;
				}
				continue; // ���� ���, ����
			}
			if (map[nx][ny] == '#') continue; // �̵��� ������ ���� ��쵵 ����
			q.push({ nx,ny,v+1,f }); // �� �ܿ� �̵� ����
		}
		if (ans) break; // ���� ã�Ҵٸ� ����
	}
	if (ans) cout << ans << endl; // ���� �ִٸ�, Ż�� ����
	else cout << "IMPOSSIBLE" << endl; // ����
}