#include <iostream>
#include<cstdio>
using namespace std;
// ������ ǥ�� 
// Union-Find ���

int arr[1000001]; // �� ����� ��Ʈ
int N, M;

int F(int idx) { // ���Ͽ� ���ε� Ž���� ��� �Լ�
	if (arr[idx] == idx) return idx; // �ش� ������ ��ǥ���� ������ ��� ��ȯ
	int next = arr[idx];
	return arr[idx] = F(next); // �ڽ��� ���� ������ ��ȯ�޾� �ڽ��� ���� ��ǥ�� ����
}

int main() {
	cin >> N >> M;
	for (int k = 1; k <= N; k++) { // �ʱ� ����
		arr[k] = k;
	}

	for (int k = 0; k < M; k++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		int b_root = F(b);
		int c_root = F(c); // �Է� ����� ��ǥ���� Ž��
		switch (a) { // ���� ���
		case 0: // ��ġ�� ���
			if (b_root <= c_root) // �� ��ǥ�� ��, ���� ������ ������
				arr[c_root] = b_root;
			else
				arr[b_root] = c_root;
			break;
		case 1: // ���� �׷� �Ǵ�
			if (b_root == c_root) printf("YES\n"); // �����ϴٸ� �� �׷�
			else printf("NO\n"); // �ٸ��� �ٸ� �׷�
			break;
		default:
			break;
		}
	}
}