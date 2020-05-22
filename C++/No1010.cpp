#include<iostream>
using namespace std;
// �ٸ� ����
// �ٸ��� ��ġ�� �ʵ��� �ϴ� ���� ��ǥ
// so, ��� ȣ�� ��, �ڽ��� �տ� �����ϴ� �ٸ����� ����

int arr[31][31];

int Pascal(int a, int b) {
	if (arr[a][b])
		return arr[a][b]; // �̹� �Ծ����� ����
	if (b == 0) // ������ �ٸ��� ����� ���
		arr[a][b] = 1;
	else if (a < b) // ������ �� �ִ� �ٸ��� �����ϸ�
		arr[a][b] = 0;
	else // �� ���� ���� ���ȣ��� ���� ����
		arr[a][b] = Pascal(a - 1, b - 1) + Pascal(a - 1, b);
	// �ٸ��� ������ ��� + ���� ���� ���
	return arr[a][b];
}

int main() {
	int loop;
	cin >> loop;
	for (int k = 0; k < loop; k++) {
		int N, M;
		cin >> N >> M;
		cout << Pascal(M, N) << endl; // �׽�Ʈ ���̽��� ���� ��� ���
	}
}