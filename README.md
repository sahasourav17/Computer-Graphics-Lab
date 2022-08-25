# Computer-Graphics-Lab
I will store my computer graphics lab work and the final project that the course instructor assigned in this repository. I have attempted to include all the tools and commands required to work with the OpenGL/GLUT libraries in the readme.md file.


## Requrements:
- OpenGL/GLUT library
- IDE (vs code/codeblocks etc.)
- C++ Compiler

## OS:
- Linux

## Installing GLUT in linux:

- sudo apt update
- sudo apt install freeglut3 freeglut3-dev libglew1.5 libglew1.5-dev libglu1-mesa libglu1-mesa-dev libgl1-mesa-glx libgl1-mesa-dev mesa-common-dev libglew-dev libglfw3 libglfw3-dev libglm-dev

## Running C++ files [ note: You have to add linkers]:
- g++ filename.cpp -o filename -lglut -lGL -lGLU -lGLEW
- ./filename

