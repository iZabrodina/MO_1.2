#include <iostream>
#include <locale.h>
#include <cmath>
#include "Functions.h"
#include "Huk Jivs.h"
#include "Nelder_Mid.h"
using namespace std;

int main()
{
	//задаем начальную точку
	double x = pointX();
	double y = pointY();
	//запускаем метод Хука-Дживса
	float huk_jivs = Huk_Jivs(x, y);
	//запускаем метод Нелдер-Мида
	float nelder_mid = Nelder_Mid(x, y);
}
