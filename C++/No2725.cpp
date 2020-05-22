#include<iostream>
using namespace std;
// ���̴� ���� ����
// ���������� Ư�� (x,y) ��ǥ�� ������� ������ �� �� ����
// ��, �����佺�׳׽��� ü ����� ������ ����

#define MAX 1000 // ���� �ִ� ũ��

int main() {
	int loop;
	cin >> loop; // �ݺ� Ƚ��
	for (int k = 0; k < loop; k++) {

		bool visit[MAX + 1][MAX + 1] = {}; // ��ǥ ����

		int size, cnt = 0;
		cin >> size;
		for (int k = 1; k <= size; k++) {
			for (int m = k + 1; m <= size; m++) { // �밢���� �߽����� �� ���鸸 ���
				if (visit[k][m]) continue; // �湮�� ��� ����
				visit[k][m] = true;
				cnt++; // �������� �� �� �ִ� ��ǥ �� ����
				for (int n = 2; n * k <= size && n * m <= size; n++) {
					visit[n * k][n * m] = true; 
					// �ش� ��ǥ�� ������ �� ���� ��� ��ǥ ����
				}
			}
		}
		cnt *= 2; // �밢���� �������� ��Ī ( 2�� )
		cnt += 3; // ����, ����, �밢���� ���� �߰�
		cout << cnt << endl; // ����� ���
	}
}