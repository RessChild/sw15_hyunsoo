#include<iostream>
using namespace std;
// ���� ��� 2
// '�Ľ�Į�� �ﰢ��'
// ���� ������� �����ϴ� ������ ����� ���� ����� ����
// ���� ������ int ���� �����Ƿ�,
// ���õ� ��� Ÿ���� long long int ������ ���

long long int tri[1001][1001];

long long int Pascal(long long int a, long long int b) {
	if (tri[a][b] != 0) return tri[a][b];
	if (b == 0)
		tri[a][b] = 1;
	else if (a < b)
		tri[a][b] = 0;
	else
		tri[a][b] = (Pascal(a - 1, b - 1) + Pascal(a - 1, b)) % 10007;
	return tri[a][b];
}

int main() {
	long long int num, sel;
	cin >> num >> sel;
	long long int ans = Pascal(num, sel);
	cout << ans << endl;
}
