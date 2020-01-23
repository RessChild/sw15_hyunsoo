#include<iostream>
#include<cstdio>
#include<queue>
#include<tuple>
using namespace std;
// ��Ʈ��ũ ����
// �ּ� ���д� Ʈ�� ����
// so, ũ�罺Į �Ǵ� ���� �˰����� ���

// �� ǥ���� ���Ǹ� ���� tuple Ÿ���� ����, �켱���� ť ���
// tuple �� ���, �� ���� ������ ���ؼ� get<index>(tuple) �Լ��� ����ؾ� ��

struct my_fun { // �켱���� ť�� �켱���� �Ǵܿ� ���� ��ü
	bool operator()(tuple<int, int, int> a, tuple<int, int, int> b) {
		return get<2>(a) > get<2>(b); // a, b�� 2���� �ε����� ���� �޾ƿ�
	} // �������� ������ �� ���̹Ƿ�, �Ʒ��� a�� �� Ŀ�� ��
};

int N, M;
int arr[1001];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, my_fun> pq;

int F(int idx) { // Union-Find
	if (arr[idx] == idx) return idx;
	return arr[idx] = F(arr[idx]);
}

int main() {
	cin >> N >> M;
	for (int k = 1; k <= N; k++) {
		arr[k] = k;
	}
	for (int k = 0; k < M; k++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		tuple<int, int, int> edge(a, b, c); // ���� ������ ���� Ʃ���� ����
		pq.push(edge); // �켱���� ť�� ���� ( ũ�罺Į �˰��� )
	}

	int sum = 0;
	while (!pq.empty()) { // ť�� ���� �� �� ����
		tuple<int, int, int> link = pq.top();
		pq.pop();
		int a_root = F(get<0>(link)), b_root = F(get<1>(link)); // ���� ����Ǿ��ִ��� Ȯ��
		if (a_root != b_root) { // �ٸ����� ���
			sum += get<2>(link); // �ش� ������ ����� ����
			arr[a_root] = b_root; // ����
		}
	}
	cout << sum << endl;
}