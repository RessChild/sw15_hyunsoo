#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// ���� �� ������� �κ� ����
// ���̳��� ���α׷����� ����Ͽ� ������ ���
// �� ������ �����Ͽ� ��󳻴� ����� ���

int loop;
int max_up[1000]; //�� �ε��� �� �ڽź��� ���� ��
int max_down[1000]; //�� �ε��� �� �ڽź��� ���� ��
int total[1000]; //����
vector<int> list; // ������ �Է�

int Up(int index); //���� Ŀ���� ��Ģ�� Ȯ��
int Down(int index); //���� �۾����� ��Ģ�� Ȯ��
void DP(); //���̳��� ���α׷���

int main() {
	cin >> loop; // �迭 ũ��
	
	for (int k = 0; k < loop; k++) {
		int d;
		cin >> d;
		list.push_back(d);
		max_up[k] = -1; // �����迭 �ʱ�ȭ
		max_down[k] = -1;
	}
	
	DP();
}

int Up(int index) { //���� ��ġ�� �ε�����, ���� �θ����� ��
	if (max_up[index] != -1) //�̹� ��ϵ� ���� �ִٸ�
		return max_up[index]; //����
	max_up[index] = 0; //�ϴ� ����
	for (int k = 0; k < index; k++) { // ��� ���� ��鿡 ���� ȣ��
		if (list[k] < list[index]) //���� Ŀ���� ��Ģ�� �����ϸ�
			max_up[index] = max(max_up[index], Up(k) + 1);
			//ȣ�� ��, �༮�� ���� �ִ� ���� �޾� ���Ͽ� �ִ밪�� ����
	}
	return max_up[index];
}

int Down(int index) { //���� ��ġ�� �ε�����, ���� �θ����� ��
	if (max_down[index] != -1) //�̹� ��ϵ� ���� �ִٸ�
		return max_down[index]; //����
	max_down[index] = 0; //�ϴ� ����
	for (int k = index + 1; k < loop; k++) { // ��� ���� ��鿡 ���� ȣ��
		if (list[index] > list[k]) //���� �۾����� ��Ģ�� �����ϸ�
			max_down[index] = max(max_down[index], Down(k) + 1);
		//ȣ�� ��, �༮�� ���� �ִ� ���� �޾� ���Ͽ� �ִ밪�� ����
	}
	return max_down[index];
}

void DP() {
	for (int k = 0; k < loop; k++) { //��� ��Ȳ�� ���Ͽ� ���
		Up(k);
		Down((loop - 1) - k);
	}
	for (int k = 0; k < loop; k++) 
		total[k] = max_up[k] + max_down[k] + 1; 
	// Up,Down ���� ���Ͽ�
	// �� �ε����� �߽��� �Ǿ��� ���, �ִ��� ����

	cout << *max_element(total,total+loop) << endl; //�ִ��� ��� ���
}