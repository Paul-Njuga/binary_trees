#include "binary_trees.h"

/**
 * binary_tree_depth - Function that measures the depth of a binary tree
 * @tree: Pointer to the node to measure depth
 *
 * Return: Depth of the binary tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree)
		return (0);

	while (tree->parent)
	{
		depth++;
		tree = tree->parent;
	}

	return (depth);
}
