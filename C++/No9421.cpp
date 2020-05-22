#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
// �Ҽ���ټ�
// �Ҽ� ��, ������ �����ϴ� ���� Ž���ؾ� ��
// �� ��, �ߺ��Ǵ� ���� ����ؼ� �߻��ϹǷ� �̸�������̼��� �߰��� Ȱ��

#define NUM 1000000

int arr[NUM + 1], visit[NUM + 1][2];
vector<int> v; // �Ҽ� ����

void Prime() { // �����佺�׳׽��� ü
	for (int k = 2; k <= NUM; k++) {
		if (arr[k]) continue;
		v.push_back(k); // ������ �� ���� �� ���� ������ �ʾҴٸ� �Ҽ�
		for (int m = 1; m * k <= NUM; m++) {
			arr[m * k] = 1;
		}
	}
}

int DFS(int a) { // ��ټ� �Ǵ�
	if (a == 1) return 1; // ���� 1 �� �����Ѵٸ� ����
	if (visit[a][0]) return visit[a][1];
	// �̹� �湮�ߴٸ� ��ټ� �Ǵܰ� ��ȯ
	// ���� ���� false �̹Ƿ�, ����Ŭ�� ���� ��湮�� ��� ���з� �Ǵܵ�

	visit[a][0] = 1;
	int num = 0, copy = a; // ���ο� ��, ���纻
	while (copy) {
		num += pow(copy % 10, 2); // �� �ڸ����� ������ ��� ����
		copy /= 10;
	}
	return visit[a][1] = DFS(num); // �ڽ��� ��ټ� ���δ� ���� ����� ����
}

int main() {
	int N;
	cin >> N;

	Prime(); // �Ҽ� ����

	vector<int> ans; // ���� ����
	int last = lower_bound(v.begin(), v.end(), N) - v.begin();
	for (int k = 0; k < last; k++) { // �Է°����� ���� �Ҽ��� ���� ��� �Ǵ�
		int val = v[k];
		if (DFS(val)) ans.push_back(val);
	}

	for (int a : ans) cout << a << endl; // ���
}