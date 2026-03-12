*This project has been created as part of the 42 curriculum by inaciri & ffeder*


**DESCRIPTION**

    This project is the setup of my first server by following specific rules.

* 	PROJECT DESCRIPTION

    	The push_swap programme sorts the given numbers in ascending order with as few operations as possible. To sort them, they have two stacks in which the numbers can be manipulated, using three operations. The push command moves the number at the top of stack 1 to the top of stack 2. The swap command swaps the first and second numbers in the selected stack. The rotate command moves all numbers up by one, so that the first number ends up last. There are variations on these operations, such as reverse_rotate, which works in the same way but in reverse, or ss, which swaps stacks 1 and 2 at the same time.

		Thanks to these operations, sorting algorithms are performed with the aim of reorganising the numbers in stack 1 in as few steps as possible. There are therefore three algorithms adapted to the level of disorder and the size of the given list of numbers. The simple algorithm is effective with small numbers, but beyond 25 items, the number of operations increases exponentially. The medium algorithm, which is slightly less efficient than the simple one on small lists of numbers, becomes relevant when the simple one no longer works. The complex algorithm is precise and has a tighter range of moves. It will never make a small number of moves, but even in poor conditions it will remain stable.

**INSTRUCTIONS**
	
*	Makefile commands :

	* make run : Launch the programme with random numbers. Set the desired number of items by changing the last number.

	* make re : deletes the .o files and recompiles the programme with the latest changes.

*	Push_swap commands :

		* main command : ./push_swap 

		* --simple : This command forces the use of the simple algorithm.

		* --medium : This command forces the use of the medium algorithm.

		* --complex : This command forces the use of the complex algorithm.

		* --adaptive :  This command forces the programme to choose which of the algorithms will make the fewest moves.

		* --benchmark : This command provides details on sorting, the number of pushes, swaps, and rotations.




**RESOURCES**

	https://web.maths.unsw.edu.au/~lafaye/CCM/c/cliste.htm
	https://www.geeksforgeeks.org/dsa/bucket-sort-2/
	https://openclassrooms.com/fr/courses/19980-apprenez-a-programmer-en-c/19733-stockez-les-donnees-avec-les-listes-chainees
	http://sdz.tdct.org/sdz/les-listes-doublement-chainees-en-langage-c.html
