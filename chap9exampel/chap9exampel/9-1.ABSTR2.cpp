// 9-1. ABSTR2.CPP  9.4 추상 class
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Printer{
public:
    Printer (){ }
    virtual void Method (char * buffer) ;
    virtual int Dpi ();
};

class DotMatrixPrinter : public Printer{
    int nDots;
	
public:
	//void Printer() {  }
	void Method(char *buffer);
	int Dpi();
    DotMatrixPrinter (int n) :
        nDots (n)
        { }
	 
} ;
void DotMatrixPrinter:: Method(char *buffer) {
	sprintf(buffer, "Dot matrix printer with %d pins", nDots); 
}
int DotMatrixPrinter::Dpi() {
	int tmp = -1;
	if (nDots == 8)
		tmp = 150;
	else if (nDots == 9)
		tmp = 160;
	else if (nDots == 24)
		tmp = 300;
	else
		tmp = 100;
	return tmp;

}

void main(){
    char description [40];
    DotMatrixPrinter dmp (24);
    dmp.Method (description);
    cout << description << endl << "DPI: " << dmp.Dpi () << endl <<endl;
    Printer * pPri;
    pPri = new DotMatrixPrinter (9);
    pPri -> Method (description);
    cout << description << endl << "DPI: " << pPri -> Dpi ()<< endl <<endl;
	delete pPri;
	system("pause");
}


//Method 함수 요구사항
//- char*를 파라미터로 전달 받아야함
//- sprintf를 이용하여 "Dot matrix printer with %d pins"문구를 writing해야함. %d에는 nDots 정보를 기입
//- sprintf의 파라미터는 buffer, 문자열, 변수 순서임

//Dpi 함수 요구사항
//- return type 은 int형
//- ndots의 값에 따라 반환 값이 달라져야함.
//- nDots이 8이면 150, 9이면 160, 24이면 300, default면 100

void Printer::Method(char * buffer)
{
}

int Printer::Dpi()
{
	return 0;
}
