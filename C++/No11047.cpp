#include<iostream>
using namespace std;
// ���� 0
// ó���� ������ �߸� ��������..
// �־��� ������ ���� �ϳ��� �ִٰ� �����ؼ�
// Ǯ�� ����� ���� �ȿ� ����

int val[10];
int main() {
	int num, money; // ���� ������ �ݾ�
	cin >> num >> money;

	for (int k = 0; k < num; k++) {
		cin >> val[k]; // ��ġ�� �Է¹���
	}

	int coin = 0; // ���� �� ��
	for (int k = num - 1; k >= 0; k--) {
		coin += money / val[k]; //������ �����ϴ� ��
		money %= val[k]; //�ʿ��� ���� ��
	}
	cout << coin << endl; //���
}