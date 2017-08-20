#include <iostream>
using namespace std;

// サンプル
// 学生要素を管理し、スコアが合格点（60点）に満たない学生は削除される

#include "BaseElement.h"
#include "BaseManager.h"

// 学生クラス（BaseElementを継承）
class Student : public BaseElement {
public:

	// 学生は学生番号とスコアを保持している
	Student(int id, int score) : student_id(id), student_score(score) {}

	// 更新：スコアが満たない場合、自分を削除済みにする
	virtual void update() override {
		if (get_score() < 60) clear();
	}

	// 学生番号取得
	virtual int get_student_id() const { return student_id; }

	// スコア取得
	virtual int get_score() const { return student_score; }

private:

	// 学生番号
	int student_id;

	// スコア
	int student_score;

};

// 学生管理クラス：BaseManagerを継承し、保持する要素の型をStudentとする
class StudentManager : public BaseManager<Student>{
public:

	// 全学生の学生番号とスコアを表示
	virtual void show_student() const {
		for (auto p : elements) {
			cout << "学生" << p->get_student_id() << " スコア:" << p->get_score() << endl;
		}
	}
};

int main() {
	StudentManager sm;

	// 学生を追加していく
	sm.add(new Student(1, 80));
	sm.add(new Student(2, 50));
	sm.add(new Student(3, 75));
	sm.add(new Student(4, 25));
	sm.add(new Student(5, 40));

	// 学生の情報を表示（5人いる）
	sm.show_student();

	// テストの結果を反映
	sm.update();

	// 再度学生を表示（2人に減っている）
	sm.show_student();

}
