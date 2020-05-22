#include<cstdio>
#include<queue>
#include<string>
using namespace std;
// ������ �ʶ��
// �켱���� ť�� �׸��� Ž���� �õ�
// but, �� �� ���� ���� case �� ����..

#define NUM 10000

struct func {
	bool operator()(pair<int, int> &a, pair<int, int> &b) {
		return a.second > b.second;
	}
};

int T, arr[2][NUM + 1], visit[2][NUM + 1];
int cnt[2][NUM + 1]; // ���� ���� ������ ����
string x = "211", y = "102";
priority_queue<pair<int,int>,vector<pair<int,int>>,func> q;
vector<int> v[NUM * 2 + 1];

int main() {
	scanf("%d", &T); // �ݺ� Ƚ��
	for (int m = 0; m < T; m++) {
		int N, W;
		scanf("%d %d", &N, &W);

		for (int k = 0; k < 2; k++) { // ���� �Է�
			for (int i = 0; i < N; i++) {
				scanf("%d", &arr[k][i]);
			}
		}

		for (int k = 0; k <= 2 * N; k++) v[k].clear(); // �ʱ�ȭ
		for (int k = 0; k <= N; k++) cnt[0][k] = cnt[1][k] = visit[0][k] = visit[1][k] = 0;

		for (int k = 0; k < 2; k++) {
			for (int i = 0; i < N; i++) { // ��� ������ ���캽
				visit[k][i] = 0; // �ʱ�ȭ

				for (int j = 0; j < 3; j++) { // ���� �� �ִ� ��� ���� 3����
					int new_x = (k + x[j] - '1' + 2) % 2, new_y = (i + y[j] - '1' + N) % N; // ���캼 �ε���
					int comp = arr[k][i] + arr[new_x][new_y]; // �ش� ��ġ�� ������ ��
					if (comp > W) continue; // ��� ������ �ο� ���� �Ѿ�� ����
					v[k + i * 2].push_back(j); // ���� ������ ����
					cnt[k][i] += 1; // �ϳ� �߰�
				}
			}
		} // ������ ��� ������ ����

		for (int i = 0; i < 2; i++) { // ��� ��츦 ť�� �߰�
			for (int j = 0; j < N; j++) {
				q.push(pair<int, int>(i + 2 * j, cnt[i][j]));
			}
		}

		int ans = 0; // ���� ��
		while (!q.empty()) { // ť�� �����Ͱ� ������ ��� ����
			int index = q.top().first;
			q.pop();
			if (visit[index % 2][index / 2]) continue;

			visit[index % 2][index / 2] = 1; // ���

			int min_x = 0, min_y = N; // �Ⱦ��� �����
			for (int dir : v[index]) {
				int new_x = ((index % 2) + x[dir] - '1' + 2) % 2, new_y = ((index / 2) + y[dir] - '1' + N) % N; // ���캼 �ε���
				if (visit[new_x][new_y]) continue; // �̹� ��������� ��ŵ

				if (min_y == N) { // ���ذ��� ������ �ϴ� ����
					min_x = new_x;
					min_y = new_y; // ��ü
				}
				else if (cnt[new_x][new_y] < cnt[min_x][min_y]) { // ���� �� ���� �������� �� ���ٸ�
					cnt[min_x][min_y] -= 1; // ���� ���� �������� �����Ƿ� ����� ��� ���� �ٿ�����
					q.push(pair<int, int>(min_x + 2 * min_y, cnt[min_x][min_y])); // ���ǿ� ������ ����

					min_x = new_x;
					min_y = new_y; // ��ü
				}
				else {
					cnt[new_x][new_y] -= 1; // ����� ��� ���� �ٿ�����
					q.push(pair<int, int>(new_x + 2 * new_y, cnt[new_x][new_y])); // ���ǿ� ������ ����
				}
			}
			visit[min_x][min_y] = 1;
			for (int dir : v[min_x + 2 * min_y]) { // ������ ���� �ֺ� ���������� �����ؾ���
				int new_x = (min_x + x[dir] - '1' + 2) % 2, new_y = (min_y + y[dir] - '1' + N) % N; // ���캼 �ε���
				cnt[new_x][new_y] -= 1; // ��ĥ �� �ִٸ� ��������� ������ ����
				q.push(pair<int, int>(new_x + 2 * new_y, cnt[new_x][new_y])); // ť�� �߰� ����
			}
			ans += 1;
		}
		printf("%d\n", ans);
	}
}
