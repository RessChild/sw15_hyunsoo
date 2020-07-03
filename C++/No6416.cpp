#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
// Ʈ���ΰ�?
// �迭 Union-Find �� Ȱ���Ϸ�������, ���� ���ְ� �ʹ� �龦����
// vector�� ����ϴ� ���, �޸��ʰ��� �߻�
// so, ������ �ִ��� �ܼ�ȭ���� ����

// �� ��尡 ���� �θ� ���°�?
// ��Ʈ�� �� �� �ִ� ����� �������ΰ�?
// ��尡 �ϳ� ���� Ʈ���ΰ�?

#define MAX 15

int arr[MAX]; // Union-Find �� Ȱ��
unordered_map<int, int> m; // Ʈ���� �θ� ����

int main() {
	bool loop = true;
	for (int k = 1; ; k++) {
		int u, v;
		bool flag = true; // Ʈ�� ����

		m.clear(); // �ʱ�ȭ

		while (true) {
			cin >> u >> v;
			if (u + v < 0) { // ���� ���� �� ���� ���� ��
				loop = false;
				break;
			}
			if (u + v == 0) break; // ���� 0�̸� �Է� ��

			if (m[v]) flag = false; // ���� ������ ���� ���� ���, Ʈ���� �ƴ�
			m[v] = u; // v �� �θ�� u
			m[u]; // �θ� u�� ������ ����
		}

		if (!loop) break; // ���̽� ������ ����
		
		int cnt = 0; // �θ� ���� ����� ��
		for (unordered_map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
			// ���� ��� �������Ҹ� ���캽
			if (!it->second) cnt += 1; // �θ� ���ٸ� ����
		}
		flag &= (!m.size() || cnt == 1);
		// ��尡 �����ϰų�, ��Ʈ�� �� �ϳ��� ���
		cout << "Case " << k << " is " << (!flag ? "not " : "") << "a tree." << endl;
	}
}