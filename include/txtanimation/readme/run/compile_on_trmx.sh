#!/bin/bash

part1="run_animation.cpp"
part1res="run_animation_trmx"

part2="run_animation_parser.cpp"
part2res="run_animation_parser_trmx"

echo "Copmpiling... $part1 to $part1res"
g++ $part1 -o $part1res

echo "Copmpiling... $part2 to $part2res"
g++ $part2 -o $part2res
