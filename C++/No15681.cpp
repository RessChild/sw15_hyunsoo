#include<cstdio>
#include<vector>
using namespace std;
// Ʈ���� ����
// ������ ��带 �������� DFS Ž��
// ���� ����Ʈ���� ���Ե� ��带 ��� ���Ͽ� ���

#define NUM 100000 // 10�� 5��

int N, R, Q, node[NUM + 1], visit[NUM + 1];
vector<int> v[NUM + 1];

int DFS(int idx) {
	if (visit[idx]) return 0;
	visit[idx] = 1;
	for (int edge : v[idx]) {
		node[idx] += DFS(edge); // �̹� �湮�ߴٸ� -1 �� ������
	}
	return node[idx] += 1; // �ڽ��� �����Ͽ� ���
}

int main() {
	scanf("%d %d %d", &N, &R, &Q); // ��� ��, ��Ʈ, ���� ��
	for (int k = 1; k < N; k++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a); // ���⼺�� �����Ƿ� ���� ��� �Է�
	}
	DFS(R); // ��Ʈ�� �߽����� DFS Ž��
	for (int k = 0; k < Q; k++) {
		int query;
		scanf("%d", &query);
		printf("%d\n", node[query]); // ���� ��� ���
	}
}