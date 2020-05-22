#include<iostream>
#include<algorithm>
using namespace std;
// ��

#define MAX 100 // �����ϴ� ���� �ִ� ����
#define INF 100 * MAX // �ִ� ��

int N, M;
int mem[MAX], cost[MAX], calc[INF + 1]; // �޸�, ���, �� ��� �� ���� �� �ִ� �ִ� ����

int main() {
	scanf("%d %d", &N, &M);
	for (int k = 0; k < N; k++)
		scanf("%d", &mem[k]);
	for (int k = 0; k < N; k++) {
		scanf("%d", &cost[k]);
	}

	for (int m = 0; m < N; m++) { // �Էµ� ��� ���� ���ؼ� ����
		for (int k = INF; k >= cost[m]; k--) { // ��� ������ ����
			calc[k] = max(calc[k], calc[k - cost[m]] + mem[m]); // �ش� ������� ���� �� �ִ� �ִ� ���� ȹ��
		}
	}

	int k = 0;
	while (calc[k] < M) { // ���ϴ� ������ ���� ������ ��� ����
		k++;
	}
	cout << k << endl;
}