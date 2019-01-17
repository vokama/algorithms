#include<stdio.h>
#include<math.h>


unsigned long mno (unsigned long x)  //picks one of all possible factorizations of x so that sum of digital roots of its elements is the biggest one
{
	unsigned long i, result = 0;
	unsigned p = 0, Mas[6] = {2, 4, 5, 6, 7, 8}, f2 = 0, f3 = 0, f4 = 0;

/* if digital root of x is equal to 9 or 3 then x divides by 9 or 3 respectively */
	while(x % 9 == 0)
	{
		x /= 9;
		result += 9;
	}
	if(x % 3 == 0)  //it could happen only once or not at all since we already divided it by 9
	{
		x /= 3;
		result += 3;
		f3++;
	}

	for(i = 0; i + 2 <= x ; i += 9)
	{
		for(p = 0; p < 6; p++)
		{
			while(x % (i + Mas[p]) == 0)
			{
				x /= (i + Mas[p]);
				result += Mas[p];
				if(p == 0)
					f2++;
				else if(p == 1)
					f4++;
			}
		}
	}
	for(i = 10; x > 1; i = i + 9)
	{
		while(x % i == 0)
		{
			x /= i;
			result += 1;
		}
	}

	while(f4 > 0 && f2 > 0)
	{
		result += 2;
		f2--;
		f4--;
	}
	while(f2 >= 3)
	{
		result += 2;
		f2 -= 3;
	}
	if(f3 && f2)
	{
		result += 1;
		f3--;
		f2--;
	}

	return result;
}

int main ()
{
	unsigned long i;

	scanf("%lu", &i);
	printf("%lu\n", mno(i));

	return 0;
}
