/**
 *  This is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * trial is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with trial.  If not, see <http://www.gnu.org/licenses/>.
 *
 * \file tree.h
 * \author KDuncan
 */
#pragma once
#ifndef KD_TRIAL_TREE_H_
#define KD_TRIAL_TREE_H_

namespace kd
{
    /*
     * Red-Black Tree (balanced binary tree)
     *
     * Properties:
     *  1. Every node has a color, either red or black
     *  2. The root of the tree is always black.
     *  3. There are no two adjacent red nodes. Therefore, a red node can't have a red parent or red child.
     *  4. Every path from the root node to a leaf node (NULL node) has the same number of black nodes.
     *
     * The height of a red black tree is always O(logN)
     * Red-Black Tree Operations:
     *  o insert
     *  o search
     *  o remove / delete
     *  o max / min
     *  o getList
     *
     * Site List:
     *  o https://www.topcoder.com/community/data-science/data-science-tutorials/an-introduction-to-binary-search-and-red-black-trees/
     *  o http://code.geeksforgeeks.org/NtLnIk
     *  o http://www.geeksforgeeks.org/red-black-tree-set-1-introduction-2/
     *  o https://gist.github.com/mgechev/5911348
     *  o 
     */
}


#endif /* KD_TRIAL_TREE_H_ */
