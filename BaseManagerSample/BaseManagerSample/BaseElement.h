#pragma once

// BaseManagerが保持する要素の基底クラス
class BaseElement{
public:

	// 要素自身の更新関数
	virtual void update() = 0;

	// 削除済み
	bool has_cleared() const { return cleared; }

protected:

	// 削除関数
	void clear() { cleared = true; }

private:

	// 削除済みフラグ
	bool cleared = false;
};

