#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
// �� �迭�� ��
// ���δٸ� �� �迭 ���̿��� ���� ����ؾ��ϹǷ�,
// �� �迭�� ���� ���� �� �ִ� ��� ���� ���� �̸� ��� ��
// �� �� �����͸� ����Ͽ� ���� ����

int main() {
	int T, n, m, A[1000], B[1000];
	vector<int> A_sum, B_sum;

	cin >> T >> n;

	for (int k = 0; k < n; k++) { // ù��° �迭
		int data;
		cin >> data;
		if (k != 0) A[k] = A[k - 1] + data;
		else A[k] = data; // �Է� �����͸� ���� ���� �� �迭�� ����

		A_sum.push_back(A[k]); // ������ �迭�� ���Ϳ� �߰�
		for (int m = 0; m < k; m++)
			A_sum.push_back(A[k] - A[m]);
		// ���� ������� ���� �տ� ����, ���� �� �ִ� ��� ���� ���� ���
	}

	cin >> m;
	for (int k = 0; k < m; k++) { // �ι�° �迭
		int data;
		cin >> data;
		if (k != 0) B[k] = B[k - 1] + data;
		else B[k] = data;

		B_sum.push_back(B[k]);
		for (int m = 0; m < k; m++)
			B_sum.push_back(B[k] - B[m]);
	}

	sort(A_sum.begin(), A_sum.end());
	sort(B_sum.begin(), B_sum.end()); // ���� ���� ũ�� ������ ����

	long long int select = 0;
	int a_pos = 0, b_pos = B_sum.size() - 1;

	while (a_pos <= A_sum.size() - 1 && b_pos >= 0) { // �� ���Ͱ� ��� ���� �� �� ����
		long long int a_count = 1, b_count = 1; // ������ ���� ���� Ƚ��
		for (int k = a_pos + 1; k < A_sum.size(); k++) { 
			if (A_sum[a_pos] == A_sum[k]) a_count += 1;
			else break;
		}
		for (int k = b_pos - 1; k >= 0; k--) {
			if (B_sum[b_pos] == B_sum[k]) b_count += 1;
			else break;
		} // ���� �ε������� �ߺ� ���� ���� ���� üũ

		int sum = A_sum[a_pos] + B_sum[b_pos]; 
		if (sum == T) { // ���ϴ� ���� ���� �����ϸ�
			select += a_count * b_count;
			a_pos += a_count;
			b_pos -= b_count; // ���� ������ �ߺ� ���� ���� ������ ��� ���� ���
		}
		else if (sum > T) { // ū ���, ���� ������ϹǷ�
							// �ں��� Ž���ϴ� �ι�° �迭�� �����͸� �̵�
			b_pos -= b_count;
			if (b_pos < 0) break;
		}
		else { // ���� ���, ���� ������� �ϹǷ�
				// �պ��� Ž���ϴ� ù��° �迭�� �����͸� �̵�
			a_pos += a_count;
			if (a_pos > A_sum.size() - 1) break;
		}
	}

	cout << select << endl;
}