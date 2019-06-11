// 9-3.VIRTDEST.CPP   9.6 virtual 소멸자

#include <iostream>
using namespace std;
class CShape {
public:
	CShape() {
			}
	~CShape() {
			}
public:
	virtual void draw() = 0;
	virtual void setName(const char* _name) = 0;
	virtual void move() = 0;
	virtual void colorChange() = 0;
};

class CRectangle : public CShape {
	const char* m_Name;

public:
	CRectangle() {
		
	}
	~CRectangle() {
		
	}
	void draw() {
		cout << "도형을 그린다." << endl;
	}
	void setName(const char* _name) {
		m_Name = _name;
	}
};

class CColorRectangle :public CRectangle {
public:
	void move() { cout << "a" << endl; };
	void colorChange() { cout << "a" << endl; };
	//void draw() {};

};

void main() {
	CColorRectangle CRobject;
	CRobject.draw();
	system("pause");
}