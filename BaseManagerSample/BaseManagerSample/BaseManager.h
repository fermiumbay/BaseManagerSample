#pragma once
#include "BaseElement.h"
#include <vector>

// �v�f��ێ�����}�l�[�W���[�N���X�̊��
template<class C> class BaseManager{
public:
	BaseManager() {}
	~BaseManager() { all_clear(); }

	// �v�f�̒ǉ�
	virtual void add(C* e) {
		elements.push_back(e);
	}

	// �v�f���ꊇ�X�V�i�폜���s���j
	virtual void update() {
		for (auto it = elements.begin(); it != elements.end(); it++) {
			(*it)->update();
		}
		for (auto it = elements.begin(); it != elements.end(); ) {
			if ((*it)->has_cleared()) {
				delete *it;
				it = elements.erase(it);
			}
			else {
				it++;
			}
		}
	}

	// �ێ����Ă���v�f��S�폜
	virtual void all_clear() {
		for (auto it = elements.begin(); it != elements.end(); it++) {
			delete *it;
		}
		elements.clear();
	}
	
protected:

	// �ێ����Ă���v�f
	std::vector<C*> elements;

};
