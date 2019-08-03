#include<iostream>
#include<vector>
using namespace std;
// �ּ� ���д� Ʈ��
// Minimum Spanning Tree ��, ������ weight ���� ��� ���� �� ����ϴ�
// ũ�罺Į �˰����� ���
// �ٸ�, ����Ŭ�� Ȯ���ϴ� �������� '���Ͽ� ���ε�'�� ������ ��

class Edge {
public:
	int from, to, weight; // �� ������ ����
	Edge();
	Edge(int i_from, int i_to, int i_weight);
};

int v, e; // ���, ����
int group[10000];
vector<Edge> sort; // ��� ������ �����ϰ�, ������ ����

int Minimum_Spanning_Tree();
bool Union(int a, int b);
int Find(int here);

int main() {
	cin >> v >> e;

	for (int k = 0; k < v; k++) { // ��� ������ ù ���̴� 1
		group[k] = -1;
	}

	while (e--) {
		int from, to, weight;
		cin >> from >> to >> weight;

		if (sort.empty()) { // �켱������ vector�� ��������� �۵��� �ȵ�
			//so, �̸� 1�������� �ɷ���
			sort.push_back(Edge(from, to, weight));
			continue;
		}

		vector<Edge>::iterator it; // ���ͷ����� (�ݺ���)
		for (it = sort.begin(); it != sort.end(); it++) { // ���� 0�� ��� ������ ����
			if (it->weight >= weight) { // ���� �ݺ��ڰ� ����Ű�� ���� ���԰�
				   // �����ϰ��� �ϴ� �����Ͱ����� ū ���, ���� (ũ��� ����)
				sort.insert(it, Edge(from, to, weight));
				break;
			}
		} // ��Һ񱳷� ���� �ְ�

		sort.push_back(Edge(from, to, weight));
		// ���������� ���Ұ� ���� �ʾҴٸ�, ������ ���� ����

	} // ���� ���� ���� �Է� ��

	cout << Minimum_Spanning_Tree() << endl;
}

Edge::Edge(){}
Edge::Edge(int i_from, int i_to, int i_weight){
	from = i_from;
	to = i_to;
	weight = i_weight;
}

int Minimum_Spanning_Tree() {
	int total = 0;

	for (int k = 0; k < sort.size(); k++) {  //��� ������ ���鼭
		Edge select = sort[k];
		if (Union(select.from - 1, select.to - 1)) // ������ �õ�
			total += select.weight; // ���ῡ ������ ��� ���� ����
	}
	return total; // ������ �������� �� ���Ը� ��ȯ
}

bool Union(int a, int b) {
	int a_root = Find(a);
	int b_root = Find(b); // �� ����� �Ҽ� ������ ã��

	int result = (a_root == b_root); // ����� ��

	if (!result) { // �ٸ� ���
		if (group[a_root] <= group[b_root]) { // �� �� ���̰� ������ ����
				// �� ����� ���̰� ������ �� �����Ƿ�, ��Ȳ�� ���� ���̰� 1 �����ϱ⵵ ��
			group[a_root] -= "10"[group[a_root] == group[b_root]] - '0';
			group[b_root] = a_root;
		}
		else
			group[a_root] = group[b_root]; // �� ���� ���� �������
	}

	return !result; // ���� ���� �� true, ���н� false ��ȯ
}

int Find(int here) {
	if (group[here] == -1) return here; // ���� ��ġ ���� -1�̸� ��Ʈ���� �ǹ�
	return group[here] = Find(group[here]); // �� �ܿ��� ���� ����, ���� ���� ��ȯ
}