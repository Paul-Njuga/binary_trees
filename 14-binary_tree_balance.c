#include "binary_trees.h"

/**
 * binary_tree_height - Function that measures,
 * the height of a binary tree
 * @tree: Pointer to the root node of the tree,
 * to measure height
 *
 * Return: Height of the binary tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	height_l = tree->left ? binary_tree_height(tree->left) + 1 : 0;
	height_r = tree->right ? binary_tree_height(tree->right) + 1 : 0;

	return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_balance - Function that measures,
 * the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure,
 * the balance factor
 *
 * Return: The balance factor of the binary tree,
 * 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int lh, rh;

	if (!tree)
		return (0);

	lh = tree->left ? (int)binary_tree_height(tree->left) : -1;
	rh = tree->right ? (int)binary_tree_height(tree->right) : -1;

	return (lh - rh);
}
