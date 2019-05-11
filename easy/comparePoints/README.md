# COMPARE POINTS

### CHALLENGE DESCRIPTION:

Bob's hiking club is lost in the mountains on the way to a scenic overlook. Fortunately, Bob has a GPS device, so that he can see the coordinates where the group is currently at. The GPS gives the current X/Y coordinates as O, P, and the scenic overlook is located at Q, R. Bob now just needs to tell the group which way to go so they can get to the overlook in time for s'mores.

### INPUT SAMPLE:

The input is a file with each line representing a test case. Each test case consists of four integers O, P, Q, R on a line, separated by spaces.

```
0 0 1 5
12 13 12 13
0 1 0 5
```

### OUTPUT SAMPLE:

For each test case print a line containing one of the following: N, NE, E, SE, S, SW, W, NW, here if the coordinates Q, R are (respectively) north, northeast, east, southeast, south, southwest, west, northwest, or already at ("here") the coordinates O, P. Note that N, S, E and W mean directly North, South, East or West respectively, i.e. X or Y coordinates of two points are exactly the same. In all other cases your output should be one of the NW, NE, SW, SE or here.

```
NE
here
N
```

### CONSTRAINTS:

1. All coordinates -10000 < |O,P,Q,R| < 10000
2. Number of test cases is 40