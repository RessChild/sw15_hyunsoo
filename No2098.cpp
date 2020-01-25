#include<iostream>
#include<algorithm>
using namespace std;
// ���ǿ� ��ȸ
// ���� �˰����� �������� �ʴ� ���� Ž�� ���� �� �ϳ�
// so, �Է��� ũ�Ⱑ ����� ���� �� ( ����� �� 16 )
// �ٸ�, '� ���ø� ���� �ߴ°�' �� ������ �ݵ�� �ʿ��ϹǷ�
// bit mask �� ����Ͽ� �������� ������ �ܼ�ȭ�Ͽ� ó��
// ( �� 16��Ʈ�� �ʿ��ϹǷ�, int ������ ��� )

#define MAX 16
#define INF MAX * 1000000 + 1
#define BIT (1<<MAX) // ��Ʈ����ũ �ִ밪

int N, arr[MAX][MAX];
int datas[MAX][BIT];

int DP(int idx, int record) {
	record |= (1 << idx); // �ش� ��带 �湮������ ǥ��
	if (record == (1 << N) - 1) return arr[idx][0] != 0 ? arr[idx][0] : INF;
	// ��� ���� �� �湮�ߴٸ� �������� ���ư��� ��� ����� ��ȯ
	// �ٸ� ���ư��� ��ΰ� ���ٸ� ('0') ����� �� �����Ƿ�, ��ȯ ���� �����ؾ� ��
	if (datas[idx][record]) return datas[idx][record]; // ���� �ִٸ� ���

	datas[idx][record] = INF;
	for (int k = 0; k < N; k++) {
		if (!(record & (1 << k)) && arr[idx][k] != 0) { // �湮 ���Ѱ��
			datas[idx][record] = min(datas[idx][record], DP(k, record) + arr[idx][k]); // ��� ��ο� ���ϸ� �ּ��� ���� ���
		}
	}
	return datas[idx][record];
}

int main() {
	cin >> N;
	for (int k = 0; k < N; k++) {
		for (int m = 0; m < N; m++) {
			cin >> arr[k][m];
		}
	} // ��� ��ΰ��� �Է¹���
	cout << DP(0, 0) << endl; // '���ƿ��� ���' �� ã�� ���� ��ǥ�̹Ƿ�, Ž�� ��ġ�� ��� ����
}