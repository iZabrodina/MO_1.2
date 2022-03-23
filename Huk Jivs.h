#pragma once

#include <iostream>
#include <locale.h>
#include <cmath>
#include "Functions.h"
using namespace std;


float Huk_Jivs(double x, double y)
{
    setlocale(LC_ALL, "Russian");
    cout << endl << "Запуск метода Хука-Дживса" << endl;
    int step = 0;
    //Приращение: 
    double delta = 1;
    //Коэффициент уменьшения шага (>1): 
    double alfa = 2;
    //Параметр окончания поиска (>0): 
    double e = 0.00001;

    float result_fun, result_fun1, result_fun2, result_fun3;
    //cout << endl << result_fun << endl;

    float x1, y1, x0, y0, x2, y2;
    bool b = true;
    x1 = x;
    y1 = y;
    do
    {
        step++;
        x0 = x;
        y0 = y;
        result_fun = function(x, y);
        result_fun1 = function((x - delta), y);
        result_fun2 = function((x + delta), y);
        if (result_fun1 < result_fun)
        {
            x1 = x - delta;
            result_fun = result_fun1;
            x = x1;
        }
        else if (result_fun2 < result_fun)
        {
            x1 = x + delta;
            result_fun = result_fun2;
            x = x1;
        }

        result_fun1 = function(x, (y - delta));
        result_fun2 = function(x, (y + delta));
        if (result_fun1 < result_fun)
        {
            y1 = y - delta;
            result_fun = result_fun1;
            y = y1;
        }
        else if (result_fun2 < result_fun)
        {
            y1 = y + delta;
            result_fun = result_fun2;
            y = y1;
        }


        if ((x1 != x0) || (y0 != y1))
        {
            do
            {
                x2 = x1 + (x1 - x0);
                y2 = y1 + (y1 - y0);
                result_fun3 = function(x2, y2);
                if (result_fun3 < result_fun)
                {
                    result_fun = result_fun3;
                    x0 = x1;
                    y0 = y1;
                    x1 = x2;
                    y1 = y2;
                    x = x2;
                    y = y2;
                    b = true;
                }
                else b = false;
            } while (b == true);
            delta = delta / alfa;
        }
        else (delta = delta / alfa);
        cout << "Шаг №" << step << endl;
        cout << "Выбранная точка: (" << x << ", " << y << ")" << endl;
        cout << "Значение функции: " << result_fun << endl;
    } while (sqrt(delta * delta) >= e);

    result_fun = function(x, y);
    cout << endl << "Полученное минимальное значение функции: " << result_fun << endl;
    cout << "Ответ: (" << x << ", " << y << ")" << endl;
    cout << "Количество шагов: " << step;
    return result_fun;
}
