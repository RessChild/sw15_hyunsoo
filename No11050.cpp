#include<iostream>
using namespace std;
// ���� ��� 1

int main() {
	int num, sel;
	cin >> num >> sel;

	int a = 1, b = 1;
	for (int k = 0; k < sel; k++) { // ����
		a *= (num - k);
	}
	for (int k = 1; k <= sel; k++) { // ��� ������ �ߺ� ����
		b *= k;
	}
	cout << a / b << endl; // ����
}