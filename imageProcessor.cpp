/*
Program: Image Processor (baby photoshop)
Version: 1.0
Date: 20/3/2024
Authors: Loai Hataba, ID: 20230553, Section: S24, Email: Loaiwleed2005@gmail.com
         Abdallah mohammed, ID: 20230231, Section: S24, Email: abdallamohammmed649@gmail.com
         Hossam Abdelaziz, ID: 20230121, Section: S24, Email: saulgoodman2005@gmail.com

*/

#include <iostream>
#include "Image_Class.h"
using namespace std;

//prototypes
void menu(Image image);
void save(Image image);
void choose_filter(string ans, Image image);

void grayscale(Image image);
void black_white(Image image);
void inverted(Image image);
void merge(Image image);
void flip(Image image);
void rotate(Image image);
void darken_lighten(Image image);
void crop(Image image);
void frame(Image image);
void edges(Image image);
void resize(Image image);
void blur(Image image);


int main()
{
    while (true)
    {
        cout << "\n      Welcome to Photoshop on a budget!\n\n";
        string file_name;
        cout << "Please enter the image name (with the extension included): ";
        cin >> file_name;

//    construct image object
        Image image(file_name);

//        display menu
        menu(image);

    }
    return 0;
}

//display menu
void menu(Image image)
{
    string ans;
    cout << "\n\nChoose which filter you would like to apply\n"
            "1)  Grayscale\n"
            "2)  Black & White\n"
            "3)  Inverted\n"
            "4)  Merge\n"
            "5)  Flip\n"
            "6)  Rotate\n"
            "7)  Darken/Lighten\n"
            "8)  Crop\n"
            "9)  Add Frame\n"
            "10) Edges\n"
            "11) Resize\n"
            "12) Blur\n"
            "Choice: ";
    cin >> ans;
    choose_filter(ans, image);
}

//call filter
void choose_filter(string ans, Image image)
{
    if (ans == "1")
    {
        grayscale(image);
    }
    else if (ans == "2")
    {
        black_white(image);
    }
    else if (ans == "3")
    {
        inverted(image);
    }
    else if (ans == "4")
    {
        merge(image);
    }
    else if (ans == "5")
    {
        flip(image);
    }
    else if (ans == "6")
    {
        rotate(image);
    }
    else if (ans == "7")
    {
        darken_lighten(image);
    }
    else if (ans == "8")
    {
        crop(image);
    }
    else if (ans == "9")
    {
        frame(image);
    }
    else if (ans == "10")
    {
        edges(image);
    }
    else if (ans == "11")
    {
        resize(image);
    }
    else if (ans == "12")
    {
        blur(image);
    }
    else{
        cout << "Invalid choice!\n";
    }
}


//name and save the new file
void save(Image image)
{
    string file_name;
    cout << "Choose the name of the new image(include extension):";
    cin >> file_name;
    cout << file_name << endl;
    image.saveImage(file_name);
    cout << file_name << " Saved succesfully.\n";
}


//  ********************** Filters ****************************
void grayscale(Image image) //Hossam
{  cout << "hoss \n" ;
    save(image);
}

void black_white(Image image) //Abdallah
{
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < 3; ++k) {
                // getting the avg for all channels  for every pixel

                unsigned int average = (image(i, j, 0) + image(i, j, 1) + image(i, j, 2)) / 3;

                // the avg for the colors black and white is (255+0)/ 2 = 127.5

                if (average <= 127.5) { // means that the brightness level is low
                    image(i, j, k) = 0; }
                else { // means that the brightness level is high
                    image(i, j, k) = 255; }
            }
        }
    }




    save(image);

}

void inverted(Image image) //Loai (done)
{
    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            unsigned int red = image(i, j, 0);
            unsigned int green = image(i, j, 1);
            unsigned int blue = image(i, j, 2);

            image(i, j, 0) = 255 - red;
            image(i, j, 1) = 255 - green;
            image(i, j, 2) = 255 - blue;
        }
    }

    save(image);
}

void merge(Image image) //Hossam
{
    cout << "merge\n";

}

void flip(Image image) {
    // we will flip the image vertically
    Image flipped_image(image.width, image.height);     // store the  flipped image in a new one
    for (int i = 0; i < image.width; ++i) {
        for (int j = image.height - 1; j >= 0; --j) { //  to reach each column of the image in reverse order
            for (int k = 0; k < 3; ++k) {
                flipped_image(i, image.height - 1 - j, k) = image(i, j, k);
            }
        }
    }

    // Save the flipped image
    save(flipped_image);
}



void rotate(Image image) //Loai
{
    Image rotated_image;
    rotated_image.width = image.height;
    rotated_image.height = image.width;
    int angle;
    cout << "How much rotation angle would you like? (90, 180, 270)\n"
            "Choice: ";
    cin >> angle;
// ******************* error handle!!!!!
//    if 90 angle
    if (angle == 90)
    {
        cout << "1 \n";
        for (int i = 0; i < rotated_image.width; i++)
        {
            cout << "2 \n";
            for (int j = 0; j < rotated_image.height; j++)
            {
                cout << "3 \n";
                for (int k = 0; k < 3; k++)
                {
                    cout << "4 \n";
                    rotated_image(j, rotated_image.width - i - 1, k) = image(i, j, k);
                }
            }
        }
    }
    save(rotated_image);
//    if 180 angle
//    else if (angle == 180)
//    {
//
//    }
////    if 270 angle
//    else if (angle == 270)
//    {
//
//    }

}

void darken_lighten(Image image) //Hossam
{
    cout << "darken_lighten\n";

}

void crop(Image image) //Abdallah
{
    cout  << "crop\n";

}

void frame(Image image) //Loai
{
    cout << "frame\n";

}

void edges(Image image) //Hossam
{
    cout << "edges\n";

}

void resize(Image image) //Abdallah
{
    cout << "resize\n";

}

void blur(Image image) //Loai
{
    cout << "blur\n";

}

/*void grayscale(Image image) //Hossam
{  for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        { unsigned  int avg = 0 ;
            for (int k = 0; k < 3 ; ++k) {
                avg += image(i, j, k) ;
            }
            avg = avg / 3 ;
            for (int k = 0; k < 3; ++k) {
                image(i,j,k) = avg ;
            }
        }
    }

    save(image);
}*/