#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
// �ּڰ� ã��
// ���ӵ� ������ ���� ������ ���� �� �Ǵ��� �ʿ�
// so, ������ ���� �ð� ������ �ʿ��ϹǷ� Segment Tree �� ���������,
// ��� ȣ�� ������ ���� �ð��ʰ� ( �߰������� ã�ƺ���, �ð��� �ִ��� �ٿ��� �ƽ��ƽ��ϴٰ� �� )

// ���� �켱���� ť ������� �����Ͽ�
// ��� ���� ���� 1ȸ�� ����

#define NUM 5000000

int N, L, val[NUM]; // ���� ��, ���� ����, �� ���� ��

struct func {
	bool operator()(int a, int b) {
		return val[a] > val[b]; // ������ ���� 
	}
};

priority_queue<int, vector<int>, func> pq; // �ε����� ������ ť

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> L;
	for (int k = 0; k < N; k++) {
		cin >> val[k]; // �� �Է�
	}

	int f = -L + 1, b = 0; // ������ ( i - L + 1, i )  
	while (b != N) {
		pq.push(b); // ���� �ε����� �߰��� ����
		while (pq.top() < f) pq.pop(); // ������ ��� �� ����
		cout << val[pq.top()] << " ";

		f += 1;
		b += 1; // �յ� �ε��� �̵� ( ���� �̵� )
	}
}