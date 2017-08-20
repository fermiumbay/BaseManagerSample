#pragma once

class BaseElement{
public:
	BaseElement();
	~BaseElement();
	virtual void update() = 0;

protected:
	bool has_cleared() const;
	void clear();

private:
	bool cleared = false;
};

