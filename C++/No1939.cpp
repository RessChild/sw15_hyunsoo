#include<cstdio>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
// �߷�����
// �̵��ϴ� ��θ� ���� ���� ������ �ִ� ���Ը� ȹ���ؾ� ��
// so, ��ΰ� ���� ���� ��� �ִ� ���� �����ؾ��ϰ�,
// �ϳ��� ��� ������ ���� ���ҵ��� �ּҰ��� ���� ������ �ִ� ���԰� ��

// �Էµ� ������ ���� ������ �����Ͽ� maximum-spanning tree �� ����
// ����, �ش� Ʈ���� Ž���ϸ�, ���ϴ� ��忡 ������ ���,
// ������� ���İ� �ּ� ũ���� ������ ����ϴ� ���

#define NUM 100000 // ����� �ִ� ����
#define INF 1000000000 // �ٸ��� �ִ� ����߷�

int N, M, A, B, node[NUM + 1], from, to, visit[NUM + 1], ans;
vector<tuple<int, int, int>> v; // ��ü ����
vector<pair<int, int>> whole[NUM + 1]; // ����� ����

int Repre(int a) { // ��ǥ�� ȹ�� �Լ�
	if (node[a] == a) return a; // ��ǥ�� ��ȯ
	return node[a] = Repre(node[a]);
}

bool Union(int a, int b) { // ��ġ ���� �Ǵ�
	return Repre(a) == Repre(b);
}

void DFS(int a, int weight) { // ��� Ž��
	if (a == to) { // from ���� to �� �����ߴٸ�
		ans = weight; // ������� ���� �� �ٸ� �� �ּҰ��� ����
		return; // ����
	}
	if (visit[a]) return; // �̹� �湮�� �� ����
	visit[a] = 1;

	for (auto edge : whole[a]) { // ������ ������ ����
		int b, c;
		tie(b, c) = edge; // ���� ������ + ���� ����
		DFS(b, min(weight, c)); // �̵�
	}
}

int main() {
	scanf("%d %d", &N, &M);

	for (int k = 1; k <= N; k++) {
		node[k] = k;
	}

	for (int k = 0; k < M; k++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v.push_back(tuple<int, int, int>(a, b, c)); // Ʃ�� ���·� ������ ����
	}

	scanf("%d %d", &from, &to); // ������ �ִ� �� ����

	sort(v.begin(), v.end(), [](auto a, auto b)->bool { // ���� ����
		return get<2>(a) > get<2>(b); // �ٸ��� ��� ���԰� ū ������� ����
		});

	// ������ ū ������� Ȯ�� ( Maximum-spanning Tree )
	for (auto& edge : v) { // �� �����鿡 ����
		int a, b, c;
		tie(a, b, c) = edge; // Ʃ�� ���� ���� �� ���� �޾ƿ�
		if (Union(a, b)) continue; // �̹� ����� �׷��̸� �ǳʶ�

		whole[a].push_back(pair<int, int>(b, c));
		whole[b].push_back(pair<int, int>(a, c)); // ������ ����
		
		int r_a = Repre(a), r_b = Repre(b);
		r_a > r_b ? node[r_a] = r_b : node[r_b] = r_a; // �� �׷��� ��ħ

		if (Union(from, to)) break; // �� ���ð� ����� ���, ����
	}

	DFS(from, INF); // Ʈ�� Ž��
	printf("%d\n", ans); // ���� ���
}