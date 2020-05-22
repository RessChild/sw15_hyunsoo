#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
// DFS ����� ����
// �⺻������ DFS Ž���� �ϵ�, �Է� ������ ��ġ�ϴ� ���θ� �̵��� �õ�
// �Ź� ���� ������ Ž���ϸ�, ���������� ť�� �����ִ� ������ ������ �Ǵ�

#define NUM 100000
#define ROOT 1

int N, visit[NUM + 1]; // �湮 ����
vector<int> v[NUM + 1]; // ���� ����
queue<int> ans; // ���� ���θ� �Ǻ��� ť

void DFS(int idx) {
	if (ans.empty()) return; // ����ִٸ� ���������� Ž��
	visit[idx] = 1;

	int next = ans.front();
	for (int k = 0; k < v[idx].size(); k++) { // ��� ������ ���캽
		if (v[idx][k] == next) {
			// Ž�� ������ �´� ��尡 ������
			ans.pop(); // �ش� ��带 �̾Ƴ��� ���ȣ��
			DFS(next);
			if (ans.empty()) return; // ����ִٸ� ����
			next = ans.front(); // ���� Ž�� ��带 ���� ��
			k = -1; // �ٽ� ó������ ������ ����
		}
	}
}

int main() {
	cin >> N;
	int a, b;
	for (int k = 1; k < N; k++) { // ���� ����
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a); // ������ �� �� �����Ƿ� �Ѵ� �߰�
	}
	int order;
	for (int k = 0; k < N; k++) { // ���Ŀ� Ž�� ������ �޾ƿ�
		scanf("%d", &order);
		ans.push(order);
	}
	int start = ans.front(); // ������ üũ
	ans.pop();
	if (start != ROOT) cout << 0 << endl; // ��Ʈ�� �������� ������ ������ ����
	else {
		DFS(start);
		cout << (ans.empty()) << endl; // Ž�� �� ���� ť ������ �Ǵ�
	}
}
