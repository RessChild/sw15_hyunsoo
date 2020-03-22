#include<iostream>
#include<vector>
using namespace std;
// �Բ� ��� �ױ�
// ��� ����� ������ ����� ���, �־����� 50 * 11! �� �Ҹ�
// ( �ִ� 50���� �л�, ���� ��� �� 10�� + �������� �ʴ� ��� )
// so, �ܼ� ����Ž������ Ǫ�� ��� �������� �ĳ����� �ð��ʰ��� �߻��� �� ����

// �������� ���� �� �ִ� �ִ밪�� 1000 �̹Ƿ�,
// �̸� Ȱ���Ͽ� �̸�������̼� ����� ���

#define NUM 50
#define MAX 1000
#define DIV 10007

int N, M, H, ans;
int visit[NUM][MAX + 1], cnt[NUM][MAX + 1];
vector<int> block[NUM]; // �� ��� ����

int DP(int idx, int val) {
	if (val < 0) return 0; // ���� ������ �������� �� �ʿ� ����
	if (idx == N) return val == 0; // ��� ���� �� ���� ���, 1�� ��ȯ
	if (visit[idx][val]) return cnt[idx][val]; // �̹� �湮�� ����� �ִٸ� ��ȯ
	visit[idx][val] = 1;

	cnt[idx][val] += DP(idx + 1, val); // �ش� ���̽��� �������� �ʰ� ����� ���
	for (int w : block[idx]) { // �� ���̽��� �����Ͽ� ����� ���
		cnt[idx][val] += DP(idx + 1, val - w);
	}
	return cnt[idx][val] %= DIV; // ���� �䱸���׿� ���� ���� �� ����
}

int main() {
	cin >> N >> M >> H;

	for (int k = 0; k < N; k++) {
		// �־����� ���� �л��� ���� �� �ִ� ����� �ִ밪
		// so, �� �л��� ���� ����� ���� �̺��� ���� �� ����
		do {
			int w;
			cin >> w;
			block[k].push_back(w); // ��� ũ�⸦ �޾Ƽ� ���Ϳ� ����
		} while (getchar() != '\n'); // �ڿ� ���� ���ڰ� �����̸� �Ѿ
	}

	cout << DP(0, H) << endl;
}