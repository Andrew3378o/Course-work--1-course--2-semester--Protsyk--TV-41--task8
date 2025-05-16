#ifndef PRINT_H
#define PRINT_H

#include "cell.h"
#include <string>
#define SIZE 10

void print_row(Cell cells[], int cols);
void print(Cell *cells[], int rows, int cols);
void print_title(std::string title, int cols = 0);

#endif