#include<iostream>
#include<string>
#include<cmath>
using namespace std;
// 30
// 30�̶�� ���� 3*10 ���� �и��Ͽ� �� �� ����
// �켱 �־��� ������ 30�� ����� ����� ���ؼ��� 0�� �ʿ�
// ����, 3�� ����� �Ǿ�� �ϴ� ���� ��, �� �ڸ��� ���� ���� 3�� ����� �Ǿ�� ��
// �ش� ������ �����ϴ� ���, ���� ������ �� ������,
// ���� ū ���� ����ؾ� �ϹǷ�, ū ���Ұ����� �� �ڸ��� ����

int num[10]; // �Էµ� ���ҵ��� �� ī����

int main() {
	string str;
	cin >> str;

	for (int k = 0; k < str.length(); k++) {
		num[str[k] - '0']++; // ���� ���ҵ��� �м�
	}

	int sum = 0;
	string ans = "";
	int max = 0; // ��°�
	for (int k = 9; k > 0; k--) {
		if (num[k]) { // 0�� �ƴ϶��
			sum += k * num[k]; // ������ ���ҵ��� ���� ����
			while (num[k]--) {
				ans.push_back(k + '0'); // �ִ밪 ����
			}
		}
	}
	if (sum && !(sum % 3) && num[0]) // �� ���� 3�� ����̰�, 0 ���� ����������
		for (int k = 0; k < num[0]; k++)
			ans.push_back('0');
	else
		ans = "-1"; // �� �� ������ �������� ������ ������

	cout << ans << endl;
}