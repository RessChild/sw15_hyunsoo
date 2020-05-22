#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
// ���� �κ� ���ڿ�
// ���� ���� ���� '���ӵ�' ���ڿ��� ������ ��
// so, ��ġ�ϴ� ��쿡�� �밢�� ������ ������Ŵ

#define MAX 4000 // ���ڱ��� �ִ� 4000

int datas[MAX][MAX], visit[MAX][MAX]; // �ش� ��ġ���� ���ӵ� �ִ� ����
string str1, str2;

int DP(int a, int b) {
	if (a < 0 || b < 0) return 0; // ���� ���� ����
	if (visit[a][b]) return datas[a][b]; // ���� ������ ��ȯ
	visit[a][b] = 1;
	if (str1[a] == str2[b]) // ���� ��쿣 �밢�� ������ �� +1
		return datas[a][b] = DP(a - 1, b - 1) + 1;
	return 0; // ���ӵ� ���� ����� 0 ��ȯ
}

int main() {
	cin >> str1 >> str2;
	 
	int ans = 0;
	for (int k = 0; k < str1.length(); k++) {
		for (int m = 0; m < str2.length(); m++) { // ��� ���� ������ Ž��
			ans = max(ans, DP(k, m));
		}
	}
	printf("%d\n", ans);
}