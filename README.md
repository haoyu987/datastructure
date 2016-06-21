# datastructure
github markdown
https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet
# tree
## traversal
inorder left,root,right

preorder root,left,right

postorder left,right,root

https://en.wikipedia.org/wiki/Tree_traversal#Post-order

http://www.geeksforgeeks.org/618/

## leaf
if !node->left && !node->right is true, then the node is a leaf.

## BFS
Why would we use BFS? For example, in some situations the same value might
appear as a datum more than once in the tree, and we want to find the shortest path from the root node to
a node containing that datum. To do that, we have to look at nodes near the root before looking at nodes
far away from the root.
Another example is a game-strategy program that generates a tree of moves. The root node is the initial
board position; each child is the result of a legal move I can make; each child of a child is the result of a legal
move for my opponent, and so on. For a complicated game, such as chess, the move tree is much too large to
generate in its entirety. So we use a breadth-first technique to generate the move tree up to a certain depth
(say, ten moves), then we look for desirable board positions at that depth. (If we used a depth-first program,
we’d follow one path all the way to the end of the game before starting to consider a different possible first
move.)

# hashtable
##c++
unordered_set

http://www.cplusplus.com/reference/unordered_set/unordered_set/

unordered_map

http://www.cplusplus.com/reference/unordered_map/

map erase returns the number of elements erased. 0 for non-existing key.

http://en.cppreference.com/w/cpp/container/map/erase
