#include<iostream>
using namespace std;
// ������ ����

int reverse(int val); // ���ڸ� ������ �Լ�
int r_add(int a, int b); // ������ �䱸�� �Լ�

int main() {
	int a, b;
	cin >> a >> b; // �Է�
	cout << r_add(a, b) << endl;
}

int reverse(int val) {
	int make = 0;
	while (val != 0) { // �Է°��� 0�� �ƴϸ� �ݺ�
		make *= 10;
		make += val % 10;
		val /= 10;
	}
	return make; // ������ ���� ��ȯ
}

int r_add(int a, int b) {
	return reverse(reverse(a) + reverse(b));
}