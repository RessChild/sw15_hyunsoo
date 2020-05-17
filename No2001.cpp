#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<algorithm>
using namespace std;
// ���� �ݱ�
// �ִ� ���� Ʈ���� ���� ��, �Ǵ�
// cause, �ִ����� ������ �ݱ� ���ؼ� ���Ǵ� �ٸ��� ũ�Ⱑ �ִ�ġ�� �Ǵ°� ����
// �� �ٸ��� ������������ �����Ͽ� DFS Ž��
// ���� �ٸ��� �ǳʿ� �� �־��ٸ�, ū �ٸ��� �� ������ ��� ���� �̵��� �� �ֱ� ����

#define NUM 100
typedef tuple<int, int, int> tp; // a�� b�� �����ϴ� ����ġ c �ٸ�

struct func { // �켱���� ť ���� ����
	bool operator()(tp a, tp b) {
		return get<2>(a) < get<2>(b);
	}
};

int N, M, K, visit[NUM + 1], land[NUM + 1], group[NUM + 1];
vector<pair<int,int>> v[NUM + 1]; // ���õ� �ٸ� ����
priority_queue<tp, vector<tp>, func> pq; // �ִ� ��â Ʈ�� ������ �켱���� ť

// Union-Find
int Find(int idx) {
	if (group[idx] == idx) return idx;
	return group[idx] = Find(group[idx]);
}

bool Union(int a, int b) {
	int ra = Find(a), rb = Find(b);
	if (ra == rb) return false;
	group[ra] = rb;
	return true;
}

// DFS Ž��
int DFS(int idx, int sum) { // ���� ����ȣ, ������� �ֿ� �� ���� ��
	if (visit[idx]) return sum; // �̹� �湮�� ���̸� ����
	visit[idx] = 1;

	// �� ��带 �ٸ� ���ġ�� ���� ������ ����
	sort(v[idx].begin(), v[idx].end(), [](pair<int, int> a, pair<int, int> b)->bool {
		return a.second < b.second;
		});

	for (pair<int, int> next : v[idx]) { // ���� �ٸ����� �ǳʸ� ������ �ֿ���
		sum = min(next.second, DFS(next.first, sum));
		// �ٸ��� ���ġ��, �Ѿ ������ �ֿ� �� ������ �� ���� �� ���� ���� ����
	}
	return sum + land[idx]; // ���� ��ġ�� ������ �ֿ��� �̵�
}

int main() {
	cin >> N >> M >> K;
	for (int k = 1; k <= N; k++) { // ���Ͽ����ε� ����
		group[k] = k;
	}
	for (int k = 0; k < K; k++) { // ���� �Է�
		int num;
		cin >> num;
		land[num] = 1; // �ش� ���� ������ ����
	}
	for (int k = 0; k < M; k++) { // ���� �Է�
		int a, b, c;
		cin >> a >> b >> c;
		pq.push({ a,b,c }); // �ش� ������ ����
	}

	while (!pq.empty()) { // �ִ� ���д� Ʈ�� ����
		int a, b, c;
		tie(a, b, c) = pq.top();
		pq.pop();

		if (Union(a, b)) { // ���� �� �׷��� ���� ��ģ�Ŷ��
			v[a].push_back({ b,c });
			v[b].push_back({ a,c }); // �ش� ������ �����
		}
	}
	cout << DFS(1, 0) << endl; // ���������� Ž��
}