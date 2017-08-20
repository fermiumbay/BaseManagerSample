#include <iostream>
using namespace std;

// �T���v��
// �w���v�f���Ǘ����A�X�R�A�����i�_�i60�_�j�ɖ����Ȃ��w���͍폜�����

#include "BaseElement.h"
#include "BaseManager.h"

// �w���N���X�iBaseElement���p���j
class Student : public BaseElement {
public:

	// �w���͊w���ԍ��ƃX�R�A��ێ����Ă���
	Student(int id, int score) : student_id(id), student_score(score) {}

	// �X�V�F�X�R�A�������Ȃ��ꍇ�A�������폜�ς݂ɂ���
	virtual void update() override {
		if (get_score() < 60) clear();
	}

	// �w���ԍ��擾
	virtual int get_student_id() const { return student_id; }

	// �X�R�A�擾
	virtual int get_score() const { return student_score; }

private:

	// �w���ԍ�
	int student_id;

	// �X�R�A
	int student_score;

};

// �w���Ǘ��N���X�FBaseManager���p�����A�ێ�����v�f�̌^��Student�Ƃ���
class StudentManager : public BaseManager<Student>{
public:

	// �S�w���̊w���ԍ��ƃX�R�A��\��
	virtual void show_student() const {
		for (auto p : elements) {
			cout << "�w��" << p->get_student_id() << " �X�R�A:" << p->get_score() << endl;
		}
	}
};

int main() {
	StudentManager sm;

	// �w����ǉ����Ă���
	sm.add(new Student(1, 80));
	sm.add(new Student(2, 50));
	sm.add(new Student(3, 75));
	sm.add(new Student(4, 25));
	sm.add(new Student(5, 40));

	// �w���̏���\���i5�l����j
	sm.show_student();

	// �e�X�g�̌��ʂ𔽉f
	sm.update();

	// �ēx�w����\���i2�l�Ɍ����Ă���j
	sm.show_student();

}
