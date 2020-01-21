#include<iostream>
#include<vector>
using namespace std;
// �ִ����� �ϳ� ����
// ������ ���� �ϳ��� �� ��� ȹ�� ������ �ִ� ������� ���ؾ� ��
// so, ��� ��쿡 ���� ������ �ʿ��ϳ�,
// N �� ũ��� ���� �Ϲ����� ���Ʈ �����δ� ������ �Ұ���
// so, ��, ���� �ִ������� �̸� ����Ͽ� ��� 

#define MAX 1000000

int N, num[MAX];
int l_gcd[MAX], r_gcd[MAX];
// ���õ� ���� �߽����� ����, ������ gcd

int G(int a, int b) { // ��Ŭ���� ȣ����
	while (b != 0) {
		int c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	cin >> N;
	for (int k = 0; k < N; k++) {
		cin >> num[k];
	}
	
	for (int k = 1; k < N; k++) {
		l_gcd[k] = G(l_gcd[k - 1], num[k - 1]);
		r_gcd[(N - 1) - k] = G(r_gcd[N - k], num[N - k]);
	} // �¿� �ִ������� �̸� ���

	int gcd = 0, idx = -1;
	for (int k = 0; k < N; k++) {
		int val = G(l_gcd[k], r_gcd[k]);
		if (gcd < val) { // ���� ���� �ִ����� ���� �� ũ�ٸ�
			gcd = val;
			idx = k; // ��ü
		}
	}
	// ������ ���� Ȯ��
	if (!(num[idx] % gcd)) cout << -1 << endl;
	else cout << gcd << " " << num[idx] << endl;
}