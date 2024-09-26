# push\_swap

ordering numbers with two stacks and limited special operations

## yea, k-sort algorithm

tl;dr
0. parse (keep in mind the quotes on the numbers!!!!)
1. sort at start (ie. merge or insertion, idk, here the complexity is not important lol)
2. number indexing with the sorted array
3. if the amount of numbers is small, just sort it with something more efficient
3. if not, then k-sort
	- separate numbers into chunks from a to b made up by ranges
	- restore the numbers separated from b to a

### step 1

first, we'll need to sort the numbers previously
why? to get the index of each number in the ordered array
at first it may seem against the purpose of the project, but here we are not measuring how effective you are, but how can you escape the limitations of what is being measured (stack movements)

### step 2

after, we will sort the numbers according to those indexes
we will place them properly on stack b according to if they fit on the range

the range has to be proportionate to the size of the stack
here, we calculate it as the square root of the size of the stack times 1.4
why? you may ask
the factor 1.4 seems arbitrary to everyone (it is) but responds to
- optimization for larger number sets
- balanced rotations: to minimize push\_swap movements
(thanks chatgpt)



whenever a value is on the range from 0,i then
if its on the other, then ...
-> CHECK!!!

counting execution time
```
time ./push_swap 3 2 1
```
