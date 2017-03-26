##### Exercise 6.1 What is the declaration of an untagged structure containing two ints called a and b?
```
struct {
	int a, b;
};
```

##### Exercise 6.2. Why is such a declaration of limited use?

Unless we affix an initialisation to a variable directly after the closing brace, it can't be referenced therefore can't be used.

##### Exercise 6.3. What would the structure look like with a tag of int_struc and two variables called x and y of the structure type being defined?

```
struct int_struc {
...
}x,y;
```

##### Exercise 6.4. How would you declare a third variable later, with the the same type as x and y but called z?

`struct int_struc z;`

##### Exercise 6.5. Assuming that p is the right type of pointer, how would you make it point to z and then set z.a to zero, using the pointer?

```
p = &z;
p->a = 0;
```

##### Exercise 6.6. What are the two ways of declaring a structure with incomplete type?
Normally via `struct int_struc;` or even by mentioning it another struct e.g. as a pointer.

##### Exercise 6.7. What is unusual about a string "like this" when it's used to initialize a character array?

It doesn't store a char string literal, it is really like a shortcut method for { 'l', 'i', 'k', 'e'... }. Each character is able to be modified after initialisation.

##### Exercise 6.8. What if it initializes a char *?

This creates a pointer to an unnamed, immutable char array with static storage. So we can't just go around changing any individual character we like CAN WE.