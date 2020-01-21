#include<iostream>
#include<vector>
using namespace std;
// ���μ�����
// ��� ���� ���� �� �ִ� (�ڽ��� ������) ���� ū ����� �ش� ���� ������
// so, �����ٱ��� �����ϴ� ��� �Ҽ��� ���ظ� �õ�

// �ٸ�, �� ����� 1�� �ƴ� ���� �� ��ü�� �Ҽ��� �ȴٴ� �ǹ�
// �ش� ���ܸ� �������� ���� �� ���� ����

#define MAX 3164 // õ���� ������ ���� �ø�

int cnt[MAX];
bool arr[MAX]; // �湮 ����
vector<int> v; // �Ҽ� ����

void eratos() {
	for (int k = 2; k < MAX; k++) {
		if (arr[k]) continue; // �̹� �湮�� ���

		v.push_back(k);
		for (int m = 2; m * k < MAX; m++) {
			if (arr[m * k]) continue; // �̹� �湮�� ���
			arr[m * k] = true;
		}
	}
}

int main() {
	eratos(); // �Ҽ� ȹ��

	int num;
	cin >> num;

	for (int k = 0; k < v.size();) {
		if (num == 1) break; // ���� ���� 1�� ��� ����
		if (!(num % v[k])) { // ���� ���Ͱ����� ���� �� �ִٸ� ���
			cout << v[k] << endl;
			num /= v[k];
			continue;
		}
		// �������� �ϳ��� �Ҽ��� ã�� ���, ó������ ��õ��� ������ �ð��ʰ�
		// but, �׷� �ʿ�� ������ ������ �Ҽ��� ����� �� �� �����Ƿ�,
		// �ش� �Ҽ����� �ٽ� ���ظ� �õ��ϸ� ���
		k++;
	}
	if (num != 1) cout << num << endl; // ���� ���� �ִٸ� �� ��ü�� �Ҽ�
}