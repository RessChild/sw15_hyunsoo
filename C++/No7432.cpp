#include<iostream>
#include<vector>
#include<cstring>
#include<sstream> // ���ڿ� �и��� ���� ���̺귯��
#include<algorithm>
using namespace std;
// ��ũ Ʈ��
// Trie �� ����� ����
// �ٸ�, �ش� �ڵ�� ��� ���� ���θ� ����Ž������ ã�Ƴ��Ƿ� ����� ��ȿ����

class Dir { // Ʈ���� ����ü
public:
	vector<pair<string, Dir*>> folder; // ���� ���
};

int N;
Dir dir; // Ʈ����

void DFS(Dir* move, int idx) { // ��� ��� ��� �Լ�
	sort(move->folder.begin(), move->folder.end(), [](pair<string, Dir*> a, pair<string, Dir*> b) -> bool {
		return strcmp(a.first.c_str(), b.first.c_str()) < 0;
	});

	for (pair<string, Dir*> info : move->folder) {
		for (int k = 0; k < idx; k++) cout << " ";
		cout << info.first << endl; // �ش� �������� ���
		DFS(info.second, idx + 1); // ���� ���� ���
	}
}

int main() {
	cin >> N;
	for (int k = 0; k < N; k++) { // ��� �Է�
		string str;
		cin >> str;

		vector<string> list; // ���丮�� ������ ����� ����
		stringstream ss(str); // �Էµ� str ���� �о�� string stream
		string part; // �ɰ��� �κ� ���ڿ� ������ ����
		while (getline(ss, part, '\\')) { // \ �� �������� �� �κ��� �߶�
			list.push_back(part);
		}

		Dir* move = &dir;
		for (string path : list) { // �־��� ��� ��ο� ���� Ʈ���� ����
			Dir* find = NULL;
			for (int k = 0; k < move->folder.size(); k++) { // �ش� ��ΰ� �ִٸ� ����
				if (move->folder[k].first == path) find = move->folder[k].second;
			}

			if (find == NULL) { // ã�� ��ΰ� ������
				find = new Dir();
				move->folder.push_back({ path, find }); // ���� ���� ����
			}
			move = find;
		}
	}

	DFS(&dir, 0); // ���������� ��� ���
}
