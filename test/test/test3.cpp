#include <iostream>

using namespace std;

int max = 0;
class point {
public:
	int x;
	int y;
	point(int x,int y):x(x),y(y){}
	point(){}
};
class block {
public:
	int rows;
	int cols;
	int length;
	int* values =nullptr;
	bool set() {
		if (!(cin >> rows >> cols)) {
			return false;
		}
		length = rows * cols;
		if (values != nullptr) {
			delete values;
		}
		values = new int[length];
		for (int i = 0; i < length; i++)
		{
			cin >> values[i];
		}
		return true;
	}
	void input(point p,int value) {
		values[p2i(&p)] = value;
	}
	int p2i(point* p) {
		return cols * (p->y) + p->x;
	}
	point* i2p(int i) {
		return new point(i % cols,i/cols);
	}
	int slip(point* sp) {
		int m = 0;
		point* pUp = up(sp);
		point* pDown = down(sp);
		point* pLeft = left(sp);
		point* pRight = right(sp);
	}
	point* up(point* sp) {
		int t = p2i(sp)-cols;
		if (t >= 0) {
			return i2p(t);
		}
		return nullptr;
	}
	point* down(point* sp) {
		int t = p2i(sp) + cols;
		if (t < length) {
			return i2p(t);
		}
		return nullptr;
	}
	point* left(point* sp) {
		if (sp->x <= 0)return nullptr;
		return i2p(p2i(sp) - 1);
	}
	point* right(point* sp) {
		if (sp->x>=rows-1)return nullptr;
		return i2p(p2i(sp) + 1);
	}
};
int main() {
	block b;
	while (b.set())
	{

	}
	return 0;
}
