#include<iostream>
#include<unordered_map>
using namespace std;
// ���ڿ� ����
// ���� ���� �ڷ��� ���� Ȯ��
// Ʈ���̸� ����Ͽ� ������ ���� ����

int N, M, ans; // ���� ����, �Է� ���� ��, ����
unordered_map<string, int> m; // ��

int main() {
	cin >> N >> M;
	for (int k = 0; k < N; k++) { // ���� ���� ����
		string str;
		cin >> str;
		m[str] = 1;
	}
	for (int k = 0; k < M; k++) { // ��ġ�ϴ� ���� ���� Ȯ��
		string str;
		cin >> str;
		if (m[str]) ans += 1; // �ִٸ� ���� �� ����
	}
	cout << ans << endl;
}