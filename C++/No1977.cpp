// ���� ������

#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int min, max;
	int first = -1; // ���� �� �ּҰ�
	bool tag = false; // �ּҰ� ȹ���� ���� flag ��
	cin >> min >> max; //���� ���� �Է�

	int ans = 0; // �ϴ� ������ 0
	int cal = 0; //��� ��
	for (int k = 1; cal <= max; k++) {
		// ���ָ� ����� ����
		if (cal >= min) { // ��� ���� ���� ���� ����
			ans += cal; //�ش� ���� ����
			if (!tag) {
				tag = true;
				first = cal; // ���� ���� ���� ù ��
			}
		}
		cal = (int)pow(k, 2.0f);
	}
	if (ans)
		cout << ans << endl;
	cout << first << endl;
}