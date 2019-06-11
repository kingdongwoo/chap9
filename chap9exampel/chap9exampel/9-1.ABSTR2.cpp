// 9-1. ABSTR2.CPP  9.4 �߻� class
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


//Method �Լ� �䱸����
//- char*�� �Ķ���ͷ� ���� �޾ƾ���
//- sprintf�� �̿��Ͽ� "Dot matrix printer with %d pins"������ writing�ؾ���. %d���� nDots ������ ����
//- sprintf�� �Ķ���ʹ� buffer, ���ڿ�, ���� ������

//Dpi �Լ� �䱸����
//- return type �� int��
//- ndots�� ���� ���� ��ȯ ���� �޶�������.
//- nDots�� 8�̸� 150, 9�̸� 160, 24�̸� 300, default�� 100

void Printer::Method(char * buffer)
{
}

int Printer::Dpi()
{
	return 0;
}
