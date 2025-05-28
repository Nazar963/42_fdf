# FdF 🔺

[![42 Firenze](https://img.shields.io/badge/42-Firenze-blue)](https://42firenze.it/)
[![GitHub license](https://img.shields.io/github/license/Nazar963/42_fdf)](https://github.com/Nazar963/42_fdf/blob/master/LICENSE)
[![Build Status](https://img.shields.io/github/actions/workflow/status/Nazar963/42_fdf/.github/workflows/build.yml?branch=master)](https://github.com/Nazar963/42_fdf/.github/workflows/build.yml)

A 3D wireframe renderer that converts elevation maps into stunning landscapes using 42's MiniLibX graphics library.

![FdF Example](https://raw.githubusercontent.com/Nazar963/42_fdf/master/images/sample.png)

## Table of Contents 📖
- [Description](#description-)
- [Features](#features-)
- [Installation](#installation-)
- [Usage](#usage-)
- [Controls](#controls-)
- [Makefile Targets](#makefile-targets-)
- [Testing](#testing-)
- [Acknowledgments](#acknowledgments-)
- [License](#license-)

## Description 📝
FdF (Fil de Fer - "Wireframe") is a 42 School computer graphics project that:
- Parses `.fdf` map files containing elevation data
- Renders 3D wireframe models using Bresenham's line algorithm
- Implements affine transformations (rotation, translation, scaling)
- Supports custom color schemes and gradient generation

**Bonus Features**:
- Advanced camera controls
- Multiple projection modes (Isometric/Parallel/Perspective)
- Dynamic color gradients based on elevation
- Height exaggeration modifier
- HUD display with controls information

## Features ✨

### Core Functionality 🔧
- Map parsing with error checking
- Isometric projection
- Z-buffering for proper line drawing
- Basic transformations (rotate, zoom, pan)
- Color interpolation between points

### Bonus Features 🚀
| Feature          | Description                          |
|------------------|--------------------------------------|
| Parallel Projection | Orthographic rendering mode       |
| Color Palettes   | Multiple predefined color schemes    |
| Height Scaling   | Adjust vertical exaggeration (Q/E)   |
| Dynamic HUD      | On-screen controls reference         |
| Smooth Rotation  | Fluid 3D manipulation with mouse     |

## Installation ⚙️

### Requirements
- MiniLibX (42's graphics library)
- X11/Xquartz (macOS/Linux)
- GCC & Make

### Compilation
1. Clone the repository:
   ```bash
   git clone https://github.com/Nazar963/42_fdf.git
   cd 42_fdf
   ```
2. Build the project:
   ```bash
   make
   ```
3. Run with a map file:
   ```bash
   ./fdf maps/test.fdf
   ```

## Usage 💻

### Basic Syntax
```bash
./fdf [map_file.fdf] [--color=gradient_name] [--projection=iso/para]
```

### Example
```bash
# Render with cool color gradient in parallel projection
./fdf maps/42.fdf --color=volcano --projection=para
```

## Controls 🎮
| Key              | Action                      |
|------------------|-----------------------------|
| Arrow Keys       | Pan view                    |
| W/S/A/D/Q/E      | Rotate                      |
| +/-              | Zoom                        |
| C                | Cycle color palettes        |
| P                | Toggle projections          |
| R                | Reset view                  |
| ESC              | Quit program                |

## Makefile Targets 🛠️
- `make`       : Compile standard version
- `make bonus` : Enable bonus features
- `make clean` : Remove object files
- `make fclean`: Full clean
- `make re`    : Rebuild project

## Testing 🧪
Included test maps:
- `maps/42.fdf` : 42 logo
- `maps/t1.fdf` : Simple terrain
- `maps/pyra.fdf` : Pyramid structure

Use height exaggeration to test z-buffering:
```bash
./fdf maps/mars.fdf -z 5
```

## Acknowledgments 🙏
- 42 School for project concept
- MiniLibX documentation
- Bresenham's line algorithm
- Computer Graphics: Principles & Practice

## License 📄
This project is licensed under the MIT License - see [LICENSE](LICENSE) for details.

---

🖌️ **Bringing Mathematics to Life!**  
[![42 Profile](https://img.shields.io/badge/Profile-<your_42_login>-blue)](https://profile.intra.42.fr/users/<your_42_login>)  
[![GitHub Follow](https://img.shields.io/github/followers/<your_username>?style=social)](https://github.com/<your_username>)
```

**Customization Guide**:
1. Replace all `<your_username>` with your GitHub handle
2. Update `<your_42_login>` with your 42 intra ID
3. Add actual screenshots to `images/` directory
4. Modify bonus features to match your implementation
5. Include your most impressive test maps
6. Add specific compilation notes for MiniLibX if needed

Key Features:
- Visual hierarchy with emoji markers
- Responsive image display
- Comprehensive controls table
- Projection mode explanations
- Clear compilation/usage instructions
- Badge system showing project status

Let me know if you need adjustments for specific technical implementations or want to highlight particular aspects of your FdF project!
