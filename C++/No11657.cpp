#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<algorithm>
using namespace std;
// Ÿ�Ӹӽ�
// ���� ���� �˰���
// ���ͽ�Ʈ��� �ٸ���, ���� ����ġ�� ���� ó���� ������
// �ٸ�, ��� ���, ��� ������ ���� Ȯ�� �� ������ ����ؼ� �Ͼ�Ƿ�
// ������ ���� �˰��� �� �ϳ�

#define MAX 500
#define LIMIT MAX*10000 +1 // �� �Ÿ� ���� ������ -10000 ~ 10000

int N, M;
int arr[MAX + 1], visit[MAX + 1]; // ���� ���� �Ÿ�����, �湮 ����
vector<pair<int,int>> v[MAX + 1]; // ���� ����
queue<tuple<int,int,int>> q; // Ž���� ť

int main() {
	scanf("%d %d", &N, &M);

	for (int k = 1; k <= N; k++)
		arr[k] = LIMIT; // �� ���� �ʱ�ȭ

	int a, b, c;
	for (int k = 0; k < M; k++) {
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(pair<int, int>(b, c)); // ������ �޾� ���Ϳ� ����
	}
	arr[1] = 0; // ���� ������ ���� 0
	for (int k = 1; k <= N; k++) { // ��� ��忡 ���ؼ� ���� Ž��
		for (int m = 1; m <= N; m++) visit[m] = 0; // �湮���� �Ź� �ʱ�ȭ
		q.push(tuple<int, int, int>(k, k, 0)); // ������ ���� ť�� �⺻������ ����

		while (!q.empty()) { // ť�� �� �� ����
			tuple<int, int, int> data = q.front();
			q.pop();
			int from = get<0>(data), to = get<1>(data), len = get<2>(data); // �� �����͸� �̾ƿ�

			if (arr[from] == LIMIT) continue;
			// �⺻������ '������ ���' �� ������� ������ Ȯ��
			// ���� ����� �Ǵ� ���� 0���� �ʱ�ȭ �߱⿡
			// ������� �ش� ������ LIMIT �� ��������� �����ϴ� ���� ������ �ǹ�

			int calc = arr[from] + len; // ���ο� ���� ��� (Ž�� ��尪 + ���� ����)
			arr[to] = min(calc, arr[to]); // �ּڰ� ����

			if (visit[to]) continue; // �湮�� ��� ť�� �߰������� �ʿ� x
			visit[to] = 1;
			for (int m = 0; m < v[to].size(); m++) {
				q.push(tuple<int, int, int>(to, v[to][m].first, v[to][m].second)); // ť�� ����
			}
		}
	}

	int cnt = 0; // �ּҰ����� �������� ���ϴ� ���, ���� ��ȭ�ϹǷ�
				// ������ �����ϴ� ����Ŭ�� �����Ѵٴ� ���� �ǹ�
				// so, ���� �˰����� 1ȸ �� �߰��� �õ��� ��, ���� �ٽ� ���ϴ� ��� ���� �Ұ�
	for (int m = 1; m <= N; m++) visit[m] = 0;
	q.push(tuple<int, int, int>(1, 1, 0));
	while (!q.empty()) {
		tuple<int, int, int> data = q.front();
		q.pop();
		int from = get<0>(data), to = get<1>(data), len = get<2>(data);

		if (arr[from] == LIMIT) continue; // �����ϴ� ���� ���ٸ� ����

		int calc = arr[from] + len;
		if (calc < arr[to]) { // ���� ���� ���� ��ȭ�� ����� (�ּҰ��� ���ŵȴٸ�)
			cnt++;
			break; // �ش� ��δ� ���� ����Ŭ�� ������ ���� �پ�� (���� �Ұ�)
		}

		if (visit[to]) continue; // �̹� �湮�ߴٸ� ��� ����
		visit[to] = 1;
		for (int m = 0; m < v[to].size(); m++) {
			q.push(tuple<int, int, int>(to, v[to][m].first, v[to][m].second)); // ť�� ����
		}
	} // ���� �Ұ����� �Ǵ� ��

	if (cnt) // ���ǿ� ���� ���
		cout << -1 << endl;
	else {
		for (int k = 2; k <= N; k++)
			if (arr[k] != LIMIT)
				cout << arr[k] << endl;
			else
				cout << -1 << endl;
	}
}