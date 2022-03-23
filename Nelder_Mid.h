#pragma once

#include <iostream>
#include <locale.h>
#include <cmath>
#include "Functions.h"
using namespace std;

float Nelder_Mid(double x, double y)
{
    cout << endl << endl << endl << endl << "Запуск метода Нелдера-Мида" << endl;
    setlocale(LC_ALL, "Russian");
    int step = 0;

    double x1 = pointX1(), y1 = pointY1(), x2 = pointX2(), y2 = pointY2();
    double xx[3] = { x, x1, x2 };
    double yy[3] = { y, y1, y2 };
  
    double a = 1, b = 2, g = 0.5, e = 0.0001, res, new_res;
    double xc, yc;
    int best_coef = 0, worst_coef = 0;
    do
    {
        step++;
        for (int i = 0; i < 3; i++)
        {
            if (function(xx[i], yy[i]) < function(xx[best_coef], yy[best_coef]))
                best_coef = i;
            else if (function(xx[i], yy[i]) > function(xx[worst_coef], yy[worst_coef]))
                worst_coef = i;

        }
        xc = 0.5 * (xx[0] + xx[1] + xx[2] - xx[worst_coef]);                          //нашли центр тяжести
        yc = 0.5 * (yy[0] + yy[1] + yy[2] - yy[worst_coef]);

        double x_otr, y_otr, x_szh, y_szh;
        x_otr = xc + a * (xc - xx[worst_coef]);                                   //отражение
        y_otr = yc + a * (yc - yy[worst_coef]);

        double x_ras, y_ras;
        if (function(x_otr, y_otr) < function(xx[best_coef], yy[best_coef]))
        {
            x_ras = xc + b * (x_otr - xc);                                        //растяжение
            y_ras = yc + b * (y_otr - yc);
            if (function(x_otr, y_otr) < function(xx[best_coef], yy[best_coef]))
            {
                xx[worst_coef] = x_ras;
                yy[worst_coef] = y_ras;
            }
            else
            {
                xx[worst_coef] = x_otr;
                yy[worst_coef] = y_otr;
            }
        }
        else //if (function(x_otr, y_otr) >= function(xx[best_coef], yy[best_coef]))              //сжатие
        {
            x_szh = xc + g * (xx[worst_coef] - xc);
            y_szh = yc + g * (yy[worst_coef] - yc);
            xx[worst_coef] = x_szh;
            yy[worst_coef] = y_szh;
        }
        double result_fun;
        result_fun = function(xx[best_coef], yy[best_coef]);
        cout << "Шаг №" << step << endl;
        cout << "Выбранная точка: (" << xx[best_coef] << ", " << yy[best_coef] << ")" << endl;
        cout << "Значение функции: " << result_fun << endl;
        res = 0;
        for (int i = 0; i < 3; i++)
        {
            res += pow((function(xx[i], yy[i]) - function(xc, yc)), 2);
        }
        new_res = (sqrt(res) / 3);
    } while (new_res > e);

    cout << endl << "Полученное минимальное значение функции: " << function(xx[best_coef], yy[best_coef]) << endl;
    cout << "Ответ: (" << xx[best_coef] << ", " << yy[best_coef] << ")" << endl;
    cout << "Количество шагов: " << step;
    return step;
}