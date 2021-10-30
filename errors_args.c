

#include "pushswap.h"

int check_is_not_empty(char *string)
{
    int i;

    i = 0;
    while (string[i])
    {
        if (ft_isdigit(string[i] != 0))
            return(1);
        i++;
    }
    return (0);
}
int errors_args(char **argv)
{
    int m;
    int i;

    i = 0;
    m = 1;
    while (argv[m])
    {
        while (argv[m][i])
        {
            if(!(argv[m][i] == '-' && ft_isdigit(argv[m][i + 1]) || ft_isdigit(argv[m][i])))
                return(1);
            else if (!(ft_isdigit(argv[m][i])))
                return (1);
            i++;
        }
        m++;
    }
    return (0);
}
int error_string(char **argv)
{
    int m;
    int i;

    i = 0;
    m = 1;
    while (argv[m][i] == '-' ||  argv[m][i] == ' ' || ft_isdigit(argv[m][i]) != 0)
    {
        if(argv[m][i] == '-' && ft_isdigit(argv[m][i + 1]) == 0)
            return(1);
        else if (argv[m][i] == ' '  && ft_isdigit(argv[m][i + 1] == 0))
            return (1);
        i++;
    }
    if(ft_isdigit(argv[m][i]) == 0 && argv[m][i] != '\0')
        return(1);
    return (0);
}
int check_not_error(int argc, char **argv)
{
    if (argc != 2)
    {   
        if (errors_args(argv) == 1)
            return(1);
    }
    else if (argc == 2)
    {
        if (check_is_not_empty(&argv[1][0]) == 0)
            return (1);
        else if (error_string(argv) == 1)
            return(1);
    }
    return(0);
}
int main(int argc, char **argv)
{
    int a;

    a = check_not_error(argc,argv);
    if( a == 1)
        printf("ERROR");
    else
        printf("NICE NIGGA");
    return (0);
}