#include<iostream>
#include<algorithm>
using namespace std;
// ��Ȯ
// �� �ϸ��� �� �� �ִ� ���� ��, ���̸�, ���� ������ Ŭ���� �ʰ� ���� ���� ����
// so, �׸��� + �������� �� ����Ϸ� ������, ���� ������ ���� ��� ó���� ��ȣ
// DP �� ����� ������� ������ ��ȸ

#define NUM 2000

// ���� ��, �� ����, dp �迭
long long int N, rice[NUM + 1], dp[NUM + 1][NUM + 1];

long long int DP(int f, int b, int depth) {
	if (dp[f][b]) return dp[f][b]; // ���� ���� �ִٸ� ���
	if (f == b) return dp[f][b] = rice[f] * depth; // ������ ���� ���
	return dp[f][b] = max( // ����, �������� ���� ��� �� ū ���� ����
		DP(f + 1, b, depth + 1) + rice[f] * depth,
		DP(f, b - 1, depth + 1) + rice[b] * depth);
}

int main() {
	// �Է�
	cin >> N; 
	for (int k = 1; k <= N; k++) cin >> rice[k];

	// DP Ž��
	cout << DP(1, N, 1) << endl;
}