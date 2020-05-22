#include<iostream>
#include<algorithm>
using namespace std;
// �� �μ��� �̵��ϱ�
// DP �� ����Ͽ� ��� ��쿡 ���� �Ǵ�

// �ٸ�, ù Ž������ ���޿� ������ ���, INF ���� ��ϵǸ�
// �ٸ� ���� ���� ��� ���� INF ���� �޴� ������ �߻�
// so, ���� �μ� ���θ� ��������, ������ ������ ����� �ʿ䰡 ����

#define NUM 1000
#define INF NUM * NUM
#define X "0121"
#define Y "1210"

int H, W, len[NUM + 1][NUM + 1][2]; // ����, �ʺ�, DP��
char map[NUM + 1][NUM + 1]; // ���� ��

int DP(int x, int y, bool canBreak) { // ���� ��ǥ, ���� �μ� �� �ִ°�?
	if (len[x][y][canBreak]) return len[x][y][canBreak]; // �̹� �湮�� ���
	if (x == H && y == W) return len[x][y][canBreak] = 1; // ���� ������ ���, 1�� ��ȯ

	len[x][y][canBreak] = INF;
	for (int k = 0; k < 4; k++) {
		int n_x = x + X[k] - '1', n_y = y + Y[k] - '1'; // �̵��� ��ǥ
		if (n_x < 1 || n_x > H || n_y < 1 || n_y > W) continue; // ���ġ�� ����� ����

		if (map[n_x][n_y] == '1') { // �� ��ǥ�� ���̰�, �μ� ��ȸ�� �����ִٸ� 
			if (canBreak) {
				len[x][y][canBreak] = min(len[x][y][canBreak], DP(n_x, n_y, !canBreak) + 1); // �ش� ���� �μ��� ����
			}
		}
		else { // ���� �ƴ϶�� �� ĭ �̵�
			len[x][y][canBreak] = min(len[x][y][canBreak], DP(n_x, n_y, canBreak) + 1);
		}
	}
	return len[x][y][canBreak];
}

int main() {
	cin >> H >> W;
	for (int k = 1; k <= H; k++) { // ���� �Է�
		for (int m = 1; m <= W; m++) {
			cin >> map[k][m];
		}
	}
	int ans = DP(1, 1, true);
	cout << (ans != INF ? ans : -1) << endl; // ��� ȣ��
}