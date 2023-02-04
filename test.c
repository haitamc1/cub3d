#include <stdio.h>
# define PI 3.14159265359

int main()
{
	double i;
	int	j;

	j = 0;
	i = -(PI / 6);
	while (i < (PI / 6))
	{
		j++;
		i += 0.0017452;
	}
	printf("%d", j);
}