#include <unistd.h>
#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (32 <= str[i] && str[i] <= 127)
		{
			i++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}

int	main(void)
{
	char	*str1 = "€";
	char	*str2 = "Hello World!";
	char	*str3 = "123Hello";
	char	*str4 = "12345";
	char	*str5 = "";

	if (ft_str_is_printable(str1)) 
	{
		printf("'%s' 1 \n", str1);
	} 
	else 
	{
		printf("'%s' 0 \n", str1);
	}
}
