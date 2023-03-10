/*

Purpose of program: To manage the data for a bookclub with club members and books using C++.

Usage: 1. Open the Command prompt and navigate to the directory where the files are stored
       2. Compile the files using the Makefile by typing "make" in the Command prompt then press Enter
       3. Run the executable created which is called "midterm" by typing "./midterm" and then press Enter

Author(s): Daniel Adebola-Dada

*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "Control.h"

int main(){
  Control control;
  control.launch();

  return 0;
}
