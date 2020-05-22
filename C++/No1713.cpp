#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// �ĺ� ��õ�ϱ�
// �Ź� ������ ���ؿ� ���� ���� ��, ó���ϴ� ����� ���
// �����ϴ� �������� ũ�Ⱑ ������ �۱� ������ ������ ���

#define SIZE 100 // ���� ������ �ĺ��� ��ȣ
#define LOOP 1000 // �ִ� �ݺ� Ƚ��

int N, M, candi[SIZE + 1], arr[LOOP]; 
vector<int> idx; // ������ arr�� index

int main() {
	cin >> N >> M;
	int data;
	for (int k = 0; k < M; k++) {
		cin >> arr[k]; // k ��°�� ������ ��
		if (!candi[arr[k]]) { // ���ڿ� ���ٸ�
			if (idx.size() >= N) { // ���� ���� ������ �ĺ��ڰ� ������
				sort(idx.begin(), idx.end(), [](int& a, int& b)->bool { // ���� Ƚ��, idx ���� �켱������ ����
					return candi[arr[a]] == candi[arr[b]] ? a > b : candi[arr[a]] > candi[arr[b]];
					});
				int remove = idx[idx.size() - 1]; // ���� �ڿ��� �����ϴ� ���� ������ ��
				idx.pop_back();
				candi[arr[remove]] = 0; // ���� ���� ���� ó���� ������ ���� �ʱ�ȭ
			}
			idx.push_back(k); // ���� ��ȣ�� ����
		}
		candi[arr[k]] += 1; // �ߺ� ���� Ƚ�� ����
	}

	sort(idx.begin(), idx.end(), [](int& a, int& b)->bool {
		return arr[a] < arr[b]; // ��ȣ ũ������� ����
		});
	for (int k = 0; k < idx.size(); k++) {
		cout << arr[idx[k]] << " "; // ���
	}
}