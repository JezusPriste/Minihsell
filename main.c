#include "minishell.h"

Node* create_node(char *data)
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
        return NULL;
    new_node->data = strdup(data);
    if (new_node->data == NULL)
    {
        free(new_node);
        return NULL;
    }
    new_node->next = NULL;
    return new_node;
}

void insert_last_with_delimiter(Node** head, char *str, char delim)
{
    char **tokens = ft_split(str, delim);
    if (tokens == NULL)
        return;

    int i = 0;
    while (tokens[i])
    {
        Node* new_node = create_node(tokens[i]);
        if (new_node == NULL)
            return;
        if (*head == NULL)
            *head = new_node;
        else
        {
            Node* last = *head;
            while (last->next != NULL)
                last = last->next;
            last->next = new_node;
        }
        i++;
    }
   // free_string_array(tokens);
}

void print_list(Node* head) 
{
    if (head == NULL) {
        printf("La lista è vuota.\n");
    }
    else 
	{
        Node* current = head;
        while (current != NULL) {
            printf("%s -> ", current -> data);
            current = current -> next;
        }
        printf("NULL\n");
    }
}

void parseTokens(Node* head) 
{
    Node* current = head;
    int i = 0;
    while (current != NULL) 
	{
        printf("Token %d: %s\n", i, current -> data);
        current = current -> next;
        i++;
    }
}

void clear_list(Node** head)
{
    Node* current = *head;
    Node* temp = NULL;

    while (current != NULL)
    {
        temp = current;
        current = current->next;
        free(temp->data);
        free(temp);
    }
    *head = NULL;
}

int main()
{
    t_mini mini;
    Node* head = NULL;
    while (1)
    {
        mini.input = readline("Minishell>> ");
        if (mini.input == NULL)
            break;
		insert_last_with_delimiter(&head, mini.input, '||');
        free(mini.input);
    	print_list(head);
    	parseTokens(head);
		clear_list(&head);
		 //questo è dove usi la tua funzione per analizzare la lista concatenata
    }
    printf("La stringa divisa in nodi: \n");
    return (0);
}






/*void analyze_until_pipe(Node* head)
{
    Node* current = head;
    while (current != NULL && strcmp(current->data, "|") != 0)
    {
        // eseguire l'analisi per il contenuto del nodo corrente
        
		
        current = current->next;
    }
}*/