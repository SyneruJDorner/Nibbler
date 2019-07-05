#/bin/bash

#Library Repo's
glfwRepo="https://github.com/glfw/glfw.git"
sdlRepo="https://hg.libsdl.org/SDL"

#Specific Directory Names
glfw="GLFW"
sdl="SDL"

#Main Directory Names
sourceDir="source"
buildDir="build"

#Create build and source directories
mkdir -p "$sourceDir"
mkdir -p "$buildDir"

cd "$sourceDir"

#clone Repo's into Source Directory
git submodule add --force "$glfwRepo" "$glfw"
hg clone "$sdlRepo" "$sdl"

cd ..
cd "$buildDir"

#Create folders to cmake into
mkdir -p "$glfw"
mkdir -p "$sdl"

#cmake and build projects from repo
cd "$glfw"
cmake ../../"$sourceDir"/"$glfw"
make

cd ..

cd "$sdl"
../../"$sourceDir"/"$sdl"/configure
make