#include<iostream>
using namespace std;
// �����佺�׳׽��� ü
// �ܼ��� ������ ���� �� ��Ģ

bool eratos[1001];

int main() {
	int until, num;
	cin >> until >> num;

	int cnt = 0;
	for (int k = 2; k <= until; k++) {
		if (eratos[k]) continue; // �̹� �湮�� ��� ����

		for (int m = 1; m * k <= until; m++) {
			// ���Ŀ� ������ ��� ����鿡 ���� ����
			if (eratos[m * k]) continue; // �̹� �湮�� ��� ����
			eratos[m * k] = true;

			if (++cnt == num) { // K ��° ���� ���������� ��� �� ���� 
				cout << m * k << endl;
				break;
			}
		}
	}
}