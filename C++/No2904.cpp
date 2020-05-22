#include<iostream>
#include<vector>
using namespace std;
// ������ �ʹ� ����
// �����Ǵ� ������ ���� ���μ������ϰ�, ������ ��
// �����ϴ� ���μ����� ��� ������ �й谡 ������ ��ŭ �ִ��� Ȯ��

#define MAX 1001

int num, arr[MAX], datas[100]; // �Է� ������
int cnt[1000000]; // ������ �Ҽ� ���� üũ
vector<int> v; // �Ҽ� ����

void eratos() {
	arr[0] = arr[1] = 1;
	for (int k = 2; k < MAX; k++) {
		if (arr[k]) continue;
		v.push_back(k);
		for (int m = 2; m * k < MAX; m++)
			arr[m * k] = 1;
	}
}

int main() {
	eratos();
	
	cin >> num;
	for (int k = 0; k < num; k++) {
		int d;
		cin >> d;
		datas[k] = d; // ��� �Է°��� ���� �Ҽ��� �Ǵ�

		for (int m = 0; m < v.size();) {
			if (!(d % v[m])) { // �ش� �Ҽ��� ������������
				cnt[v[m]] += 1;
				d /= v[m];
				continue; // ���� Ƚ���� �ø��� ��� ����
			}
			if (d == 1) break; // 1�̸� ��
			m++;
		}
		if (d != 1) cnt[d] += 1; // 1�� �ƴ϶�� �� ��ü�� �Ҽ�
	}

	int gcd = 1, check = 0;
	for (int k = 2; k < 1000000; k++) {
		if (cnt[k] / num) { // ��ο��� ����� ������ ����ŭ �ִٸ�
			int loop = cnt[k] / num; // ��з���ŭ �ݺ�
			for (int n = 0; n < loop; n++) {
				gcd *= k; // �ִ����� ���
				for (int m = 0; m < num; m++) { // ��� ���鿡 ���� �й� üũ
					if (datas[m] % k) // ���� �� ���ٸ�
						check += 1; // �̵��� �ʿ�
					else
						datas[m] /= k; // ���� �� �ִٸ� ����
				}
			}
		}
	}
	cout << gcd << " " << check << endl; // �ּҰ������ ���� Ƚ��
}

