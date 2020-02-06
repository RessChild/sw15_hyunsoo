#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
// Ʈ���� ����
// Ʈ���� ���� �� �� ����� �Ÿ��� ��Ÿ���� ǥ��

// ��� :
// ������ ��Ʈ���� ���� �� ��带 ���� ��,
// ������ ��带 �������� �ٽ� �� �� ���� �� �������� �Ÿ��� ����

// Ʈ���� �� ����Ʈ���� �������� ����
// so, ������ ����Ʈ�� ��, ���� �ָ� ������ �� ����� �Ÿ��� ã�ƾ� ��
// ��, ������ ����� ���¿��� '���� �ָ�' ������ ��带 ���ο� �������� ã����
// �ѹ� �� Ž���ϴ� ������� Ʈ���� ������ ã�� �� ����

#define NUM 100000

struct func{ // �Ÿ��� �������� �켱���� ����
	bool operator()(pair<int, int> a, pair<int, int> b) { 
		return a.second > b.second;
	}
};

int N, visit[NUM + 1];
vector<pair<int, int>> v[NUM + 1]; // ��������
priority_queue<pair<int, int>, vector<pair<int, int>>, func> pq; // �켱���� ť 

int main() {
	scanf("%d", &N);
	for (int k = 0; k < N; k++) {
		int a, b, c;
		scanf("%d", &a); // ��� ����

		while (true) { // ���� ����
			scanf("%d", &b); // ���� ��� ����
			if (b == -1) break; // -1 �̸� ����
			scanf("%d", &c); // ����ġ ����
			v[a].push_back(pair<int, int>(b, c)); // a ���� b �� c ��� �Ÿ��� ������ �����
		}
	}

	int select = 1; 
	pq.push(pair<int, int>(1, 0)); // ������ (���Ƿ�Ʈ = 1)
	while (!pq.empty()) { // ������� ���� ���� �ݺ�
		pair<int, int> info = pq.top();
		pq.pop(); // ����

		if (visit[info.first]) continue; // �̹� �湮�� ����� ����
		visit[info.first] = 1;

		select = info.first; // ������� ���� �ָ� ������ ���� ����
		for (pair<int, int> edge : v[info.first]) { // �ش� ���� ����� �������� ���캽
			int len = info.second + edge.second; // �ش� ��θ� ���İ��� �Ÿ�
			pq.push(pair<int, int>(edge.first, len)); // ���
		}
	}

	for (int k = 1; k <= N; k++) visit[k] = 0; // �ʱ�ȭ

	// ������ ��带 �������� �ٽ� �ѹ� �ݺ�
	int width;
	pq.push(pair<int, int>(select, 0)); 
	while (!pq.empty()) { // ������� ���� ���� �ݺ�
		pair<int, int> info = pq.top();
		pq.pop();

		if (visit[info.first]) continue; // �̹� �湮�� ����� ����
		visit[info.first] = 1;

		width = info.second; 
		for (pair<int, int> edge : v[info.first]) { // �ش� ���� ����� �������� ���캽
			int len = info.second + edge.second; 
			pq.push(pair<int, int>(edge.first, len));
		}
	}
	printf("%d\n", width);
}