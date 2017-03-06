##### Exercise 3.1. What is the type and value of the result of the relational operators? and Exercise 3.2. What is the type and value of the result of the logical operators ( &&, ||, and ! )?
The type and value of the result of all relational *and* logical operators are ints. 'False' is a `0` value. 'True' is a not `1` value.

##### Exercise 3.3. What is unusual about the logical operators?
They shortcurcuit. Also you have to be careful about their precedence. I believe || is evaluated before && but shit I could be wrong.

##### Exercise 3.4. Why is break useful in switch statements?
Because switch statements evaluate all switch statement expressions downstream until they hit a break statement.

##### Exercise 3.5. Why is continue not very useful in switch statements?
Continue isn't useful in switch statements because... because I don't think you can even use them in switch statements. Yes just confirmed. They would breakout of a loop enclosing the switch statement though.

##### Exercise 3.6. What is a possible problem using continue in while statements?

There is no loop to break out of.

##### Exercise 3.7. How can you jump from one function to another?

Using goto. But you should really use this only with absolute confidence. For one, it makes it difficult to debug as you can't track that stack so neatly.