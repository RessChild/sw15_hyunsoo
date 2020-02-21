#include<cstdio>
#include<algorithm>
using namespace std;
// īī���Ӵ�
// �ּ� ���� ������ �ľ��ϱ� ���ؼ�
// �� �ŷ����� �����Ǵ� ������ �ִ������� �ľ��ؾ� ��
// so, ��Ŭ���� ȣ������ ���

// �ٸ�, ���� ������ �־ long long int Ÿ���� ����ؾ߸� ������,
// �Լ����� �����͸� �����ϴ� �������� ���� c �� int Ÿ������ �����Ͽ� ������ �߻�����
// ä���� 32% ���� ���и� �����´� ����..

#define MAX 9 * 1000000000000000000 // �ִ� �Ѱ� ����

long long int N, money, maximum, ans; // ����� ���, ���� �ܰ�, ���� �� ������ �ִ��ܰ�, ����

long long int GCD(long long int a, long long int b) { // ��Ŭ���� ȣ����
	while (b != 0) {
		long long int c = a % b; // Ÿ�� ���� ����
		a = b;
		b = c;
	}
	return a; // �ִ����� ��ȯ
}

int main() {
	scanf("%lld", &N);

	bool flag = true; // ���� ���� �Ǵ�
	for (int k = 0; k < N; k++) {
		long long int give, result;
		scanf("%lld %lld", &give, &result); // �ŷ���, ���� �ܰ�

		if (give >= 0) { // 0���� ū ���,
			if (money + give != result) flag = false; // ���� ����
		}
		else { // ������ ���
			if (money + give >= 0) { // �ܰ�� ����� ���
				if (money + give != result) flag = false; // ������� �ٸ��� ����
			}
			else { // �Ұ����� ���, �������� �Ǵ��ؾ� ��
				long long int charge = result - give - money; // ������
				ans = GCD(charge, ans); // ���� ���� �ִ������� ����
				maximum = max(maximum, result); // ���� �� �ܰ� ���� ���� �ִ�ġ ����

				if (maximum / ans) flag = false; // ���� �������� ������ ���� �־���Ѵٸ� �Ұ���
			}
		}
		money = result;
	}

	if (ans > MAX) flag = false; // �������� ���ġ�� �Ѿ�� ����

	if (flag) { // ���ǿ� ���� ���
		if (ans) printf("%lld\n", ans); 
		else printf("1\n");
	}
	else {
		printf("-1\n");
	}
}