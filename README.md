# Cantionale

Song manager and songbook generator.

Not developed. For working command-line tool see: [Cantionale repository](https://github.com/wojtex/cantionale)


# Song format

Lyrics goes like here:

```
[name R]
{G}This is some {C}very good {E}for{A}mat {G}example.[note Jakiś tekst uwagi]
[rep 2]
This text is repeated twice.
And so on...
[alt 1]Something for first time.[/alt]
[alt 2]And for second time.[/alt]
[/rep]
[name 1]
Some numbered stuff.
After that will be R part.
[call R]
[name 2]
And second part here.
```

Lilypond script is stored separately.
