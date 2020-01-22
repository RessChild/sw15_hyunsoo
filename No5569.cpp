#include<iostream>
using namespace std;
// ��� ���
// �⺻������ ��� ��Ģ ����
// but, ȸ���� ������ �����鼭 ��� �ݷʰ� ����Ƿ� ����

#define MAX 100

int W, H; // ���μ���
int verti[MAX + 2][MAX + 2], horiz[MAX + 2][MAX + 2]; 
// ���� ����, ���η� ������ ����� ��

int main() {
	cin >> W >> H;

	for (int k = 1; k <= H; k++) {
		for (int m = 1; m <= W; m++) {
			if (k == 1 && m == 1) { // �������� ����ó��
				verti[1][1] = 1;
				horiz[1][1] = 1;
				continue;
			}

			// ���� ���� ������ �״�� �� �� ���� (���� x)
			if (k <= H) verti[k][m] += verti[k - 1][m];
			if (m <= W) horiz[k][m] += horiz[k][m - 1];
			verti[k][m] %= 100000;
			horiz[k][m] %= 100000; // ���ǿ� ���缭 �� ũ�� ����

			if (k + 2 <= H) {
				// ���� ���⿡�� ��� ���η� 2ĭ �ö� �� �ִ� ���
				verti[k + 2][m] += horiz[k][m];
			}
			else if (m == W) {
				// ������ ������ ������ ���ΰ��
				verti[k + 1][m] += horiz[k][m];
			}
			if (m + 2 <= W) {
				// ���� ���⿡�� ��� ���η� 2ĭ �̵��� �� �ִ� ���
				horiz[k][m + 2] += verti[k][m];
			}
			else if (k == H) {
				// ������ ������ ������ ���ΰ��
				horiz[k][m + 1] += verti[k][m];
			}
		}
	}
	cout << (verti[H][W] + horiz[H][W]) % 100000 << endl; // �� ������ ��� �� = ����
}