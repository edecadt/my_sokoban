# my_sokoban Documentation

## Overview

Welcome to my_sokoban, a C implementation of the Sokoban game. Sokoban challenges players to move boxes to storage locations within a warehouse. This technical documentation guides you through the compilation process, adding custom maps, and provides an overview of the project and tools used.
### 1. Compilation

To compile the project, use the provided Makefile. Ensure you have gcc installed on your system.

```shell
make
```

This command compiles the my_sokoban program.
### 2. Usage

To launch the game, use the following command:

bash

```shell
./my_sokoban map
```

* Replace **`map`** with the file representing the warehouse map. Refer to the next section for creating your custom maps.

### 3. Adding Custom Maps

Create custom maps using the following characters:

    #: Wall
    P: Player
    X: Box
    O: Storage location
    Use spaces and line breaks to define the warehouse structure.

Example map:

```text
############
# O        #
# P ####   #
#          #
#######    #
# O ##     #
# ##       #
#          #
# XX       #
#          #
############
```

### 4. Bonus and Tools

   The project utilizes the ncurses library for terminal mode user interface.
   Compilation is facilitated through a Makefile with rules for re, clean, and fclean.
   Additional features such as menus, a game interface, music, etc., can be added as needed.

Explore the game, leverage additional features, and feel free to create your own maps to test your Sokoban skills!