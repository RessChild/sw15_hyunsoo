#include<iostream>
using namespace std;
// ����
// �ܼ��� ��Ģ�� ���� ���ļ� ����� ����� ����

int main() {
	int first; //ù �Է� ��
	int second; //�ι�° �Է� ��

	cin >> first >> second;
	// �� �Է�
	int save = second; //���� ��ȣ�� ���� �ӽ�����
	while (save != 0)	{
		// second�� ��� ������ ���, second ���� 0�� �Ǵ¼��� ��
		cout << first * (save % 10) << endl; //���� second�� 1�� �ڸ��� ����
		save /= 10; //1�� �ڸ��� ������ �ڸ����� �ű�
	}
	cout << first * second << endl; // ���� ���� ���
}