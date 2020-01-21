#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
// Ŀ�Ǽ� 2
// ���׸�Ʈ Ʈ���� ����� Ǯ��
// �־����� �������� ������ int���̹Ƿ�, �� ���� long long int ���� ����ؾ߸� ��
// �Լ��� ��ȯ���� ���̰� ���� long long int ������ �����ؾ� �Ѵٴ� ������ �ɷ���

#define MAX (1<<19)
#define NUM_MAX (MAX >> 1) // ���׸�Ʈ Ʈ����

long long int arr[MAX]; // ���׸�Ʈ Ʈ��
int start = NUM_MAX - 1; // ���� index
int N, Q;

long long int S(int idx, int from, int to, int a, int b) {
	if (from == a && to == b) return arr[idx]; // ã�� ������ ��Ȯ�� ��ġ�ϸ� ����

	long long int sum = 0;
	int mid = (from + to) / 2; // �߰���
	if (a <= mid) { // �߰� �� ���� ������ ���� ���
		sum += S(idx * 2 + 1, from, mid, a, min(mid, b)); 
	} // ���� ���� ~ �߰��� ���� ��Ž��
	if (b > mid) { // �߰� �� ���� ������ ���� ���
		sum += S(idx * 2 + 2, mid + 1, to, max(mid + 1, a), b);
	} // �߰� + 1 ~ �� �������� ��Ž��

	//�̶� ���� ã�� ���� a, b �� mid ���� ũ�����̷� ������
	return sum; // ���� ���
}

int main() {
	scanf("%d %d", &N, &Q);
	for (int k = 0; k < N; k++) {
		scanf("%lld", &arr[start + k]);
	}

	int f = start, b = MAX - 1; // ���׸�Ʈ Ʈ�� �� depth �� ����
	while (f != 0) { // ��Ʈ�� ������ ������
		for (int k = f; k < b; k += 2) 
			arr[k / 2] = arr[k] + arr[k + 1]; // �ش� �ܰ��� ��� ��ĭ�� ä��
		b = f - 1;
		f /= 2;
	}

	for (int k = 0; k < Q; k++) {
		int from, to;
		scanf("%d %d", &from, &to);
		if (from > to) { // �迭 �ε��� ũ�Ⱑ �ڹٲ������ swap
			int save = from;
			from = to;
			to = save;
		}
		printf("%lld\n", S(0, 1, NUM_MAX, from, to)); // ����� long long int �� ���

		int sel;
		long long int change;
		scanf("%d %lld", &sel, &change); // ���� �ε����� ��ȭ ��

		int sel_idx = start + sel - 1;
		long long int differ = change - arr[sel_idx]; // ���������� ���̰��� ���
		while (sel_idx) { // ��Ʈ�� �Ž��� �ö� �� ���� �ݺ�
			arr[sel_idx] += differ; //��ȭ�� ����ŭ ��� ����
			sel_idx = (sel_idx - 1) / 2;
		}
		arr[0] += differ; // ��Ʈ �� ����
	}
}