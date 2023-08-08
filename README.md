# Sokoban

## Table of Contents

1. [General Info](#general-info)
2. [Technologies](#technologies)
3. [Installation](#installation)
4. [Overview](#overview)

### General Info

***
The main objective of this project is to create a copy of the Sokoban game in terminal mode, using the ncurses library

The Sokoban Game:

Sokoban (warehouse keeper in Japanese) is a type of transport puzzle, in which
the player pushes boxes or crates around in a warehouse, trying to get them to
storage locations. The puzzle is usually implemented as a video game.
Sokoban was created in 1981 by Hiroyuki Imabayashi, and published in 1982 by
Thinking Rabbit, a software house based in Takarazuka, Japan.
The game is played on a board of squares, where each square is a floor or
a wall. Some floor squares contain boxes, and some floor squares are marked as
storage locations. The player is confined to the board, and may move
horizontally or vertically onto empty squares (never through walls or boxes).
The player can also move into a box, which pushes it into the square beyond.
Boxes may not be pushed into other boxes or walls, and they cannot be pulled.
The puzzle is solved when all boxes are at storage locations.

***

## Technologies

A list of technologies used within the project:

* [C](https://en.wikipedia.org/wiki/C_(programming_language))
* [ncurses library](https://en.wikipedia.org/wiki/Ncurses)

## Installation

***
A little intro about the installation.

```c
git clone git@github.com:Tom-Mendy/Sokoban.git
cd Sokoban
make
```

### Docker

check : [hub.docker.com/r/tommendy/sokoban](https://hub.docker.com/r/tommendy/sokoban)

## Overview

***

```c
$> ./my_sokoban -h

USAGE
        ./my_sokoban map
DESCRIPTION
        map file representing the warehouse map, containing '#' for walls,
        'P' for the player, 'X' for boxes and 'O' for storage locations.
KEYMAP
        ←↑↓→ to move the P
        SPACE to reset the map to original state
```

You can launch the exemple map like that:

```c
./my_sokoban map/map.exemple
```
