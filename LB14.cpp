#include <stdio.h>    
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <conio.h>
using namespace std;

int fib(int n) {
	if (n<0) return -1;
    if (n<3) return 1;
    if (n==0) return 0;
    return fib(n-1)+fib(n-2);
}

double f(double x) {return x * x;}

double dih(double a, double b) {
	
	if (f(a) == 0)return a;
	if (f(b) == 0)return b;

	double c = (a + b)/2;
	if ((f(c) == 0) || ((b-a)/2<=0.001)) return c;

	if (f(a) * f(c) < 0) b = c; else a = c;
	return dih(a, b);
}


double kor(double x1, double c, double x){
	if ((f(c) == 1) || ((f(c) < x) && (abs(c-x1)>0.001))) return c;
	if (f(c) > x) x1=c;
	c=(x1+1)/2;
	return kor(x1,c,x);
}

int st(int n) {
	int k=0 ;
	if (n == 1)k = 1;
	if (n == 2)k = 2;
	if (n == 3)k = 2;
	
	if (n>3){
		k += st(n - 1);
		k += st(n - 2);
		k += st(n - 3);
	}
	return k;
}

int ch(int a, int k,int z) {
	int kol=0;
	if (k == 5) {
		if (a % z == 0) kol++;
	}
	else {
		kol += ch(a*10+2, k+1, z);
		kol += ch(a*10+3, k+1, z);
		kol += ch(a*10+5, k+1, z);
	}
	return kol;	
}

int chm(int a, int k,int z) {
	int kol=0;
	if (k == 3) {
		if (a % z == 0) kol++;
	}
	else {
		kol += ch(a*10+1, k+1, z);
		kol += ch(a*10+2, k+1, z);
		kol += ch(a*10+3, k+1, z);
	}
	return kol;	
}


 int main() {
 	setlocale(LC_ALL, "Russian");
 	int nb;
 	cout<<"��������:\n 1)����� ���������\n 2)����� ������� ��������� f(x)=x*x �� ������� [a,b]\n 3)����� ����������� �����\n 4)���-�� �������� ��������� �� ��������\n 5)������� ����������� �����, ���������� ������  � ������� ���� 2,3,5 ������ ��������� �����?\n 6)������� ����������� ����, ��������� ������ �� ���� 1,2  ��� 3, ������� �� 3?\n"; 
	cin>>nb;
	switch (nb) {
 		case 1:
	  		int n;cout<<"������� �����))"; cin>>n;
	  		while (n<0) {cout<<"\n������! ������� �����"; cin>>n;}
			cout<<fib(n)<<endl;
	  		break;
	  		
	  	case 2:
	  		double a,b; cout<<"������� ����������))"; 
			  cin>>a>>b; 
			  while ((a>0) || (b<0)) {cout<<"\n������! ������� ����������))"; cin>>a>>b;}
			  cout<<dih(a,b)<<endl;
	  		break;
	  	
	  	case 3:
	  			double x,x1,c;
	  			cout<<"������� �����))"; cin>>x;
	  			while (x<1) {cout<<"\n������! ������� �����"; cin>>x;}
				x1=x;
			 	c=(x1+1)/2;
			 	cout<<kor(x1,c,x); 
				break;
				
//	  	case 4: 
//				cout<<"������� ���-�� ��������))"; cin>>n; 
//				while (n<1) {cout<<"\n������! ������� �����"; cin>>n;}
//				cout << st(n); 
//				break;
		
		case 5:
				int z; cout<<"������ ����� ������?))"; cin>>z;
				while (z<1) {cout<<"\n������! ������� �����"; cin>>z;}
				cout << ch(0, 0, z); 
				break;
				
		case 6: 
				cout << chm(0, 0, 3); 
				break;
				
		default: cout<<"\n������ ������ ���!"; break;
 	}
}


