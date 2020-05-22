#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;
// ���ѱ�
// BFS Ž������ �ڵ尡 ����������, �Դ� ���� �ǵ��� �� �� �ִٴ� ������ ����
// so, �̸� ó���ϱ� ���� ���������� ���� ���� �������� ���� �濡 ����
// ���� ������ ����صδ� ����� ���

#define NUM 100
#define X "1210"
#define Y "2101"

int N, M, on[NUM + 1][NUM + 1], visit[NUM + 1][NUM + 1], fail[NUM + 1][NUM + 1];
vector<pair<int, int>> v[NUM + 1][NUM + 1]; // ���� ����ġ ����
queue<pair<int, int>> q; // Ž���� ť


int main() {
	cin >> N >> M;
	for (int k = 0; k < M; k++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		v[x][y].push_back({ a,b }); // x,y ��ǥ���� a, b �� ų �� ����
	}

	int ans = 1;
	on[1][1] = 1;
	q.push({ 1,1 }); // ���� ��ǥ

	// BFS Ž��
	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		q.pop();

		if (!on[x][y]) {  // ���� ������ ���� �ƴϸ� ǥ�� �� ����
			fail[x][y] = 1;
			continue;
		}
		if (visit[x][y]) continue; // �̹� �����ߴ� ���̿��� ����
		visit[x][y] = 1;

		for (pair<int, int> pos : v[x][y]) {
			ans += on[pos.first][pos.second] ? 0 : 1; // �̹� �����ִ� ���̸� ��꿡�� ����
			on[pos.first][pos.second] = 1; // �ش� ������ ���� ��
			if (fail[pos.first][pos.second]) { // ������ ���� ��� ������ �����̸�
				q.push({ pos.first, pos.second }); // �ش� ������ �ְ�
				fail[pos.first][pos.second] = 0; // ���� �ʱ�ȭ
			}
		}

		for (int k = 0; k < 4; k++) { // �� ������ BFS
			int nx = x + X[k] - '1', ny = y + Y[k] - '1';
			if (nx < 1 || nx > N || ny < 1 || ny > N) continue; // ���� ��
			q.push({ nx,ny });
		}
	}

	cout << ans << endl;
}