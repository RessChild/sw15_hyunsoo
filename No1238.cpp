#include<iostream>
#include<algorithm>
using namespace std;
// ��Ƽ
// �� �л��� Ư�� ��ġ�� �𿩾� �ϸ�, ���δ� �ܹ��⼺�� ��Ƿ�
// ������ ��δ� �ٸ� �� ����
// so, ��� ��쿡 ���� �ִܰŸ��� ���ϴ� �÷��̵� ���� �˰����� �ʿ�

#define NUM 1000
#define INF 100 * NUM

int N, M, X;
int w[NUM + 1][NUM + 1]; // a ���� b �� ���� �ִܰ��

int main() {
	cin >> N >> M >> X;
	for (int k = 0; k < M; k++) {
		int a, b, c;
		cin >> a >> b >> c;
		w[a][b] = c; // �˰��� �ʱ� ����
	}

	for (int k = 1; k <= N; k++) {
		for (int m = 1; m <= N; m++) {
			w[k][m] = w[k][m] ? w[k][m] : INF; // �Էµ� ���� ������ ���, �ƴϸ� ����
		}
	}

	for (int k = 1; k <= N; k++) { // �÷��̵� ���� �˰��� (�ִܰŸ� Ž��)
		for (int m = 1; m <= N; m++) {
			for (int i = 1; i <= N; i++) {
				w[m][i] = min(w[m][i], w[m][k] + w[k][i]);
			}
		}
	}
	
	int ans = 0;
	for (int k = 1; k <= N; k++) {
		if (k == X) continue; // �ڱ� �ڽ��� ��� ����
		ans = max(ans, w[X][k] + w[k][X]); // �պ� �ð��� ���� �����ɸ��� ���� ����
	}
	cout << ans << endl;
}