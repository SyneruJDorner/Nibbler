#/bin/bash

#Brew Install SFML
if brew ls --versions sfml > /dev/null; then
  # The package is installed
  echo SFML INSTALLED
else
  # The package is not installed
  brew install sfml
fi

#Brew Install GLFW
if brew ls --versions glfw > /dev/null; then
  # The package is installed
  echo GLFW INSTALLED
else
  # The package is not installed
  brew install glfw
fi

#Brew Install SDL2
if brew ls --versions sdl2 > /dev/null; then
  # The package is installed
  echo SDL2 INSTALLED
else
  # The package is not installed
  brew install sdl2
fi