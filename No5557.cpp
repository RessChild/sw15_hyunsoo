#include<iostream>
#include<queue>
using namespace std;
// 1�г�
// �� �������� ������ �� �ִ� ���� Ƚ���� ��� ����
// ���� ������ ���� �ε����� ���� ȹ��

#define SIZE 100 

int loop, num[SIZE];
long long int res[21]; // ����� ���� �迭
// �������ǿ��� ������ �ƴϸ� 20�� �Ѵ� ���� �� �� �����Ƿ�
// ũ�� 21�� ���

int main() {
	cin >> loop;
	for (int k = 0; k < loop; k++) {
		cin >> num[k];
	} // �Է�

	res[num[0]] += 1;
	for (int k = 1; k < loop - 1; k++) {
		long long int calc[21] = {}; // ����� �迭 (int �� ����)
		for (int m = 0; m < 21; m++) {
			if (res[m] == 0) // 0~20������ ��� ���� ���� 
				continue;
			if (m + num[k] <= 20) // ���� ���� �������� ���� ���
				calc[m + num[k]] += res[m];
			if (m - num[k] >= 0) // �������� ���� ���
				calc[m - num[k]] += res[m];
		}
		for (int k = 0; k < 21; k++) { // ���� �� �ִ� case �� ����
			res[k] = calc[k];
		}
	}
	cout << res[num[loop - 1]] << endl; // ������ ���� ��ȣ
}