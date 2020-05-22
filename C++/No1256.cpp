#include<iostream>
#include<algorithm>
using namespace std;
// ����

#define MAX 1000000001

int arr[202][101]; // �迭

int Pascal(int a, int b) { // �־��� �������� ���� �� �ִ� ��� Case
	// ��� ������ ��, Z �� ��
	if (arr[a][b]) return arr[a][b]; // �̹� ������ �ִٸ� ��ȯ
	if (b == 0) arr[a][b] = 1; // ���ڿ� ���̿� �����ߴٸ�
	else if (a < b) arr[a][b] = 0; // ������ ���
	else arr[a][b] = min(MAX, Pascal(a - 1, b - 1) + Pascal(a - 1, b));
	// �� �ܿ��� �� ��� �� �ּҰ��� ����
	return arr[a][b];
}

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	if (Pascal(N + M, M) < K) { // ���� �� �ִ� �������� ���ϴ� ��ȣ�� ũ�� ����
		cout << -1 << endl;
	}
	else {
		int a = M; // ���� z�� ����
		long long int flag = K; // ��ȣ
		for (int k = 1; k <= N + M; k++) {
			// ���� �� �ִ� ������ �������� �����ϴ� ���ڸ� ����
			if (Pascal(N + M - k, a) >= flag) {
				cout << "a";
			}
			else {
				cout << "z";
				flag -= Pascal(N + M - k, a); 
				// a�� �켱���� ������ ��� ���� �� �ִ� �� ��ŭ �� 
				a -= 1; // z �� �����ϰ� ���� z �� ����
			}
		}
	}
}