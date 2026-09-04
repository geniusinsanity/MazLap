# MazLap

MazLap is a maz game and algorithm visulization project written in C.

the goal of this project isn't only to create a game, but also to understand how maze genration and pathfinding algorithms work.

this project is built step by step, starting from the basics of linux, git , and C programing language.

## 1. Project setup

this section explains how the project was created from scratch.


### 1.1 Creating the project directory

we create the project directory using: **make directory**

``` bash
mkdir -p ~/Desktop/Projects/MazLap
```

then entering the folder using: **change directory**

``` bash
cd ~/MazLap
```
we crate main function and the main.c file using: **touch**

``` bash
touch main.c
```

### 1.2 Creating the Makefile

we create a makefile using: **touch**

``` bash
touch Makefile
```

then we make the file cleans and build and run the project in one cmande

### 1.3 Run the project

to run the project, we use: **make**

``` bash
make
```

this will create an executable file named `main` in the project directory.

### 1.3 RayLib setup

to setup raylib we will use this command:

``` bash
sudo apt install libraylib-dev
```
then:
``` bash
pkg-config --modversion raylib
```

