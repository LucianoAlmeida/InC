execute 'apt-get update'
## Libary SDL2
execute 'apt-get install -y --force-yes libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev'
## Git for clone
execute 'apt-get install -y --force-yes git'
## Clone project
execute 'git clone https://github.com/ImaginaNaCopa/InC.git'
execute 'cd InC'
## Build essential
execute 'apt-get -y --force-yes install build-essential'
## Cmake for build
execute 'apt-get -y --force-yes install cmake'
## Set compiler g++ for c++ (files *.cpp)
execute 'cmake -DCMAKE_CXX_COMPILER=$(which g++) -DCMAKE_C_COMPILER=$(which gcc) -DCMAKE_INSTALL_PREFIX:PATH=$(readlink -e $(pwd)/..) ..'
