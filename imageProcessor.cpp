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
    // Clear input buffer
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    image.saveImage(file_name);
    cout << file_name << " Saved succesfully.\n";
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

void flip(Image image) //Abdallah
{
    cout << "flip\n";

}


void rotate(Image image)
{
    int angle;
    cout << "How much rotation angle would you like? (90, 180, 270)\n"
            "Choice: ";
    cin >> angle;
    Image final;
    // Perform rotation based on angle
    for (int rotation = 0; rotation < angle / 90; ++rotation)
    {

//        // Create a new rotated image for each rotation
        Image rotated_image = Image(image.height, image.width); // Initialize rotated image with correct dimensions

        for (int i = 0; i < rotated_image.height; ++i)
        {
            for (int j = 0; j < rotated_image.width; ++j)
            {
                for (int k = 0; k < 3; ++k)
                {
                    if (rotation == 0) // 90-degree rotation
                    {
//                        // Rotate pixel (i, j) to (j, image.height - i - 1)
                        rotated_image(rotated_image.width - j - 1, i, k) = image(i, j, k);
//                        rotated_image(j, rotated_image.height - i - 1, k) = image(i, j, k);
                    }
//                    else if (rotation == 1) // 180-degree rotation
//                    {
//                        // Rotate pixel (i, j) to (image.width - j - 1, image.height - i - 1)
//                        rotated_image(image.width - j - 1, image.height - i - 1, k) = image(i, j, k);
//                    }
//                    else if (rotation == 2) // 270-degree rotation
//                    {
//                        // Rotate pixel (i, j) to (image.width - j - 1, i)
//                        rotated_image(image.width - j - 1, i, k) = image(i, j, k);
//                    cout << angle;
                }
            }
        }
        final = rotated_image;

//        // Assign rotated image to original image for next iteration (if any)
//        image = rotated_image;
        save(rotated_image);
    }

}



//void rotate(Image image)
//{
//    int angle;
//    cout << "How much rotation angle would you like? (90, 180, 270)\n"
//            "Choice: ";
//    cin >> angle;
//
//    Image rotated_image(image.height, image.width); // Initialize rotated image with correct dimensions
//
//    if (angle == 90)
//    {
//        for (int i = 0; i < rotated_image.height; ++i)
//        {
//            for (int j = 0; j < rotated_image.width; ++j)
//            {
//                for (int k = 0; k < 3; ++k)
//                {
//                    // Rotate pixel (i, j) to (j, rotated_image.height - i - 1)
//                    rotated_image(rotated_image.width - j - 1, i, k) = image(i, j, k);
//                }
//            }
//        }
//    }
//    else if (angle == 180)
//    {
//        // Implement rotation by 180 degrees (similar logic)
//    }
//    else if (angle == 270)
//    {
//        // Implement rotation by 270 degrees (similar logic)
//    }
//    else
//    {
//        cout << "Invalid angle choice." << endl;
//        return; // Exit function if angle is invalid
//    }
//
//    save(rotated_image);
//}





void darken_lighten(Image image) //Hossam
{
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




//
//        void rotate(Image image) //Loai
//        {
//            Image rotated_image;
//            rotated_image.width = image.height;
//            rotated_image.height = image.width;
//            int angle;
//            cout << "How much rotation angle would you like? (90, 180, 270)\n"
//                    "Choice: ";
//            cin >> angle;
//// ******************* error handle!!!!!
////    if 90 angle
//            if (angle == 90)
//            {
//                for (int i = 0; i < rotated_image.width; i++)
//                {
//                    cout << "2 \n";
//                    for (int j = 0; j < rotated_image.height; j++)
//                    {
//                        cout << "3 \n";
//                        for (int k = 0; k < 3; k++)
//                        {
//                            cout << "4 \n";
//                            rotated_image(j, rotated_image.width - i - 1, k) = image(i, j, k);
//                            cout << "5 \n";
//                        }
//                    }
//                    cout << "6 \n";
//                }
//                cout << "7 \n";
//
//            }
//            save(rotated_image);
//            cout << "darken_lighten\n";
//
//        }
