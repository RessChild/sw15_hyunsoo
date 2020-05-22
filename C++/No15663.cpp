#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
// N�� M (9)
// ���� Ž���� ����ϵ�, �ߺ� ���� ó���� ���Ͽ�
// �ߺ��Ǵ� ���� �ľ��Ͽ� ���� ������ �� ���� ���길 ����

int N, M;
vector<int> v; // ������ �ִ� ��� ��
vector<int> s; // ���� ���� ��¿����� ����� �� ���� ����
int visit[10001], cnt[10001];

void D(int idx) {
	if (idx == s.size()) { // ���ϴ� ���̱��� ����
		for (int k = 0; k < idx; k++) {
			printf("%d ", s[k]); // ���
		}
		printf("\n");
		return;
	}

	for (int k = 0; k < N; k++) {
		if (k < v.size() - 1 && v[k] == v[k + 1]) continue; // �ߺ��Ǵ� ���� ������ ��ŵ
		if (visit[v[k]] == cnt[v[k]]) continue; // �ش� ���� ��� �� ��� ��ŵ
		visit[v[k]] += 1; // ���� �����
		s[idx] = v[k]; // ���ÿ� �ش� ���� ���
		D(idx + 1); // ���
		visit[v[k]] -= 1; // ����� �� ��ȯ
	}
}

int main() {
	scanf("%d %d", &N, &M);

	s.resize(M); // ���� M�� ���� ���� ����
	for (int k = 0; k < N; k++) {
		int data;
		scanf("%d", &data);
		v.push_back(data);
		cnt[data] += 1; // ������ �ִ� ���� �߰�
	}
	sort(v.begin(), v.end()); // ���� �� Ž���̹Ƿ�, ����
	for (int k = 0; k < v.size(); k++) { // 0���� ��� ī�带 ���������� �Ͽ� Ž��
		if (k < v.size() - 1 && v[k] == v[k + 1]) continue;
		visit[v[k]] += 1;
		s[0] = v[k];
		D(1);
		visit[v[k]] -= 1;
	}
}