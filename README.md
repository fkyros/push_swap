# push\_swap

ordering numbers with two stacks and limited special operations

## k-sort & chamber algorithm

tl;dr
0. parse (keep in mind the quotes on the numbers!!!!)
1. sort (ie. merge or insertion, idk, here the complexity is not important lol)
2. number indexing with the sorted array
3. k-sort
	- separate numbers into chunks from a to b
	- restore the numbers separated from b to a

first, we'll need to sort the numbers previously
why? to get the index of each number in the ordered array
at first it may seem against the purpose of the project, but here we aint measuring how effective you are, but how can you escape the limitations of what is being measured
