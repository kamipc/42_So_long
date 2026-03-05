*This project has been created as part of the 42 curriculum by cpinho-c.*

# So_long

## Main objective

**So_long** is our introduction to the school's graphical library, and with it learn to manage windows, events, textures, etc.
The objective here is to create a simple game that will have a movable player character that can be moved through **wasd** or **↑ ↓ → ←** keys, the player can then collect itens to unlock the exit and after collecting all and entering the exit point the game ends.

## Instructions

- to clone the repository:
```
git clone https://github.com/kamipc/42_So_long.git
```
- then to enter the directory and compile the project:
```
cd 42_So_long
make
```
This will also clone the repository libft and minilibx which are dependencies and compile then.

- to run :
```
./so_long [map_name]
```

there are multiple maps available in the **maps** folder, but any map can be created by filling a .ber file with the following information:
- `1` for **wall** (the map must be surrounded by walls)
- `0` for **walkable spaces**
- `E` for the **exit** (there must only be **one**)
- `P` for the **player starting position** (there must only be **one**)
- `C` for **collectibles** (there must be atleast **one**)