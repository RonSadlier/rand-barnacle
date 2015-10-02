# rand-barnacle
Tool to produce random binary files using Mersenne Twister algorithm.

## Dependencies
* C++11
* Boost

## Installation
```shell
$ mkdir build
$ cd build
$ cmake ../
$ make
$ sudo make install
```

## Usage

parameter | name | type | required | default
--- | --- | --- | --- | ---
-h (--help) | *print help* | *none* | no | *none*
-s (--seed) | *seed value* | Ulong | no | System clock with at worst millisecond precision.
-o (--output) | *output file* | string | yes | *none*
-c (--count) | *byte count* | Ulong | yes | *none*
