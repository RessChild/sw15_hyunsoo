#include<cstdio>
#include<algorithm>
using namespace std;
// ���� �ﰢ��
// �ϴ����� ������ ��, �̵� ���� 2���� ��
// so, ������ �� �ִ� ���� �� �ִ밪�� �����Ͽ� ���� ��ġ�� ���� ����
// ���������� �� �� ���� ū ���� ����

#define MAX 500

int s, memo[MAX + 1][MAX + 1];

int main() {
	int s;
	scanf("%d", &s);
	for (int k = 1; k <= s; k++) {
		for (int m = 1; m <= k; m++) { // ���������� �ڽ��� �հ� ������ �ִ밪�� ��
			int d;
			scanf("%d", &d);
			memo[k][m] = max(memo[k - 1][m - 1], memo[k - 1][m]) + d;
			// �� ��ġ�� ������ ����� �ִ밪
		}
	}
	printf("%d\n", *max_element(&memo[s][1], &memo[s][s + 1])); // ���� ��� ��, �ִ���� ����
}