##### Exercise 2.1-2.2 Why are trigraphs used? When would you expect to find them in use, and when not?
Trigraphs are used on systems where the standard ANSII (ISO 646) set of 96 7-bit characters are used or otherwise lack any of the additional 9 characters used by C. A trigraph consists of two `?` characters followed by an ANSII symbol to represent these characters. The map is defined in the C standard. They should only be used where the environment demands it. In 2017, I doubt that is anywhere.

##### Exercise 2.3. When is a newline not equivalent to a space or tab?

A newline is not equivalent to a space or tab in preprocessor command lines & when preceded by a backslash (which the compiler ignores both altogether).

##### Exercise 2.4-2.5. When would you see the sequence of ‘backslash newline’ in use? What happens when two strings are put side by side?

When the programmer wants to break a line up, though in the case of two sequential strings separated by blank space the two strings will be treated as one.

##### Exercise 2.6. Why can't you put one piece of comment inside another one? (This prevents the technique of ‘commenting out’ unused bits of program, unless you are careful.)

Because the opening of the internal comment will be treated as a piece of comment but the closing will be treated as a close.

##### Exercise 2.7. What are the longest names that may safely be used for variables?

Ok so this has changed as predicted it would in the text. 63 for internal identifiers or 31 for external identifiers.

##### Exercise 2.8. What is a declaration?

Unsure of rules yet. From my own observation, a declaration declares an identifier and it's type but not the substance (e.g. the body of the function or the value to be assigned to a variable).

##### Exercise 2.9. What is a definition?

A definition assigns a value to a declaration.

##### Exercise 2.10. Which type of variable can hold the largest range of values?

Of the three real (floating-point) types defined in C89, a long double.

##### Which type of variable can store values to the greatest precision?

Also a long double.

##### Exercise 2.12. Are there any problems possible when assigning a float or double to a double or long double?

Nope, implicit conversion to higher precision values baby.

##### Exercise 2.13. What could go wrong when assigning, say, a long double to a double?

A loss of precision at best, undefined behaviour at worst. If you want portability, stability and predictability, don't be assigning high precision float values to low precision floats.

##### Exercise 2.14. What predictions can you make about a program showing ‘undefined behaviour’?

Not a fuck of a lot m80.