#include<iostream>
#include<vector>
using namespace std;
// �巡�� Ŀ��
// ������ ��ǥ�� �����ϴ°��� �ƴ�, ���� �������� �̵� �������� ǥ��
// �� �������� ��� ä�����°��� ��Ʈ����ŷ���� Ȯ��

#define SIZE 100
#define NUM 20
#define FULL ( 1 << 4 ) - 1
#define X "1012"
#define Y "2101"

int N, map[SIZE][SIZE]; // 0~100 ������ ��ǥ�� ������ ���� ��ǥ�� 0~99 (100��) �� ���
vector<int> v[NUM]; // �� Ŀ���� ���� ����

int main() {
	cin >> N;
	for (int k = 0; k < N; k++) {
		int x, y, d, g;
		cin >> y >> x >> d >> g;
		// �ش� �������� x ��ǥ�� ����, y ��ǥ�� ���η� ����ϹǷ�
		// �ش� �ڵ忡�� �Է��� �ݴ�� ��� ( x : ����, y : ���� )

		v[k].push_back(d); // ���� ����
		for (int m = 0; m < g; m++) { // ���븸ŭ �ݺ�
			for (int i = v[k].size() - 1; i >= 0; i--) {
				// ������� ���� ������ ȸ������ ����
				v[k].push_back((v[k][i] + 1) % 4);
				// RIGHT = 0, UP = 1, LEFT = 2, DOWN = 3 �̸�
				// ������ 90�� ȸ�� ��, ���� ���·� ������ ������
			}
		}

		// ���������� ���� ó��
		if (x - 1 >= 0 && x - 1 < SIZE && y - 1 >= 0 && y - 1 < SIZE) map[x - 1][y - 1] |= (1 << 0);
		if (x - 1 >= 0 && x - 1 < SIZE && y >= 0 && y < SIZE) map[x - 1][y] |= (1 << 1);
		if (x >= 0 && x < SIZE && y - 1 >= 0 && y - 1 < SIZE) map[x][y - 1] |= (1 << 2);
		if (x >= 0 && x < SIZE && y >= 0 && y < SIZE) map[x][y] |= (1 << 3);

		// �̵��� ������������ ó��
		for (int dir : v[k]) {
			x += X[dir] - '1';
			y += Y[dir] - '1';

			if (x - 1 >= 0 && x - 1 < SIZE && y - 1 >= 0 && y - 1 < SIZE) map[x - 1][y - 1] |= (1 << 0);
			if (x - 1 >= 0 && x - 1 < SIZE && y >= 0 && y < SIZE) map[x - 1][y] |= (1 << 1);
			if (x >= 0 && x < SIZE && y - 1 >= 0 && y - 1 < SIZE) map[x][y - 1] |= (1 << 2);
			if (x >= 0 && x < SIZE && y >= 0 && y < SIZE) map[x][y] |= (1 << 3);
		}
	}

	int cnt = 0; // ��� �������� ä���� ���, 1 + 2 + 4 + 8 = 15�� ���� ��������
	for (int k = 0; k < SIZE; k++) {
		for (int m = 0; m < SIZE; m++) {
			if (map[k][m] == FULL) cnt += 1;
		}
	}
	cout << cnt << endl;
}