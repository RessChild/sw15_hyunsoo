#include<iostream>
using namespace std;
// ������� 
// �迭�� ���� �ʰ�
// �ܼ� �ݺ������� �������� �� ����

int main() {
	int quiz; // ���� ��
	cin >> quiz;

	int point = 0; //��ü ����
	int result; //���� ����
	int stack = 0; //���̴� ����
	for (int k = 0; k < quiz; k++) {
		cin >> result;
		result == 1 ? stack++ : stack = 0; 
		//����� �����̸� �������� +1, �ƴϸ� ��������
		point += stack; //�� ���� ����
	}
	cout << point << endl; 
}