#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
// �̸� �����
// �־��� ���ڿ� ���� � ���ڸ� ���� ó���ϴ°��� ���� ���� �޶���
// so, ���� �������� ó���� ������ �Է��� ���� ������ ������ �����Ͽ� ����
// �Է� ���ڿ��� ���̴� �ִ� 18 �����̹Ƿ�, ��Ʈ����ŷ�� ���

#define ALP 26
#define STR 18 // �Է� ���� �ִ� ����
#define BIT ( 1 << STR ) // ��Ʈ����ŷ
#define INF 1000 // default ��

string str;
int visit[STR][BIT]; // Ŀ�� ��ġ, �ۼ��� ���� ����

int Calc(int cur, int bit, char alp) { // ���� Ŀ�� ��ġ, ��ϵ� ���� ����, ���� ���ĺ�
	if (visit[cur][bit]) return visit[cur][bit]; // �湮�� ����� �ִٸ� ���
	if (bit == (1 << str.length()) - 1) return 0; // ��� ���ڸ� �� ä���ٸ� ��ȯ

	visit[cur][bit] = INF;
	for (int k = 0; k < str.length(); k++) {
		if (bit & (1 << k)) continue; // �ش� ���ڰ� �̹� �ִٸ� �ǳʰ�

		int move = 0;
		if (k < cur) { // ���� ��ġ���� �տ� �����ϴ� ���̸�
			for (int m = k; m <= cur; m++) {
				if (bit & (1 << m)) move += 1;
				// ���̿� �����ϴ� ���ڸ�ŭ �ǳʶپ����
			}
		}
		else { // �ڿ� �����ϴ� ���̸�
			for (int m = cur + 1; m < k; m++) { // ���� Ŀ�� �������� ���
				if (bit & (1 << m)) move += 1;
			}
		}

		int btw = abs(str[k] - alp);
		int updown = min(btw, ALP - btw); // ��, �Ʒ� �� �� ���� ��ȭ�� ����

		// ��� �Լ� + Ŀ�� �̵� �� + ���� ��ȯ�� + �Է� (1)
		int calc = Calc(k, bit | (1 << k), str[k]) + move + updown + 1;
		visit[cur][bit] = min(visit[cur][bit], calc); // ������ ��� ��, �ּҸ� ����
	}
	return visit[cur][bit];
}

int main() {
	do {
		cin >> str;
		if (str == "0") break; // ���� ���ڿ��̸� ����

		memset(visit, 0, sizeof(visit)); // �̸�������̼� �迭 �ʱ�ȭ

		int ans = INF;
		for (int k = 0; k < str.length(); k++) {
			ans = min(ans, Calc(k, 0, 'A'));
		}
		cout << ans << endl; // ���� ���
	} while (true);
}