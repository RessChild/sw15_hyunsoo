#include<cstdio>
#include<functional>
#include<queue>
using namespace std;
// ����� ���ؿ�
// �Է� ũ�� 10���� ���Ͽ� ���� Ž���� ���� ����
// �ܼ� �Ϲ� Ž���� ��� N ������� �ð��ʰ��� �߻��ϹǷ�
// �߰� �� Ž���� log N �� �ذ��� �� �ִ°��� ���� ����

// ��, �� ������ ��� �����ϸ� �߰� ���� ����ؼ� �����ؾ� ��
// so, �� �ڷ� �ΰ��� heap �� ����ϸ� ũ�⸦ �����ϰ� �����ϴ� ���

priority_queue<int, vector<int>, less<int>> pql; // �ִ밪 �켱���� ť (����)
priority_queue<int, vector<int>, greater<int>> pqr; // �ּҰ� �켱���� ť (������)

int main() {
	int loop;
	scanf("%d", &loop); // ���� Ƚ�� �Է�

	for (int k = 0; k < loop; k++) {
		int data;
		scanf("%d", &data);

		if (pql.empty()) { // ������ �� ��� (ù ���)
			pql.push(data); // ������ ���ʿ� �߰�
			// �׻� ���� ť�� ������ ť�� ũ�Ⱑ ���ų� 1�� ������ ����
		}
		else { // �� ���� ��� ��� 
			int mid = pql.top();  // ���� ù ���� ��ȯ (�߰���) 

			if (mid < data) pqr.push(data); 
			else pql.push(data); 
			// �߰������� ũ�� �����ʿ�, ������ ���ʿ� ����

			// �߰����� �׻� �����ϱ� ���� �¿� ť ũ�⸦ ����
			if (pql.size() < pqr.size()) { 
				int m = pqr.top();
				pqr.pop();
				pql.push(m);
			}
			else if (pql.size() > pqr.size() + 1) {
				int m = pql.top();
				pql.pop();
				pqr.push(m);
			}
		}
		printf("%d\n", pql.top()); // ���� ���
	}
}
