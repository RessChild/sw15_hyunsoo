#include<iostream>
using namespace std;
// �Ǻ���ġ �� 2
// �Էµ� Ƚ����ŭ �ݺ������� �Ǻ���ġ ������ ���

int main() {
	long long int num;
	cin >> num;

	long long int a = 0, b = 1;
	for (int k = 0; k < num; k++) { // �Ǻ���ġ ��� �ݺ���
		long long int c = a + b;
		a = b;
		b = c;
	}

	cout << a << endl; // ���
}