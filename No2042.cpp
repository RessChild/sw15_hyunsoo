#include<iostream>
#include<algorithm>
using namespace std;
// ���� �� ���ϱ�
// �������� ����� �κ� Ž���� ����ϹǷ�, ���׸�Ʈ Ʈ���� ���
// ���� �Է� �������� ���� int �� ���ָ� �Ѿ�Ƿ�, long long int �� ������� ����

#define NUM ( 1 << 23 )
#define START (NUM / 2) - 1

typedef long long int lli;

lli N, M, K, seg[NUM];

lli Sum(lli idx, lli front, lli back, lli a, lli b) { // �ش� ��尡 ���� ����, ã�� ����
	if (front == a && back == b)
		return seg[idx]; // ã�� ������ �� ������ �� �� ��ȯ

	lli mid = (front + back) / 2; // �̺� Ž���� ���� (�߰� ��)
	lli ans = 0; // �¿� ��
	if (a <= mid) ans += Sum(idx * 2 + 1, front, mid, a, min(b, mid)); // ���ʿ� ���� �ִ� ���
	if (b > mid) ans += Sum(idx * 2 + 2, mid + 1, back, max(a, mid + 1), b); // �����ʿ� ���� �ִ� ���
	return ans;
}

int main() {
	cin >> N >> M >> K;
	for (int k = 0; k < N; k++) {
		cin >> seg[START + k];
	}

	{ // ���׸�Ʈ Ʈ�� ����
		int idx = START;
		while (idx != 0) {
			for (int k = 0; k < idx + 1; k += 2) {
				seg[(idx + k) / 2] = seg[idx + k] + seg[idx + k + 1];
			}
			idx /= 2;
		}
	}

	for (int k = 0; k < M + K; k++) {
		lli a, b, c;
		cin >> a >> b >> c;

		if (a == 1) {
			lli idx = START + (b - 1);
			lli residual = c - seg[idx];
			seg[idx] = c; // ������ ����

			while (idx != 0) {
				idx = (idx - 1) / 2; // �� �ڽ��� +1, +2 �� ���� �����Ƿ�, 1�� �� �� ������ ��
				seg[idx] += residual; // ��ȭ����ŭ ���� ������ ��
			}
		}
		else {
			cout << Sum(0, 1, START + 1, b, c) << endl;
		}
	}
}