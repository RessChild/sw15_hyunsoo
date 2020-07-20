#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Trie {
public:
	unordered_map<char, Trie*> m;
};

bool solution(vector<string> name_list) {
	bool answer = false;
	sort(name_list.begin(), name_list.end(), [](string a, string b)->bool {
		// �̸��� ���� ������ ����
		return a.length() > b.length();
		});

	Trie trie; // Ʈ���� ����
	for (string name : name_list) { // �̸��� ����
		bool flag = false;
		vector<Trie*> v;
		for (char c : name) { // ���ڷ� Ʈ���� ����
			v.push_back(&trie); // �� ������ �߰�
			for (int k = 0; k < v.size(); k++) {
				if (!(v[k]->m[c])) { // ����� ���� ������
					v[k]->m[c] = new Trie();
					if (k == 0) flag = true;
					// ������ ���ο� ���� Ʈ�� ���, �ߺ�����
				}
				v[k] = v[k]->m[c]; // �� ��ǥ�� �̵���Ŵ
			}
		}
		if (!flag) {
			// �� ���� ������ ���� ������ �ִٸ� �ߺ�
			answer = true;
			break;
		}
	}
	return answer;
}