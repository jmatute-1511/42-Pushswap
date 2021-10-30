
#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct s_stack
{
    int     content;
    struct  s_stack *next;
}              t_stack;
#endif