# RACING CHARS

### CHALLENGE DESCRIPTION:

You are given a file where each line is a section of a race track with obstructions, gates, and checkpoints. Your task is to find a way to pass this track using the following information:

1. Each section contains either one single gate or one gate with a checkpoint. 
2. You should drive only through gates or checkpoints. 
3. You should drive through a checkpoint rather than a gate. 
4. An obstruction is represented by a number sign "#". 
5. A gate is represented by an underscore "_". 
6. A checkpoint is represented by a letter C.

### INPUT SAMPLE:

Your program should accept a path to a filename as its first argument. Each line of the file is a new section of a race track.

```
#########_##
########C_##
#######_####
######_#C###
#######_C###
#######_####
######C#_###
######C_####
#######_####
#######_####
```

### OUTPUT SAMPLE:

Print out the way of passing this race track starting from the first line in the file. Use a pipe "|" for the straight, use a slash "/" for the left turn, and use a backslash "\" for the right turn.

```
#########|##
########/_##
#######/####
######_#\###
#######_|###
#######/####
######/#_###
######|_####
#######\####
#######|####
```

### CONSTRAINTS:

* The number of lines in a file is 50.
* The width of a section is 12 characters.