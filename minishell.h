#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <stdlib.h>
# include <string.h>
# include <readline/history.h>
# include "libft/libft.h"
# include <readline/tilde.h>
# include <stdbool.h>

typedef struct Node 
{
    struct Node* next;
    char *data;
    

}   Node;

typedef struct s_mini
{
    char    *input;
    char    **token;

}   t_mini;
/////split 

void print_list(Node *head);
void clear_list(Node** head);

void parseTokens(Node* head);

void insert_last_with_delimiter(Node** head, char *str, char delim);





Node* create_node(char *data);


// static unsigned int	ft_counter(char *s, char c);
// static int	ft_strcheck(char *s, char c);
// void	*ft_cicle(char *s, char **str, char c, unsigned int count);
// char	**ft_split(char *s, char c);


#endif