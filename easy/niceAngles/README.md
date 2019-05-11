# NICE ANGLES

### CHALLENGE DESCRIPTION:

![Header](http://i.imgur.com/Z9AL9fi.png)

Write a program that outputs the value of angle, reducing its fractional part to minutes and seconds.

### INPUT SAMPLE:

The first argument is a path to a file that contains the values of angles with their decimal fractions:

```
330.39991833
0.001
14.64530319
0.25
254.16991217
```

### OUTPUT SAMPLE:

Print to stdout values of angles with their fractional parts reduced to minutes and seconds.

The whole and fractional parts are separated by period, minutes are separated by apostrophe, seconds by double quotes. The values of minutes and seconds are shown as two numbers (with leading zeros if needed).

```
330.23'59"
0.00'03"
14.38'43"
0.15'00"
254.10'11"
```