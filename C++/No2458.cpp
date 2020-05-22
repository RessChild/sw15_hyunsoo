#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
// Ű ����
// �ڽ��� ��, �ڿ� �ִ� ����� ���� ��ü �ο��� �����ϸ�
// ������ ��Ȯ�� �� �� ����
// so, �ش� ������ �����ϴ� ����� Ž���ϴ� ������� ����

// �ٸ� ó���� �޸�������̼��� ����Ϸ�������, 
// �� ��� �� ��尡 �ڽ��� �湮�� ��������� ����ϰ� �־����
// ����� ���, ��Ʈ ����ũ ����� �ʿ��ϳ�, �޸� ���� ( 2�� 500 ������ )
// so, ���� �ܼ��� ��üŽ�� ����� ���

#define MAX 500

int N, M, visit[MAX + 1], total[MAX + 1];
vector<int> v[MAX + 1], r_v[MAX + 1];

int DFS(int idx) { // ���� ���� ���� Ž��
	if (visit[idx]) return 0; // �̹� �湮�� ��� �� ���� x
	visit[idx] = 1;

	int cntB = 0;
	for (int k = 0; k < v[idx].size(); k++) {
		cntB += DFS(v[idx][k]); // Ȯ���� �ڽ��� �ڿ� �����ϴ� ��� ���� üũ
	}
	return cntB + 1; // �ڽ��� ������ ���� ��ȯ
}

int r_DFS(int idx) { // ���� ���� ���� Ž��
	if (visit[idx]) return 0; // �̹� �湮�� ��� �� ���� x
	visit[idx] = 1;

	int cntF = 0;
	for (int k = 0; k < r_v[idx].size(); k++) {
		cntF += r_DFS(r_v[idx][k]); // Ȯ���� �ڽ��� �տ� �����ϴ� ��� ���� üũ
	}
	return cntF + 1; // �ڽ��� ������ ���� ��ȯ
}

int main() {
	scanf("%d %d", &N, &M);
	int a, b;
	for (int k = 0; k < M; k++) {
		scanf("%d %d", &a, &b);

		v[a].push_back(b);
		r_v[b].push_back(a); // ���� �߰� ( ������, ������ )
	}

	for (int k = 1; k <= N; k++) { // ��� ��忡 ���� �ڽ��� �� ��� �� Ž��
		for (int m = 1; m <= N; m++) visit[m] = 0;
		total[k] += DFS(k); // Ž�� ������ ����
	}

	for (int k = 1; k <= N; k++) { // ��� ��忡 ���� �ڽ��� �� ��� �� Ž��
		for (int m = 1; m <= N; m++) visit[m] = 0;
		total[k] += r_DFS(k); // Ž�� ������ ����
	}
	
	int people = 0;
	for (int k = 1; k <= N; k++) {
		if (total[k] - 1 == N) people++; // ��� ���� �ڽ��� �յڿ� �ִٸ�
	}
	printf("%d\n", people);
}
