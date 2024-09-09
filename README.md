# push\_swap

ordering numbers with two stacks and limited special operations

## k-sort & chamber algorithm

tl;dr
0. parse (keep in mind the quotes on the numbers!!!!)
1. sort (ie. merge or insertion, idk, here the complexity is not important lol)
2. number indexing with the sorted array
3. k-sort
	- separate numbers into chunks from a to b made up by ranges
	- restore the numbers separated from b to a

### setp 1

first, we'll need to sort the numbers previously
why? to get the index of each number in the ordered array
at first it may seem against the purpose of the project, but here we aint measuring how effective you are, but how can you escape the limitations of what is being measured

### step 2

after, we will sort the numbers according to those indexes
we will place them properly on stack b according to if they fit on the range

the range is made by the square root of the size times 1.4
why? you may ask
the factor 1.4 seems arbitrary to everyone (it is) but responds to
- optimization for larger datasets
- balanced rotations: to minimize push\_swap movements
(thanks chatgpt)


whenever a value is on the range from 0,i then
if its on the other, then ...
-> CHECK!!!
