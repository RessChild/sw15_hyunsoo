#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
// ġŲ ���

#define INF 50000

int N, M, visit[100]; // �� ũ��, ������ ���� ��, ���� Ž���� �ε���
vector<pair<int, int>> store, home; // ����, �� ��ǥ

int DFS(int idx, int depth) {
	visit[depth++] = idx; // ���� ��ġ�� ������ ����
	if (depth == M) { // ���ϴ� ���̱��� ������ ���
		int cost[100]; // �� ������ ���Ա����� �ּҰŸ�
		for (int k = 0; k < home.size(); k++) {
			cost[k] = INF;
		}
		for (int m = 0; m < M; m++) { // ������ ��� ���Կ� ���� ��
			pair<int, int> s = store[visit[m]]; // ��ǥ ȹ��
			for (int k = 0; k < home.size(); k++) { // �� ���� ���� �ּҰŸ��� ȹ��
				cost[k] = min(cost[k], abs(s.first - home[k].first) + abs(s.second - home[k].second));
			}
		}
		int ans = 0; // �ش� ����� ġŲ�Ÿ��� �� ��
		for (int k = 0; k < home.size(); k++) {
			ans += cost[k];
		}
		return ans; // ���� ��ȯ
	}

	int mini = INF; // ���̰� ������ ���, ���� �����ϴ� ���鿡 ���� ���ȣ��
	for (int k = idx + 1; k < store.size(); k++) {
		mini = min(mini, DFS(k, depth)); // �ּҰ� ����
	}
	return mini;
}

int main() {
	cin >> N >> M;
	for (int k = 0; k < N; k++) {
		for (int m = 0; m < N; m++) {
			int data;
			cin >> data;

			if (data == 1) home.push_back(pair<int, int>(k, m));
			else if (data == 2) store.push_back(pair<int, int>(k, m)); // ����, �� ��ǥ ���� ���
		}
	}

	int ans = INF;
	for (int k = 0; k < store.size(); k++) {
		ans = min(ans, DFS(k, 0));
	} // ��� ��� ��, ġŲ�Ÿ��� ���� ���� ���� ����
	cout << ans << endl;
}