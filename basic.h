
typedef unsigned int UINT;

UINT ZuiDaGongYueShu(UINT x, UINT y)
{

	while (x % y != 0 && y % x != 0) {
		x %= y;
		if (x % y != 0 && y % x != 0)
			y %= x;
	}

	return x > y ? y : x;
}


UINT ZuiXiaoGongBeiShu(UINT x, UINT y)
{
	return x * y / ZuiDaGongYueShu(x, y);
}

