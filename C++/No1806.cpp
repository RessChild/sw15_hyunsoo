#include<iostream>
#include<algorithm>
using namespace std;
// �κ���
// �ܼ��� ���̸� ���ϸ� ���
// so, �� ���� ��ġ�ϴ� ����� �� �������� index �� ���̸� ���

#define DEFAULT 100001 // �ִ밪 (�⺻)

int main() {
	int N, S, arr[100000];
	cin >> N >> S;
	for (int k = 0; k < N; k++)
		cin >> arr[k]; // �Է�

	int f, b, sum, len; // �� ������ �ε���, ��, �迭 ����
	f = b = sum = 0;
	len = DEFAULT;

	while (f != N) {
		if (sum > S || b == N) {
			sum -= arr[f];
			f += 1;
		}
		else {
			sum += arr[b];
			b += 1;
		} // �� ������ ���

		if (sum >= S) len = min(len, b - f);
		// ������ �����ϴ� ���, ������� ������ ���� �� �ּҰ��� ����
	}
	if (len == DEFAULT)	len = 0; // ���� �ʱⰪ���� ������ �ʾ����� 0 ���� ��ȯ
	cout << len << endl;
}