# PASCALS TRIANGLE

### CHALLENGE DESCRIPTION:

![Header](https://i.imgur.com/DsufUqz.png)

A Pascals triangle row is constructed by looking at the previous row and adding the numbers to its left and right to arrive at the new value. If either the number to its left/right is not present, substitute a zero in it's place. More details can be found here: Pascal's triangle. E.g. a Pascal's triangle upto a depth of 6 can be shown as:

```
            1
          1   1
        1   2   1
       1  3   3   1
     1  4   6   4   1
    1  5  10  10  5   1
```

### INPUT SAMPLE:

Your program should accept as its first argument a path to a filename. Each line in this file contains a positive integer which indicates the depth of the triangle (1 based). E.g.

```
6
```

### OUTPUT SAMPLE:

Print out the resulting pascal triangle upto the requested depth in row major form. E.g.

```
1 1 1 1 2 1 1 3 3 1 1 4 6 4 1 1 5 10 10 5 1
```