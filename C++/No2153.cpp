#include<iostream>
#include<string>
#include<cmath>
using namespace std;
// �Ҽ� �ܾ�
// 'A' �� �ƽ�Ű�ڵ� ���� 'a' ���� ŭ
// ���� ����ó���� �ʿ�

int main() {
	string str;
	int sum = 0;

	cin >> str;

	for (int k = 0; k < str.length(); k++) {
		if (str.at(k) >= 'a')
			sum += str.at(k) - 'a' + 1; // �ҹ����� ���
		else
			sum += str.at(k) - 'A' + 27; // �빮���� ���
	}

	for (int k = 2; k <= sqrt(sum); k++) { // �ִ� ��Ʈ���� ���캽
		if (sum%k == 0) { // �߰��� �� �������� ���� �ִٸ� �ռ���
			cout << "It is not a prime word." << endl;
			return 0;
		}
	}
	cout << "It is a prime word." << endl; // �ݺ����� ���������� ������ �Ҽ�
	return 0;
}