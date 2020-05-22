#include<iostream>
#include<cstdio>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
// ���� ��Ʈ��ũ
// �⺻������ LCA ( Longest Common Ancient ) ��� ����
// �ܼ��� �θ� �����Ӹ� �ƴ϶� �ش� �θ���� ��ġ�� �Ǵ� �ִ�, �ּ� ������ ������ �ʿ�

#define MAX 100000

int N, M;
int depth[MAX + 1], visit[MAX + 1];
vector<tuple<int, int, int>> v[MAX + 1]; // �� ����� ���� ����
vector<pair<int, int>> edges[MAX + 1]; // ���� ����

void DFS(int a, pair<int, int> b) {
	if (visit[b.first]) return; // �̹� �湮�� ���� ��� (�� ������ ���)
	visit[b.first] = 1;

	// ��Ʈ�� 1�� �������� Ʈ���� ��������Ƿ�,
	// a�� �θ�, b�� �ڽ��̶�� ������ ���� ( ��Ʈ�� ����� ��尡 �ݵ�� ���� �湮 )
	depth[b.first] = depth[a] + 1; // �θ��� ���� + 1
	v[b.first].push_back(tuple<int, int, int>(a, b.second, b.second)); // �θ� �ε��� ������ ���
	int mul = 0, idx = a;
	while (mul < v[idx].size()) {
		int Min = min(get<1>(v[b.first].back()), get<1>(v[idx][mul])); // ������� �ǳʿ� ���� �� �ּ� ��
		int Max = max(get<2>(v[b.first].back()), get<2>(v[idx][mul])); // ������� �ǳ� �� ���� �� �ִ� ��
		v[b.first].push_back(tuple<int, int, int>(get<0>(v[idx][mul]), Min, Max)); // �ش� ��ġ�� 2�� �¼� �ڸ� �θ� ����
		idx = get<0>(v[idx][mul]); // ���� ��ġ�� �̵�
		mul += 1; // �ٴ� ���� ���� ( �������� 2�� )
	}

	for (int k = 0; k < edges[b.first].size(); k++) {
		DFS(b.first, edges[b.first][k]); // ���� ��ġ�� ����� ���鿡 ���� ���� �ݺ�
	}
}

int Match(int idx, int d, int* Min, int* Max) {
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
	*Min = min(*Min, get<1>(v[idx][k])); 
	*Max = max(*Max, get<2>(v[idx][k]));
	// ���̸� ���ߴ� �������� �߰� �� ���� �����Ƿ�, ���� ������ �ʿ�

	return Match(get<0>(v[idx][k]), d, Min, Max); // ���ȣ��
}

int Find(int a, int b, int* Min, int* Max) {
	if (a == b) return a; // ���� ���� ������ ��� ����

	int k = 0;
	for (; k < v[a].size(); k++) { // ���� depth �� �����ϹǷ� ���� ũ�⵵ ����
		if (get<0>(v[a][k]) == get<0>(v[b][k])) { // �� ������ ������ �� �ؿ� ����
			break;
		}
	}
	if (k != 0) {
		k = k - 1; // k �� 0�� ���� �״�� ����
	}
	int check1 = min(get<1>(v[a][k]), get<1>(v[b][k]));
	int check2 = max(get<2>(v[a][k]), get<2>(v[b][k]));
	*Min = min(*Min, check1); // �ּҰ� ����
	*Max = max(*Max, check2); // �ִ밪 ����

	return Find(get<0>(v[a][k]), get<0>(v[b][k]), Min, Max); // �̵��Ͽ� Ž�� ����
}

int main() {
	cin >> N;
	int a, b, c;
	depth[1] = 1; // ���̴� 1���� ����
	for (int k = 1; k < N; k++) { // 1~N-1 ���� �� N-1 ��
		scanf("%d %d %d", &a, &b, &c);
		edges[a].push_back(pair<int, int>(b, c));
		edges[b].push_back(pair<int, int>(a, c)); // ���� ������ ����
	}

	visit[1] = 1; // ��Ʈ���� ����Ͽ� �ϳ��� LCA Ʈ�� ������ ����
	for (int k = 0; k < edges[1].size(); k++) {
		DFS(1, edges[1][k]);
	}

	cin >> M;
	for (int k = 0; k < M; k++) {
		int Min = 1000000, Max = 0; // ��ȯ �޾ƾ� �ϴ� �� �� ( �����͸� ����� ���� �ְ���� )
		scanf("%d %d", &a, &b);
		if (depth[a] > depth[b]) a = Match(a, depth[b], &Min, &Max);
		else if (depth[a] < depth[b]) b = Match(b, depth[a], &Min, &Max); // �� �� ���� depth ������ ����
		Find(a, b, &Min, &Max); // ���� �θ� ã�� ���
		printf("%d %d\n", Min, Max);
	}
}