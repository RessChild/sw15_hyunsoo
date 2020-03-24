#include<iostream>
#include<queue>
#include<cmath>
using namespace std;
// �ź�ο� ��
// '������ ����' �� ������ ����

// ������ �� N �� ��� p �� ���� [ N = a*p + r ] ���·� ǥ���� ����
// �̶�, p �� ���� ������ r �� ���ٴ� ����
// �� �� M, N �� ���� [ N - a*p = M - b*p = r ] �� �������� �ǹ�
// �̸� �����ϸ� [ N - M = (a - b)*p ] �̸�, �� ���� ���� �ݵ�� p �� ������� �� �� ����

// so, �־��� ��� ���� ���Ͽ� ���̰��� ���� ��, �ִ������� ���ϸ� p �� ���� �� ����

int GCD(int a, int b) { // ��Ŭ���� ȣ����
	while (b) {
		int c = a % b;
		a = b;
		b = c;
	}
	return a; // �ִ����� ��ȯ
}

int main() {
	int T;
	cin >> T;
	while (T--) { // �׽�Ʈ ���̽�
		int N;
		cin >> N; // �Է¹޴� ��

		queue<int> q; // ���� ���� ������ ť

		int first;
		cin >> first; // ������ �Ǵ� ù ��
		for (int k = 1; k < N; k++) {
			int next; 
			cin >> next;
			q.push(abs(first - next)); // ���� �ϳ��� �о� �� ���̸� ť�� ����
		}

		int gcd = 0;
		while (!q.empty()) { // ���� ��� ���� ���� �ִ������� Ȯ��
			gcd = GCD(q.front(), gcd);
			q.pop();
		}

		if (!gcd) cout << "INFINITY" << endl; // 0 �� ���, ������ �Ǵ� ����� ���� (����)
		else cout << gcd << endl; // �� �ܿ� ���� ���� ���
	}
}