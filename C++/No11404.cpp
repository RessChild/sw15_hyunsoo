#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
// �÷��̵�
// �÷��̵� ���� �˰���
// '��� ����' ���� '��� ���' ������ �ִ�Ÿ��� ��� ���ϴ� �˰���
// ���������� ������ ���� �ɸ��� �˰��� �� �ϳ�

#define MAX 100 // ��� �ִ� ����
#define VAL MAX*100000 + 1 // �Ÿ� �ִ� ��

int map[MAX + 1][MAX + 1]; // ��忡�� �������� �ִܰŸ��� ���, ������ �迭
int N, M;

int main() {
	scanf("%d %d", &N, &M);

	for (int k = 1; k <= N; k++)
		for (int m = 1; m <= N; m++)
			if (k == m) map[k][m] = 0;
			else map[k][m] = VAL; // ���� ���� 0, �� �ܿ��� �켱 ���� �Ұ���

	int a, b, c;
	for (int k = 0; k < M; k++) {
		scanf("%d %d %d", &a, &b, &c);
		map[a][b] = min(map[a][b], c);
	} // �ԷµǴ� ���� ��� ��, �ߺ��� ���� �� �����Ƿ� �ּҰŸ����� ���

	for (int k = 1; k <= N; k++) { // 1~N ������ ��带 ����Ͽ� ���� ���
		for (int m = 1; m <= N; m++) { 
			for (int n = 1; n <= N; n++) { // ��� ��θ� ����
				map[m][n] = min(map[m][n], map[m][k] + map[k][n]);
			} // ���� ������ ��� vs ��� 'k'�� ���� ���� ���
		}
	}

	for (int k = 1; k <= N; k++) { // ��� ���
		for (int m = 1; m <= N; m++) {
			if (map[k][m] == VAL) printf("0 ");
			else printf("%d ", map[k][m]);
		}
		printf("\n");
	}
}