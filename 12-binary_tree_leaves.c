#include "binary_trees.h"

/**
 * binary_tree_leaves - function that counts the leaves in a binary tree
 * @tree: Pointer to the root node of the tree to count the number of leaves
 *
 * Return: Number of leaves
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if ()
		return (0);

	if (!tree || (!tree->left && !tree->right))
		return (1);

	leaves = binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right);

	return (leaves);
}
