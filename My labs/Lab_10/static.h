#pragma once

#include <iostream> 
#include <fstream> 

class matrixdyn
{
protected:
	double *matr;
	int rows;
	int colums;
	bool boo;
public:
	virtual void create();
	virtual void input();
	void print();
	void transp();
	int getrows() const
	{
		return rows;
	}
	int getcolums() const
	{
		return colums;
	}
	double getelem(int r, int c) const
	{
		return matr[r*colums + c];
	}
	void olelem(int oro, int oco, double oel)
	{
		matr[oro*colums + oco] = oel;
	}
	void odim(int oro, int oco)
	{
		rows = oro;
		colums = oco;
		matr = new double[rows*colums];
	}
	friend std::ostream& operator << (std::ostream& os, const matrixdyn& d);
	void del();
	friend matrixdyn operator + (matrixdyn A, matrixdyn B);
	friend matrixdyn operator - (matrixdyn A, matrixdyn B);
	friend matrixdyn operator * (matrixdyn A, matrixdyn B);
};