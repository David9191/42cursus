#!/bin/bash

echo "case1 : \" \""
./push_swap " "
echo ""

echo "case2 : \" \" 1 2 3"
./push_swap " " 1 2 3
echo ""

echo "case3 : 1 2 3 \" \""
./push_swap 1 2 3 " "
echo ""

echo "case4 : 1 \"\" 3 "
./push_swap 1 "" 3
echo ""

echo "case5 : 1 1"
./push_swap 1 1
echo ""

echo "case6 : -00124 -124"
./push_swap -00124 -124
echo ""

echo "case7 : -2-"
./push_swap -2-
echo ""

echo "case8 : --2"
./push_swap --2
echo ""

echo "case9 : 2++"
./push_swap 2++
echo ""

echo "case10 : 2+3"
./push_swap 2+3
echo ""

echo "case11 : 23+"
./push_swap 23+
echo ""

echo "case12 : + -"
./push_swap + -
echo ""

echo "case13 : one 2 three"
./push_swap one 2 three
echo ""

echo "case14 : 2147483648"
./push_swap 2147483648
echo ""

echo "case15 : -2147483649"
./push_swap -2147483649
echo ""
