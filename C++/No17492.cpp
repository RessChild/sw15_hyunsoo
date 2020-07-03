#include<iostream>
using namespace std;
// �ٵϾ� ����
// ���� ũ�Ⱑ 10���� ���� ��
// so, ���� Ž������ ���� ���θ� �Ǵ�

#define MAX 10
#define X "00012221"
#define Y "01222100"

int N, map[MAX][MAX];

bool DFS() {
	bool ans = false; // �ڽ��� ���� ����� ���� ����
	int cnt = 0; // �ٵϾ� ��
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {

			if (map[x][y] == 2) { // �ش� ��ġ�� �ٵϾ��̸� ���� �õ�
				cnt += 1; // �ٵϾ� �� ����

				for (int k = 0; k < 8; k++) { // 8�������� ���� ����
					int nx = x + X[k] - '1', ny = y + Y[k] - '1'; // ������ ��
					int nnx = nx + X[k] - '1', nny = ny + Y[k] - '1'; // �̵��� ��

					if (nnx < 0 || nnx >= N || nny < 0 || nny >= N) continue; // ���� ���� ����
					if (map[nx][ny] == 2 && map[nnx][nny] == 0) {
						// ������ ���� �ٵϵ��̰�, �̵��� ���� �� ������ ��츸 ����
						map[x][y] = map[nx][ny] = 0;
						map[nnx][nny] = 2;
						ans |= DFS(); // DFS Ž��
						map[x][y] = map[nx][ny] = 2;
						map[nnx][nny] = 0; // ����
					}
				}
			}
		}
	}
	return ans || (cnt == 1); // 1�� ���� ����, �� �ܴ� ����
}

int main() {
	cin >> N;

	for (int k = 0; k < N; k++) { // ��ü �� �Է�
		for (int m = 0; m < N; m++) {
			cin >> map[k][m];
		}
	}
	cout << (DFS() ? "Possible" : "Impossible") << endl; // ����� ���� ���
}