#include <unistd.h>

int ft_strlen(char *str)
{
	int len;

	len = 0;
    while (str[len] != '\0')
        len++;
    return (len);
}

char	*change(char *str, char letter1, char letter2)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == letter1)
		   str[i] = letter2;
		i++;
	}
	return (str);
}

void ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int main(int argc, char **argv)
{
    int i;
	char *cadena;

    if (argc == 4)
    {
		if (ft_strlen(argv[2]) == 1 && ft_strlen(argv[3]) == 1)
		{
			cadena = change(argv[1], argv[2][0], argv[3][0]);
			i = 0;
			ft_putstr(cadena);
		}
		else
			ft_putstr(argv[1]);
	}
	write(1, "\n", 1);
}
