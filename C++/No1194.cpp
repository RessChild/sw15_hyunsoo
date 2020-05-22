#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
// ���� ��������, ����.
// �� ���� �´� ���踦 �����ִ°��� �Ǵ��ؾ� ��
// �Ϲ����� Ž�������ʹ� �ٸ���, �Դ� ���� �ٽ� ���ư� �� �ִ� ������ ��޾�����,
// ������ �ִ� ����� ���¸� ������ �� �ִٴ� ������ BFS Ǯ�̰� �������� Ȯ��
// ������ ������ �ִ� 6���̹Ƿ�, ��Ʈ ����ŷ�� BFS �� �����ϰ� ��� �ذ�

#define NUM 50
#define MAX 1000
#define KEY ( 1 << 7 ) // a~f ���� �� 6���� ��
#define X "0121"
#define Y "1210"

int N, M, step[NUM][NUM][KEY]; // ����, �ʺ�, BFS �迭
char map[NUM][NUM]; // �� ����
pair<int, int> from; 
vector<pair<int, int>> to; // ���� ��ġ, ���� ��ġ

int main() {
	cin >> N >> M;
	for (int k = 0; k < N; k++) {
		for (int m = 0; m < M; m++) {
			cin >> map[k][m];
			if (map[k][m] == '0') from = pair<int, int>(k, m); // ������
			if (map[k][m] == '1') to.push_back(pair<int, int>(k, m)); // ������
		}
	}

	int ans = -1; // ������ ���� ���� -1 �� ���
	queue<tuple<int, int, int,int >> q; // BFS ť
	q.emplace(from.first, from.second, 0, 0); // �������� �������� Ž�� ����

	while (!q.empty()) { // ť�� �� ���� ��� Ȯ��
		int x, y, bit, v; // ��ǥ��, ���� ���� ��, �� ���� ����
		tie(x, y, bit, v) = q.front();
		q.pop();

		for (int k = 0; k < to.size(); k++) {
			if (x == to[k].first && y == to[k].second) { // ������ �� �ϳ��� �����ߴٸ�
				ans = v; // �������� ����
				break; // Ž�� ����
			}
		}
		if (ans > 0) break; // ������ ���� ã�Ҵ� �ǹ�

		// ���� ���, ����
		if (map[x][y] == '#') continue;
		// ������ ���, �ٷ��̿� ��ħ (���� ����)
		if (map[x][y] >= 'a' && map[x][y] <= 'f') bit |= 1 << (map[x][y] - 'a');
		// ���� ���, ���� ���踦 ���� �ִ��� �Ǵ�, ���ٸ� ����
		if (map[x][y] >= 'A' && map[x][y] <= 'F')
			if (!(bit & (1 << (map[x][y] - 'A')))) continue; 

		if (step[x][y][bit]) continue; // ������ �湮�� ����� �ִٸ� ����
		step[x][y][bit] = v; // ������� �̵��� Ƚ���� ���

		for (int k = 0; k < 4; k++) { // �� ���� BFS Ž��
			int n_x = x + X[k] - '1', n_y = y + Y[k] - '1';
			if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= M) continue; // ������ ����� ����
			q.emplace(n_x, n_y, bit, v + 1); // �� �ܿ� ���ؼ� ť�� �־� ���캽
		}
	}

	cout << ans << endl;
}