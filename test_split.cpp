/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <cstddef>

int main(int argc, char* argv[])
{
  Node* original = 1,2,3,4;
  Node* even = NULL;
  Node* odd = NULL;
  split(original, odd, even);
  cout << original << " " << even << " " << odd;
}
