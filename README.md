# rand-barnacle
Tool to produce random binary files using Mersenne Twister algorithm. If
no seed is supplied, we look at the system clock with at worst millisecond
precision.

## Dependencies
C++11, Boost

## Build
$ mkdir build   
$ cd build   
$ cmake ../   
$ make   

## Usage
--help, -h Print Help   
--seed, -s Seed Value   
--output, -o Output File   
--count, -c Output Byte Count   
