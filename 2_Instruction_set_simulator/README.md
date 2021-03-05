# Assignment 2: Instruction Set Simulator

## Introduction

In this C++ assignment, you will work on a so-called Instruction Set Simulator (ISS). Such a simulator simulates the instruction set (or subset of it) of a specific processor. The simulator of this assignment will simulate a very limited subset (four instructions) of the MIPS instruction set.

## Overview

The simulator is very simple, it has no memory, so instructions can only operate on registers. The simulator consists of two parts:
* Set of registers
* Program with instructions

Text-based user interface
* d Disassaemble program
* e Execute program
* h Show help screen
* q Quit
* f Print registers
* s Single step program

## Getting started

### Windows
```
Install windows subsystem for linux
https://docs.microsoft.com/en-us/windows/wsl/install-win10
sudo apt-get update
sudo apt-get install build-essential cmake
```
in directory with cmakefile
```
mkdir build && cd build
cmake ../ && make
./app
```
