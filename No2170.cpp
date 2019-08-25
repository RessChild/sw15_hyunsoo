#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// �� �߱�
// Line Sweeping �� ����� Ǯ�̹�

class Line {
public:
	int s, e; //���۰� ��
	Line();
	Line(int i_s, int i_e);
};

int main() {
	int loop;
	vector<Line> line; // ������ �ִ� �� ����

	cin >> loop; //�ݺ� Ƚ��
	while (loop--) {
		int s, e;
		cin >> s >> e;
		line.push_back(Line(s, e));
	}

	sort(line.begin(), line.end(), [](Line a, Line b) -> bool {
		// false ���� ������ ��쿡�� ������ �ٲ�
		if (a.s == b.s) { // �������� ���� ���
			return a.e < b.e; // �� ������ ū ���� ��� �ٲ�
		}
		else return a.s < b.s;
	}); // sort �Լ��� ���� ������ �Լ��� ��������

	for (int k = 0; k < line.size() - 1;) { // ���ĵ� ���� ��ġ�� ����
		if (line[k].e >= line[k + 1].s) { // ���� ������ �� ���������� ��ġ�� ���
			if (line[k].e < line[k + 1].e)  // ���� ������ �� �ִ°��
				line[k].e = line[k + 1].e; // ����
			// �ݴ��� ���� �����ص� ��
			line.erase(line.begin() + k + 1); //���� ��ġ ����
		}
		else
			k++; //�� ���� ���, ���� �������� �Ѿ
	}

	int ans = 0;
	for (int k = 0; k < line.size(); k++) {
		ans += line[k].e - line[k].s; // ���̸�ŭ �߰�
	}
	cout << ans << endl;
}

Line::Line(){}
Line::Line(int i_s, int i_e){
	s = i_s;
	e = i_e; // �� �Է�
}
