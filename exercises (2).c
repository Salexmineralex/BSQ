//ESCRIBIR AL REVÉS EL STRING 
#include <unistd.h>
int main(int argc, char **argv)
{
    int i;
    int j;
    
    i = 0;
    if (argc == 2)
    {
        while (argv[1][i] != '\0')
            i++;
        j = i - 1;
        while (argv[1][j] && j >= 0)
        {
            write(1, &argv[1][j], 1);
            j--;
        }
    }
    write(1, '\n', 1);
}

//SUMAR O RESTAR CADA LETRA 13 POSICIONES 
#include <unistd.h>
int main(int argc, char **argv)
{
    int i;
    
    i = 0;
    if (argc == 2)
    {
        while (argv[1][i] != '\0')
        {
            if (argv[1][i] >= 'a' && argv[1][i] <= 'm'
            || argv[1][i] >= 'A' && argv[1][i] <= 'M')
                argv[1][i] += 13;
            if (argv[1][i] >= 'n' && argv[1][i] <= 'z'
            || argv[1][i] >= 'N' && argv[1][i] <= 'Z')
                argv[1][i] -= 13;
            write (1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, '\n', 1);
}

//BUSCAR Y REMPLAZAR hola 'h' 'b' -> bola
#include <unistd.h>

int ft_strlen(char *str)
{
    while (*str)
        str++
    return (str);
}

int main(int argc, char **argv)
{
    int i;
    
    i = 0;
    if (argc == 3)
    {
        while (argv[1][i] != '\0')
        {
            if (ft_strlen(argv[2]) == 1 && ft_strlen(argv[3]) == 1)
            {
                if (argv[1][i] == argv[2][0])
                    argv[1][i] = argv[3][0];
                write(1, &argv[1][i], 1);    
            }    
            i++;
        }
    }
    write(1, '\n', 1);
}

//REPETIR CARÁCTER SEGUN POSICIÓN EN EL ALFABETO abc -> abbccc
#include <unistd.h>
int main(int argc, char **argv)
{
    int i;
    
    i = 0;
    if (argc == 2)
    {
        while (argv[1][i] != '\0')
        {
            if (argv[1][i] 
        
        
        }
    
    
    }
    write(1, '\n', 1);
}    
    