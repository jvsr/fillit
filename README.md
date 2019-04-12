# fillit
A simple space optimisation algorithm. A Codam School project

## Description

Fillit is a project that makes you find the optimal solution among a huge set of possibilities.
In this particular project, we have to create an algorithm which fits some Tetriminos together into the smallest possible square.

A Tetriminos is a 4-blocks geometric figure that looks similar to a tetris piece.
The accepted size of a tetremino can get changed in `fillit.h`.
The program takes a file as parameter which contains a list of these Tetriminos and arranges them to fit them in the smallest square possible.

The program displays the smallest square solution on the standard output.
Every tetremino will be assigned a capital letter (starting with 'A') in the order they appear in the file.
That is why a file will contain 26 tetreminos at max.
If the file contains at least one error, the program must display error on the standard output and exits properly.

## How to use ?
Create the executable by typing `make`.

Usage: `./fillit [tetremino_file]`

Some test files are included in the test directory. Or test by using `test.sh`.
