#!/usr/bin/python3
"""Island perimeter."""


def island_perimeter(grid):
    """Return the perimiter of the island described in grid.

    The grid represents water zone by 0 and land zone by 1.

    Args:
        grid (list): A list of list of integers.
    Returns:
        The perimeter of the island defined in grid.
    """
    width = len(grid[0])
    height = len(grid)
    edges = 0
    size = 0

    for n in range(height):
        for j in range(width):
            if grid[n][j] == 1:
                size += 1
                if (j > 0 and grid[n][j - 1] == 1):
                    edges += 1
                if (n > 0 and grid[n - 1][j] == 1):
                    edges += 1
    return size * 4 - edges * 2
