#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;
// LCS 2
// DFS ������� �� case �� ���� ��Ž���� ������ �̷������ ��
// so, �޸�������̼� ����� ���

// ���� �ܼ��� ���̸��� �޴� ���� �ƴ�, �̸� ���� ��� ���ڿ��� ����ؾ��ϹǷ�
// �� ������ ���Ž�Ű�� ������ ������ �ʿ�

#define MAX 4000 // ���ڱ��� �ִ� 4000

int datas[MAX][MAX], visit[MAX][MAX]; // �ش� ��ġ���� ���ӵ� �ִ� ����
int link[MAX][MAX]; // 0: �밢��, 1: ����, 2: ����
string str1, str2;
stack<char> s;

void Search(int a, int b) {
	if (a < 0 || b < 0) return; // Ž�� �Ұ����ϸ� ����
	if (!link[a][b]) { // �밢���̶�� ���� ���ڸ� ã������ �ǹ�
		s.push(str1[a]); // ���ÿ� ����
	}
	int a_n = a - ("101"[link[a][b]] - '0'), b_n = b - ("110"[link[a][b]] - '0'); // ���� ��ġ�� ����
	Search(a_n, b_n);
}

int DP(int a, int b) {
	if (a < 0 || b < 0) return 0; // ���� ���� ����
	if (visit[a][b]) return datas[a][b]; // ���� ������ ��ȯ
	visit[a][b] = 1;

	int val;
	if (DP(a - 1, b) < DP(a, b - 1)) {
		val = DP(a, b - 1);
		link[a][b] = 1;
	}
	else {
		val = DP(a - 1, b);
		link[a][b] = 2;
	}
	if (val < DP(a - 1, b - 1) + (str1[a] == str2[b])) {
		val = DP(a - 1, b - 1) + (str1[a] == str2[b]);
		link[a][b] = 0;
	} // �� 3 ���� ��� ��, ���� ū ���� ȹ���ϰ� ��θ� ���

	return datas[a][b] = val;
}

int main() {
	cin >> str1 >> str2;

	int ans = 0;
	for (int k = 0; k < str1.length(); k++) {
		for (int m = 0; m < str2.length(); m++) {
			ans = max(ans, DP(k, m));
		}
	} // ��� ��츦 ���Ǹ� ������ Ž��
	printf("%d\n", ans);

	Search(str1.length() - 1, str2.length() - 1); // ����� ��η� ���� ���ڿ��� ����
	for (int k = 0; k < ans; k++) { // ���
		printf("%c", s.top());
		s.pop();
	}
}