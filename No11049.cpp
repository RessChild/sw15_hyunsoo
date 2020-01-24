#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
// ��� ���� ����

#define MAX 500 // �Է� �ִ�ġ

long long int N, sum[MAX][MAX]; // i~j �� �� ���귮
pair<int, int> arr[MAX]; // �� ����� ũ�� ����

long long int DP(int from, int to) {
	if (from == to) return 0; // ������ 1�� ��� ���귮 ����
	if (sum[from][to]) return sum[from][to]; // �̹� ��ϵǾ������� ��ȯ

	pair<int, int> a = arr[from];
	pair<int, int> b = arr[to];
	sum[from][to] = (1 << 31) - 1; // �ִ� ������
	for (int k = from + 1; k <= to; k++) { // ������ ��� ��츦 ����� ��
		pair<int, int> c = arr[k]; // �ش� ����� ũ�� ����
		int add = a.first * b.second * c.first; // �߰������� �������� ���귮 
		// ( �� ��� 1�� ũ�� ) * ( �߰� ��� 1�� ũ�� ) * ( �� ��� 2�� ũ�� )
		sum[from][to] = min(sum[from][to], DP(from, k - 1) + DP(k, to) + add); // �ּ� ���� ����
	}
	return sum[from][to]; // ��� ��ȯ
}

int main() {
	scanf("%d", &N);
	int a, b;
	for (int k = 0; k < N; k++) {
		scanf("%d %d", &a, &b);
		arr[k] = pair<int, int>(a, b);
	}
	printf("%lld\n", DP(0, N - 1)); // ��� ���
}