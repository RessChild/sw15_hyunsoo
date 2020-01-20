#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
// ���� �ڸ���
// �Ķ��Ʈ�� ��ġ (���� ������ �̺� Ž��)

long long int tree, want;
vector<long long int> height; // �� �������� ���� ����
bool check(int mid);

int main() {
	cin >> tree >> want; // �Է�

	int sum = 0, m = 0;
	for (int k = 0; k < tree; k++) {
		int data;
		cin >> data; // ������ �Է¹���
		height.push_back(data); 
		m = max(m, data);// ���Ϳ� �����ϰ�, �ִ밪 �Ǵ�
	}
	sort(height.rbegin(), height.rend()); // ����

	int f = 0, b = m;
	while (f <= b) { // �̺� Ž��
		// ���ǿ� �´� ���, �� ���� ��� ���ǿ� ����
		int mid = (f + b) / 2;
		if (check(mid)) f = mid + 1;
		else b = mid - 1; // ���� �Ǵ��ϸ� ��ġ�� ����
	}

	cout << b << endl; // ������ ���̸� ���
}

bool check(int mid) {
	long long int sum = 0;
	for (int k = 0; k < tree; k++) { // ������ ���̿� ���� ���� ���� ���
		long long int val = height[k] - mid; // �߶� ���� �� �ִ� ��
		if (val > 0) sum += val; // 0���� ũ�� ���ϰ�
		else break; // �۴ٸ�, ���� ���̴� ���ĵǾ� �����Ƿ� ����
	}
	if (sum >= want) return true;
	else return false; // ���� ���� ��� �Ǵ�
}