# rand-barnacle
Tool to produce random binary files using Mersenne Twister algorithm. If no seed is supplied, we look at the system clock with at worst millisecond precision.

## Dependencies
* C++11
* Boost

## Build
```shell
$ mkdir build
$ cd build
$ cmake ../
$ make
```

## Usage

parameter | name | type
---|---|---
--h | *print help* | *none*
--s | *seed value* | Ulong
--o | *output file* | string
--c | *byte count* | Ulong
