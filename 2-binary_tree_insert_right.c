#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the left-child of another node
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 *
 * Return: pointer to the new node,
 * or NULL on failure, or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (!parent)
		return (NULL);

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = parent->right;
	parent->right = new;

	if (new->right)
		/*Set new->left as parent of old left */
		new->right->parent = new;
	return (new);
}
