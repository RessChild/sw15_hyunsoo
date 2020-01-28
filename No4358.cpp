#include<iostream>
#include<cstdio>
#include<string>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
// ������
// ���� �˰����� Trie ������, hash map �� ���� ���� üũ�ε� ���
// �ٸ�, �Է� �����Ϳ��� �� �ٿ� ���� ����ó���� �߰��� �ʿ�����
// �ణ ���ڰ� �ִ� ����

float cnt;
vector<string> v;
unordered_map<string, int> m;

int main() {
	string str;
	while (!cin.eof()) { // ���� ���� �ƴ� ��� ���� �ݺ�
		getline(cin, str); // ���ڿ��� �ٴ����� �Է�
		if (str.length() != 0) { // �� ������ �ƴ϶�� (������ ������ ����ó���� �ʿ���)
			cnt++;
			if (m.find(str) != m.end()) { // �̹� ����ִ� �������
				m[str] += 1; // 1ȸ ����
			}
			else {
				m[str] = 1; // 1�� ���� �� ���Ϳ� �߰�
				v.push_back(str);
			}
		}
	}
	sort(v.begin(), v.end(), [](string& a, string& b)->bool {
		return a.compare(b) < 0; // ���� �� ����
		});
	for (int k = 0; k < v.size(); k++) {
		printf("%s %.4f\n", v[k].c_str(), (m[v[k]] * 100) / cnt);
		// string �� char* ������ ��ȯ �� ������ �Ҽ� 4�ڸ����� ���
	}
}