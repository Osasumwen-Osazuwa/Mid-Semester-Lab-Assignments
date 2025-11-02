CSC-301 Data Structures Lab Exercise

Analytical Minds Group
Osasumwen Osazuwa: 
Daniel Igwe:
Emmanuella:
Joseph Inaku:
Emmanuel:


QUESTION 1: Implementing a Custom Linked List
	
Objective
To implement and test a custom singly linked list with proper memory management and error handling.

Algorithm
1.	Initialize an empty linked list with the head pointer set to NULL
2.	Define the node structure with each node containing an integer data field and a pointer to the next node
3.	Implement a function to insert a new node at the beginning of the list
4.	Implement a function to insert a new node at the end of the list.
5.	Implement a function to insert a new node at a given position
6.	Implement a function to delete a node by value
7.	Implement a function to delete a node by position
8.	Implement a function to display all nodes in the list
9.	Test the program with at least three sets of input data, including error handling for deletion from empty lists.
10.	Stop the program

Sample Output








Brief Explanation
Memory management in a singly linked list is handled dynamically through the use of pointers. Each node is created and allocated memory during program execution. Every node holds a data field and a pointer to the next node, forming a chain-like structure. This allows insertion and deletion operations without requiring contiguous memory blocks. When a new node is inserted, pointer references are updated to include the new element thereby modifying the list. When a node is deleted, the ‘delete’ operator is used to reassign links to bypass its target node and deallocate its memory. Linked lists adapt to varying data sizes without reallocation, eliminating the need for predefined size and reducing memory wastage. Sequential traversal through pointers makes access time slower but ensures proper memory utilization and adaptability for applications that require frequent modification of data.

Conclusion
The custom singly linked list was successfully implemented using C++, allowing insertion, deletion and display operations. Each operation was tested with three different data sets, proving that the linked list handles dynamic memory and supports frequent modification of data.


QUESTION 2: Solving Problems Using Recursion

Objective
To implement recursion in solving computational problems like calculating factorials, generating Fibonacci sequences, reversing strings and performing binary search operations on sorted arrays.

Algorithm
1.	Factorial calculation
- Start
- If n  <=  1 , return 1 (base case)
- Otherwise, return n  *  factorial(n  -  1) (recursive case)
- End
2.	Fibonacci sequence
- Start
- If n  ==  0 , return 0; if n  ==  1 , return 1 (base cases)
- Otherwise, return fibonacci(n  -  1)  +  fibonacci(n  -  2) (recursive case)
- End
3.	String reversal
- Start
- If string length ≤ 1 return the string (base case)
- Otherwise return reverse(substring from index 1)  +  first character (recursive case)
- End
4.	Binary search
- Start
- If left  > right , return -1 (element not found)
- Compute mid  =  left  +  right / 2
- If arr[mid]  ==  target , return mid
- If target  <  arr[mid] , recursively search in the left sub array
- Else, recursively search in the right subarray
- End


Summary

Recursion is when a function calls itself to solve smaller sub-problems until a base case is reached and iteration is the process of repeatedly executing a set of instructions until a condition is met. Both techniques are widely used for problem-solving in programming. 
There are two fundamental elements of recursion: a recursive case and a base case. When the recursive case is reached, the function is broken down into smaller sub-problems and calls itself. This process repeats itself until the base case is reached which defines when the recursion should stop and prevents infinite repetition. Recursion offers numerous advantages such as simplicity and readability. Iteration, on the other hand, uses loops like for and while to automate repetitive tasks. It is memory efficient, safe for large input and generally faster since it doesn’t require repeated function calls. 
While both methods are effective, recursion is preferred for various problems such as divide-and-conquer algorithms (like quick sort and binary search,) problems defined naturally recursively (like factorial and Fibonacci) and hierarchical or nested structures (like trees and graphs).

Conclusion

Computational problems like calculating factorials, generating Fibonacci sequences, reversing strings and performing binary search operations on sorted arrays were successfully solved using recursion. These problems were broken down into smaller, simpler sub-problems until the base case was reached.
