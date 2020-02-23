#include<iostream>
#include<queue>
#include<tuple>
#include<algorithm>
using namespace std;
// �����
// input ������ �ִ� 300 * 300, �ð����� 5��
// so, ���ǿ� �����ϴ� ������� �߷� ������ Ȯ����ѳ����� ����� ���
// ������ ų���� ũ�Ⱑ ¦,Ȧ�� ��츦 ���� ������ ó���ؾ� �ϴ� ���ŷο��� ��������

#define NUM 300

int R, C;
char datas[NUM][NUM];
queue<tuple<int, int, int, int>> q; // x,y, ũ��, Ȧ/¦

// Ȧ�� ũ�� ������ : �߽��� ��ǥ (x,y), �߽����� �������� ������ �Ÿ� s, Ȧ�� flag 1
// ¦�� ũ�� ������ : �� ������ ��ǥ (x,y), ������������ �Ÿ� s (�� �Ÿ��� ����), ¦�� flag 0

bool Check(int x, int y, int s, int select) {
	if (select) { // ũ�� ���� Ȧ���� ���
		// Ȧ�� �������� ��ǥ�� �߽��� ����
		if (x - s < 0 || x + s >= R || y - s < 0 || y + s >= C) return false; // ���� �����ؼ� Ȯ�� �Ұ���

		// ���� ���ҵ鿡 ���� ��
		int top_x = x - s, top_y = y - s, btm_x = x + s, btm_y = y + s; 
		for (int k = 0; k < 2 * s + 1; k++) {
			if (datas[top_x][top_y + k] != datas[btm_x][btm_y - k]) return false; // �ٸ� ��� ����
		}

		// ���� ���ҵ鿡 ���� ��
		int left_x = x - s, left_y = y - s, right_x = x + s, right_y = y + s;
		for (int k = 0; k < 2 * s + 1; k++) {
			if (datas[left_x + k][left_y] != datas[right_x - k][right_y]) return false; // �ٸ� ��� ����
		}
	}
	else { // ũ�� ���� ¦���� ���
		// ¦�� �������� ��ǥ�� �� ������ ���� �ֻ��
		if (x < 0 || x + (2 * s - 1) >= R || y < 0 || y + (2 * s - 1) >= C) return false; // ���� �����ؼ� Ȯ�� �Ұ���

		// ���� ���ҵ鿡 ���� ��
		int btm_x = x + (2 * s - 1), btm_y = y + (2 * s - 1);
		for (int k = 0; k < 2 * s; k++) {
			if (datas[x][y + k] != datas[btm_x][btm_y - k]) return false; // �ٸ� ��� ����
		}

		// ���� ���ҵ鿡 ���� ��
		int right_x = x + (2 * s - 1), right_y = y + (2 * s - 1);
		for (int k = 0; k < 2 * s; k++) {
			if (datas[x + k][y] != datas[right_x - k][right_y]) return false; // �ٸ� ��� ����
		}
	}

	return true; // �� �ܿ� ����
}

int main() {
	cin >> R >> C;
	for (int k = 0; k < R; k++) {
		for (int m = 0; m < C; m++) {
			cin >> datas[k][m];
			q.push(tuple<int, int, int, int>(k, m, 1, 1)); // ��� ������ �⺻���� ������ ų�� (Ȧ��)
		}
	}

	for (int k = 0; k < R - 1; k++) { // ¦�� ũ�⸦ ���� ������ ų��
		for (int m = 0; m < C - 1; m++) {
			q.push(tuple<int, int, int, int>(k, m, 1, 0));
		}
	}

	int ans = 1;
	while (!q.empty()) { // ť���� ���� �������� �Ǵ�
		tuple<int, int, int, int> data = q.front();
		q.pop();

		int x = get<0>(data), y = get<1>(data), s = get<2>(data), select = get<3>(data); // ������ ���� ����
		if (Check(x, y, s, select)) { // ������ �����ϴ��� Ȯ��
			ans = max(ans, 2 * s + (select)); // �����ϴ� ������ ų�� ��, ���� ū ���� ����
			q.push(tuple<int, int, int, int>(x + (select - 1), y + (select - 1), s + 1, select)); // Ȯ��� ������ ť�� �ٽ� ����
		}
	}
	cout << ans << endl; // ���� ���
}