<div align="center">

# 3D Rotating Donut in C++

### A 3D donut animation made with C++ and pure mathematics.

<p>
  <img src="https://img.shields.io/badge/C%2B%2B-17%2B-blue?style=for-the-badge&logo=cplusplus" alt="C++">
  <img src="https://img.shields.io/badge/3D-Rendering-purple?style=for-the-badge" alt="3D Rendering">
  <img src="https://img.shields.io/badge/ASCII-Art-black?style=for-the-badge" alt="ASCII Art">
</p>

</div>

---

## About

This project creates a **3D rotating donut directly in the terminal** using C++.

The interesting part?

**No graphics engine. No OpenGL. No external libraries.**

Just C++, mathematics, and ASCII characters.

<div align="center">

<img src="donut.png">

</div>

---

## Features

*  Smooth 3D rotation
*  Uses mathematical equations to create the donut
*  Simple lighting effect
*  Perspective projection
*  Z-buffer for depth
*  Runs directly in the terminal
*  Lightweight and simple
*  No graphics libraries required

---

## How Does It Work?

The program creates a **3D torus (donut)** using two angles:

* `theta` — controls the donut's tube
* `phi` — controls the donut's main circle

It then performs a few important steps:

### 1. Create the 3D Shape

Mathematical equations are used to generate points around the donut.

### 2. Rotate the Donut

The points are rotated using two angles:

```cpp
float A = 0;
float B = 0;
```

These values are continuously changed:

```cpp
A += 0.05f;
B += 0.02f;
```

This makes the donut rotate.

### 3. Convert 3D → 2D

The 3D points are converted into positions that can be displayed on the terminal.

The program uses perspective so that points farther away appear smaller.

### 4. Add Depth

A **Z-buffer** is used to decide which part of the donut should appear in front.

```cpp
float zbuffer[width * height];
```

This prevents points behind the donut from being displayed incorrectly.

### 5. Add Lighting

Different ASCII characters represent different brightness levels:

```cpp
const char* chars = ".,-~:;=!*#$@";
```

Darker areas use lighter characters, while brighter areas use denser characters.

---

## Technologies

<div align="center">

| Technology              | Used For                           |
| ----------------------- | ---------------------------------- |
| **C++**                 | Main programming language          |
| **Math / Trigonometry** | Creating and rotating the 3D shape |
| **ASCII Characters**    | Drawing the donut                  |
| **Z-Buffer**            | Handling depth                     |
| **ANSI Escape Codes**   | Updating the terminal              |

</div>

---

## Getting Started

### Requirements

You need:

* A C++ compiler
* A terminal that supports ANSI escape codes
* C++11 or newer

### Clone the Repository

```bash
git clone https://github.com/your-username/3d-donut-cpp.git
cd 3d-donut-cpp
```

### Compile

```bash
g++ main.cpp -o donut -std=c++17
```

### Run

```bash
./donut
```

You should now see the donut rotating in your terminal. 

---

## Customize It

You can easily experiment with the project.

### Change the Size

```cpp
const int width = 80;
const int height = 40;
```

Try larger values for a bigger output.

### Change Rotation Speed

```cpp
A += 0.05f;
B += 0.02f;
```

Increase the values to make the donut rotate faster.

### Change the Characters

```cpp
const char* chars = ".,-~:;=!*#$@";
```

Try your own characters to create a different look.

---

## What I Learned

This small project helped me understand how mathematics can be used to create something visual.

I learned about:

* 3D coordinates
* Trigonometry
* 3D rotation
* Perspective projection
* Z-buffering
* Basic lighting
* ASCII rendering
* Terminal animation
* C++ mathematical functions

---

## Why I Made This

I wanted to see how far I could go with **just C++ and mathematics**.

Instead of using a graphics engine, I wanted to understand what is happening behind the scenes when a computer displays a 3D object.

This project is a simple example of how **math can turn into graphics**.

---

## Future Improvements

Some things I want to try next:

* [ ] Add terminal colors
* [ ] Add keyboard controls
* [ ] Control rotation with the mouse/keyboard
* [ ] Create other 3D shapes
* [ ] Improve the lighting
* [ ] Add multiple objects
* [ ] Build a small ASCII 3D renderer

---

## Support

If you found this project interesting, consider giving it a ⭐ on GitHub!

<div align="center">

### C++ + Mathematics = 3D Graphics

**Made with curiosity and a lot of trigonometry.**

</div>
