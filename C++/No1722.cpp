#include<iostream>
using namespace std;
// ������ ����
// ���� �ӵ��� ���� �޸�������̼��� ���

int s;
long long int cnt[21];
bool visit[21];

long long int Cnt(int n) { 
	if (n == 0)	return 1; // ��� �ڸ��� �� ���
	if (cnt[n] != 0) { // �̹� �湮�ߴٸ� ��ȯ
		return cnt[n];
	}
	cnt[n] = n * Cnt(n - 1); // �ش� ��ġ�� ���� �� �ִ� ���� ��
	return cnt[n];
}

void Q1() {
	long long int sel;
	cin >> sel;
	int ka = 1;
	while (sel != 0) {
		long long int a = Cnt(s - ka); // ���� �ڸ��� �޺κ��� ���� �� �ִ� ���� ��
		long long int q = (sel - 1) / a + 1; // �� ��° ����� ����ϴ°�?
		int check = 0; // ��� ���� Ƚ��
		int aaa = 0; // ����ϴ� ī�� ��ȣ
		while (check != q) {
			aaa += 1;
			if (!visit[aaa]) { // ���� ���� ���� ī����, ��Ͽ� ���� ����
				check += 1;
			}
		}
		visit[aaa] = true; // ���õ� ī�带 ���
		cout << aaa << " "; // ���
		sel %= a; // ���� ��ġ�� ����� ������ ����
		ka++; // ���� �ڸ��� ����
	}
	for (int k = s; k > 0; k--) { // �� �� ��µ��� ���� ����� ���������� ���
		if (!visit[k])
			cout << k << " ";
	}
}

void Q2() {
	long long int sum = 1;
	int arr[21];
	for (int k = 1; k <= s; k++) {
		cin >> arr[k]; // �� �Է�
		long long int a = Cnt(s - k); // ���ڸ� ���� ����� ��

		int check = 0;
		visit[arr[k]] = true; // �ش� ī�带 ����Ͽ���
		for (int m = 1; m < arr[k]; m++) {
			if (!visit[m]) { // �ڽ��� �ش� ��ġ���� ���°�� �����ϴ��� �Ǵ�
				check++;
			}
		}
		sum += check * a; // �� ����ŭ ���� ����
	}
	cout << sum; // ���
}

int main() {
	cin >> s;
	int ques;
	cin >> ques; // ���� ����

	switch (ques)
	{
	case 1: // k ��° ����
		Q1();
		break;
	case 2: // �־��� ������ ��ȣ
		Q2();
		break;
	default:
		break;
	}
}
