#pragma once

// BaseManager���ێ�����v�f�̊��N���X
class BaseElement{
public:

	// �v�f���g�̍X�V�֐�
	virtual void update() = 0;

	// �폜�ς�
	bool has_cleared() const { return cleared; }

protected:

	// �폜�֐�
	void clear() { cleared = true; }

private:

	// �폜�ς݃t���O
	bool cleared = false;
};

