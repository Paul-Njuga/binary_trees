#include <math.h>
#include "binary_trees.h"

/**
 * binary_tree_height - Function that measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure height
 *
 * Return: Height of the binary tree
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
 * binary_tree_size - Function that measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: Size of the binary tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (!tree)
		return (0);

	size = binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1;

	return (size);
}

/**
 * binary_tree_leaves - function that counts the leaves in a binary tree
 * @tree: Pointer to the root node of the tree to count the number of leaves
 *
 * Return: Number of leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	leaves = binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right);

	return (leaves);
}

/**
 * _pow_recursion - returns the value of x raised to the power of y
 * @x: the value to exponentiate
 * @y: the power to raise x to
 *
 * Return: x to the power of y
 */

int _pow_recursion(int x, int y)
{
	if (y == 0)
		return (1);
	return (x * _pow_recursion(x, y - 1));
}

/**
 * binary_tree_is_perfect - Function that checks,
 * if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is perfect,
 * 0 if tree is not perfect,
 * 0 if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int nodes, height, leaves;

	if (!tree)
		return (0);

	height = (int)binary_tree_height(tree);
	nodes = (int)binary_tree_size(tree);
	leaves = (int)binary_tree_leaves(tree);

	/**
	 * Properties of perfect binary tree used as assumptions:
	 * Total no. of leaves = no. of non-leaf nodes + 1
	 * The total no. of leaves = 2^height
	 */
	if ((leaves == _pow_recursion(2, height)) &&
		(leaves == ((nodes - leaves) + 1)))
		return (1);
	return (0);
}
