#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<algorithm>
#include<functional>
using namespace std;
// ��Ȯ�� ������
// ���ͽ�Ʈ�� ����� ��� ����
// ����� ���� ���ο� ���� ��Ʈ����ŷ�� ����Ϸ� ������,
// �Է� ������ ����� �ĺ����� �ִ� 2000 �̹Ƿ�, ǥ�� ���� ���ָ� �Ѿ
// so, ���� �Լ� ������ ���� ������ Ȯ���ϴ� ������� �ڵ带 ���

#define NUM 2000

typedef tuple<int, int, int> tp;

int main() {
	int loop;
	cin >> loop;
	while (loop--) {
		int N, M, T, S, G, H; // ������, ����, �������ĺ�, �����, G-H
		cin >> N >> M >> T >> S >> G >> H;

		int visit[2][NUM + 1] = {}; // ���� ���, �ʿ俧�� ��� ����
		vector<pair<int, int>> v[NUM + 1]; // ���� ����

		for (int k = 0; k < M; k++) {
			int a, b, c;
			cin >> a >> b >> c;
			v[a].push_back({ b,c });
			v[b].push_back({ a,c });
		}

		// ��� ��� Ȯ�� �Լ� (���ٽ�)
		auto func = [&](int a, int b)->bool{
			return (a == G && b == H) || (a == H && b == G);
		};

		priority_queue<tp, vector<tp>, greater<tp>> pq;
		pq.emplace(0, 0, S); // ����� S ���� �ִܰŸ� Ž��
		while (!pq.empty()) {
			int val, prnt, child;
			tie(val, prnt, child) = pq.top();
			pq.pop();
			if (visit[0][child]) { // ������ �湮�� ���
				if (visit[0][child] == val) // ���� ������ ���� ��츸, ��� ���� ����
					visit[1][child] = max(visit[1][child], visit[1][prnt]) + func(prnt, child);
				continue; // �̹� �湮�� ���� ����
			}
			visit[0][child] = val; // �ش� ������ ����

			// G-H ��� ���ο� ���� ����� ���̰� ����
			if (func(prnt, child)) visit[1][child] = 1;
			else visit[1][child] = visit[1][prnt];

			// ���� Ž���� ��� ����
			for (pair<int, int> next : v[child])
				pq.emplace(val + next.second, child, next.first);
		}

		// ������ �ĺ� �߷�����
		priority_queue<int,vector<int>,greater<int>> ans;
		for (int k = 0; k < T; k++) {
			int a;
			cin >> a;
			ans.push(a);
		}
		while (!ans.empty()) { // G-H �� ����ߴٸ� ���
			if (visit[1][ans.top()]) cout << ans.top() << " ";
			ans.pop();
		}
		cout << "\n";
	}
}