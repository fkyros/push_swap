# push\_swap

ordering numbers with two stacks and limited special operations

## visualize

```
python3 pswapviz.py -p ./push_swap -s 247
```

//TODO: add a gif

## check it

this wonderful line will get you 500 numbers (or as much as you want by changing the `tail` parameter) randomly sorted
```
seq -1000 1000 | sort -R | tail -n 500 | tr '\n' ' '
```

throw it to the ckecher and get your own tester every time (s/o to psapio-)
```
ARG=$(seq -1000 1000 | sort -R | tail -n 500 | tr '\n' ' '); ./push_swap $ARG | ./checker_linux $ARG
```

you can always test it with the [psegura-](https://github.com/PepeSegura/push_swap_Tester) tester which is also fire as well

also you can check how long it lasts an execution with the `time` command (if u into that idk)
```
time ./push_swap 3 2 1
```

# how to survive this project

**patience, gdb and valgrind** will be your best friends here

also this [webpage](https://42-cursus.gitbook.io/guide/rank-02/push_swap/building-the-thing) to check all your corner cases

## yea, k-sort algorithm

tl;dr
0. parse (keep in mind the quotes on the numbers!!!!)
1. sort at start (ie. merge or insertion, idk, here the complexity is not important lol)
2. number indexing with the sorted array
3. if the amount of numbers is small (3 or 5), just sort it with something more efficient
4. if not, then k-sort
	- separate numbers into chunks from a to b made up by ranges
	- restore the numbers separated from b to a

easy right? well, get ready

### step 0

make sure the user (or you after a few days of trying to forget this awful project) doesn't mess up the input he gives:
- [ ] he cannot place a number above MAX\_INT or below MIN\_INT
- [ ] when a number is malformed (ie. 3a2), make sure your atoi gives you an error you can check and discard this "number"
- [ ]

### step 1 & 2

first, we'll need to sort the numbers before sorting it with the push\_swap stack movements
why? to get an index of each number in the ordered array. this index is an unsigned int that tells us easly where is this number supposed to be on the stack.
at first it may seem against the purpose of the project, but here we are not measuring how effective you are, but how can you escape the limitations of what is being measured (stack movements)

### step 3

sorting for an small amount of values

for 3 numbers:
get a piece of paper and draw all the possible permutations of 3 numbers. yep, not many cases, and they can be solved with just one or two movements in place.
//TODO: add a pic

for 5 numbers:
we will take advantage of the precious 3 number sorting algorithm we already made
we'll dispatch to the stack b all the numbers that have an index greater or equal than 3, sort the stack a and then transfer properly the 2 remaining values

### step 4

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

## bonus

if you get this down bad, you have nothing to loose. the world is yours, even if you have less than a week of runaway (BH days). lets get down to it.

we will have to create our own checker.


