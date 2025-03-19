#include "Canvas.h"
#include <cmath>
#include <stdio.h>

Canvas::Canvas(int width, int height) //constructor
{
	this->width = width;
	this->height = height;

	//Alocam memorie pentru matricea canvasului
	matrice = new char* [height];
	for (int i = 0; i < height; i++)
	{
		matrice[i] = new char[width];

		for (int j = 0; j < width; j++)
			matrice[i][j] = ' '; //initializam cu spatiu
	}
}

Canvas::~Canvas()
{
	//Eliberam memoria alocata pentru matrice
	for (int i = 0; i < height; i++)
		delete[] matrice[i]; //Eliberam fiecare rand
	delete[] matrice; //Elibereaza matricea
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	x--;
	y = height - y + 1;

	for (int i = 0; i <= ray; i++) 
	{
		matrice[y + i][x - ray + i] = ch;
		matrice[y - i][x - ray + i] = ch;

		matrice[y + i][x + ray - i] = ch;
		matrice[y - i][x + ray - i] = ch;
	}
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	x--;
	y = height - y + 1;

	for (int i = 0; i <= ray; i ++)
		for (int j = y - i + 1; j <= y + i; j++)
		{
			matrice[j][x - ray + i] = ch;
			matrice[j][x + ray - i] = ch;
		}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	left--;
	right--;

	for (int i = left; i <= right; i++)
	{
		matrice[top][i] = ch; //Desenam partea de sus
		matrice[bottom][i] = ch; //Desenam partea de jos
	}

	for (int i = top; i <= bottom; i++)
	{
		matrice[i][left] = ch; //desenam partea din stanga
		matrice[i][right] = ch; //desenam partea din dreapta
	}
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	left--;
	right--;

	for (int i = top + 1; i < bottom; i++)
		for (int j = left + 1; j < right; j++)
			matrice[i][j] = ch;
}

void Canvas::SetPoint(int x, int y, char ch)
{
	x--;
	y = height - y + 1;

	if (x >= 0 && x < width && y >= 0 && y < height) 
		matrice[y][x] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);

	int sx;
	if (x1 < x2)
		sx = 1;
	else
		sx = -1;
	
	int sy;
	if (y1 < y2)
		sy = 1;
	else
		sy = -1;
	
	int err = dx - dy;

	while (true) 
	{
		SetPoint(x1, y1, ch);  // Setează punctul pe canvas

		if (x1 == x2 && y1 == y2)  // Dacă am ajuns la punctul final, ieșim
			break;

		int e2 = 2 * err;
		if (e2 > -dy) 
		{
			err = err - dy;
			x1 = x1 + sx;
		}
		if (e2 < dx) 
		{
			err = err + dx;
			y1 = y1 + sy;
		}
	}
}

void Canvas::Print()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			printf("%c", matrice[i][j]);
		printf("\n");
	}
}

void Canvas::Clear()
{
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			matrice[i][j] = ' ';
}
