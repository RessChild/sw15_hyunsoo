#include<cstdio>
#include<queue>
#include<functional>
using namespace std;
// �ּ� ��
// �Է°� ������� ���� �ð��ʰ��� �߻��� ����
// so, iostream �迭 �Լ� ��� cstdio �Լ��� ���

int loop; // ���� Ƚ��
priority_queue<int, vector<int>, greater<int>> pq; // �ּ� �켱���� ť

int main() {
	scanf("%d", &loop);
	int val;
	for (int k = 0; k < loop; k++) {
		scanf("%d", &val); // �Է�
		if (!val) { // 0 �� ���, ������ ��� �õ�
			if (pq.empty()) printf("%d\n", 0); // �� ���, 0 �� ���
			else {
				printf("%d\n", pq.top());
				pq.pop(); // �����Ͱ� �ִٸ� ����ϰ� ����
			}
		}
		else pq.push(val); // ���� �ִٸ� �߰�
	}
}