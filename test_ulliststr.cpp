#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
#include <iostream>
using namespace std;

#include <gtest/gtest.h>
#include <random>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
 ULListStr example;
 example.push_back("hello");
 example.push_back("hello");
 example.push_back("hello");
 example.push_back("hello");
 example.push_back("hello");
 example.push_back("hello");
 example.push_back("hello");
 example.push_back("hello");
 example.push_back("hello");
 example.push_back("hello");
 //example.push_back("hello");
 //example.push_back("hello");
 example.push_back("bye");

 
 cout << example.back() << endl;

}
