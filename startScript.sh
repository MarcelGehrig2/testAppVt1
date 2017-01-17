#!/bin/bash

# g++ main.cpp -o testAppVt1 -pthread -std=c++11

cd ~/git_repos/VT1/build/testAppVt1

make


~/git_repos/VT1/build/testAppVt1/testappvt1

# gnome-terminal --working-directory="$HOME/git_repos/VT1/build/testAppVt1/" -x bash -c './testappvt1; exec bash' &
