#ifndef VALIDATING_USER_INPUT
#define VALIDATING_USER_INPUT

#include <string>
using std::string;

string read_string (string prompt);
int read_integer (string prompt);
double read_double (string prompt);
double read_double_range (string prompt, double min, double max);
bool read_boolean (string prompt);

#endif