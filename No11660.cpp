#include<cstdio>
using namespace std;
// ���� �� ���ϱ� 5
// �ܼ� �迭�� �ƴ� 2���� �迭 
// so, �� ������ (0,0) ~ (A,B) ������ ��� ������ ���� ����
// ���� ���ʿ��� ���� �����ϴ� ���������� �ߺ����� ������ ���� �����Ƿ�
// �߰����� ���� ���ܰ� �ʿ�

#define MAX 1024

int N, M;
int datas[MAX + 1][MAX + 1]; // (0,0) ~ (A,B) ������ ���� ��

int main() {
	scanf("%d %d", &N, &M);

	int d;
	for (int k = 1; k <= N; k++) {
		int arr[MAX + 1] = {};
		for (int m = 1; m <= N; m++) {
			scanf("%d", &d);
			arr[m] = arr[m - 1] + d; // �̹� ������ ����
			datas[k][m] = datas[k - 1][m] + arr[m]; // �ڽ��� �� ���� ���� + ���� ������ ������
		}
	}
	for (int k = 0; k < M; k++) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%d\n", datas[x2][y2] - (datas[x2][y1 - 1] + datas[x1 - 1][y2]) + datas[x1 - 1][y1 - 1]);
	} // ��ǥ����� ���� ���� ������ ���ϱ�
	// �ٸ�, �ߺ����� ������ ��ġ�� ������
}