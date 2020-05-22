#include<iostream>
#include<unordered_map>
using namespace std;
// ī�� ����
// ���ذ������� �ɸ� ����
// ī�带 �����ָ鼭 ���� ���� �ƴ�, ��� ���� �� �� ���� ���� ��
// so, �ܼ��� �ߺ��� üũ�ϴ� �ùķ��̼� �������� �ذ� ����

#define NUM 48

int N, card[NUM], shuffle[NUM]; // ī�� ��, ���� ī�尡 ���� ����, �ڼ��� ��Ģ
unordered_map<string, bool> m; // �ߺ� üũ�� ��

int main() {
	cin >> N;

	string ans = ""; // ���� ���ڿ�
	for (int k = 0; k < N; k++) { // ���� �Է¹޾� �ϳ��� ���� ���ڿ��� ����
		int num;
		cin >> num;
		ans += ('0' + num);
	}
	m[ans] = true;

	// ī�� ���� ��Ģ + ī�� �ʱ�ȭ
	for (int k = 0; k < N; k++) {
		cin >> shuffle[k];
		card[k] = k;
	}

	int cnt = 0; // ���� ��°�
	string str; // �񱳿� ���ڿ�
	for (int k = 0; k < N; k++) str.push_back(k % 3 + '0'); // �ʱ� ī�� ��� ����
	for (; !m[str]; cnt++) { // �ߺ��� �����ϱ� ������ �ݺ�
		m[str] = true; // �ش� ��� ���°� �������� ǥ��

		int save[NUM] = {};
		for (int k = 0; k < N; k++) save[k] = card[k]; // ī�� ����
		for (int k = 0; k < N; k++) card[shuffle[k]] = save[k]; // ī�� �̵�
		for (int k = 0; k < N; k++) str[card[k]] = (k % 3 + '0'); // ���ο� ��� ����
	}
	cout << (ans == str ? cnt : -1) << endl; // ���
}