#include <iostream>
#include "Canvas.h"

int main()
{
	//Creez o matrice 20x20
	Canvas myCanvas(20, 20);

	//desenez un dreptunghi cu colturile (2,2) si (15,7)
	myCanvas.DrawRect(2, 2, 15, 7, '#');
	//umplu dreptunghiul cu caractere '*'
	myCanvas.FillRect(2, 2, 15, 7, '*');

	//desenez un cerc cu centrul in (10,5) si raza 3
	myCanvas.DrawCircle(10, 5, 3, 'O');
	//umplu cercul cu caracterul '@'
	myCanvas.FillCircle(10, 5, 3, '@');

	//desen o linie de la punctul (1,1) la punctul (19,19)
	myCanvas.DrawLine(1, 1, 19, 19, '+');
	//setez un punct pe coordonatele (10,15) cu caracterul '@'
	myCanvas.SetPoint(10, 15, '@');

	//afisez canvasul
	myCanvas.Print();

	return 0;
}