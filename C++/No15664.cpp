#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
// N�� M (10)
// �⺻������ ���� Ž���� ������� �ϵ�, �񳻸����� (��������) �̶�� ���������� �߰��� ����
// ����ó���� ��ٷӱ⿡, ������ �޸� ��Ģ���� ã�� ����� �ƴ�
// hash map �� ����� �ߺ� üũ�� ���

int N, M;
int stack[8]; // �ε��� �����
unordered_map<long long int, int> exist; // �ߺ� �Ǵܿ� hash map
vector<int> v; // �����Ͱ� �� ����

void S(int idx, int depth) {
	if (depth == M) { // ���̿� ������ ���
		long long int check = 0;

		// ���� ���� ������ ������� ������ ���� key�� ����
		// 10000 ������ �� * 8 �� = �� 40�ڸ� �ʿ�
		// so, 64bit �� ���� long long int ������ ���
		for (int k = 0; k < depth; k++) {
			check = (check << 5) + v[stack[k]];
		}
		if (exist.end() != exist.find(check)) return;
		// �ش� Ű�� hash_map�� �����ϸ� ����

		exist[check] = 1; // map ���� Ű ������ ���
		for (int k = 0; k < depth; k++) {
			printf("%d ", v[stack[k]]); // ���� ���
		}
		printf("\n");
		return;
	}
	for (int k = idx; k < v.size(); k++) { // ���̿� �������� �������� ���ȣ��
		stack[depth] = k;
		S(k + 1, depth + 1);
	}
}

int main() {
	cin >> N >> M;
	for (int k = 0; k < N; k++) { // ������ ���Ϳ� �߰�
		int d;
		cin >> d;
		v.push_back(d);
	}
	sort(v.begin(), v.end()); // ũ�� ���� �����̹Ƿ� ����

	for (int k = 0; k < v.size(); k++) { // ���� Ž�� ����
		stack[0] = k;
		S(k + 1, 1);
	}
}