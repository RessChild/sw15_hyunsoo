#include<iostream>
using namespace std;
// ���ڿ� ȭ��
// ��Ȯ�� ����, ��Ȯ�� ��, ���� �� �̶�� �� ����
// so, �ش� ������ ���ڿ��� �⺻���� ���� ��,
// �ʿ信 ���� �ں��� ȭ�� ���� ��ȭ�ذ��� ����� ���

#define ALP 25

int N, X;

int main() {
	cin >> N >> X;
	
	string str;
	for (int k = 0; k < N; k++) { // �⺻ ���ڿ� ����
		str += 'A';
		X -= 1;
	}
	for (int k = N-1; k >= 0 && X > 0; k--) {
		// ��� ȭ�� ���� ���� ȭ�� ����ŭ �߰��� ����
		if (X >= ALP) { // A �� Z �� �ٲܸ�ŭ ����� ���Ҵٸ�
			str[k] += ALP;
			X -= ALP; // ��ȯ
		}
		else { // ������ ���
			str[k] += X;
			X -= X; // ������ ���� �����
		}
	}
	str = !X ? str : "!"; // X ���� 0�� �ƴ� ���, ����
	cout << str << endl;
}