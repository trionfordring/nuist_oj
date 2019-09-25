#include <iostream>

using namespace std;

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
		int temp= 0;
		if(pUp!=nullptr&&values[p2i(sp)]>values[p2i(pUp)]){
			temp=slip(pUp)+1;
			if(temp>m)m=temp;
		}
		if(pDown!=nullptr&&values[p2i(sp)]>values[p2i(pDown)]){
                        temp=slip(pDown)+1;
                        if(temp>m)m=temp;
                }
		if(pLeft!=nullptr&&values[p2i(sp)]>values[p2i(pLeft)]){
                        temp=slip(pLeft)+1;
                        if(temp>m)m=temp;
                }
		if(pRight!=nullptr&&values[p2i(sp)]>values[p2i(pRight)]){
                        temp=slip(pRight)+1;
                        if(temp>m)m=temp;
                }
		return m;

	}
	int slip(int i){
		return slip(i2p(i));
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
	int temp;
	int max;
	while (b.set())
	{
		max = 0;
		for(int i=0;i<b.length;i++){
			temp = b.slip(i);
			if(temp>max)max=temp;
		}
		cout<<max+1<<endl;
	}
	return 0;
}
