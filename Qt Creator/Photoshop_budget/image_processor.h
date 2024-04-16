// image_processor.h
#ifndef IMAGE_PROCESSOR_H
#define IMAGE_PROCESSOR_H

#include <string>
#include "Image_Class.h"
using namespace std;

Image image_path(const std::string& path);
//prototypes
void menu(Image image);
void choose_filter(string ans, Image image);
void save(Image image, int back = 0, string path = "F:/Loai/School/Programming/C++/Main/College/Structured_Programming/Assignment 3/imageProcessor-CS112-A3/Qt Creator/Photoshop_budget/temp/temp.jpg");
string file_check(string file_name);
/*--------------------------------------------*/
void grayscale(string path);
void black_white(string path);
void inverted(string path);
void merge(string path);
void flip(string path);
void rotate(string path);
void darken_lighten(string path);
void crop(string path);
void frame(Image image);
void edges(string path);
void resize(string path);
void blur(string path);
/*--------------------------------------------*/
void Sunlight(string path);
void look_Purple(string path);
void IR(string path);
void tv(string path);
void oil(string path);
void Skewed(string path);
void sepia(string path);
void Pixelate(string path);
string test();
#endif // IMAGE_PROCESSOR_H
