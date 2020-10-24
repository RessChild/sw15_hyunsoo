#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;
// Strongly Connected Component 
// SCC ����
// �� �׷������� �պ��ϴ� ����Ŭ�� �����Ѵٴ� ����
// ��� ���� �Ųٷ� �������� ���� ��ΰ� �������� �ǹ�

#define NUM 10001

int V, E, visit[NUM]; // �湮 ���� (DFS)
stack<int> s; // ����
vector<int> edge[NUM], r_edge[NUM]; // ����, �� ����

// SCC �迭 ( �� scc�� ��� ��ȣ�� ������������ ����ؾ� �ϹǷ�, �켱���� ť�� ��� )
vector<priority_queue<int, vector<int>, greater<int>>> scc;

// 1�� Ž��
void DFS(int idx) {
	if (visit[idx]) return;
	visit[idx] = 1; // �湮 ����

	for (int next : edge[idx]) DFS(next); // �������� �̵�

	s.push(idx); // �ش� ��带 ���ÿ� ����
}

// 2�� Ž��
void RDFS(int idx) {
	visit[idx] = 0; // �湮 ����
	for (int next : r_edge[idx]) {
		if (!visit[next]) continue;
		RDFS(next);
	}
	// ���� �������� ������� scc �� �ش� ��� �߰�
	scc[scc.size() - 1].push(idx);
}

int main() {
	cin >> V >> E;
	for (int k = 0; k < E; k++) {
		int a, b;
		cin >> a >> b; // �Է�
		edge[a].push_back(b);
		r_edge[b].push_back(a); // ���� ����
	}

	for (int k = 1; k <= V; k++) DFS(k); // 1�� Ž�� ����
	while (!s.empty()) {
		int node = s.top();
		s.pop();
		if (!visit[node]) continue; // �ٸ� �������� �湮�� ���� ����

		// ���ο� scc ����
		scc.push_back(priority_queue<int, vector<int>, greater<int>>());
		RDFS(node);
	}

	// �� scc ���� ����
	sort(scc.begin(), scc.end(), [](auto a, auto b) -> bool {
		return a.top() < b.top();
	});

	cout << scc.size() << endl;
	for (auto nodes : scc) {
		while (!nodes.empty()) {
			cout << nodes.top() << " "; // �� ���� ����� ����
			nodes.pop();
		}
		cout << -1 << endl; // �� scc�� �ٹٲ����� ����
	}
}