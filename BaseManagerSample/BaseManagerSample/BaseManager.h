#pragma once
#include "BaseElement.h"
#include <vector>

// 要素を保持するマネージャークラスの基底
template<class C> class BaseManager{
public:
	BaseManager() {}
	~BaseManager() { all_clear(); }

	// 要素の追加
	virtual void add(C* e) {
		elements.push_back(e);
	}

	// 要素を一括更新（削除も行う）
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

	// 保持している要素を全削除
	virtual void all_clear() {
		for (auto it = elements.begin(); it != elements.end(); it++) {
			delete *it;
		}
		elements.clear();
	}
	
protected:

	// 保持している要素
	std::vector<C*> elements;

};
