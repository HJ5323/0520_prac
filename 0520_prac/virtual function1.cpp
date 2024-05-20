#include <iostream>

using namespace std;

class Person {
public:
	virtual void intro() {
		cout << "����Դϴ�~" << endl;
	}

	virtual ~Person() {} // ���� �Ҹ��� �߰�
};

class Student : public Person {
	string name;

public:
	Student(string name) {
		this->name = name;
	}
	void intro() override { // intro �Լ� ������
		cout << name << "�л��Դϴ�." << endl;
	}
	void learn() {
		cout << "���ϴ�." << endl;
	}
};

class Teacher : public Person {
	string name;

public:
	Teacher(string name) {
		this->name = name;
	}
	void intro() override {
		cout << name << "�����Դϴ�." << endl;
	}
	void teach() {
		cout << "����Ĩ�ϴ�." << endl;
	}
};

int main() {
	Person* pList[3];
	string names[3];

	cout << "3���� �̸��� �Է����ּ���.(������, �л�, �л�)" << endl;
	cin >> names[0] >> names[1] >> names[2];

	/* names[] �迭 �̿��Ͽ� �� class ���� */
	/* pList�� �Ҵ��ϴ� �ڵ� �߰� */
	pList[0] = new Teacher(names[0]); // names[0]�� ����Ͽ� Teacher ��ü�� �����ϰ� pList[0]�� �Ҵ�
	pList[1] = new Student(names[1]);
	pList[2] = new Student(names[2]);

	for (auto p : pList) { // �� ��ü�� intro �Լ��� ȣ��
		p->intro(); 
	}

	/* �� class�� ���� �Լ� ���� (teach(), lear(), lear()) */
	((Teacher*)pList[0])->teach(); // teach ȣ��
	((Student*)pList[1])->learn();
	((Student*)pList[2])->learn();

	// new�� �Ҵ�� �޸� ����
	for (int i = 0; i < 3; i++) {
		delete pList[i];
	}
}

//int main() {
// 	Person* pList[3];
//
//	string names[3];
//
//	cout << "3���� �̸��� �Է����ּ���.(������, �л�, �л�)" << endl;
//	cin >> names[0] >> names[1] >> names[2];
//
//	/* names[] �迭 �̿��Ͽ� �� class ���� */
//	Teacher teacher(names[0]);
//	Student student_1(names[1]);
//	Student student_2(names[2]);
//
//	/* pList�� �Ҵ��ϴ� �ڵ� �߰� */
//	Person* pList[3] = { &teacher, &student_1, &student_2 };
//
//	for (auto p : pList) { // �� ��ü�� intro �Լ��� ȣ��
//		p->intro();
//	}
//
//	/* �� class�� ���� �Լ� ���� (teach(), lear(), lear()) */
//	((Teacher*)pList[0])->teach(); // teach ȣ��
//	((Student*)pList[1])->learn();
//	((Student*)pList[2])->learn();
//}