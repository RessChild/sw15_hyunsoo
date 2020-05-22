#include<iostream>
#include<tuple>
#include<queue>
using namespace std;
// ���ٲ���
// ť�� ����� BFS Ž��

#define NUM 100000

int arr[NUM + 1];
queue<pair<int, int>> q;

int main() {
	int N, K;
	cin >> N >> K;

	q.emplace(N, 0); // ��� ��ġ
	while (!q.empty()) {
		int x, v;
		tie(x, v) = q.front();
		q.pop();

		if (arr[x]) continue; // �̹� �湮�� ���̸� ����
		arr[x] = v;
		if (x == K) break; // ������ �ִ� ���̸� ����

		if (x + 1 <= NUM) q.emplace(x + 1, v + 1); // ������ �̵�
		if (x - 1 >= 0) q.emplace(x - 1, v + 1); // ���� �̵�
		if (x * 2 <= NUM) q.emplace(x * 2, v + 1); // ���� �̵�
	}
	cout << arr[K] << endl;
}