#include<iostream>
#include<algorithm>
using namespace std;
// �κ� �����ϱ�
// ���̳��� ���α׷���
// �̵� ������ ������ ���� ������ �� ����
// but, ���, ���� ������ ������ ����

// �������� ���� �� ���θ� ��Ģ�� �ǰ��Ͽ� ���� ��, DP �� ���� Ǯ�̸� �õ�
// but, ���ȣ���� ���̰� �����ϰ� ����� ��Ÿ�� ������ ����
// so, �� ���� ���� �ش� ������ ������ �� �ִ� ����ġ�� ���ϴ� ������� ������ ���

#define NUM 1000
#define MIN NUM * NUM * -100

int N, M, map[NUM + 1][NUM + 1], sum[NUM + 1][NUM + 1];
int left[NUM + 1][NUM + 1], right[NUM + 1][NUM + 1];

void DP(int x, int y,int dir,int val) { // 1 : ������ -> ����, -1 : ���� -> ������
	if (y < 1 || y > M) return; // �ε��� ���ָ� �Ѿ�� ����

	int v = val + map[x][y]; // ���� ���� �ε���
	if (v > sum[x][y]) sum[x][y] = v; // �� ū ��� �ٲ����
	
	DP(x, y - dir, dir, v); // �ش� ��Ʈ�� ������ ���� �����Ƿ�, ��� ���ҿ� ���� �ݺ�
}

int main() {
	cin >> N >> M;
	for (int k = 1; k <= N; k++) {
		for (int m = 1; m <= M; m++) {
			cin >> map[k][m]; // �� �Է�
			sum[k][m] = MIN; // �ʱ�ȭ
		}
	}

	for (int k = 1; k <= M; k++) {
		sum[1][k] = map[1][k];
		sum[1][k] += sum[1][k - 1]; // ���� ���� ������� �޾ƿ�
	}

	for (int k = 2; k <= N; k++) { // �߰��� ��� ���ο� ���ؼ�
		for (int m = 1; m <= M; m++) { // �� ���ҵ鿡 ����
			int up_val = sum[k - 1][m]; // �ڱ� ���� �ִ밪�� �޾ƿ�
			int v = up_val + map[k][m]; // ���� ���� ��

			if (v > sum[k][m]) sum[k][m] = v; // �� ū ��� ��ü
			DP(k, m - 1, 1, v);
			DP(k, m + 1, -1, v); // ��, ��� ������ ��Ʈ��
		}
	}
	cout << sum[N][M] << endl; // ���
}