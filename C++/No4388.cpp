#include<iostream>
using namespace std;
// �޾ƿø�

int main() {
	int a, b;
	while (1) {
		cin >> a >> b; //�Է�
		int up = 0; // �ø� �� ī����
		int isUp = 0; // �ø��߻� ����

		if (a != 0 || b != 0) {//���� �ϳ��� ���� ������
			while (a != 0 || b != 0) { // �� ������ ���� �ݺ�
					// �� ���� �ڸ����� ���� �ٸ� �� �����Ƿ�\
					// && ��� || ���
				isUp = (a % 10 + b % 10 + isUp) / 10; // ���� �ø����� �ݿ�
				up += isUp;
				a /= 10;
				b /= 10;
			}
			cout << up << endl;
		}
		else break; //�� �ܿ� ����
	} 
}