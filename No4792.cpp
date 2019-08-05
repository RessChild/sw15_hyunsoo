#include<iostream>
#include<vector>
using namespace std;
// ���� ��� ���д� Ʈ��
// ��� ������ 1�� ���, ���д� Ʈ���� ��� ���� ������ ����
// ���� ��͸� ������� �� Union Find ��� ��, �޸� �ʰ��� ��
// so, ��� ���� ����� ����, �ݺ������� �Ž��� �ö󰡴� ��ĸ� ä��

int node, edge, b_edge; // ���, ����, �Ķ� ���� ��
int group[1000]; // 1000���� ��带 �ǹ�
vector<int> red, blue; // �� ����� ���� ������ �Է½�ų ����

int Red_First();
int Blue_First();
int Find(int here);
bool Union(int a, int b);
void reset();

int main() {
	while (true) {
		red.clear();
		blue.clear(); // ����Ŭ ������ �����Ƿ�, ���� �ʱ�ȭ ���� �ʿ�

		cin >> node >> edge >> b_edge; // �Է�
		if (node + edge + b_edge == 0) // ��� �Է°��� 0�� ��� ����
			break; // �ٸ�, ��� ������ 2 �̻��̹Ƿ�, node ������ ���ص� OK

		for (int k = 0; k < edge; k++) { // ���� �� ��ŭ �Է�
			char select; // ���� �� ����
			int node[2]; // 2���� ��
			cin >> select >> node[0] >> node[1];
			node[0]--;
			node[1]--; // �Է� ��� ���� ��� �ε����� ���ָ� ��ġ��Ŵ

			if (select == 'R')  // ���� ������ ���
				red.push_back(node[0] * 1000 + node[1]); // ���������� ��ȣȭ
			else
				blue.push_back(node[0] * 1000 + node[1]);
			// ��� ����(����)�� weight ���� �����ϹǷ�, ������ �ڿ� push
		} // ��� ���� �Է� �Ϸ�
	
		if (Red_First() <= b_edge && b_edge <= Blue_First())
			cout << 1 << endl;
		else
			cout << 0 << endl;
		// � ���� �켱���� ����߳Ŀ� ���� blue ���� ��� ���� �����
		// �ݵ�� �ʿ��� ������, �ִ�� Ȱ�� ������ ���� ���� �ִ� ���
		// �ش� ���� ���� ������ ���д� Ʈ���� �ݵ�� �����Ѵٴ� ������ ���
	}
}

int Red_First(){ // ���� ������ �켱 ����ϴ� ���
				 // �ش� case�� ���, '�ݵ�� �ʿ���' �Ķ� ������ ���� �ǹ�
	int red_first = 0;
	reset();
	for (int k = 0; k < red.size(); k++) { // �켱 ���� ���� �켱
		Union(red[k] / 1000, red[k] % 1000); // �����Ų ���� ������ Ǯ� �ǳ���
											 // �� ��, ���� ������ ������ �߿����� �����Ƿ� ����
	}
	for (int k = 0; k < blue.size(); k++) { // ���� �Ķ� ���� ���
		if (Union(blue[k] / 1000, blue[k] % 1000)) // �ش� ������ ���Ǵ� ���, true�� ��ȯ�ϹǷ�
			red_first++; // ���� ��� ���� ������Ŵ
	} 
	return red_first; // ��ȯ
}

int Blue_First(){ //�Ķ� ������ �켱 ����ϴ� ���
				  // ���� ������ ��� ���δ� �߿����� �����Ƿ� ����
				  // �ش� case�� ���, '�ִ�� ��� ������' �Ķ� ������ ���� �ǹ�
	int blue_first = 0;
	reset();
	for (int k = 0; k < blue.size(); k++) { // �Ķ� ������ ���� ����ϴ� ���
		if (Union(blue[k] / 1000, blue[k] % 1000))
			blue_first++; // �Ķ� ���� ��� ���� ������Ŵ
	} 
	return blue_first; //��ȯ
}

int Find(int here){
	while (group[here] != here) { // ��Ʈ�� ������ ������
		here = group[here]; // ����ؼ� �Ž��� �ö�
	}
	return here; //������ ��Ʈ���� ��ȯ
} // ���� �ڵ�� �ٸ��� ��θ� �����ϴ� ������ �������� ����

bool Union(int a, int b) {
	int root_a = Find(a), root_b = Find(b);
	if (root_a != root_b) { // ��Ʈ�� �ٸ� ���
		group[root_a] = root_b; // �ϳ��� ��ħ
		return true; // �ش� ���� �����
	}
	return false; // �׿��� ��쿣 ����
}

void reset() {
	for (int k = 0; k < node; k++)
		group[k] = k; // �� ����� ��ǥ�� �ʱ�ȭ
}