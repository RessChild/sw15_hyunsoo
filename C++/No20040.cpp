#include<iostream>
using namespace std;
// ����Ŭ ����
// ����Ŭ�� ����� ������ �Ǵ��ϸ� ����ϹǷ�, Union-Find �� ���

#define NUM 500001

int arr[NUM], N, M;

int Find(int a) { // ��ǥ�� Ž��
	if (arr[a] == a) return a;
	return arr[a] = Find(arr[a]);
}

bool Union(int a, int b) { // Union
	int ra = Find(a), rb = Find(b);
	if (ra != rb) {
		arr[ra] = rb;
		return false;
	}
	return true;
}

int main() {
	int ans = 0; // ���� �� ����
	cin >> N >> M;
	for (int k = 0; k < N; k++) arr[k] = k; // �⺻ ����
	for (int k = 1; k <= M; k++) {
		int a, b; // ������ �� ���
		cin >> a >> b;
		if (Union(a, b)) { // �̹� ������ �Ҽ��̸� ����
			ans = k;
			break;
		}
	}
	cout << ans << endl;
}