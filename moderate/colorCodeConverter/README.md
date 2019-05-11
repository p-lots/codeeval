# COLOR CODE CONVERTER

### CHALLENGE DESCRIPTION:

Your task is to write a program which converts different types of color codes, such as CMYK, Hex, HSL, HSV, and RGB. The converter should accept codes formatted as follows:

```
HSL: "HSL(D,P,P)"
HSV: "HSV(D,P,P)"
CMYK: "(F,F,F,F)"
Hex: "#000000"
```

Where:  
'D' is in range [0, 359] degrees,  
'P' is in range [0, 100] percent,  
'F' is a float, rounded to a second digit after dot in range [0.00, 1.00],  
Hex is in range [#000000, #ffffff]

### INPUT SAMPLE:

Your program should accept a file as its first argument. Each line of the file contains a color code.

For example:

```
(0.56,0.94,0.21,0.02)
HSL(359,0,0)
HSV(276,33,7)
#cfa9c4
```

### OUTPUT SAMPLE:

For each line of input, determine the color code, convert it to RGB, and print out the result. You must round all floating-point numbers, if any, to integers.

For example:

```
RGB(110,15,197)
RGB(0,0,0)
RGB(15,12,18)
RGB(207,169,196)
```