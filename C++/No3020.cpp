#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
// ���˹���
// ������ �������� ���� ������ �ǹ̰� ���� (������ ���̿� ���� �浹���� ����)
// so, �Է°��� ����, ���������� �з� �� ����
// ����, �� ���̸� �浹 Ƚ�� �� ���� ���� �ּҰ��� ����, ī����

// +) �ش� ������ ���� ���Ӽ��� ������� �����Ƿ� �Ķ��Ʈ�� ��ġ�� ��� �Ұ�
// so, ���δ��� ���׸�Ʈ Ʈ�� 2���� ����� Ǯ�� (����, ������)


vector<int> btm, top; // ����, ������ ����
int sum[500000], sum2[500000]; // ���̿� ���� �浹 ����

int main() {
	int loop, h;
	cin >> loop >> h; // ���� ����, ����

	for (int k = 0; k < loop; k++) {
		int len;
		cin >> len;
		if (k % 2) top.push_back(len); // ¦���� ������
		else btm.push_back(len); // Ȧ���� ����
	}
	sort(top.begin(), top.end());
	sort(btm.begin(), btm.end()); // ���̿� ���� ����

	int iter = top.size() - 1; // �������� ���ؼ�
	for (int k = h - 1; k >= 0; k--) {
		int cnt = 0; // ����
		while (iter >= 0 && top[iter] == k) { // �ߺ��Ǵ� �� ���� üũ
			cnt += 1;
			iter -= 1;
		}
		if (k != h - 1)	sum[k] += sum[k + 1]; 
		sum[k] += cnt; // ���̼� �����̹Ƿ� ���� ���� ����ͼ� ����
	}

	iter = btm.size() - 1; // ������ ���ؼ�
	for (int k = 0; k < h; k++) { // ����
		int cnt = 0;
		while (iter >= 0 && h - btm[iter] == k - 1) {
			cnt += 1;
			iter -= 1;
		}
		if (k != 0)	sum2[k] += sum2[k - 1];
		sum2[k] += cnt;
		sum[k] += sum2[k]; // ���� ������ ���� ���� ���� �߰��Ͽ� ����
	}

	int cnt = 0, min = 200000;
	for (int k = 0; k < h; k++) { 
		if (min > sum[k]) {
			cnt = 1;
			min = sum[k];
		}
		else if (min == sum[k])
			cnt += 1;
	} // ��� ���̸� Ž���ϸ� �ּ� �浹 ���� ������ ���� ���� üũ
	cout << min << " " << cnt << endl;
}


