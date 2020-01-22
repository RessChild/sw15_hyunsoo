#include<iostream>
#include<unordered_map>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
// ī�� ����
// �ܼ��� ���� ���� �����̳�,
// 2�ڸ� �� ī��� ���� �����ϴ� ���� �ߺ� �Ǵ��� ������ ����
// so, hash map �� ���� ���� �ߺ��� �Ǵ�

int cnt;
int N, K;
int visit[100], s[10]; // ������ �ε��� ����
vector<int> v;
unordered_map<int, bool> m; // �� �ߺ��� �Ǵ��� hash map

int S(int level) {
	if (level == K) { // ���ϴ� ī�常ŭ ���� ���
		int key = 0;
		for (int k = 0; k < K; k++) {
			key *= v[s[k]] < 10 ? 10 : 100;
			key += v[s[k]];
			// ���� ������ ��ġ�� �ʵ��� Ű�� ����
			// 1~9 = 10 �� ��, 10~99 = 100
		}
		if (m.end() != m.find(key)) return 0; // �̹� �����ϴ� ���̶�� ����
		m[key] = true; // Ű�� �ʿ� �߰�
		return 1; // ��� �� + 1
	}

	int sum = 0;
	for (int k = 0; k < v.size(); k++) {
		if (visit[v[k]] == 0) continue; // ���� �� �ִ� ī�尡 ���ٸ� �ѱ�
		s[level] = k; // ���Ϳ� ���� �ε��� ����
		visit[v[k]] -= 1; // ī�� �ϳ� ����
		sum += S(level + 1); // ��� ȣ��
		visit[v[k]] += 1; // ī�� ��ȯ
	}
	return sum; // ���� ��ȯ
}

int main() {
	cin >> N >> K;
	for (int k = 0; k < N; k++) {
		int num;
		cin >> num;
		v.push_back(num);
		visit[num] += 1; // ī�� �� üũ
	}

	int sum = 0;
	for (int k = 0; k < v.size(); k++) { // ������ ��� ��츦 ���鼭
		s[0] = k; // ���� �ε��� ����
		visit[v[k]] -= 1;
		sum += S(1); // ȣ��
		visit[v[k]] += 1;
	}
	cout << sum << endl;
}