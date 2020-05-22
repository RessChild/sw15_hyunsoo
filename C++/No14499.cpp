#include<iostream>
#include<queue>
using namespace std;
// �ֻ��� ������
// �ܼ� ���������̳�,
// �ֻ����� ���¿� ���� ȸ�� ������ ����ؼ� ��ȭ
// so, �� ���⿡ ���� ���� �����Ͽ� �ֻ����� �� ��ġ�� ���

#define MAP 20
#define DICE 6
#define X "11102"
#define Y "12011"
// ��, ��, ��, �� ������ �̵� ( �� 0�� ������� ���� )

int H, W, x, y, N; // ����, �ʺ�, ��ǥ, ������ Ƚ��
int map[MAP][MAP], dice[DICE + 1]; // ��, �� �ֻ��� ���� ���� ��
queue<int> dir; // �̵� ���� ���

int main() {
	cin >> H >> W >> x >> y >> N;
	for (int k = 0; k < H; k++) { // �� ä���
		for (int m = 0; m < W; m++) {
			cin >> map[k][m];
		}
	}

	int d; // �̵� ���� ���
	for (int k = 0; k < N; k++) {
		cin >> d;
		dir.push(d);
	}

	// �ֻ��� ������
	int mid = 1, top = 2, right = 3; // �ֻ����� ����, ��, ������ �� ����
	while (!dir.empty()) {
		int d = dir.front();
		dir.pop();

		int nx = x + X[d] - '1', ny = y + Y[d] - '1'; // �̵����� ������ ��ǥ
		if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue; // ���̸� ����
		x = nx;
		y = ny;

		int save = 0; // �ӽ� �����
		switch (d) { // �ֻ��� ���� ��ȭ
			// ���ֺ��� �ֻ��� ��ȣ�� ���� 7�� �ǹǷ�, �̸� Ȱ��
		case 1: // ���������� ������, ���� ���� ����� �ö��
			save = 7 - right;
			right = mid;
			mid = save;
			break;
		case 2: // �������� ������, ������ ���� ����� �ö��
			save = 7 - mid;
			mid = right;
			right = save;
			break;
		case 3: // ���� ������, �Ʒ��� ���� ����� �ö��
			save = 7 - top;
			top = mid;
			mid = save;
			break;
		case 4: // �Ʒ��� ������, ���� ���� ����� �ö��
			save = 7 - mid;
			mid = top;
			top = save;
			break;
		default:
			break;
		}

		if (!map[x][y])	// ĭ�� 0 �̸�,
			map[x][y] = dice[7 - mid]; // �ֻ����� �ٴڸ��� ����
		else { // 0�� �ƴ� ���,
			dice[7 - mid] = map[x][y]; // �ֻ����� �� ����
			map[x][y] = 0; // ĭ ����
		}

		cout << dice[mid] << endl; // ������ ���� �ִ� ���� ���� ��
	}
}