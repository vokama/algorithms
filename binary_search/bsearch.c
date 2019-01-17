int bsearch(int *buf, int n, int x)  //buf is the pointer to an array, n is the number of elements
{
	int k;

	if(x >= buf[n - 1])
		k = -1;
	else
	{
		if(x < buf[n / 2])
		{
			if(n < 3)
			{
				if(x < buf[0])
					k = 0;
				else
					k = 1;
			}
			else
				k = bsearch(buf, n / 2 + 1, x);
		}
		else
			k = bsearch(buf + n / 2 + 1, (n - 1) / 2, x) + n / 2 + 1;
	}

	return k;
}
