#include <iostream>

using namespace std;

class Person {
public:
	virtual void intro() {
		cout << "사람입니다~" << endl;
	}

	virtual ~Person() {} // 가상 소멸자 추가
};

class Student : public Person {
	string name;

public:
	Student(string name) {
		this->name = name;
	}
	void intro() override { // intro 함수 재정의
		cout << name << "학생입니다." << endl;
	}
	void learn() {
		cout << "배웁니다." << endl;
	}
};

class Teacher : public Person {
	string name;

public:
	Teacher(string name) {
		this->name = name;
	}
	void intro() override {
		cout << name << "선생입니다." << endl;
	}
	void teach() {
		cout << "가르칩니다." << endl;
	}
};

int main() {
	Person* pList[3];
	string names[3];

	cout << "3명의 이름을 입력해주세요.(선생님, 학생, 학생)" << endl;
	cin >> names[0] >> names[1] >> names[2];

	/* names[] 배열 이용하여 각 class 생성 */
	/* pList에 할당하는 코드 추가 */
	pList[0] = new Teacher(names[0]); // names[0]을 사용하여 Teacher 객체를 생성하고 pList[0]에 할당
	pList[1] = new Student(names[1]);
	pList[2] = new Student(names[2]);

	for (auto p : pList) { // 각 객체의 intro 함수를 호출
		p->intro(); 
	}

	/* 각 class의 고유 함수 실행 (teach(), lear(), lear()) */
	((Teacher*)pList[0])->teach(); // teach 호출
	((Student*)pList[1])->learn();
	((Student*)pList[2])->learn();

	// new로 할당된 메모리 해제
	for (int i = 0; i < 3; i++) {
		delete pList[i];
	}
}

//int main() {
// 	Person* pList[3];
//
//	string names[3];
//
//	cout << "3명의 이름을 입력해주세요.(선생님, 학생, 학생)" << endl;
//	cin >> names[0] >> names[1] >> names[2];
//
//	/* names[] 배열 이용하여 각 class 생성 */
//	Teacher teacher(names[0]);
//	Student student_1(names[1]);
//	Student student_2(names[2]);
//
//	/* pList에 할당하는 코드 추가 */
//	Person* pList[3] = { &teacher, &student_1, &student_2 };
//
//	for (auto p : pList) { // 각 객체의 intro 함수를 호출
//		p->intro();
//	}
//
//	/* 각 class의 고유 함수 실행 (teach(), lear(), lear()) */
//	((Teacher*)pList[0])->teach(); // teach 호출
//	((Student*)pList[1])->learn();
//	((Student*)pList[2])->learn();
//}