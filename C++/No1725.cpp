#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
// ������׷�
// �� ���븶�� �ڽ��� ��, �쿡�� ������ �� �ִ� ���� ���� �����ؾ� ��
// �⺻������ ���� ���� �����̳�, '����' �� Ȱ���Ͽ� ���� Ǯ�� ����

#define NUM 100000

int N, graph[NUM], from[NUM], to[NUM];

int main() {
	cin >> N; // �׷��� ����

	for (int k = 0; k < N; k++) {
		cin >> graph[k]; // �� ������ ����
	}

	{ // ���� ���� �� ���
		stack<pair<int, int>> s; // ����
		s.push({ -1, 0 }); // ������ -1�� ���� 0 ���� ���
		for (int k = 0; k < N; k++) {
			while (!s.empty()) {
				if (graph[k] > s.top().second) break; // ���� ���, �߰� ������ ����
				s.pop(); // ���� ���̺��� ũ�ų� ���� ���� ��� ����
			}
			from[k] = (s.empty() ? 1 : k - s.top().first); // �ִ�� ���� ������ ���� ���� ��
			s.push({ k,graph[k] }); // ��ǥ�� ���� ����
		}
	}

	{ // ������ ���� �� ���
		stack<pair<int, int>> s;
		s.push({ N, 0 });
		for (int k = N - 1; k >= 0; k--) {
			while (!s.empty()) { // ���� ���̺��� �۾����� ���� ��ġ�� ����
				if (graph[k] > s.top().second) break;
				s.pop();
			}
			to[k] = (s.empty() ? 1 : s.top().first - k); // �ִ�� ���� ������ ������ ���� ��
			s.push({ k,graph[k] }); // ��ǥ�� ���� ����
		}
	}

	int ans = 0;
	for (int k = 0; k < N; k++) { // �ڽ� ������ �ߺ��ǹǷ� 1�� �� �� ����
		ans = max(ans, (from[k] + to[k] - 1) * graph[k]); // ���ӵ� ���� * ����
	}
	cout << ans << endl;
}
