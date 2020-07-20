#include<cstdio>
#include<queue>
#include<tuple>
using namespace std;
// �ʹ� �Ļ�
// �׸��� �����ϴ� ������ ũ�� 2����
// (1) �ڽ��� ��� ������ ū ��� ( ������ �̵� )
// (2) ������ ��� ������ ū ��� ( ��뿡�� �̵� )
// so, �� ������ ��Ȳ�� ���� �Ǵ��ؾ� �ϸ�, �̸� �ϳ��� '��' ���� ǥ���� �� ����
// �� ���� ū ������� �̴� ���� ���� �̻���

// iostream �� �Է��������� �ð��ʰ� �߻�
// so, cstdio �� ����

// �����÷ο찡 �߻��ϹǷ� long long int �� ����
typedef pair<long long int, long long int> pr;

struct func {
	bool operator()(pr a, pr b) { // �� ũ�� ������ ���
		return a.first + a.second < b.first + b.second;
	}
};

long long int T, num; // ���� ��, �ʹ�׸� ��
priority_queue<pr, vector<pr>, func> pq; // �켱���� ť

int main() {
	scanf("%lld", &T);
	for (int k = 1; k <= T; k++) {
		scanf("%lld", &num);
		for (int m = 0; m < num; m++) {
			long long int a, b;
			scanf("%lld %lld", &a, &b);
			pq.emplace(a, b);
		} // �� �Է�

		// �����̺��� �ϳ��� ����
		bool flag = false;
		long long int ans[2] = {};
		while (!pq.empty()) {
			pr data = pq.top(); // �ֻ��� ��
			pq.pop();
			ans[flag] += !flag ? data.first : data.second; // ���� ���� �ູ����
			flag = !flag; // ���� �ٲٱ�
		}
		printf("#%d %lld\n", k, ans[0] - ans[1]); // ���
	}
}