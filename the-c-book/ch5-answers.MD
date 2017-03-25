##### Exercise 5.1 What is the valid range of indices for an array of ten objects?

0-9

##### Exercise 5.2 What happens if you take the address of the 11th member of that array?
You can use its address as a pointer reference for bounds checking. The Standard will guarantee element `n` in a `arr[n]` array is accessible, but its value will most likely give undefined behaviour.

##### Exercise 5.3 When is it valid to compare the values of two pointers?
It is valid to compare the values of two pointers when they both point into the same array. You can compare with a direct equality comparison operator with other types too - to check if pointers point to the same value.

##### Exercise 5.4. What is the use of a pointer to void?
If you're expecting a valid pointer but can't return one, for example, you can return a null pointer in its place. You can assign it to any pointer variable and it is guaranteed not to point to any real object.

##### Exercise 5.6 Explain the examples using malloc to somebody else.

Malloc returns the pointer i.e. a typed reference to a memory address to available memory with the byte size specified by its arguments.