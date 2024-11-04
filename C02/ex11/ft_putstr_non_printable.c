#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_convert_hexa(unsigned char c)
{
	char	*hexabase;

	hexabase = "0123456789abcdef";
	if (c / 16 > 0)
	{
		ft_putchar(hexabase[c / 16]);
		ft_putchar(hexabase[c % 16]);
	}
	else
	{
		ft_putchar('0');
		ft_putchar(hexabase[c]);
	}
}

void	ft_putstr_non_printable(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
		{
			ft_putchar('\\');
			ft_convert_hexa(str[i]);
		}
		else
		{
			ft_putchar(str[i]);
		}
		i++;
	}
}

int main(void)
{
	char str1[] = "Coucou\ntu vas bien ?";
	char str2[] = "Hello\x1FWorld!";
	char str3[] = "PrintableOnly";

	ft_putstr_non_printable(str1);
	printf("\n");

	// printf("Output 2: ");
	ft_putstr_non_printable(str2);
	printf("\n");

	// printf("Output 3: ");
	ft_putstr_non_printable(str3);
	printf("\n");
}
