#include<iostream>
#include<algorithm>
using namespace std;
// ����
// �ܼ� Ž�� ������ Ǯ���� �Ͽ�����, �ð��ʰ�
// so, �̹� ��ϵ� ������ �����ϴ� DP ����� ����ؾ� ��

#define SIZE 50
#define INF SIZE * 2000

int N, M, calc[SIZE][SIZE], visit[SIZE][SIZE];
char map[SIZE][SIZE];

int DFS(int x,int y) {
	if (x < 0 || x >= N || y < 0 || y >= M || map[x][y] == 'H') return 0; // ���� �Ұ��ϸ� ����
	if (visit[x][y]) return INF; // �̹� �湮�� ���̶�� ���ۺ��� �� �� ����
	if (calc[x][y])return calc[x][y]; // ������ ����� ���� �ִٸ� ���

	visit[x][y] = 1;
	int calc_x = max(DFS(x - (map[x][y] - '0'), y), DFS(x + (map[x][y] - '0'), y));
	int calc_y = max(DFS(x, y - (map[x][y] - '0')), DFS(x, y + (map[x][y] - '0'))); 
	visit[x][y] = 0; // �湮������ ǥ���ϰ�, ��������� ���
	return calc[x][y] = max(calc_x, calc_y) + 1; // ���� �� �ִ� �ִ밪�� ����
}

int main() {
	cin >> N >> M;
	char ch;
	for (int k = 0; k < N; k++) {
		for (int m = 0; m < M; m++) {
			cin >> map[k][m];
		}
	}
	int ans = DFS(0, 0); // ������ ��� ���ǿ� ���� ���
	if (ans >= INF) cout << -1 << endl;
	else cout << ans << endl;
}