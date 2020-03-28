#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
// �ּ� ���д� Ʈ��
// ������ �ּҰ� ������ �����ϴ� ũ�罺Į �˰��� ���

#define NUM 10000 // ��Ʈ �ִ� ����

struct func { // �켱���� ť ���� ����
	bool operator()(tuple<int, int, int> a, tuple<int, int, int> b) {
		return get<2>(a) > get<2>(b);
	}
};

int V, E, ans;
int group[NUM + 1]; // �� ��尡 ������ �׷쿡 �����ִ°�?
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, func> pq;

int Find(int a) { // �׷� Ȯ��
	if (group[a] == a) return a;
	return group[a] = Find(group[a]);
}

bool Sum(int a, int b) { // �� �׷��� �������� Ȯ�� �� ��ħ
	int r_a = Find(a), r_b = Find(b);
	if (r_a == r_b) return false;
	group[r_a] = group[r_b];
	return true;
}

int main() {
	cin >> V >> E;

	for (int k = 1; k <= V; k++) group[k] = k; // �ʱ�ȭ
	for (int k = 0; k < E; k++) { // ���� �Է�
		int a, b, w;
		cin >> a >> b >> w;
		pq.emplace(a, b, w);
	}

	while (!pq.empty()) { // �ּ� ���д� Ʈ�� ����
		int a, b, w;
		tie(a, b, w) = pq.top();
		pq.pop();
		if (Sum(a, b)) ans += w; // �ٸ� �׷��̸� ������ ��� (����ġ �߰�)
	}
	cout << ans << endl;
}