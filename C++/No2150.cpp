#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// SCC
// �ڻ���� �˰����� ����Ϸ� ������, ����

int v, e; // ���, ���� ��
bool visit[10000]; // �ϳ��� SCC���� �����ϴ� ��
vector<int> ori[10000]; // 10000���� ���鿡 ���� �������
vector<int> rev[10000]; //������ �׷���
vector<int> stack; // ����
vector<vector<int>> group;

void DFS(int here); // �׷��� Ž��
void Union();
void R_DFS(int here, int& num);


int main() {
	cin >> v >> e;

	while (e--) {
		int a, b; //���� ����
		cin >> a >> b;
		ori[a - 1].push_back(b - 1); // a���� b �������� �����
		rev[b - 1].push_back(a - 1); // �� ����
	}

	for (int k = 0; k < v; k++) { // ��� ��带 �湮�ؾ���
		if (!visit[k]) // ���� �湮 ���� ���� �ִٸ�
			DFS(k); //�湮 ����
	} // �켱 �� ���� �׷��� Ž�� �Ϸ�
	Union();
}

void DFS(int here) {
	if (visit[here]) // �湮�� ���� �ִ� ���̸�
		return; // �ѷ����� ����
	visit[here] = true; // �湮 ������ ǥ��
	for (int k = 0; k < ori[here].size(); k++) { //�ڽŰ� ����� ��� ������ ����
		DFS(ori[here][k]); // �ش� ���� �湮 �õ�
	}
	stack.push_back(here); //�ش� ��ġ�� ����� ������ ��� ��������, ���ÿ� ���� (Ž�� ���� ��)
	return;
}

void Union() {
	for (int k = 0; k < v; k++) {
		visit[k] = false; // �ʱ�ȭ
	}
	int num = 0;
	for (int k = stack.size() - 1; k >= 0; k--) {
		int place = stack[k]; // �̹��� �湮�ؾ��� ��
		if (visit[place])
			continue; // �̹� �湮�� ���̶�� �ѱ�� �ƴϸ� ����
		group.resize(group.size() + 1); //����� 1ĭ �ø�
		R_DFS(place, num); // Ž�� ����
		num++;
	}

	int head[10000];
	for (int k = 0; k < group.size(); k++) { // �׷� �������� ��� �ʱ�ȭ
		sort(group[k].begin(), group[k].end()); // �ش� ������ ����
		head[k] = k;
	}

	for (int k = 0; k < group.size(); k++) {
		for (int i = k; i < group.size(); i++) {
			if (group[head[k]][0] > group[head[i]][0]) {
				// ���� �������� ���� �ּҰ��� �ڿ� ���� ���� �ּҰ����� ���� ���
				int save = head[k];
				head[k] = head[i];
				head[i] = save; // ��������
			}
		}
	} // �� �׷캰�ε� ����

	for (int k = 0; k < group.size(); k++) {
		int list = head[k]; // ���ĵ� ������� SCC�� ���
		for (int i = 0; i < group[list].size(); i++) {
			cout << group[list][i] + 1 << " ";
		}
		cout << "-1\n"; // ���� -1
	}
}

void R_DFS(int here, int& num) {
	if (visit[here]) // �湮�� ���� �ִ� ���̸�
		return; // �ѷ����� ����
	visit[here] = true; // �湮 ������ ǥ��
	for (int k = 0; k < rev[here].size(); k++) { //�ڽŰ� ����� ��� ������ ����
		R_DFS(rev[here][k], num); // �ش� ���� �湮 �õ�
	}

	group[num].push_back(here); //�ش� �׷쿡 �Ҽ�������

	return;
}
