// �л� ó��
// math �Լ� ���� pow���� ����� �����̾�����
// long long Ÿ�����ε� �����÷ο찡 ������ ����
// 1�� �ڸ��� ����ϴ� �˰���

#include<iostream>
using namespace std;

int main() {
	int loop; //�ݺ� Ƚ��
	cin >> loop;

	int *ans = new int[loop]; //�����Ҵ�

	for (int k = 0; k < loop; k++) {
		int sub, pow;
		cin >> sub >> pow; // ���� ���� �Է�

		ans[k] = sub; // ù ���� sub �� �״��
		for (int i = 1; i < pow; i++) {
			ans[k] = (ans[k] * sub) % 10 != 0 ? (ans[k] * sub) % 10 : 10;
			//1�� �ڸ����� �˸� ���
			//10���� ������ ���������� 10��° ��ǻ�Ͱ� ó���ϴ� ����ó��
		}
	}

	for (int k = 0; k < loop; k++) {
		cout << ans[k] << endl;
	}

	delete[] ans; //�Ҵ� ����
}