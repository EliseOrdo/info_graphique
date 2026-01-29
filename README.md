

In this project, we created a 3D scene representing a room with a stained glass on the roof and a circle of candle on the floor. There are different sources of light, one for each candle and one for the stained glass, we also modelised the light attenuation and the camera can move.

To move the camera, you must push: Z to go forward, S to go backward,
    Q to go to the left,
    D to go to the right,
 ARROW_UP to look up,
    ARROW_DOWN to look down,
    ARROW_LEFT to look on the left,
    ARROW_RIGHT to look on the right

https://github.com/user-attachments/assets/38bd2129-de9f-4e48-acb1-da07a8c69821





# Skeleton code for OpenGL using C++

This is the skeleton code for creating graphics applications using OpenGL and C++.

# Installation

You would need CMake(to build our project) which can be downloaded from [here](https://cmake.org/download/).

# Setup

After cloning this repo, you also need to load the submodules GLEW, GLFW and GLM using the following command.

    git submodule update --init --recursive


## Run the Application

To launch the window, simply run:

    cmake .
    make
    ./opengl_program





