# 42 Lisbon C Projects

Portfolio repository for projects completed during the 42 Lisbon software development curriculum. The work is mainly written in C and covers low-level programming, Unix process control, graphics, algorithms, and concurrency.

## Project Index

| Project | Area | What it demonstrates |
| --- | --- | --- |
| [libft](libft/) | C foundations | Reimplementation of common libc functions, string/memory utilities, and linked-list helpers. |
| [ft_printf](ft_printf/) | C formatting | Custom implementation of `printf`, including variadic arguments and multiple conversion specifiers. |
| [get_next_line](get_next_line/) | File I/O | Line-by-line file descriptor reading with static-buffer management. |
| [push_swap](push_swap/) | Algorithms | Stack-based sorting with constrained operations and optimization for operation count. |
| [minitalk](minitalk/) | Unix signals | Client/server communication using Unix signals. |
| [so_long](so_long/) | C graphics / game programming | Tile-based 2D game using MiniLibX, map validation, movement handling, collectibles, and exit logic. |
| [philosophers](philosophers/) | Concurrency | Dining philosophers simulation with process/thread synchronization concepts. |
| [minishell](minishell/) | Systems programming | Interactive Unix-like shell with parsing, built-ins, redirections, pipes, heredoc, and signal handling. |
| [cub3d](cub3d/) | Graphics / raycasting | Wolfenstein-style 3D rendering project using raycasting concepts. |
| [exam_rank2](exam_rank2/) | Exam practice | 42 exam exercises. |
| [exam_rank3](exam_rank3/) | Exam practice | 42 exam exercises, including compact `ft_printf` and `get_next_line` implementations. |

## Highlight: Minishell

[minishell](minishell/) is the strongest systems-programming project in this repository. It implements an interactive shell in C and reproduces core Unix shell behavior.

Main features:

- Interactive prompt with `readline` and command history.
- Lexer and parser for command lines, quotes, redirections, pipes, and heredoc.
- Environment-variable expansion, including `$?` error status handling.
- Built-ins: `cd`, `echo`, `env`, `exit`, `export`, `pwd`, and `unset`.
- External command execution through `PATH`.
- Single-command and multi-command execution with pipes.
- Input/output redirections and heredoc support.
- Signal handling for `Ctrl-C`, `Ctrl-\`, and EOF behavior.

Build and run:

```bash
cd minishell
make
./minishell
```

Demo:

![Minishell demo](https://user-images.githubusercontent.com/87911989/235367730-d0cd2e05-b730-4a63-bae2-4c16cfc3d328.gif)

This project was developed with [joao-aiveca-caseiro](https://github.com/joao-aiveca-caseiro).

## Highlight: so_long

[so_long](so_long/) is a small 2D game built in C with MiniLibX. It is a good visual project because the result is easy to inspect and the implementation combines map parsing, rendering, and event-driven game logic.

Main features:

- `.ber` map parsing and validation.
- Validation for rectangular maps, wall boundaries, valid composition, player, exit, and collectibles.
- Flood-fill path validation to ensure the map can be completed.
- MiniLibX window creation and tile rendering.
- Player movement, move counting, collectible tracking, and exit conditions.
- Bonus version with directional sprites, animated collectibles, and enemies.

Build and run:

```bash
cd so_long
make
./so_long maps/map.ber
```

Bonus version:

```bash
make bonus
./so_long maps/map_bonus.ber
```

Demo:

![so_long demo](https://user-images.githubusercontent.com/87911989/224358441-719326c1-5e45-4962-9579-6e7264b4e5cc.gif)

## Notes

- Most projects are compiled with `make` inside their own folder.
- Several projects include their own local copy of `libft` as a dependency.
- The repository is kept as a curriculum archive; the highlighted sections point to the projects most useful for a portfolio review.
