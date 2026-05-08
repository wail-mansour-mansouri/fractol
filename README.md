# Fractol

A small fractal explorer written in C with MiniLibX.

The program can draw Julia, Mandelbrot, and a cubic Mandelbrot variant. It
supports zooming on the mouse position, moving through the view, changing color
depth, and updating Julia parameters with mouse movement.

## Fractals

- `mandelbrot_2`: classic Mandelbrot set.
- `mandelbrot_3`: cubic Mandelbrot variant.
- `julia`: Julia set with optional starting parameters.

## Preview

Images are available in
[docs/screenshots.md](docs/screenshots.md).

## Build

```sh
make
```

MiniLibX is bundled as a prebuilt Linux static library in `mlx/`. The system
still needs the usual X11 development libraries available at link/runtime.

If you want to use another MiniLibX path:

```sh
make MLX_DIR=/path/to/minilibx
```

Run:

```sh
./fractol mandelbrot_2
./fractol mandelbrot_3
./fractol julia
./fractol julia -0.8 0.156
```

Clean:

```sh
make fclean
```

## Controls

- Mouse wheel: zoom in and out on the cursor.
- Mouse move on Julia: change the Julia constant.
- Arrow keys: move the view.
- `+` / `-`: change the iteration count.
- Space: rotate the color palette.
- ESC or window close: exit.

## Layout

```text
include/        Header
mlx/            MiniLibX headers and static library
src/app/        Startup and cleanup
src/events/     Keyboard, mouse, expose, close hooks
src/fractals/   Fractal formulas
src/math/       Complex number helpers
src/render/     View mapping and image drawing
src/utils/      Small utility functions
docs/           Notes and screenshots
```

## Limits

- Rendering is CPU-based.
- Zoom depth is limited by floating point precision.
- The project is a 2D explorer, not a full graphics engine.
