#include<iostream>
#include<algorithm>
using namespace std;
// ���� �� ���ϱ� 2
// Lazy Propagation ���

#define NUM ((1 << 21) - 1)
#define START NUM / 2
#define RANGE (NUM + 1) / 2
typedef long long int lli;

int cnt[NUM];
lli N, M, K, seg[NUM], lazy[NUM];

// ���� ���� �Լ� (�Ʒ� -> ���� �� ����)
lli Lazy(lli idx, lli front, lli back, lli from, lli to, lli val) {
	// ���� ��ǥ, ��/�� ������, ���� ������, ������ ��
	if ((front == from && back == to) || START <= idx) {
		lazy[idx] += val; // �Ϻ��ϰ� ��ġ�ϴ� �����̸� lazy
		lli add = cnt[idx] * val; // ���� ���Ե� ����ŭ�� ����
		seg[idx] += add; // ���� �ڸ��� �� ���� ����
		return add; // �߰��� �� ��ȯ
	}

	lli ans = 0;
	lli mid = (front + back) / 2; // �̺� Ž���� �߰� ��ġ
	Lazy((idx << 1) + 1, front, mid, front, mid, lazy[idx]);
	Lazy((idx << 1) + 2, mid + 1, back, mid + 1, back, lazy[idx]);
	// ���� �ִ� ���� �ڽĿ��� 1���� �ѱ�
	lazy[idx] = 0;

	// ������ ���� ���� ���� ���� �¿�� �ѱ�
	if (from <= mid) { // ���� ����
		ans += Lazy((idx << 1) + 1, front, mid, from, min(to, mid), val); 
	}
	if (mid < to) { // ������ ����
		ans += Lazy((idx << 1) + 2, mid + 1, back, max(from, mid + 1), to, val);
	}
	seg[idx] += ans; // �ڽĿ��� ������ ���� �ѷ���ŭ ����
	return ans; // ���ŷ� ��ȯ
}

// ���� �� Ž�� �Լ� (�� -> �Ʒ��� �� ����)
lli Sum(lli idx, lli front, lli back, lli from, lli to, lli val) {
	seg[idx] += val * cnt[idx]; // �� ����
	if ((front == from && back == to) || START <= idx) {
		lazy[idx] += val; // ������ ����
		return seg[idx]; // ��ȯ
	}

	lli ans = 0;
	lli mid = (front + back) / 2;
	Lazy((idx << 1) + 1, front, mid, front, mid, lazy[idx]);
	Lazy((idx << 1) + 2, mid + 1, back, mid + 1, back, lazy[idx]);
	lazy[idx] = 0;

	if (from <= mid) { // ���� Ž��
		ans += Sum((idx << 1) + 1, front, mid, from, min(to, mid), val);
	}
	if (mid < to) { // ���� Ž��
		ans += Sum((idx << 1) + 2, mid + 1, back, max(from, mid + 1), to, val);
	}
	return ans; // �¿� �� ��ȯ
}


int main() {
	cin >> N >> M >> K;
	for (int k = 0; k < N; k++) { // �Է�
		cin >> seg[START + k];
		cnt[START + k] = 1;
	}
	int from = START >> 1, to = START - 1;
	while (from <= to) { // ���׸�Ʈ Ʈ��
		for (int k = from; k <= to; k++) {
			seg[k] = seg[(k << 1) + 1] + seg[(k << 1) + 2];
			cnt[k] = cnt[(k << 1) + 1] + cnt[(k << 1) + 2];
		}
		to = from - 1;
		from /= 2;
	}

	// Ž�� or ����
	for (int k = 0; k < M + K; k++) {
		lli a, b, c, d;
		cin >> a;
		if (a == 1) { // ���� ����
			cin >> b >> c >> d;
			Lazy(0, 1, RANGE, b, c, d);
		}
		else { // ���� ��
			cin >> b >> c;
			cout << Sum(0, 1, RANGE, b, c, lazy[0]) << endl;
		}
	}
}