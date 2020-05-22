#include<cstdio>
#include<algorithm>
using namespace std;
// �ּڰ��� �ִ�
// Ư�� ������ Ư�� ���� �����ϴ� ������ �ڷᱸ���� �ʿ�
// so, ���׸�Ʈ Ʈ���� ���

#define NUM ( 1 << 19 ) // ������ ũ�� 10���� (�� 1�� 18��)
#define START ( NUM >> 1 ) - 1 // ���� ���� ��ġ�� �ε���
#define LIM 1000000000 // ���� �ִ�ġ 10��

int N, M, start = START;
pair<int, int>  segment[NUM]; // �ִ�, �ּ� �� ���׸�Ʈ Ʈ��

int F_Max(int idx, int s, int e, int f, int b) { // �ִ밪 Ž��
	if (s == f && e == b) { // ������ ���� �� �´� ���
		return segment[idx].first; // �ش� �ε����� �ִ밪 ��ȯ
	}

	int val = 0, mid = (s + e) / 2; // �߰���ġ
	if (f < mid) { // Ž�� ������ ���� ����
		int limit = min(b, mid);
		val = max(val, F_Max(idx * 2 + 1, s, mid, f, limit));
	}
	if (mid < b) { // Ž�� ������ �ڸ� ����
		int limit = max(f, mid);
		val = max(val, F_Max(idx * 2 + 2, mid, e, limit, b));
	}
	return val;
}

int F_Min(int idx, int s, int e, int f, int b) { // �ּҰ� Ž��
	if (s == f && e == b) { // ������ ���� �� �´� ���
		return segment[idx].second; // �ش� �ε����� �ּҰ� ��ȯ
	}

	int val = LIM, mid = (s + e) / 2; // �߰���ġ
	if (f < mid) { // Ž�� ������ ���� ����
		int limit = min(b, mid);
		val = min(val, F_Min(idx * 2 + 1, s, mid, f, limit));
	}
	if (mid < b) { // Ž�� ������ �ڸ� ����
		int limit = max(f, mid);
		val = min(val, F_Min(idx * 2 + 2, mid, e, limit, b));
	}
	return val;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int k = 0; k < N; k++) {
		int num;
		scanf("%d", &num);
		segment[start + k] = pair<int, int>(num, num); // �� �ϳ��� �ִ� �� �ּ�
	}

	int f = start, b = (NUM >> 1); // ���׸�Ʈ Ʈ�� ����
	while (f) { // ��Ʈ�� �ƴϸ� ���
		for (int k = 0; k < b; k += 2) {
			pair<int, int> first = segment[f + k], second = segment[f + k + 1];
			segment[(f + k) / 2] = pair<int, int>(max(first.first, second.first), min(first.second, second.second));
			// ���� �ִ�, �ּҰ��� �����Ͽ� ���� ��Ʈ�� ���� ���
		}
		f /= 2;
		b /= 2; // ���� �� ���� �ε��� ����
	}

	for (int k = 0; k < M; k++) { // ��� ó��
		int a, b;
		scanf("%d %d", &a, &b); // ���� �Է�

		a -= 1; // ������ ��ó�� ( �ε��� ����ȭ )
		printf("%d %d\n", F_Min(0, 0, NUM / 2, a, b), F_Max(0, 0, NUM / 2, a, b)); // �ִ�, �ּҰ� Ž���Ͽ� ���
	}
}