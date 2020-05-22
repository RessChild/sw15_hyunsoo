#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
// ���� 0�� �� ����
// hash map �� ����� ���� ������ ����Ϸ�������,
// �ʹ� ����� ������ ũ�� ������ �浹 ó���� ����� ���� �ڷᱸ���� ��
// so, ���� Ž���� ����ϴ� �ڵ尡 �ʿ�
// long long int �� ��� Ÿ������ ���� ����� ��� �ڵ�

#define NUM 4000

int N, arr[4][NUM];
vector<int> v[2];

int main() {
	scanf("%d", &N);;
	for (int k = 0; k < N; k++) {
		for (int m = 0; m < 4; m++) {
			scanf("%d", &arr[m][k]);
		}
	}
	for (int k = 0; k < 2; k++) { // ���� a,b �� c,d �� �� ���͸� ����
		for (int m = 0; m < N; m++) {
			for (int i = 0; i < N; i++) {
				v[k].push_back(arr[2 * k][m] + arr[2 * k + 1][i]);
			}
		}
		sort(v[k].begin(), v[k].end(), [](int a, int b)->bool {
			return a < b; // �� ���͸� ũ�� ������ ����
			});
	}

	long long int ans = 0;
	for (int value : v[0]) { // ��� ���� ���� Ž��
		int s_idx = lower_bound(v[1].begin(), v[1].end(), -value) - v[1].begin(); // ��ġ�ϰų� ó������ ū ���� ��ġ
		int e_idx = upper_bound(v[1].begin(), v[1].end(), -value) - v[1].begin(); // ó������ ū ���� ��ġ
		ans += e_idx - s_idx; // �� �ε��� ���� ���� ���, ��ġ���� ����
	}
	printf("%lld\n", ans); // long long int ���� ���
}