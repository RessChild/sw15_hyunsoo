#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<algorithm>
using namespace std;
// �ִܰ��
// ���ͽ�Ʈ�� �˰��� �ܼ� ���� ����

#define MAX 20000
#define INF MAX*10 + 1

struct S { // �켱���� ť�� �Ǵܿ� ����ü
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

int V, E, root, visit[MAX + 1], w[MAX + 1]; // ���� ����, Ȯ���� ����� ���� ���
vector<pair<int, int>> v[MAX + 1]; // ���� ���� (���� ��� ��ȣ, ����ġ)
priority_queue<pair<int, int>, vector<pair<int, int>>, S> pq; // ��� �� ���� ���
// ���ͽ�Ʈ���� ���, ������� �ʴ� ��� �� �ּҰŸ��� ���� ���� ����

int main() {
	scanf("%d %d %d", &V, &E, &root);

	for (int k = 1; k <= V; k++) {
		w[k] = INF; // �� ����� ù ����ġ�� ���� (�� �� �ִ� �� ����)
	}

	int a, b, c;
	for (int k = 0; k < E; k++) {
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(pair<int, int>(b, c)); // ���� �Է�
	}

	w[root] = 0;
	pq.push(pair<int, int>(root, 0));
	while (!pq.empty()) { // �켱���� ť�� �� �� ����
		pair<int, int> sel = pq.top(); // ���� ���� ��ΰ� ���� ��带 ������
		pq.pop();
		if (visit[sel.first]) continue; // �̹� ���õ� ��� ����
		visit[sel.first] = 1; // �湮 ����

		for (int k = 0; k < v[sel.first].size(); k++) { // �ش� ���� ����� ��� ������ ���캽
			int len = v[sel.first][k].second + sel.second; // �ش� ��θ� ���ļ� �����ϴ� �Ÿ��� ���
			if (w[v[sel.first][k].first] > len) {
				w[v[sel.first][k].first] = len;
				pq.push(pair<int, int>(v[sel.first][k].first, len)); // ���� ���� �����ٸ�, ���� �� ť�� �߰�
			}
		}
	}
	for (int k = 1; k <= V; k++) { // ��� ��� ��� ���
		if (w[k] == INF) printf("INF\n");
		else printf("%d\n", w[k]);
	}
}