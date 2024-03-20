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
        cout << "\n      Welcome to Baby Photoshop!\n\n";
        string file_name;
        cout << "Please enter the image name (with the extension included): ";
        cin >> file_name;

//    construct image object
        Image image(file_name);

//        display menu
        menu(image);

//        rerun program
        string ans;
        cout << "Would you like to Filter a new image? (y/n) ";
        cin >> ans;
        if (ans == "n")
        {
//            exit
            return 0;
        }
        else if (ans != "y")
        {
            while (ans != "y") {
                cout << "please enter a valid option\n";
                cout << "Would you like to Filter a new image? (y/n) ";
                cin >> ans;
                if (ans == "n")
                {
//                  exit
                    return 0;
                }
            }
        }

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
    image.saveImage(file_name);
}


//  ********************** Filters ****************************
void grayscale(Image image) //Hossam
{
 cout << "grayscale\n";
}

void black_white(Image image) //Abdallah
{
    cout << "black_white\n";

}

void inverted(Image image) //Loai
{
    cout << "inverted\n";

}

void merge(Image image) //Hossam
{
    cout << "merge\n";

}

void flip(Image image) //Abdallah
{
    cout << "flip\n";

}

void rotate(Image image) //Loai
{
    cout << "rotate\n";

}

void darken_lighten(Image image) //Hossam
{
    cout << "darken_lighten\n";

}

void crop(Image image) //Abdallah
{
    cout << "crop\n";

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

