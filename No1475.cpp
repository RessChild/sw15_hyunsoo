#include<iostream>
using namespace std;
// �� ��ȣ
// 6,9�� ���� �ٲ㾵 �� ����
// �ʿ��� ��Ʈ ���� ã�µ�, count ������ ����� ����
// 6,9�� ���� ���� �� �� �����Ƿ� �� ��Ʈ�� 2���� ����ִ� ����
int main() {
	int num;
	int count[10] = {}; //ī���ÿ� ����� ���ڹ迭

	cin >> num;

	do {
		int one = num % 10;
		num /= 10;
		count[one]++; //�� ������ ���� ����
	} while (num != 0);
	// do while �� ���� ������ 0�� �ԷµǴ� ��쵵 ó���ϱ� ����

	count[6] += count[9]; //�� ���� ���� ��Ʈ�� ����
	++count[6] /= 2; // �� ��Ʈ���� �� 2���� ��

	int max = 0;
	for (int i = 0; i < 9; i++) {
		max = max > count[i] ? max : count[i];
		// �� ���� ū ���� ������ ����
	}
	cout << max << endl;
}