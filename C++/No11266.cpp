#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
// ������
// �⺻���� �˰��� ������ ����� �ܼ� ����
// DFS ������� ��Ģ �� ������ �Ǵ�
// ( �ڽ��� �Ĺ� ������ �� ���� �ö�� �� �ִ°�? )

// �ٸ�, �Ǵ� �������� ���� ��尡 �̹� �湮�� ���� ��带 �� ��
// �ߺ� �Ǵ����� ������ �߻��ϴ� ������ �߻�
// +) DFS �� �������� ���, �ٸ� �Ǵ� ������ �ʿ�

#define MAX 10000

int V, E, visit[MAX + 1];
int val[MAX + 1][2]; // 0: �湮 ����, 1: ���ް����� �ּ� ��
int ch[MAX + 1];
vector<int> v[MAX + 1], ans; // ����� ���� ���� ����, ������ ����
int cnt, order = 1, root;

int DFS(int idx) {
	if (visit[idx]) return val[idx][1]; // ������ �湮������ ��ȯ
	visit[idx] = 1; // �湮�ߴٰ� ����

	val[idx][0] = order++; // �ش� ����� �湮 ��ȣ ��� �� �� ����
	val[idx][1] = val[idx][0]; // ���� ���� ������ �ִ���̴� �ڱ� �ڽ�

	bool flag = false;
	int subtree = 0, mini; // �ش� ����� ����Ʈ�� ����, �ڽ��� ���� ������ �ִ� ����
	for (int k = 0; k < v[idx].size(); k++) { // ��� ������ ���캸��
		if (!visit[v[idx][k]]) { // ���� �湮 ���� ���
			mini = DFS(v[idx][k]); // �ش� ���� �湮
			subtree++; // ����Ʈ�� �� ����
		}
		else { // �湮 �� ���
			if (val[idx][0] > val[v[idx][k]][0]) { // �ؿ��� �÷��ٺ��� ���
				mini = val[v[idx][k]][0]; // ������ ��ȣ�� �޾ƿ� (�׻� ŭ)
			} // ������ �����ٺ��� ���� Ž���������� ���� ó�������Ƿ� ����
		}
		if (mini >= val[idx][0]) // �ڽĵ��� �� ���� ���� �ٸ� ���� ���ٸ�
			flag = true; // �ش� ���� ������
		val[idx][1] = min(val[idx][1], mini); // ���� �ڽ��� ���� �̵� �����ϹǷ� �Ǵ� �ʿ�
	}

	if ((idx != root && flag) || (idx == root && subtree > 1)) {
		// 1. ��Ʈ�� �ƴ� ��� : ���� ����� ������ ���� �Ǵ�
		// 2. ��Ʈ�� ��� : �ڽ��� ���� ����Ʈ���� ������ �Ǵ�
		cnt++;
		ans.push_back(idx);
	}
	return val[idx][1]; // �� �� �ִ� ���� ���� ��ġ�� ��ȯ
}

int main() {
	scanf("%d %d", &V, &E);

	int a, b;
	for (int k = 0; k < E; k++) {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a); // ���⼺�� �����Ƿ�, ���� ��ο� ���� �߰�
	}
	for (int k = 1; k <= V; k++) {
		if (visit[k]) continue; // ������ ��带 ����Ͽ� ��� Ž�� �õ�
		root = k;
		DFS(k);
	}
	sort(ans.begin(), ans.end()); // ���õ� ������ ����

	printf("%d\n", cnt);
	for (int k = 0; k < cnt; k++) {
		printf("%d ", ans[k]); // ���� ���
	}
}