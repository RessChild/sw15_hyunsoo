#include<iostream>
#include<algorithm>
using namespace std;
// ���� ����
// ��� ������ ���� DP ����
// �ٸ�, �޸� ������ 4MB �� ����� ���� ��
// so, ��� DP Ư���� ���� ���ʿ��� �޸� ������ ���ִ� ����� �ʿ�

int H, ladder_max[2][3], ladder_min[2][3]; 
// ���� DP ��Ŀ��� �Ҵ�Ǵ� �迭�� ũ��� [100000][3]
// but, ������ �Ź� �����ϴ� �迭�� �ڽ�, �� �迭 �� ( �� 2�� )

int main() {
	cin >> H; // ��ٸ� ����

	for (int k = 1; k <= H; k++) { // ��ٸ��� 1���� ���� (�ε��� '0'�� �ʱⰪ 0)
		int a, b, c;
		cin >> a >> b >> c; // �� ���� �� �Է�

		int now = k % 2, before = (k - 1) % 2; // ���� ����� ��, ������ ����� ��

		// �ִ� �� ���
		ladder_max[now][0] = max(ladder_max[before][0], ladder_max[before][1]) + a; // ����, ��� �� ū ���� ����
		ladder_max[now][1] = max(max(ladder_max[before][0], ladder_max[before][1]), ladder_max[before][2]) + b; // �� ���� �� ū ��
		ladder_max[now][2] = max(ladder_max[before][1], ladder_max[before][2]) + c; // ����, ��� �� ū ���� ����

		// �ּ� �� ���
		ladder_min[now][0] = min(ladder_min[before][0], ladder_min[before][1]) + a; // ����, ��� �� ū ���� ����
		ladder_min[now][1] = min(min(ladder_min[before][0], ladder_min[before][1]), ladder_min[before][2]) + b; // �� ���� �� ū ��
		ladder_min[now][2] = min(ladder_min[before][1], ladder_min[before][2]) + c; // ����, ��� �� ū ���� ����

		// ¦��, Ȧ���� �����ư��� ���
	}
	cout << max(max(ladder_max[H % 2][0], ladder_max[H % 2][1]), ladder_max[H % 2][2]) <<
		" " << min(min(ladder_min[H % 2][0], ladder_min[H % 2][1]), ladder_min[H % 2][2]) << endl; // ���
}