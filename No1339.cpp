#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
// �ܾ� ����
// ���� ū �� ������ ����� ���� ��ǥ�̹Ƿ�,
// �ܼ� ��Ģ�� ����Ͽ� Ǯ��

int alpha[26]; // ���ĺ� ũ�⸸ŭ�� �迭

int main() {
	int line;
	cin >> line; 

	for (int k = 0; k < line; k++) {
		string str; // ���ڿ� �Է�
		cin >> str;

		for (int m = 0; m < str.length(); m++) { // �� ���� ������ ī����
			alpha[str.at(m) - 'A'] += (int)pow(10, str.length() - (m + 1));
			// �ٸ�, �� ������ ��ġ�� ���� ���� �޸����Ƿ�, ����
		}
	}
	sort(&alpha[0], alpha + 26); // ����

	int sum = 0, number = 9; // ���� ������ ���� ������������ ���� �ο�
	for (int k = 25; k >= 0; k--) {
		if (alpha[k] == 0) break;
		sum += alpha[k] * number;
		number--;
	}

	cout << sum << endl; // �� ���
}