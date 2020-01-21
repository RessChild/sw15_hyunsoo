#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
// �ִ�����
// �־����� ���� ��ԵǴ� ������� ������ ŭ (�����̹Ƿ�)
// so, ��Ŭ���� ȣ������ ����� �Ұ���

// ���, �־����� ������ ��� ���μ����� �� ��,
// �� ���� ���� ���μ��� ���ϸ� �ִ������� �ϼ��ϴ� ����� ���

#define MAX 31624 // 1,000,000,000 ������ �Ҽ� �Ǵܿ�

int visit[MAX + 1];
vector<int> v, a, b; // �Ҽ� ����, a, b �� ���μ� ����

void eratos() { // �����佺�׳׽��� ü
	for (int k = 2; k <= MAX; k++) {
		if (visit[k]) continue;
		v.push_back(k);
		for (int m = 2; m * k <= MAX; m++) {
			visit[m * k] = 1;
		}
	}
}

int main() {
	eratos(); // �Ҽ� ȹ��

	int loop;
	cin >> loop;
	for (int k = 0; k < loop; k++) {
		int d;
		cin >> d;
		for (int m = 0; m < v.size();) {
			if (d == 1) break;
			if (!(d % v[m])) {
				a.push_back(v[m]);
				d /= v[m];
				continue;
			}
			m++;
		}
		if (d != 1) a.push_back(d);
	} // �ԷµǴ� ��� ���� ���� ���μ� ���� ( �� a )

	cin >> loop;
	for (int k = 0; k < loop; k++) {
		int d;
		cin >> d;
		for (int m = 0; m < v.size();) {
			if (d == 1) break;
			if (!(d % v[m])) {
				b.push_back(v[m]);
				d /= v[m];
				continue;
			}
			m++;
		}
		if (d != 1) b.push_back(d);
	} // �ԷµǴ� ��� ���� ���� ���μ� ���� ( �� b )
	sort(a.begin(), a.end());
	sort(b.begin(), b.end()); // �� ���μ��� ���� ũ�� ������ ����

	bool flag = false; // ���� ���� ���� �ʰ��ߴ°��� �Ǵ� 
	long long int gcd = 1; // ��ԵǴ� �ִ� ������� ũ�⿡ ����
	int a_pos = 0, b_pos = 0; // �� ������ �ε��� ������
	while (a_pos != a.size() && b_pos != b.size()) { // ���� ���ϸ鼭 ����

		// ���� ���� �Ҽ��� ���� �ִٸ� ������� ���Խ�Ŵ
		if (a[a_pos] == b[b_pos]) {
			gcd = (gcd * a[a_pos]); 
			a_pos++, b_pos++;

			if (gcd >= 1000000000) { // ���� ��Ե� ������� ������ �ѱ��
				gcd %= 1000000000; // �� �������� ���ϰ�
				flag = true; // ��� ���¸� �����ϵ��� ��
			}
		}
		else { // �� ���� ���
			if (a[a_pos] < b[b_pos]) a_pos++;
			else b_pos++;  // �� ���� ���� �̵���Ŵ
		}
	}
	// 1,000,000,000 �� �������, ������� 0 �� ����ϴ� 9 �ڸ����� �Ǿ�� ��
	if (flag) printf("%09d\n", gcd); 
	else printf("%d\n", gcd);
}