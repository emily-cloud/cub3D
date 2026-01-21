# Cub3D - 42 Berlin

## Introduction

Cub3D is a project at 42 Berlin inspired by the classic game Wolfenstein 3D. The goal is to create a simple 3D raycasting engine using the **MiniLibX** graphical library. This project helps students understand graphics programming, raycasting techniques, and basic game engine mechanics.

## Features

- 2D map parsing and validation
- Raycasting to simulate a 3D view
- Player movement and rotation
- Wall rendering with textures
- Basic event handling (keyboard inputs)
- Simple game physics

## Installation

```bash
git clone https://github.com/emily-cloud/cub3D.git
cd cub3d
make
```

## Usage

```bash
./cub3D maps/sample.cub
```

- Use **WASD** keys to move around.
- Use **left/right arrow keys** to rotate.
- Press **ESC** to exit.

## Bonus Features

- Sprite rendering (e.g., objects like doors or enemies)
- Minimap display
- Additional textures and floor/ceiling colors
- Mouse support for looking around
- Multi-textured walls


## 3D view game screenshot

These frames highlight how the raycasting engine handles varied wall textures, lighting transitions, and patterned walls.
<p align="center">
  <img src="https://github.com/emily-cloud/cub3D/blob/main/cub3d%20screenshot/Weixin%20Image_20260121151237_49_2.jpg" 
       alt="3D Arena" width="75%">
</p>
<p align="center"><em>Harry Potter Texture</em></p>

<p align="center">
  <img src="https://github.com/emily-cloud/cub3D/blob/main/cub3d%20screenshot/Weixin%20Image_20260121151423_52_2.jpg" 
       alt="3D Arena" width="75%">
</p>
<p align="center"><em>Chinese New Year Texture</em></p>

<p align="center">
  <img src="https://github.com/emily-cloud/cub3D/blob/main/cub3d%20screenshot/Weixin%20Image_20260121151453_53_2.jpg" 
       alt="3D Arena" width="75%">
</p>
<p align="center"><em>Wolfenstein Texture</em></p>


## Resources

- `man 3 mlx`
- `man 2 open`
- `man 2 read`
- `man 2 close`
- `man 2 mmap`
- `man 2 mlx_loop`
- `man 2 mlx_put_image_to_window`

## Authors

Developed as part of 42 Berlin's curriculum by [Huayun Ai / Yuan Gao].

## License

This project follows the academic rules of 42 and is intended for educational purposes.

