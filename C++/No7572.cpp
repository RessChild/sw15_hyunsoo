#include<iostream>
using namespace std;
// ���� ����
// �ܼ��� ��Ģ
// �ٸ� ������ ���� 0�� �ƴ� 4����

#define BASE_YEAR 56

int main() {
	int year;
	cin >> year; //�ظ� �Է¹���

	int n10 = (year + BASE_YEAR) % 10; //�ʰ�
	int n12 = (year + BASE_YEAR) % 12; //������

	cout << (char)(n12 + 'A') << n10;
}