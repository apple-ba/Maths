#include"basic.h"

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
};

FenShu operator+(FenShu x, FenShu y)
{
	FenShu ans;

	ans.q = ZuiXiaoGongBeiShu(x.q, y.q);
	ans.p = x.p * ans.q + y.p * ans.q;
	ans.Correct();

	return ans;
}

