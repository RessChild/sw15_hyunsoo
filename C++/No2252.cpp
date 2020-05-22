#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
// �ټ����
// ���� ���� (topological sort) ���
// ó���� �켱���� ť 2���� ����Ͽ� ����� �Ǵ��Ϸ� ������,
// �־��� ��� N�� ���� ������ �����Ƿ� �ð� �ʰ�
// so, ���Ϳ� ī��Ʈ �迭�� ����Ͽ� ����ȭ

#define MAX 32000

int s, c;
int front[MAX + 1];
vector<int> back[MAX + 1]; // �ڽ��� �ڿ� �ִ� ���
vector<int> v;

int main() {
	cin >> s >> c;
	for (int k = 0; k < c; k++) {
		int a, b;
		scanf("%d %d", &a, &b);
		front[b] += 1; // b �� �տ��� �ݵ�� a�� �����ؾ� ��
		back[a].push_back(b); // ������ ����
	}
	for (int k = 1; k <= s; k++) { // �ڽ� �տ� �ʼ���Ұ� ���� ���, ����
		if (!front[k]) v.push_back(k);
	}

	for (int k = 0; k < v.size(); k++) {
		int data = v[k]; // �����͸� ����
		printf("%d ", data); // ���
		for (int m = 0; m < back[data].size(); m++) {
			front[back[data][m]] -= 1; // indegree ����
			if (!front[back[data][m]]) { // 0�� ��� ���Ϳ� ����
				v.push_back(back[data][m]);
			}
		}
	}
}
