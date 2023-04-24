<h1 align="center">
	push_swap
</h1>

## About 

This project consists of creating a sorting algorithm that will sort numbers using 2 stacks A & B and using specific movements. It has to print
on the terminal the moves it used to sort the numbers in asceding order.
The possible actions are:

* ```pa``` (push A): Take the first element at the top of B and put it at the top of A. Do nothing if B is empty.
* ```pb``` (push B): Take the first element at the top of A and put it at the top of B. Do nothing if A is empty.
* ```sa``` (swap A): Swap the first 2 elements at the top of stack A. Do nothing if there is only one or no elements.
* ```sb``` (swap B): Swap the first 2 elements at the top of stack B. Do nothing if there is only one or no elements.
* ```ss```: ```sa``` and ```sb``` at the same time.
* ```ra``` (rotate A): Shift all elements of stack A up by 1. The first element becomes the last one.
* ```rb``` (rotate B): Shift all elements of stack B up by 1. The first element becomes the last one.
* ```rr```: ```ra``` and ```rb``` at the same time.
* ```rra``` (reverse rotate A): Shift all elements of stack A down by 1. The last element becomes the first one.
* ```rrb``` (reverse rotate B): Shift all elements of stack b down by 1. The last element becomes the first one.
* ```rrr``` : ```rra``` and ```rrb``` at the same time.

## Implementation

We start by creating two linked lists ```A```, ```B``` and inserting the numbers passed as arguments to ```A```. The arguments are checked to make sure there
is no errors(string rather than numbers, duplicates etc). The progam will then select wich algorithm to use based on ammount of numbers.

Between 2-5 it will do a specific case by case algorithm. This is because for example sorting 2 numbers is only a matter of checking if the first is bigger
than the second , no need to complicate here. Same goes for 3 numbers, it can be sorted with very small moves(check sorter_small).

Between 5-200 we will do a more complex solution. The choice of my algorithm was mix of ```merge``` and ```insert``` sort. This is due to the limitations 
of the moves we are allowed to do. 

The algorithm starts by dividing the numbers into chunks based on its size, starting with the smallest. Each chunk will represent the lowest numbers, (IE if the stack size is 100 it will be the lowest 20).
To do this, i make a copy of the original lists, i order them using a simple algorithm of insert.Once the copy is ordered i travel the list untill i reach the chunk size getting the largest number of the first chunk.

Once we got the ```median``` we begin pushing to B. We repeat this process untill A is empty. Once A is empty we begin pushing back to A using a ```insert``` sort.
Since B is already ordered in chunks of descending order, we only have to sort chunks of n size rather than the whole list. This saves us alot of moves, since
trying to order a list of IE 100 numbers using ```insert``` would result in us ```rr``` several times just to get the number we want to push.

Once numbers are back in A , we simply check to make sure it's in correct order , if not we rotate untill it is.


## Conclusion

This project has taught me the value of properly naming files,functions and variables due to it's complexity. Also looking back at my code
altough it works, its way far from "clean". For example duping the list in order to find the median was completly unecessary and could be done in a much
easyer way. Also due to the "mess" i made, i ended up becaming very confortable with linked list.
