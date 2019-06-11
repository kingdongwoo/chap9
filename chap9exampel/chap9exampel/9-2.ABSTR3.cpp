//9-2.ABSTR3.CPP   9.4 �߻� class
#include <iostream>
using namespace std;

class Printer{
	private:
		int a;
	public:
		Printer()
		{}
		virtual void Method(const char* buffer) = 0;
		virtual int Cpi() = 0;
		void D(){
			cout << "Printer_D()" << endl;
		}
};

class LaserPrinter : public Printer{
	private:
		int cpi;
	public:
		LaserPrinter()
		{
			cpi = 20;
			//a = 2;
		}
		//�ּ� 1
		
		int Cpi(){
			cout<<"LaserPrinter Cpi() : "<< cpi << endl;
			return cpi;
		}
		void Method(const char* buffer){
			cout<<"LaserPrinter Method() : "<< buffer << endl;
		}
		void D(){
			cout << "LaserPrinter_D()" << endl;
		}
};

class InkJetLaser : public LaserPrinter{
	private:
		int cpi;
	public:
		InkJetLaser()
		{
			cpi = 30;
		}
		int Cpi(){
			cout<<"InkJetLaser Cpi() : "<< cpi << endl;
			return cpi;
		}
	
		void Method(const char* buffer){
			cout<<"InkJetLaser Method() : "<< buffer << endl;
		}
		void D(){
			cout << "InkJetLaser_D()" << endl;
		}
};

class FaxPrinter : public InkJetLaser{
	private:
		int cpi;
	public:
		FaxPrinter(){
			cpi = 40;
		}
		int Cpi(){
			cout<<"FaxPrinter Cpi() : "<< cpi << endl;
			return cpi;
		}
		//�ּ� 2
		
		void Method(const char* buffer){//overridding�� �Ű������� ���ƾ���. �׷��� ������ overloading �� ������
			cout<<"FaxPrinter Method() : "<< buffer << endl;
		}
};

void main(){
    //Printer *p = new Printer();

    LaserPrinter *laser = new LaserPrinter();
    laser->Cpi();
    laser->Method("woman");

    InkJetLaser *inkjet = new InkJetLaser();
    inkjet->Cpi();
    inkjet->Method("woman2");

    Printer *lp = new LaserPrinter();
    lp->Cpi();
    lp->Method("man1");

    Printer *fp = new FaxPrinter();
    fp->Cpi();
    fp->Method("man2");

    FaxPrinter *fp2 = new FaxPrinter();
    fp2->D();
	system("pause");
}