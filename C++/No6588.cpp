#include<cstdio>
#include<vector>
using namespace std;
// �������� ����
// �� �Ҽ��� ������ ǥ���� ���������� �Ǵ�
// ��, �����佺�׳׽��� ü�� ���� �� ��� �Ҽ��� ����
// ������ �����ϰ� ���� �� ���� �Ҽ����� �Ǵ��ϸ� ���

#define MAX 1000001

int cnt[MAX];
bool arr[MAX]; // �湮 ���� �迭
vector<int> v; // �Ҽ��� ��Ƶ� ����

void eratos() {
	for (int k = 2; k <= MAX; k++) {
		if (arr[k]) continue; // �̹� �湮�� ��� ����

		v.push_back(k); // ���Ϳ� ����
		for (int m = 2; m * k <= MAX; m++) { // ��� ����� ���� �湮
			if (arr[m * k]) continue; // �̹� �湮�� ��� ����
			arr[m * k] = true;
		}
	}
}

int main() {
	eratos(); // �Ҽ� ȹ��

	int num;
	while (true) {
		scanf("%d", &num);
		if (num == 0) break; // 0 �� �ԷµǸ� ����
		for (int k = 0; v[k] <= num / 2; k++) {
			// �� ���� ���̹Ƿ� �Է� ũ���� ���ݱ����� Ȯ���ϸ� ���
			int rev = num - v[k];
			if (arr[rev]) continue; // �Ҽ��� �ƴ϶�� ����
			printf("%d = %d + %d\n", num, v[k], rev); // �Ҽ��� ���� ���� ��� �� ����
			break;
		}
	}
}