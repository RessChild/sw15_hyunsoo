#include<iostream>
using namespace std;
// �糪�� ��
// �ൿ�� �ݺ��ǹǷ�, mod ������ Ȱ���Ͽ� �ð��� ���

int first[2], second[2]; // �� ���� �ð� ����
int Attack(int time);

int main() {
	int mail, milk, news; // ��ü��, ������޺�, �Ź���޺�

	cin >> first[0] >> first[1] >> second[0] >> second[1];
	cin >> mail >> milk >> news; // ������ �Է�

	cout << Attack(mail) << endl;
	cout << Attack(milk) << endl;
	cout << Attack(news) << endl; // �� ��� ���� ¢�� Ƚ�� ���
}

int Attack(int time) {
	int f_cycle = first[0] + first[1];
	int s_cycle = second[0] + second[1]; // �� ���� �ൿ�� �ݺ��ϴ� ����Ŭ ����

	return ((time-1) % f_cycle < first[0] ? 1 : 0)
		+ ((time-1) % s_cycle < second[0] ? 1 : 0); 
	// ������ ��, 0�� ���� ����ó���� �ʿ�
	// so, �Էµ� ���� 1 �۰� ���� ���ܸ� ����
}