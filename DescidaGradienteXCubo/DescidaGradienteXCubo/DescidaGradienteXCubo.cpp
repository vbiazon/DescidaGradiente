// DescidaGradiente.cpp :

#include <iostream>
#include <math.h>

using namespace std;

double Derivada(double x) { // calcula derivada da funcao x^3-2*x^2+2, 3*x^2-4x.
	return 3*pow(x, 2)-4*x;
}

double Funcao(double x) { // calcula funcao x^3-2*x^2+2
	return pow(x, 3)-2*pow(x, 2)+2;
}

double taxa_ap = 0.1; //taxa de aprendizado


int main()
{
	double x = 2; //valor inicial
	double f = Funcao(x); //calculo de f0
	double f_linha = Derivada(x); //derivada da funcao em X

	while (abs(f_linha) > 0.0000001) { //avala enquanto o modulo da derivada de f for maior que um numero muito proximo de 0, pois nao é possivel chegar ao zero.
		double s = Derivada(x); //calcula deruvada da funcao em x
		x = x - taxa_ap * s; //realiza o desconto da derivada multiplicada pela taxa de variacao
		cout << "X: "<< x << " s: " << s << endl;
		f_linha = Derivada(x); //calcula a derivada novamente para ser avaliada pelo while
	}
	f = Funcao(x); //calcula valor da funcao onde o x é minimo

	cout << "O minimo local da funcao x^3-2*x^2+2 se encontra em x: " << x << " e neste ponto a funcao vale: " << f << endl;
	cin.get();
}

