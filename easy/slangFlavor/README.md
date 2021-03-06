# SLANG FLAVOR

### CHALLENGE DESCRIPTION:

Long serious texts are boring. Write a program that will make texts more informal: replace every other end punctuation mark (period ‘.’, exclamation mark ‘!’, or question mark ‘?’) with one of the following slang phrases, selecting them one after another:

```
‘, yeah!’
‘, this is crazy, I tell ya.’
‘, can U believe this?’
‘, eh?’
‘, aw yea.’
‘, yo.’
‘? No way!’
‘. Awesome!’
```

The result should be funny.

### INPUT SAMPLE:

The first argument is a file that contains a text.

For example:

```
Lorem ipsum dolor sit amet. Mea et habeo doming praesent. Te inani 
utroque recteque has, sea ne fugit verterem!
Usu ei scripta phaedrum, an sed salutatus definiebas? Qui ut 
recteque gloriatur reformidans. Qui solum aeque sapientem cu.
Eu nam nusquam quaestio principes.
```

### OUTPUT SAMPLE:

Print to stdout the results: the text with slang phrases.

For example:

```
Lorem ipsum dolor sit amet. Mea et habeo doming praesent, yeah! Te 
inani utroque recteque has, sea ne fugit verterem!
Usu ei scripta phaedrum, an sed salutatus definiebas, this is 
crazy, I tell ya. Qui ut recteque gloriatur reformidans. Qui solum 
aeque sapientem cu, can U believe this?
Eu nam nusquam quaestio principes.
```

### CONSTRAINTS:

1. In the input text, end punctuation mark cannot come one after another (consequent).
2. Input text contains 40 lines.