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
void merge(Image image);
void flip(Image image);
void rotate(Image image);
void darken_lighten(Image image);
void crop(Image image);
void frame(Image image);
void edges(Image image);
void resize(Image image);
void blur(Image image);
/*--------------------------------------------*/
void Sunlight(Image image);
void look_Purple(Image image);
void IR(Image image);
void tv(Image image);
void oil(Image image);
void Skewed(Image image);
void sepia(Image image);
void Pixelate(Image image);
string test();
#endif // IMAGE_PROCESSOR_H
