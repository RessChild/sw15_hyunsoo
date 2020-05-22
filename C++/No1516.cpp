#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
// ���� ����
// ����Ŭ�� ���� ���⼺ �׷��� (DAG)
// so, ��Ģ�� ���� �� �� ȹ���� ����� �ð������� ���� ���ŵ��� �����Ƿ�
// �޸�������̼� ����� ����� �� ����

#define MAX 500
#define LIM MAX * 100000

int N, time[MAX + 1], total[MAX + 1];
vector<int> v[MAX + 1];

int DFS(int idx) {
	if (total[idx]) return total[idx]; // �湮�� ��� ����

	total[idx] = time[idx]; // �ڽ��� �ɸ��� �ð��� �ּҰ�
	for (int k = 0; k < v[idx].size(); k++) {
		total[idx] = max(total[idx], DFS(v[idx][k]) + time[idx]);
	} // �� �ǹ��� �ʿ��� ��� + ���� �ð�
	// �ٸ�, ���� �󿡴� �ּҰ��̶�� ���� ������ ��� ������ �������Ѿ� �ϹǷ�
	// max �˰����� ����ؾ���

	return total[idx];
	
}

int main() {
	cin >> N;
	for (int k = 1; k <= N; k++) {
		scanf("%d", &time[k]);
		int pre;
		while (true) {
			scanf("%d", &pre);
			if (pre == -1) break;
			v[k].push_back(pre); ; // ������ �Ǽ��ؾ� �ϴ� �ǹ�
		}
	}

	for (int k = 1; k <= N; k++) {
		printf("%d\n", DFS(k));
	} // ���
}