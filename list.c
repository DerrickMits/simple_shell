#include "shell.h"

/**
 * add_node - Adds a new node at the beginning of a linked list.
 * @head: Pointer to the head of the linked list.
 * @s: String to be stored in the new node.
 * @num: Integer to be stored in the new node.
 *
 * This function creates a new node with the given string and number,(Adds)
 * at the beginning of the linked list pointed to by 'head'.
 *
 * Return: A pointer to the newly created node, or NULL on failure.
 */


list_t *add_node(list_t **head, const char *s, int num)
{
list_t *new_node = (list_t *)malloc(sizeof(list_t));
if (!new_node)
{
return NULL;
}
new_node->str = strdup(s);
if (!new_node->str)
{
free(new_node);
return NULL;
}
new_node->number = num;
new_node->next = *head;
head = new_node;
return new_node;
}

/**
 * add_node_end - Adds a new node at the end of a linked list.
 * @head: Pointer to the head of the linked list.
 * @s: String to be stored in the new node.
 * @num: Integer to be stored in the new node.
 *
 * This function creates a new node with the given string and number,(adds)
 * at the end of the linked list pointed to by 'head'.
 *
 * Return: A pointer to the newly created node, or NULL on failure.
 */

list_t *add_node_end(list_t **head, const char *s, int num)
{
list_t *new_node = (list_t *)malloc(sizeof(list_t));
if (!new_node)
{
return NULL;
}
new_node->str = strdup(s);
if (!new_node->str)
{
free(new_node);
return NULL;
}
new_node->number = num;
new_node->next = NULL;
if (*head == NULL)
{
*head = new_node;
}
else
{
list_t *current = *head;
while (current->next != NULL)
{
current = current->next;
}
current->next = new_node;
}
return (new_node);
}

/**
 * print_list_str - Prints the content of a linked list of strings and numbers.
 * @head: Pointer to the head of the linked list.
 *
 * This function prints the strings and numbers stored in each node
 *
 * Return: The number of nodes in the linked list.
 */

size_t print_list_str(const list_t *head)
{
size_t count = 0;
while (head)
{
printf("%s, %d\n", head->str, head->number);
head = head->next;
count++;
}
return (count);
}

/**
 * delete_node_at_index - Deletes a node at a specified index in a linked list.
 * @head: Pointer to the head of the linked list.
 * @index: Index of the node to be deleted.
 *
 * This function deletes the node at the specified index in the linked list.
 *
 * Return: 0 on success, -1 on failure.
 */

int delete_node_at_index(list_t **head, unsigned int index)
{
if (!head || !(*head))
{
return (-1);
}
list_t *current = *head;
if (index == 0)
{
*head = current->next;
free(current->str);
free(current);
return (0);
}
for (unsigned int i = 0; current->next && i < index - 1; i++)
{
current = current->next;
}
if (!current->next)
{
return (-1);
}
list_t *temp_node = current->next;
current->next = temp_node->next;
free(temp_node->str);
free(temp_node);
return (0);
}

/**
 * free_list - Frees the memory allocated for a linked list.
 * @head: Pointer to the head of the linked list.
 *
 * This function frees the memory allocated for each node in the linked list.
 */

void free_list(list_t **head)
{
list_t *current;
while (*head)
{
current = *head;
*head = (*head)->next;
free(current->str);
free(current);
}
}
