#include<iostream>
#include<algorithm>
using namespace std;
// LCS
// �⺻������ ���� ���� �κ� ������ dp �����̸�
// ���̸� ������ ����ϹǷ�, ���Ž�Ų ������ ������� ����

#define NUM 1000

int comp[NUM + 1][NUM + 1]; // a, b �������� ���� �� �ִ� LCS ��
string str[2]; // 2���� ���ڿ�

int main() {
	cin >> str[0] >> str[1];
	for (int k = 0; k < str[0].length(); k++) { // �� ���ڿ��� 0~N ���� ����ϴ� ��� ��� LCS ���� ���
		for (int m = 0; m < str[1].length(); m++) {
			// �� ��� �� �ϳ��� ���Ͽ� ū ���� ����
			comp[k + 1][m + 1] = max({ comp[k + 1][m], comp[k][m + 1], comp[k][m] + (str[0][k] == str[1][m]) });
		}
	}
	cout << comp[str[0].length()][str[1].length()] << endl; // �� ���ڿ��� ���� �� �ִ� LCS �� ���
}
