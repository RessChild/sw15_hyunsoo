#include<cstdio>
#include<stack>
using namespace std;
// �� ������Ʈ
// �л� ���� �ִ� 10���̸�, Test Case ���� ���� ����
// so, �ð� ������ ���� �� �л��鿡 ���� �� �� ���� �����Ͽ� ����Ŭ�� Ȯ�� 

// �л����� ������ ���� �̵��ϸ�, stack �� ������ ����
// ����, �̹� �湮�� �л��� �ٽ� �����Ǿ��� ��,
// ������ �׷쿡 �ִ��� Ȯ��
// ����Ŭ�� �����ϴ� �Ͽ����� �����ϰ� ���� �л����� ��� ¦�� ���� ����

#define NUM 100000

int T, N, student[NUM + 1];

int main() {
	scanf("%d", &T);
	for (int k = 0; k < T; k++) {
		scanf("%d", &N);
		for (int m = 1; m <= N; m++) { // �л��� �� �Է�
			scanf("%d", &student[m]);
		}
		
		int num = 1, cnt = 0;
		int visit[NUM + 1] = {}; // �湮 ����
		for (int m = 1; m <= N; m++) {
			if (visit[m]) continue; // �̹� �湮�� ���̸� ����

			int idx = m;
			stack<int> s; // ���� ����
			for (; !visit[idx]; idx = student[idx]) { // ����Ŭ�� ���� ������ �̵��ϸ� ����
				s.push(idx);
				visit[idx] = num;
			}

			if (visit[idx] == visit[s.top()]) { // ����Ŭ�� ���������� ������� ���
				while (!s.empty()) { // ���������� ����Ŭ�� �����ϴ� ����� �߷���
					int node = s.top();
					s.pop();
					if (node == idx) break; // ����Ŭ �������� �����ϸ� ��������
				}
			}
			cnt += s.size(); // ���� ���ÿ� ���� ������ ��� ¦�� ����
			num++;
		}
		printf("%d\n", cnt);
	}
}