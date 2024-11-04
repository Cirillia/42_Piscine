#include <unistd.h>
#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ('A' <= str[i] && str[i] <= 'Z')
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
	char	*str1 = "HELLO";
	char	*str2 = "Hello World!";
	char	*str3 = "HELLO!";
	char	*str4 = "HI345";
	char	*str5 = "";

	if (ft_str_is_uppercase(str2)) 
	{
		printf("'%s' 1 \n", str2);
	} 
	else 
	{
		printf("'%s' 0 \n", str2);
	}
}
