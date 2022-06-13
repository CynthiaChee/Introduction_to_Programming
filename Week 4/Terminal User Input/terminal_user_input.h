#ifndef TERMINAL_USER_INPUT
#define TERMINAL_USER_INPUT

#include <string>
using std::string;

string read_string(string prompt);
int read_integer (string prompt);
int read_integer (string prompt, int min, int max);

#endif