#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
/**
 * is_palindrome - check if linked list is a palindrome
 * @head: pointer to pointer to head of the list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *temp = *head;
	int size = sizeof(int);
	int i = 1;
	int left = 0;
	int right = i - 1;
	int *arr = malloc(100000 * sizeof(int));

	arr[0] = (*head)->n;

	if (*head == NULL)
		return (1);

	temp = temp->next;

	while (temp != NULL)
	{
		size += sizeof(int);
		arr = realloc(arr, size);
		arr[i] = temp->n;
		i++;
		temp = temp->next;
	}
	for (; left < right; left++, right--)
	{
		if (arr[left] != arr[right])
			return (0);
	}
	return (1);
}

/**
  * get_nodeint_at_index - Gets a node from a linked list
  * @head: The head of the linked list
  * @index: The index to find in the linked list
  *
  * Return: The specific node of the linked list
  */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *current = head;
	unsigned int iter_times = 0;

	if (head)
	{
		while (current != NULL)
		{
			if (iter_times == index)
				return (current);

			current = current->next;
			++iter_times;
		}
	}

	return (NULL);
}

/**
  * slistint_len - Counts the number of elements in a linked list
  * @h: The linked list to count
  *
  * Return: Number of elements in the linked list
  */
size_t listint_len(const listint_t *h)
{
	int lenght = 0;

	while (h != NULL)
	{
		++lenght;
		h = h->next;
	}

	return (lenght);
}
