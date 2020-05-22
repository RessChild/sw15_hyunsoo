#include<iostream>
#include<vector>
using namespace std;


int book, people; //å, ��� ��
int range[1000][2]; // �� ����� å�� ������
int have[1000]; // å�� ���� ����鿡 ���� ������
bool visit[1000]; //�湮 ���ΰ�
int ans[1000];

int Binary_Match(); // ���� ��Ī �Լ�
int DFS(int want); // ���� ��Ī���� ����� ����Լ�

int main() {
	int loop;
	cin >> loop; // �׽�Ʈ ���̽�
	
	for (int k = 0; k < loop; k++) {
		cin >> book >> people; // å ��, ��� ��
		for (int k = 0; k < book; k++) {
			have[k] = -1;
		}
		ans[k] = Binary_Match();
	}
	for (int k = 0; k < loop; k++)
		cout << ans[k] << endl;
	
}

int Binary_Match() {
	for (int k = 0; k < people; k++) 
		cin >> range[k][0] >> range[k][1]; // ������ �Է¹���

	int count = 0;

	for (int k = 0; k < people; k++) { // ��� ����鿡�� å�� ���� ��ȸ ����
		for (int i = 0; i < people; i++) // �� ������� å�� �ٲ� ��ȸ�� �ʱ�ȭ
			visit[i] = false; 
		count += DFS(k);
	}
	return count;
}

int DFS(int want) {
	if (visit[want]) return 0; // �湮�� ���� �ִ� ��� ��湮 x
	visit[want] = true; //�湮 ����
	for (int k = range[want][0] - 1; k < range[want][1]; k++) { //��� ��ȣ å�� ���ؼ�
		if (have[k] == -1 || DFS(have[k])) {
			// �� ���̰ų�, �ش� ������ �ٸ� ������ �Űܰ� �� ������
			have[k] = want; // ���� ����
			return 1;
		}
	}

	return 0; // �ݺ��� ���� return ���� ������ ����
}