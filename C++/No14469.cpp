#include<iostream>
#include<queue>
#include<tuple>
#include<algorithm>
using namespace std;
// �Ұ� ���� �ǳʰ� ���� 3
// �켱���� ť, �� ��

typedef pair<int, int> p;

struct func {
	bool operator()(p a, p b) { return a.first > b.first; }
};

int N;
priority_queue<p, vector<p>, func> pq;
// ������ �ð�, �˹� �䱸�ð�

int main() {
	cin >> N; // �Է�
	for (int k = 0; k < N; k++) {
		int a, b;
		cin >> a >> b;
		pq.emplace(a, b);
	}

	int ans = 0;
	while (!pq.empty()) {
		int a, b;
		tie(a, b) = pq.top();
		pq.pop();
		// ��������� ���� �ð��� ���� ���� �ð� �� ū ���� ������� ���
		ans = max(ans, a) + b;
	}
	cout << ans << endl;
}