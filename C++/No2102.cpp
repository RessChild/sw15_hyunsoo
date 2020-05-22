#include<iostream>
#include<algorithm>
using namespace std;
// ���� �ݱ�
// �Ķ��Ʈ�� ��ġ�� ����Ͽ� �ش� ������ Ǯ �� ����
// ��Ʈ�� ���� int ���·� �����Ϸ� �õ�������,
// �Ҽ� ������ ������ ���̷� ���� Ʋ���� ��찡 �߻�

// so, �ε��Ҽ��� Ÿ���� ����ؾ��ϸ�,
// ���߿� ���ƴٴϴ� �ش� �ڵ带 �����ϴ� ���ؿ� ��ĥ �� �ۿ� ������

#define NUM 100000

int N, M, a[NUM + 1];

bool F(double x) { // Ž���Ϸ��� ��հ� x 
    double sl = 0, sr = 0, mini = 0;
    for (int i = 1; i < M; i++) sr += a[i] - x; // ����� �� ������ ������
    for (int i = M; i <= N; i++) {
        sr += a[i] - x;
        mini = min(mini, sl); // ���� �տ��� ���ϴ� ���� �ּҷ� ����
        if (sr >= mini) return true; // ���� �������� 0 �̻��̸�, �ش� ����� ���� �� ����
        sl += a[i - M + 1] - x;
    }
    return false;
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) cin >> a[i];

    // 0 ~ 2000 ������ �Ķ��Ʈ�� ��ġ
    double low = 0, up = 2000, mid;
    for (int i = 0; i < 100; i++) {
        mid = (low + up) / 2;
        F(mid) ? low = mid : up = mid;
    }
    cout << (int)(mid * 1000 + 1e-6) << endl;
    return 0;
}