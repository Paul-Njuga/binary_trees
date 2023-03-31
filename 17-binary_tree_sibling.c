#include "binary_trees.h"

/**
 * binary_tree_sibling - Function that finds the sibling of a node
 * @node: Pointer to the node to find the sibling
 *
 * Return: Pointer to the sibling node,
 * NULL if node or parent is NULL,
 * NULL if node has no sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *left_child, *right_child;

	if (!node || !node->parent)
		return (NULL);

	left_child = node->parent->left;
	right_child = node->parent->right;

	if (left_child && left_child != node)
		return (left_child);
	else if (right_child && right_child != node)
		return (right_child);
	return (NULL);
}
