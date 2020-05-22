#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
// ��ȣ �����
// ������ �����ϴ� ��� ���ڿ��� ���

int len, num, stack[16];
string mo_c = "aeiou"; // ���� ���� ����
vector<char> v; // ���� ���� ����

void DFS(int select, int cnt); // DFS Ž��

int main() {
	cin >> len >> num;
	for (int k = 0; k < num; k++) {
		char info;
		cin >> info;
		v.push_back(info);
	}  // ���ڸ� �Է¹޾� ���Ϳ� �߰� (���� ����Ʈ�� ����)

	sort(v.begin(), v.end()); // ����
	for (int k = 0; k <= num - len; k++)
		DFS(k, 0); // ��� ���ڿ��� ���� ���� Ž��
}

void DFS(int select, int cnt) {
	stack[cnt] = select;
	if (cnt == len - 1) { // ���ϴ� ���� ���̿� �����ϸ� ���� üũ
		string ans = "";
		int ja = 0, mo = 0;
		for (int k = 0; k < len; k++) {
			ans += v[stack[k]]; // ���ڸ� ���信 �߰�
			if (mo_c.find(v[stack[k]]) != -1) mo++; // ���� ���տ� �ִٸ� ���� �� �߰�
			else ja++; // ������ ����
		}
		if (mo >= 1 && ja >= 2) // ������ �����ϸ� ���
			cout << ans.c_str() << endl;
		return;
	}

	for (int k = select + 1; k < num; k++) {
		DFS(k, cnt + 1); // ���� �����ϴ� ���ڿ� ���� ���Ž��
	}
}