#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
// ACM Craft
// �ܼ� DFS �θ� ������ �ذ��ط� ������, �ð� �ʰ�
// so, �޸�������̼� ����� �߰���
// +) �ǹ� �Ǽ� ����� 0�� ���, ������븸���δ� �ݺ����� ��Ž���� �̷����
// ���� �湮���ο� ������� �迭�� �и��Ͽ� ���� ó���Ͽ� �ذ�

#define NUM 1000

int N, K;
int cost[NUM + 1], visit[NUM + 1], val[NUM + 1]; // �� �ǹ� ���, �湮, �������
vector<int> v[NUM + 1]; // �� �ǹ��� ���� ���� �ʿ��� ���� �ǹ�

int DFS(int idx) { // �ǹ� ��ȣ�� DFS Ž��
	if (visit[idx]) return val[idx];
	visit[idx] = 1;
	for (int next : v[idx]) { // �������� ����Ǿ�� �ϴ� �ǹ�
		val[idx] = max(val[idx], DFS(next));
	}
	return val[idx] += cost[idx]; // �ش� ������ �ǹ� ����� ������ �� ��ȯ
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &K);

		for (int k = 1; k <= N; k++) {
			scanf("%d", &cost[k]); // ���
			v[k].clear(); // �ʱ�ȭ
			visit[k] = val[k] = 0;
		}
		for (int k = 0; k < K; k++) { // ����
			int a, b;
			scanf("%d %d", &a, &b);
			v[b].push_back(a); // b �� �������ؼ� a�� �ʿ�
		}

		int idx;
		scanf("%d", &idx); // �̱�� ���� ����� �ϴ� �ǹ�
		printf("%d\n", DFS(idx));
	}
}