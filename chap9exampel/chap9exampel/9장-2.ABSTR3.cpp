// 9��-2.ABSTR3.CPP   9.4 �߻� class
#include <iostream>
using namespace std;
class Printer{
public:
    Printer (){ }
	virtual void Method (char * buffer) = 0;
    virtual int Dpi () = 0;
  //  ��
  //  ��
};

class LaserPrinter : public Printer{
public:
    LaserPrinter (){ }
    int Cpi (){
        return 300;
    }
} ;

void main (){
    //LaserPrinter lp1;//�߻�Ŭ����  
    LaserPrinter * lp2; 
	system("pause");
}