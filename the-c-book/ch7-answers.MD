##### Exercise 7.1. How would you arrange that the identifier MAXLEN is replaced by the value 100 throughout a program?

`#define MAXLEN 100`

##### Exercise 7.2. What is likely to cause problems in a definition of the form #define VALUE 100+MAXLEN?

Either you don't have `MAXLEN` defined, or you are operating on the value `100+MAXLEN` e.g. if `MAXLEN` is defined in the preprocessor as `100`, you might make the mistake of thinking you are evaluating `100+100` where as in fact you are placing the expression in the code. Depending on its context and the operators that precede and succeed it, the addition might come after each or either `100` has already been used. This can also fuck you through other processor directives and macro funcs. Basically you should parenthesise values.

##### Exercise 7.3. Write a macro called REM which takes two integer arguments and ‘returns’ the remainder when the first is divided by the second.

`#define REM(a,b) ((a) % (b)) // We encapsulate a & b to avoid precedence issues`

##### Exercise 7.4. Repeat the last example, but use casts so that any arithmetic type of argument may be used, assuming that there are no overflow problems.

#define REM(a,b) ((long)(a)%(long)(b))

##### Exercise 7.5. What do the <> brackets around a filename in a #include directive signify?

A library header file.

##### Exercise 7.6. What would "" mean in place of the <>?

A private header file.

##### Exercise 7.7. How would you use the preprocessor to select implementation-specific fragments of a program?

Conditional compilation directives e.g. `#if`, `#ifdef`, `#elif`, `#endif#`.

##### Exercise 7.8. What sort of arithmetic does the preprocessor use?

Uses longs that are provided by the translator so you shouldn't rely on them.