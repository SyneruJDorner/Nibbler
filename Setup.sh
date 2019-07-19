#/bin/bash

#Install Homebrew
echo SETUP: Installing HOMEBREW
which -s brew
if [[ $? != 0 ]] ; then
    sh -c "$(curl -fsSL https://raw.githubusercontent.com/Tolsadus/42homebrewfix/master/install.sh)"
else
    brew update
fi

#Install Graphics libraries
#Install SDL2
echo SETUP: Installing SDL2
if brew ls --versions sdl2 > /dev/null; then
    echo SETUP: SDL Has been Installed.
else
    brew install sdl2
    echo SETUP: SDL Has been Installed.
fi

#Install GLFW
echo SETUP: Installing GLFW: 
if brew ls --versions glfw > /dev/null; then
    echo SETUP: GLFW Has been Installed.
else
    brew install glfw
    echo SETUP: GLFW Has been Installed.
fi

#Install SFML
echo SETUP: Installing SFML: 
if brew ls --versions sfml > /dev/null; then
    echo SETUP: SFML Has been Installed.
else
    brew install sfml
    echo SETUP: SFML Has been Installed.
fi

echo SETUP: Installation of Graphics libraries Completed Successfully.

#Creating Resources Folder
cd resources

#Create Resources Folder.
mkdir SDL2
mkdir SFML
mkdir GLFW

#Copying Over Library and Includes
echo SETUP: Copying Over libraries and Includes
cd SDL2
cp -rf ~/.brew/Cellar/sdl2/2.0.9_1/lib ~/.brew/Cellar/sdl2/2.0.9_1/include .
cd ..

cd SFML
cp -rf ~/.brew/Cellar/sfml/2.5.1/lib ~/.brew/Cellar/sfml/2.5.1/include .
cd ..

cd GLFW
cp -rf ~/.brew/Cellar/glfw/3.3/lib ~/.brew/Cellar/glfw/3.3/include .
cd ..

#Cloning Glad
gladRepo="https://github.com/EIESSENHEIM/glad.git"
echo SETUP: Cloning Glad into GLFW
cd GLFW
git clone "$gladRepo"
cd ..

# Setting Library Path
# export DYLD_LIBRARY_PATH=$PWD/resources/GLFW/lib:$PWD/resources/SFML/lib:$PWD/resources/SDL2/lib
# env | grep 'DYLD_LIBRARY_PATH'

#PWD - Accesses path from open Terminal

File="$HOME/.zshrc"

if grep -q "DYLD_LIBRARY_PATH" "$File"; then
    echo PATH ALREADY EXISTS
else
    echo 'export DYLD_LIBRARY_PATH=$PWD/resources/GLFW/lib:$PWD/resources/SFML/lib:$PWD/resources/SDL2/lib:$PWD/libraries' >> ~/.zshrc
fi

exit