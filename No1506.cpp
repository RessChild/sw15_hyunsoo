#include<iostream>
#include<algorithm>
using namespace std;
// ������
// ���ø� �����ϱ� ���ؼ� �ǵ��ƿ��� ��ΰ� �ݵ�� �ʿ�
// �̴� ����Ŭ�� �ǹ��ϸ�, a�� b�� ������ �� �ִٸ�, b ���� a�� ������ �� ����

// ��, �� ������ ���� ����Ŭ�� �Ǵ� ��, �� �׷츶�� �ּҰ��� ����
// �� �������� ����Ǵ� ���� �ִ����� �Ǵ��ϸ� ����ϹǷ�, �÷��̵� ������ Ȱ��

#define NUM 100

int N, cost[NUM], bridge[NUM][NUM]; // ���, ���� ����
int visit[NUM]; // �湮 ����

int main() {
	// �Է�
	cin >> N;
	for (int k = 0; k < N; k++) {
		cin >> cost[k];
	}
	for (int k = 0; k < N; k++) {
		for (int m = 0; m < N; m++) {
			char ch;
			cin >> ch;
			bridge[k][m] = ch - '0';
		}
	}

	// �÷��̵� ���� �˰���
	for (int k = 0; k < N; k++) {
		for (int m = 0; m < N; m++) {
			for (int i = 0; i < N; i++) {
				bridge[m][i] |= bridge[m][k] & bridge[k][i]; // ����� ����� ���� ����
			}
		}
	}

	int ans = 0;
	for (int k = 0; k < N; k++) {
		if (visit[k]) continue; // �̹� �湮�� ���̸� ����
		visit[k] = 1;

		int w = cost[k]; // �⺻ ���
		for (int m = k + 1; m < N; m++) { // ���Ŀ� �����ϴ� ��� ������ ���Ῡ�� �Ǵ�
			if (bridge[k][m] & bridge[m][k]) { // �պ��� �����ϸ�
				visit[m] = 1; // �ش� ������ ���
				w = min(w, cost[m]); // �ּҺ���� ����
			}
		}
		ans += w; // ������ �ּҺ���� �信 ����
	}
	cout << ans << endl;
}