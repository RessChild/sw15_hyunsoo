#include<iostream>
using namespace std;
// ���� ����
// ���� Ž�� ����ó�� ��������, ���Ḹ �����Ѵٸ� ��θ� ũ�� ���Ƽ� �� �� ����
// so, �����δ� �׷��� �����̸� Union-Find �� �ذ� ����

#define NUM 200

int N, M, group[NUM + 1];

int Find(int a) {
	if (group[a] == a) return a;
	return group[a] = Find(group[a]);
}

void Union(int a, int b) {
	group[Find(a)] = Find(b); // �� ��Ʈ�� ���� ��ħ
}

int main() {
	cin >> N >> M;

	for (int k = 1; k <= N; k++) {
		group[k] = k; // �ڱ� ���� ���̸� ��Ʈ
	}

	for (int k = 1; k <= N; k++) {
		for (int m = 1; m <= N; m++) {
			int a;
			cin >> a;
			if (a) Union(k, m); // k�� m�� ���� �׷� �Ҽ� (�����)
		}
	}

	bool flag = true;
	int start;
	cin >> start;
	for (int k = 1; k < M; k++) {
		int idx;
		cin >> idx;
		if (Find(start) != Find(idx)) { // �׷��� �ٸ��ٸ� �ش� ��δ� �Ұ���
			flag = false;
			break;
		}
	}
	cout << (flag ? "YES" : "NO") << endl;
}