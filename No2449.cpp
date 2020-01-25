#include<iostream>
#include<algorithm>
using namespace std;
// ����
// ��ǻ�, DP ������ ã�� ���� �ذ����� ���� ����
// ���� ������ ���� �ѵ��� ���� ���ظ� ���� ���� ����� ���
// ��Ż �ٻ��

#define MAX 200

int N, M;
int light[MAX]; // ������ ��
int arr[MAX][MAX]; // a~b ������ �ּ� ���� Ƚ��

int F(int left, int right) {
	if (left >= right) return 0; // �յ� ������ �ٲ�� ���� ����
	if (arr[left][right] != -1) return arr[left][right]; // �̹� �湮�� ��� ���

	arr[left][right] = MAX + 1;
	for (int k = left; k < right; k++) { // ������ ��� ���տ� ���� �� ����
		int val = light[left] != light[k + 1] ? 1 : 0; // ���� ���� ������ ���� ������ �Ǵ� ������ ���� �ٸ��� �� ���� �߰��� �ʿ�
		arr[left][right] = min(arr[left][right], F(left, k) + F(k + 1, right) + val); // ��, ��, ���� ���� ���� �� ��
	}
	return arr[left][right];
}

int main() {
	for (int k = 0; k < 200; k++) {
		for (int m = 0; m < 200; m++) {
			arr[k][m] = -1;
		}
	}

	cin >> N >> M;
	for (int k = 0; k < N; k++) {
		cin >> light[k];
	}
	int ans = F(0, N - 1); // ���� ã��
	cout << ans << endl;
}