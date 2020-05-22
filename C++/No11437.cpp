#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
// LCA 2 ( Longest Common Ancient )

#define MAX 50000

int N, M;
int depth[MAX + 1], visit[MAX + 1];
vector<int> v[MAX + 1];
vector<int> edges[MAX + 1];

void DFS(int a, int b) {
	if (visit[b]) return; // �̹� �湮�� ���� ��� (�� ������ ���)
	visit[b] = 1;

	// ��Ʈ�� 1�� �������� Ʈ���� ��������Ƿ�,
	// a�� �θ�, b�� �ڽ��̶�� ������ ���� ( ��Ʈ�� ����� ��尡 �ݵ�� ���� �湮 )
	depth[b] = depth[a] + 1; // �θ��� ���� + 1
	v[b].push_back(a); // �θ� �ε��� ������ ���
	int mul = 0, idx = a;
	while (mul < v[idx].size()) {
		v[b].push_back(v[idx][mul]); // �ش� ��ġ�� 2�� �¼� �ڸ� �θ� ����
		idx = v[idx][mul]; // ���� ��ġ�� �̵�
		mul += 1; // �ٴ� ���� ����
		// ó������ 2�� �� ���·� mul �� ������������,
		// �̴� b�� ��ġ������ ���� ��, ���� �θ��忡�� �����ؾ� �ϴ� ���� 1�� �����Ѵٴ� Ư¡
		// so, �̷� ���� ���� depth ���� ���� ���� log N �� ���� ������ ������ �߻�����
	}

	for (int k = 0; k < edges[b].size(); k++) {
		DFS(b, edges[b][k]);
	}
}

int Match(int idx, int d) {
	if (depth[idx] == d) return idx; // ���ϴ� ���̿� ���������� ����

	int mul = 1; // �θ�� �ö󰡴� ��� ��
	int k = 0; // ���� ���� �ε��� ��ȣ
	for (; k < v[idx].size(); k++) {
		if (depth[idx] - mul < d) { // �ش� �ܰ谡 ���ϴ� ���̺��� ���� ������
			break; // ����
		}
		mul *= 2; // �� �ܿ� 2�辿 �̵�
	}
	k -= 1; // �������� ���, �ش� �ε��� ���� ���� �����ؾ� ��
	return Match(v[idx][k], d); // ���ȣ��
}

int Find(int a, int b) {
	if (a == b) return a; // ���� ���� ������ ��� ����

	int k = 0;
	for (; k < v[a].size(); k++) { // ���� depth �� �����ϹǷ� ���� ũ�⵵ ����
		if (v[a][k] == v[b][k]) { // �� ������ ������ �� �ؿ� ����
			break;
		}
	}
	k = k ? k - 1 : k; // k �� 0�� ���� �״�� ����
	return Find(v[a][k], v[b][k]);
}

int main() {
	cin >> N;
	int a, b;
	depth[1] = 1; // ���̴� 1���� ����
	for (int k = 1; k < N; k++) { // 1~N-1 ���� �� N-1 ��
		scanf("%d %d", &a, &b);
		edges[a].push_back(b);
		edges[b].push_back(a); // ���� ������ ����
	}

	visit[1] = 1; // ��Ʈ���� ����Ͽ� �ϳ��� LCA Ʈ�� ������ ����
	for (int k = 0; k < edges[1].size(); k++) {
		DFS(1, edges[1][k]);
	}

	cin >> M;
	for (int k = 0; k < M; k++) {
		scanf("%d %d", &a, &b);
		if (depth[a] > depth[b]) a = Match(a, depth[b]);
		else if (depth[a] < depth[b]) b = Match(b, depth[a]); // �� �� ���� depth ������ ����
		printf("%d\n", Find(a, b)); // ���� �θ� ã�� ���
	}
}