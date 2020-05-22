#include<cstdio>
#include<algorithm>
using namespace std;
// ��� ������
// �ش� ��ܱ��� �����ϴ� ���� ��� �� �ִ밪�� ���� ��
// �̴� ��������� ��� ��ܿ� ���� ����ǹǷ�
// �޸�������̼��� ���

#define MAX 300

int N, memo[MAX + 1][3], stair[MAX + 1];
// 1 : �ǳʼ� ���� ���, 2 : �������� ���� ���

int Step(int idx, int cnt) {
	if (cnt == 3 || idx < 1) return 0; // ����� 3�� �������� ��ų� ����� ������ ��� x
	if (memo[idx][cnt]) return memo[idx][cnt]; // ���� �̹� �ִٸ� ��ȯ
	return memo[idx][cnt] = max(Step(idx - 1, cnt + 1), Step(idx - 2, 1)) + stair[idx];
	// �ռ� ������ ��� �� �� �ִ� �� + ���� ��� ����
	// �� �ܰ迡 ���� ���� �� �ִ� �ִ밪�� ���� �������־�� ��ȣ�� �� step �Ǵ��� ����
}

int main() {
	scanf("%d", &N);
	for (int k = 1; k <= N; k++) {
		scanf("%d", &stair[k]); // �� ����
	}
	printf("%d\n", Step(N, 1)); // ������ �׻� ��ƾ� �ϹǷ�, �� ������ �Ʒ��� Ž���ϴ� ���
}