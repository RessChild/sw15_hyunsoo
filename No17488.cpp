#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// ���� �ٱ��� 

int m[1000]; // �ִ�ġ
int bagunee[1000]; //�ٱ��� ����
int list[1000]; // ������ ��� ����
int s, c; // �л� ��, ���� ��
vector<int> a[1000]; // 1�� ���� ����
vector<int> b[1000]; // �л� ����
vector<int> ab[1000]; // 2�� ���� ����

int main() {
	cin >> s >> c; // �л� s, ���� c
	for (int k = 0; k < c; k++)
		cin >> m[k];

	for (int k = 0; k < s; k++) { // 1�� �ٱ��Ͽ� ���� ���� �Է�
		while (true) {
			int ch;
			cin >> ch;
			if (ch == -1)
				break;
			ch--;
			bagunee[ch]++; // ����
			a[ch].push_back(k);
		}
	}
	for (int k = 0; k < c; k++) { // �� �������� �ʰ� ���θ� Ȯ���ϸ鼭
		if (bagunee[k] <= m[k]) { // ���� �ʾ����� (�����̸�)
			list[k] += bagunee[k]; // ������ ��� ����
			bagunee[k] = 0; // �ٱ��� �ʱ�ȭ
			for (int i = 0; i < a[k].size(); i++) {
				int num = a[k][i];
				b[num].push_back(k); // �� �л����� ���������� ������ ����
			}
		}
	}


	for (int k = 0; k < s; k++) { // 2�� �ٱ��Ͽ� ���ؼ� �ݺ�
		while (true) {
			int ch;
			cin >> ch;
			if (ch == -1)
				break;
			ch--;
			bagunee[ch]++; // ����
			ab[ch].push_back(k);
		}
	}
	for (int k = 0; k < c; k++) {
		if (bagunee[k] + list[k] <= m[k]) { //�����ϸ�
			list[k] += bagunee[k];
			for (int i = 0; i < ab[k].size(); i++) {
				int num = ab[k][i];
				b[num].push_back(k);
			}
		}
	}

	for (int k = 0; k < s; k++) { // �� �л����� �����鼭
		if (b[k].size() == 0) { // ������ ���ٸ� ����
			cout << "���߾��\n";
			continue;
		}
		sort(b[k].begin(), b[k].end()); // ������ �ִٸ� ���� �� ���
		for (int i = 0; i < b[k].size(); i++) {
			cout << b[k][i] +1 << " ";
		}
		cout << "\n";
	}
}