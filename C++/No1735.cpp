#include<iostream>
using namespace std;
// �м� ��
// ���м��� ����� ���ؼ� ���� �и��� �ִ������� ã�ƾ� ��
// so, ��Ŭ���� ȣ������ ���

int main() {
	int prnt[2], cld[2];
	for (int k = 0; k < 2; k++) {
		cin >> cld[k] >> prnt[k];
	}
	int s_prnt = prnt[0] * prnt[1], s_cld = cld[0] * prnt[1] + cld[1] * prnt[0];
	int a = s_prnt, b = s_cld;
	while (b != 0) {
		int save = a % b;
		a = b;
		b = save;
	} // ��Ŭ���� ȣ���� ���

	s_prnt /= a;
	s_cld /= a; // ���� �и� �ִ������� ����
	cout << s_cld << " " << s_prnt << endl;
}