#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<intrin.h> // __popcnt() �� ����ϱ� ���� Visual C++ ���� ���� ���̺귯��

using namespace std;
// �κ� û�ұ�
// BFS + DFS �� �Բ� ����� Ǯ��

// �ʱ⿡�� �� �������������� �Ÿ��� ���� ��, �Ÿ��� ���� ������ �����ϴ� �׸��� Ž���� ���
// but, ���� �ϳ� ���� ��쿡 ���� ���ܰ� �߻�

/*
   5 5
   *....
   xxxx.
   .*o*.
   .xxxx
   ....*

   �� : 8 + 16 = 24
*/

// so, DP �� ����� Ǯ�̸� �����Ͽ�����, ���� ������ ���� �ִ� 10�� ���̹Ƿ�,
// �ִ� 10! = 3,628,800 �� �ð��� �ҿ��ϹǷ�, �ܼ� DFS �ε� ���

#define DIRTY 10 // ���� ���� �ִ� ����
#define NUM 20 // ���� �ִ� ũ��
#define INF 1000 // �ִ� ��
#define X "0121"
#define Y "1012" // X,Y �̵�

int W, H; // ����, ����
char map[NUM][NUM]; // ����
vector<pair<int, int>> v; // ���� ���� ��ǥ�� ��Ƶ� ����

int DFS(int road[DIRTY][NUM][NUM], int idx, int bit, int val) {
	bit |= (1 << idx); // ��� ǥ��

	if (__popcnt(bit) == v.size()) return val; // ��� ���� �� �� ���
		// __popcnt(n) : �־��� �� n ���� 1�� ���õ� bit ���� ���� �Լ�
		// gcc�� ���, ���ٸ� ���� ���� __builtin_popcount �� ����� �� ����

	int ans = INF;
	for (int k = 0; k < v.size(); k++) { // ��� �������������� �Ÿ��� �Ǵ�
		if (bit & (1 << k)) continue; // �̹� ����� �����̸� ����

		int b, c;
		tie(b, c) = v[k];
		ans = min(ans, DFS(road, k, bit, val + road[idx][b][c])); // ��������� �ּ� ���� �̾Ƴ�
	}
	return ans;
}

int main() {
	while (true) {
		cin >> W >> H;
		if (W == 0 || H == 0) break; // ����, ���ΰ� 0 �̸� ����

		v.clear(); // ���� ���� �ʱ�ȭ
		pair<int, int> s; // ������
		for (int k = 0; k < H; k++) {
			for (int m = 0; m < W; m++) { // �Է�
				cin >> map[k][m]; // ���� �Է�
				if (map[k][m] == '*') v.emplace_back(k, m); // ������ ��ǥ ���
				else if (map[k][m] == 'o') s = pair<int, int>(k, m); // ������ ���
			}
		}

		int road[DIRTY][NUM][NUM] = {}; // a ���� ����Ͽ� �� (b,c) ���� �����ϴµ� �ɸ��� �ּҽð�
		for (int k = 0; k < v.size(); k++) { // ��� ������ ������ ����

			queue<pair<int, int>> node;
			node.emplace(v[k]); // �� ���������� �켱������ �ְ� ����			
			while (!node.empty()) { // ť�� ��� ��ﶧ ���� BFS Ž��
				int x, y;
				tie(x, y) = node.front();
				node.pop();

				for (int m = 0; m < 4; m++) { // �� ���⿡ ���ؼ� ó��
					int n_x = x + (X[m] - '1'), n_y = y + (Y[m] - '1');

					if (n_x < 0 || n_x >= H || n_y < 0 || n_y >= W) continue; // ���ָ� ��� ���
					if (map[n_x][n_y] == 'x') continue; // ���� ���� ���
					if (road[k][n_x][n_y]) continue; // �̹� �����ߴ� ��

					road[k][n_x][n_y] = road[k][x][y] + 1; // �Ÿ��� ���
					node.emplace(n_x, n_y); // ť�� ����
				}
			}
		}
		
		bool flag = true; // ������ �� ���� ������ �ִ°�?

		int ans = INF;
		for (int k = 0; k < v.size(); k++) { // �ּ� ���� ȹ��
			// ��� �� ���� �������� ������ Ȯ���ϹǷ�, DFS ���� Ȯ���� ��� ��
			if (!road[k][s.first][s.second]) flag = false; 
			ans = min(ans, DFS(road, k, 0, road[k][s.first][s.second]));
		}
		if (flag) printf("%d\n", ans); // ������ ���, ȹ�� ��
		else printf("-1\n"); // �Ұ����� ��� -1
	}
}