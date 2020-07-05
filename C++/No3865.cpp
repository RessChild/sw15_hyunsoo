#include<iostream>
#include<unordered_map>
#include<set>
#include<sstream>
#include<vector>
using namespace std;
// ��ȸ��
// �ߺ��� ���־��ϹǷ�, ���Ǹ� ���� set STL �� Ȱ��
// ����, ���ڿ� ó���� ���� stringstream ���� split �� ����

int N;
set<string> s;
unordered_map<string, vector<string>> m; // �� �׷캰 ����
unordered_map<string, int> visit; // �湮 ����

void DP(string g) { // DP
	if (visit[g]) return; // �湮�� ���̸� ����
	visit[g] = 1;

	for (string t : m[g]) { // �׷� �Ҽ� �ο��� ���� �ľ�
		if (!m[t].size()) s.insert(t); // ��� �̸��̸� ����
		else DP(t); // �׷� ���̸� ���ȣ��
	}
}

int main() {
	while (true) {
		cin >> N;
		if (!N) break; // 0 �̸� ����

		s.clear();
		m.clear(); 
		visit.clear(); // �ʱ�ȭ

		string save; // Ž�� �׷� �̸�
		for (int k = 0; k < N; k++) {
			string str; // ���ڿ� �Է� (�� ��)
			cin >> str;

			string group, people; // �׷�, ��� ����
			stringstream ss(str);
			getline(ss, group, ':');
			getline(ss, people, ':'); // ���ڿ� �и�

			m[group]; // ���� ����
			if (!k) save = group;; // Ž�� �׷�

			string name;
			stringstream person(people); // �Ҽ� �̸� �и�
			while (getline(person, name, ',')) { // �޸��� �������� �з�
				stringstream end(name);
				getline(end, name, '.'); // ���� ����ó�� (������ �����)
				m[group].push_back(name);
			}
		}
		DP(save); // Ž�� �׷���� ������ ���� ���� �ϳ��� ������ ����
		cout << s.size() << endl; // �� ũ�⸸ŭ ���
	}
}