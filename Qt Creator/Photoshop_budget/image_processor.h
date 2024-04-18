// image_processor.h
#ifndef IMAGE_PROCESSOR_H
#define IMAGE_PROCESSOR_H
#include <string>
#include "Image_Class.h"
using namespace std;
// Declare the external variable 'ana'
void send (string path );
Image image_path(const std::string& path);
//prototypes
void menu(string path,string filePath);
void choose_filter(string ans, Image image);
void save(Image image, int back = 0, string path = ":/new/tempImag/temp/temp.jpg");
string file_check(string file_name);
int valid(string& input) ;
/*--------------------------------------------*/
void grayscale(string path ,string filePath);
void black_white(string path ,string filePath);
void inverted(string path,string filePath);
void merge(string path,string filePath,int choice,string merge_path);
void flip(string path,string filePath,string choice) ;
void rotate(string path,string filePath, int angle);
void darken(string path,string filePath,int degree);
void lighten(string path,string filePath,int degree);
void crop(string path,string filePath ,int x,int y, int w, int h ) ;
void frame(string path,string filePath, int frame_size, int ans, unsigned int Rcolor, unsigned int Gcolor, unsigned int Bcolor, int pattern = 1);
void edges(string path,string filePath);
void resize_filter(string path,string filePath ,int res_width,int res_height);
void blur(string path,string filePath, int blur_size);
void blur_2d(string path,string filePath, int blur_size);
/*--------------------------------------------*/
void Sunlight(string path,string filePath);
void look_Purple(string path,string filePath);
void IR(string path,string filePath);
void tv(string path,string filePath);
void oil(string path,string filePath);
void Skewed(string path,string filePath,int degree);
void sepia(string path,string filePath);
void Pixelate(string path,string filePath);
string test();
#endif // IMAGE_PROCESSOR_H
