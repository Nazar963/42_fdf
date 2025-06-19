# FdF 🔺

[![42 Firenze](https://img.shields.io/badge/42-Firenze-blue)](https://42firenze.it/)
[![GitHub license](https://img.shields.io/github/license/Nazar963/42_fdf)](https://github.com/Nazar963/42_fdf/blob/master/LICENSE)
[![Build Status](https://img.shields.io/github/actions/workflow/status/Nazar963/42_fdf/.github/workflows/build.yml?branch=master)](https://github.com/Nazar963/42_fdf/.github/workflows/build.yml)

A 3D wireframe renderer that converts elevation maps into stunning landscapes using 42's MiniLibX graphics library.

![FdF Example](https://raw.githubusercontent.com/Nazar963/42_fdf/master/sample-image/Screenshot-from-2025-05-28-08-52-46.png)

## Table of Contents 📖
- [Description](#description)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Controls](#controls)
- [Makefile Targets](#makefile-targets)
- [Testing](#testing)
- [Acknowledgments](#acknowledgments)
- [License](#license)

## Description
FdF (Fil de Fer - "Wireframe") is a 42 School computer graphics project that:
- Parses `.fdf` map files containing elevation data
- Renders 3D wireframe models using Bresenham's line algorithm
- Implements affine transformations (translation, scaling)
- Supports custom color schemes

## Features

### Core Functionality 🔧
- Map parsing with error checking
- Isometric projection
- Z-buffering for proper line drawing
- Basic transformations (zoom, move)
- Color interpolation between points

## Installation

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
   ./fdf maps/42.fdf
   ```

## Usage

### Basic Syntax
```bash
./fdf [map_file.fdf]
```

### Example
```bash
# Render with cool color gradient in parallel projection
./fdf maps/42.fdf
```

## Controls
| Key              | Action                      |
|------------------|-----------------------------|
| W/S/A/D/         | Rotate                      |
| mouse-scroll     | Zoom                        |
| ESC              | Quit program                |

## Makefile Targets
- `make`       : Compile standard version
- `make clean` : Remove object files
- `make fclean`: Full clean
- `make re`    : Rebuild project

## Testing
Included test maps:
- `maps/42.fdf` : 42 logo
- `maps/t1.fdf` : Simple terrain
- `maps/pyra.fdf` : Pyramid structure

## Acknowledgments
- 42 School for project concept
- MiniLibX documentation
- Bresenham's line algorithm
- Computer Graphics: Principles & Practice

## 🤝 Contributing
Feel free to submit issues or pull requests if you have suggestions for improving the application or adding more features.

## License
This project is licensed under the MIT License - see [LICENSE](LICENSE) for details.

## 📧 Contact
For questions or feedback, please open an issue in the repository.

## ⭐ Star this repository if you found it helpful!
[![GitHub stars](https://img.shields.io/github/stars/Nazar963/42_fdf?style=social)](https://github.com/Nazar963/42_fdf/stargazers)

---

🗿 *"Transforming cold matrices into vibrant landscapes – where every z-axis becomes a mountain and every gradient whispers secrets of perspective projection."*

[![42 School](https://img.shields.io/badge/42-profile-blue)](https://profile-v3.intra.42.fr/users/naal-jen)
[![GitHub Profile](https://img.shields.io/badge/GitHub-Nazar963-lightgrey)](https://github.com/Nazar963)
[![GitHub Follow](https://img.shields.io/github/followers/Nazar963?style=social)](https://github.com/Nazar963)

---
## 🍀 Goodluck:
Good luck with your FdF project at 42! 🚀

