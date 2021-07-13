#include "basic.h"
#include <stdio.h>
struct FenShu
{
	UINT p, q;

	bool neg;

	void Correct()
	{
		unsigned int t = ZuiDaGongYueShu(p, q);
		p /= t;
		q /= t;
	}

	void FromDouble(double x)
	{
		if (x < 0)
			neg = true;

		q = 1;
		while (int(x) != x)
		{
			x *= 10;
			q *= 10;
		}
		Correct();
	}

	double ToDouble()
	{
		return 1.0 * p / q * (neg ? -1 : 1);
	}

  void Print()
  {
    printf("%d / %d" ,p ,q);

  }
};

void TongFen(FenShu &x, FenShu &y)
{
	UINT ZXGBS = ZuiXiaoGongBeiShu(x.q, y.q);
	x.p = x.p * ZXGBS / x.q;
	y.p = y.p * ZXGBS / y.q;
	x.q = ZXGBS;
	y.q = ZXGBS;
}

FenShu operator+ (FenShu, FenShu);
FenShu operator- (FenShu, FenShu);
FenShu operator* (FenShu, FenShu);
FenShu operator/ (FenShu, FenShu);

void operator+= (FenShu&, FenShu);
void operator-= (FenShu&, FenShu);
void operator*= (FenShu&, FenShu);
void operator/= (FenShu&, FenShu);

bool operator> (FenShu, FenShu);
bool operator< (FenShu, FenShu);
bool operator>= (FenShu, FenShu);
bool operator<= (FenShu, FenShu);
bool operator== (FenShu, FenShu);
bool operator!= (FenShu, FenShu);


void operator+=(FenShu& x, FenShu y)
{
	TongFen(x, y);
	x.p += y.p;
	x.Correct();
}

void operator-=(FenShu& x, FenShu y)
{
	TongFen(x, y);
	x.p -= y.p;
	x.Correct();
}

void operator*=(FenShu& x, FenShu y)
{
	TongFen(x, y);
	x.p *= y.p;
	x.Correct();
}

void operator/=(FenShu& x, FenShu y)
{
	TongFen(x, y);
 	x.q = y.p;
	x.Correct();
}


bool operator>(FenShu x, FenShu y)
{
	TongFen(x, y);
	return (x.neg ? -1 : 1) * x.p > (y.neg ? -1 : 1) * y.p;
}

bool operator<(FenShu x, FenShu y)
{
	TongFen(x, y);
	return (x.neg ? -1 : 1) * x.p < (y.neg ? -1 : 1) * y.p;
}

bool operator>=(FenShu x, FenShu y)
{
	TongFen(x, y);
	return (x.neg ? -1 : 1) * x.p >= (y.neg ? -1 : 1) * y.p;
}

bool operator<=(FenShu x, FenShu y)
{
	TongFen(x, y);
	return (x.neg ? -1 : 1) * x.p <= (y.neg ? -1 : 1) * y.p;
}

bool operator==(FenShu x, FenShu y)
{
	TongFen(x, y);
	return (x.neg ? -1 : 1) * x.p == (y.neg ? -1 : 1) * y.p;
}

bool operator!=(FenShu x, FenShu y)
{
	TongFen(x, y);
	return (x.neg ? -1 : 1) * x.p != (y.neg ? -1 : 1) * y.p;
}

FenShu operator+(FenShu x, FenShu y)
{
	x += y;
	return x;
}

FenShu operator-(FenShu x, FenShu y)
{
	x -= y;
 	return x;
}

FenShu operator*(FenShu x, FenShu y)
{
	x *= y;
 	return x;
}

FenShu operator/(FenShu x, FenShu y)
{
	x /= y;
	return x;
}
