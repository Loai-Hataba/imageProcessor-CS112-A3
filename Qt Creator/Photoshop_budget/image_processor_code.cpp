/*
Program: Image Processor (baby photoshop)
Description: A program that applies several filters and modifications to a photo.
Version: 4.0
Date: 20/3/2024
Authors: Loai Hataba,       ID: 20230553, Section: S24, Email: Loaiwleed2005@gmail.com,       Filters: 3, 6, 9, 12
         Abdallah mohammed, ID: 20230231, Section: S24, Email: abdallamohammmed649@gmail.com, Filters: 2, 5, 8, 11
         Hossam Abdelaziz,  ID: 20230121, Section: S24, Email: saulgoodman2005@gmail.com,     Filters: 1, 4, 7, 10
*/

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Image_Class.h"
#include "image_processor.h"
using namespace std;



/*To make:
1- Endless program loop                             (Done)
2- Safeguard unsigned colors                        (Done)
3- Handle current image save and Load               (Done)
4- add automatic naming for file name in main menu  (Done)
5- add usage instructions                           (Done)
6- safeguard all int input with chars               (Done)
7- add color choosing and a fancier frame           (Done)
8- add save to !!!current image or load a new image (Done)
9- not quit after 21) save image                    (Done)
10- continue or load menu adjust                    (Done)
11- proper validation (blur-oil)                    (Done)
12- Safeguard menu choices                          (Done)
13- Flowchart diagram                               *
14- Comments                                        *
15- check file extension when quitting              (Done)
16- Fix tv filter                                   (Done)
17- Handle empty or wrong files when using filters  *
*/



string file_path;

Image temp ;

Image image_path(const std::string& path)
{
    file_path = path;
    cout << file_path << endl;
    Image image(path);
    return image;
}

//name and save the new file
void save(Image image, int back, string path)
{
    image.saveImage(path);
}

//  ********************** Filters ****************************
void grayscale(string path ,string filePath) //Hossam (Done)
{
    cout << "path: " << path << endl;
    Image image(path);
    cout << "path2: " << path << endl;
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            unsigned int avg = 0;
            for (int k = 0; k < 3; ++k) {
                avg += image(i, j, k);
            }
            avg = avg / 3;
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) = avg;
            }
        }
    }
    temp = image ;
    save(image,0,filePath) ;
    cout << "Filter Applied...\n";
}

void black_white(string path ,string filePath) //Abdallah (Done)
{
    Image image(path);
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < 3; ++k) {
                // getting the avg for all channels  for every pixel

                unsigned int average = (image(i, j, 0) + image(i, j, 1) + image(i, j, 2)) / 3;

                // the avg for the colors black and white is (255+0)/ 2 = 127.5

                if (average <= 127.5) { // means that the brightness level is low
                    image(i, j, k) = 0;
                } else { // means that the brightness level is high
                    image(i, j, k) = 255;
                }
            }
        }
    }
    save(image,0,filePath) ;
}

void inverted(string path,string filePath) //Loai (Done)
{
    Image image(path);
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            //            color values
            unsigned int red = image(i, j, 0);
            unsigned int green = image(i, j, 1);
            unsigned int blue = image(i, j, 2);

            //            invert colors
            image(i, j, 0) = 255 - red;
            image(i, j, 1) = 255 - green;
            image(i, j, 2) = 255 - blue;
        }
    }
    save(image,0,filePath) ;
    cout << "Filter Applied...\n";

}

//!!
Image resizeMerge(Image image, int max_width, int max_height) { //straight up copied Abdallah's resized filter
    Image resized_Img(max_width, max_height);
    float s;
    float r;
    // -------------------------------------------------------------------------------------------------------------
    s = static_cast<float>(image.width) / max_width;
    r = static_cast<float>(image.height) / max_height;
    //--------------------------------------------------------------------------------------------------------------
    for (int i = 0; i < max_width; ++i) {
        for (int j = 0; j < max_height; ++j) {
            for (int k = 0; k < 3; ++k) {
                int new1 = round(s * i);
                int new2 = round(r * j);
                resized_Img(i, j, k) = image(new1, new2, k);
            }
        }
    }
    return resized_Img;
}
// void merge(Image image1) //Hossam (Done)
// {
//     string file_name;  //2nd image input
//     cout << "Please enter 2nd image name (Default is .jpg): ";
//     cin >> file_name;
//     string check = file_check(file_name);
//     while (check == "None") {
//         cout << "Please enter 2nd image name (Default is .jpg): ";
//         cin >> file_name;
//         check = file_check(file_name);
//     }
//     string path = check;
//     Image image(path);
//     char choice;
//     cout<<"1) Scale both images to the biggest height and width\n"
//             "2) Merge common area of the smaller image\n"
//             "Choice: ";
//     cin >> choice;
//     while (choice!='1' && choice!='2'){
//         cout<<"Invalid choice,please choose from (1,2):";
//         cin>>choice;
//     }
//     if (choice == '1') { //common area of smaller image
//         //making another image that have them both merged and setting its dimensions to the smaller image
//         Image image3(min(image1.width, image.width), min(image1.height, image.height));
//         for (int i = 0; i < image3.width; ++i) {
//             for (int j = 0; j < image3.height; ++j) {
//                 for (int k = 0; k < 3; ++k) {
//                     //merging them by adding the colors of evey pixel from both images to output image and dividing by 2
//                     image3(i, j, k) = (image(i, j, k) + image1(i, j, k)) / 2;
//                 }
//             }
//         }
//         cout << "Filter Applied...\n";

//     } else { //resized both images to the greatest height and width
//         int m_width = max(image1.width, image.width);
//         int m_height = max(image1.height, image.height);
//         Image image3(m_width, m_height);
//         Image resized_im1 = resizeMerge(image1,m_width,m_height);
//         Image resized_im2 = resizeMerge(image,m_width,m_height);
//         for (int i = 0; i < image3.width; ++i) {
//             for (int j = 0; j < image3.height; ++j) {
//                 for (int k = 0; k < 3; ++k) {
//                     image3(i, j, k) = (resized_im1(i, j, k) + resized_im2(i, j, k)) / 2;
//                 }
//             }
//         }
//         cout << "Filter Applied...\n";

//     }
// }

//!
void flip(string path,string filePath,string choice) //Abdallah (Done)
{
    Image image(path);
    Image flipped_image(image.width, image.height); // store the  flipped image in a new one
    if (choice == "V") {
            // we will flip the image vertically
        for (int i = 0; i < image.width; ++i) {
            for (int j = image.height - 1; j >= 0; --j) { //  to reach each column of the image in reverse order
                for (int k = 0; k < 3; ++k) {
                    flipped_image(i, image.height - 1 - j, k) = image(i, j, k);
                        //we start from the last index the last colum
                    }
                }
            }
         save(flipped_image, 0, filePath);
             cout << "Filter Applied...\n";
        }
    else if (choice == "H") {
        // we will flip the image horizontally
        for (int i = image.width - 1; i >= 0; i--) {//  to reach each row of the image in reverse order
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    flipped_image(image.width - 1 - i, j, k) = image(i, j, k);
                }
            }
        }

        save(flipped_image, 0, filePath);
        cout << "Filter Applied...\n";


    }
}

void rotate(string path ,string filePath, int angle) //Loai (Done)
{
    Image image(path);
    // Perform rotation based on angle
    if (angle == 90 || angle == 270) {
        // For 90 or 270 degrees, transpose and flip the image
        Image rotated_image = Image(image.height, image.width);
        for (int i = 0; i < rotated_image.height; ++i) {
            for (int j = 0; j < rotated_image.width; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (angle == 90) // 90-degree rotation
                    {
                        rotated_image(rotated_image.width - j - 1, i, k) = image(i, j, k);
                    } else if (angle == 270) // 270-degree rotation
                    {
                        rotated_image(j, rotated_image.height - i - 1, k) = image(i, j, k);
                    }
                }
            }
        }
        save(rotated_image,0,filePath) ;
        cout << "Filter Applied...\n";
    }
        //    180 Rotation
    else if (angle == 180) {
        // For 180 degrees, flip the image horizontally and vertically
        Image rotated_image = Image(image.width, image.height);

        for (int i = 0; i < rotated_image.width; ++i) {
            for (int j = 0; j < rotated_image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    // Flip horizontally and vertically
                    rotated_image(i, j, k) = image(image.width - i - 1, image.height - j - 1, k);
                }
            }
        }
        save(rotated_image,0,filePath) ;
    }
}

void darken(string path , string filePath,int degree) //Hossam (Done)
{  Image image(path);
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            //getting color values
            int red = image(i, j, 0);
            int green = image(i, j, 1);
            int blue = image(i, j, 2);
            red = red - red * degree /100;                //take the original value of the color and subtracting it from its determined fraction value thus darkening it
            green = green - green * degree / 100;
            blue = blue - blue * degree / 100;
            image(i, j, 2) = blue;
            image(i, j, 1) = green;
            image(i, j, 0) = red;
        }
    }
    save(image,0,filePath) ;
    cout << "Filter Applied...\n";

}
void lighten(string path , string filePath,int degree){ //Hossam (Done){
    Image image(path);
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            //getting color values
            int red = image(i, j, 0);
            int green = image(i, j, 1);
            int blue = image(i, j, 2);
            red = min(red + red * degree / 100,255);      // same as darkening but adding its determined fraction instead and taking the minimum of it and the color white in case the addition exceeds 255
            green = min(green + green * degree / 100, 255);
            blue = min(blue + blue * degree / 100, 255);
            image(i, j, 2) = blue;
            image(i, j, 1) = green;
            image(i, j, 0) = red;
        }
    }
    save(image,0,filePath) ;
    cout << "Filter Applied...\n";
}
int valid(string& input) {
    bool flag = true;

    for (int i = 0; i < input.size(); ++i) {
        //check if in the input there is invalid input or not
        if (!isdigit(input[i]) || input[i] == 0 ){
            flag = false;
            break;
        }
    }

    if (flag) {
        int result = stoi(input); //convert input to integer
        return result;
    } else {
        cout << "\nInvalid input! Please enter valid dimensions (digits only).\n";
        cin.clear();  // Clear the input buffer to avoid the infinite loop
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        return -1;
    }
}

void crop(string path,string filePath ,int x,int y, int w, int h ) {
    Image image(path);
        Image cropped_Img(w, h); // create a new image to store the cropped one
        for (int i = 0; i < w; ++i) {
            for (int j = 0; j < h; ++j) {
                for (int k = 0; k < 3; ++k) {
                    cropped_Img(i, j, k) = image(i + x, j + y, k);
                    // we add x to i and add y to j to start the image  at the starting points
                }
            }
        }
        save(cropped_Img,0,filePath) ;
        cout << "Filter Applied...\n";
    }


//!!!
void frame(string path ,string filePath, int frame_size, int ans, unsigned int Rcolor, unsigned int Gcolor, unsigned int Bcolor, int pattern) //Loai (Done)
{
    Image image(path);
    //        Simple frame
    if (ans == 1) {
        //    Horizontal Frame
        for (int i = 0; i < image.width; i++) {
            for (int j = 0; j < frame_size; j++) {
                //            upper
                image(i, j, 0) = Rcolor;
                image(i, j, 1) = Gcolor;
                image(i, j, 2) = Bcolor;
                //            lower
                image(i, image.height - 1 - j, 0) = Rcolor;
                image(i, image.height - 1 - j, 1) = Gcolor;
                image(i, image.height - 1 - j, 2) = Bcolor;
            }
        }
        //    Vertical Frame
        for (int j = 0; j < image.height; j++) {
            for (int i = 0; i < frame_size; i++) {
                //            left
                image(i, j, 0) = Rcolor;
                image(i, j, 1) = Gcolor;
                image(i, j, 2) = Bcolor;
                //            right
                image(image.width - 1 - i, j, 0) = Rcolor;
                image(image.width - 1 - i, j, 1) = Gcolor;
                image(image.width - 1 - i, j, 2) = Bcolor;
            }
        }
    }
        //        Textured Frame
    else if (ans == 2)
    {
        //        best at 0.1
        float frequency = 0.1; // Adjust this for texture frequency
        //        Horizontal Frame
        for (int i = 0; i < image.width; i++)
        {
            for (int j = 0; j < frame_size; j++)
            {
                // Calculate the texture intensity based on the sine function
                float texture_intensity = sin(frequency * i) * sin(frequency * j);

                // Interpolate color based on texture intensity
                unsigned int R = static_cast<unsigned int>(Rcolor * texture_intensity);
                unsigned int G = static_cast<unsigned int>(Gcolor * texture_intensity);
                unsigned int B = static_cast<unsigned int>(Bcolor * texture_intensity);

                image(i, j, 0) = R;
                image(i, j, 1) = G;
                image(i, j, 2) = B;

                // Apply same texture to the bottom part
                image(i, image.height - 1 - j, 0) = R;
                image(i, image.height - 1 - j, 1) = G;
                image(i, image.height - 1 - j, 2) = B;
            }
        }
        // Vertical Textured Frame
        for (int j = 0; j < image.height; j++)
        {
            for (int i = 0; i < frame_size; i++)
            {
                // Calculate the texture intensity based on the sine function
                float texture_intensity = sin(frequency * i) * sin(frequency * j);

                // Interpolate color based on texture intensity
                unsigned int R = static_cast<unsigned int>(Rcolor * texture_intensity);
                unsigned int G = static_cast<unsigned int>(Gcolor * texture_intensity);
                unsigned int B = static_cast<unsigned int>(Bcolor * texture_intensity);

                image(i, j, 0) = R;
                image(i, j, 1) = G;
                image(i, j, 2) = B;

                // Apply same texture to the right part
                image(image.width - 1 - i, j, 0) = R;
                image(image.width - 1 - i, j, 1) = G;
                image(image.width - 1 - i, j, 2) = B;
            }
        }
    }
        // Fancy frame
    else if (ans == 3)
    {
        int lineThickness = 5;
        //        diagonals
        if (pattern == 1) {
            for (int i = 0; i < image.width; i++) {
                for (int j = 0; j < image.height; j++) {
                    if ((i < frame_size || i >= image.width - frame_size || j < frame_size ||
                         j >= image.height - frame_size) &&
                        (i + j) % (frame_size / 10) == 0) {
                        // Increase intensity of line colors to thicken the lines
                        for (int dx = -lineThickness / 2; dx <= lineThickness / 2; dx++) {
                            for (int dy = -lineThickness / 2; dy <= lineThickness / 2; dy++) {
                                int x = i + dx;
                                int y = j + dy;
                                if (x >= 0 && x < image.width && y >= 0 && y < image.height) {
                                    image(x, y, 0) = (Rcolor + 50 <= 255) ? Rcolor + 50 : 255; // Red
                                    image(x, y, 1) = (Gcolor + 50 <= 255) ? Gcolor + 50 : 255; // Green
                                    image(x, y, 2) = (Bcolor + 50 <= 255) ? Bcolor + 50 : 255; // Blue
                                }
                            }
                        }
                    }
                }
            }
        }
            //       Checkerboard
        else if (pattern == 2)
        {
            int cellSize = frame_size / 5; // Adjust cell size as needed

            for (int i = 0; i < image.width; i++) {
                for (int j = 0; j < image.height; j++) {
                    if ((i < frame_size || i >= image.width - frame_size || j < frame_size || j >= image.height - frame_size) &&
                        ((i / cellSize) + (j / cellSize)) % 2 == 0) { // Check for checkerboard pattern
                        image(i, j, 0) = (Rcolor + 50 <= 255) ? Rcolor + 50 : 255; // Red
                        image(i, j, 1) = (Gcolor + 50 <= 255) ? Gcolor + 50 : 255; // Green
                        image(i, j, 2) = (Bcolor + 50 <= 255) ? Bcolor + 50 : 255; // Blue
                    }
                }
            }
        }
    }
    save(image,0,filePath) ;
    cout << "Filter Applied...\n";

}

void edges(string path,string filePath) { //Hossam (Done)
    Image image(path);
    for (int i = 0; i < image.width; i++) {     //black and white filter before we detect edges
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < 3; ++k) {
                unsigned int average = (image(i, j, 0) + image(i, j, 1) + image(i, j, 2)) / 3;
                if (average <= 127.5) {
                    image(i, j, k) = 0;
                } else {
                    image(i, j, k) = 255;
                }
            }
        }
    }
    int sens = 255; //doesnt matter value of sensitivity between pixels since image is in black and white filter
    //end with less height and width by one because we only check the right and bottom side pixels since they are all we need to check and if we iterate at last pixel of row or column we dont get out of image limits
    for (int i = 0; i < image.width - 1; i++) {
        for (int j = 0; j < image.height - 1; j++) {
            for (int k = 0; k < 3; ++k) {
                if (abs(image(i, j, k) - image(i, j + 1, k)) == sens ||
                    abs(image(i, j, k) - image(i + 1, j, k)) == sens) {
                    image(i, j, k) = 0;
                } else {
                    image(i, j, k) = 255;
                }
            }
        }
    }
    cout << "Filter Applied...\n";
    save(image,0,filePath) ;

}

//!!
void resize_filter(string path,string filePath ,int res_width,int res_height) //Abdallah (Done)
{  Image image(path);
        if (res_width > 0 && res_height > 0) {
            Image resized_Img(res_width, res_width); //create a new image to store the resized one
            float s; // the ratio between the width of the original img and the new width
            float r; //the ratio between the height of the original img and the new height
            // -------------------------------------------------------------------------------------------------------------
            s = static_cast<float>(image.width) / res_width;
            r = static_cast<float>(image.height) / res_height;
            //--------------------------------------------------------------------------------------------------------------
            for (int i = 0; i < res_width; ++i) {
                for (int j = 0; j < res_height; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        int new1 = round(s * i); // we make s and i normal integers
                        int new2 = round(r * j);
                        resized_Img(i, j, k) = image(new1, new2, k);
                    }
                }
            }
            save(resized_Img,0,filePath) ;
            cout << "Filter Applied...\n";

        }

    }

//!
void blur(string path,string filePath) //Loai (Done)
{Image image(path);
    int blur_size;
    string temp;
    bool test;
    //    check input validation
    do
    {
        test = true;
        cout << "Choose Blur size (1-15)\n"
                "1-->\"Less Blur, more efficient, Time: 5 Sec\"\n"
                "15-->\"More Blur,less efficient, Time: 3 Min\"\n"
                "Choice: ";
        cin >> temp;
        for (auto digit: temp)
        {
            if (not isdigit(digit))
            {
                test = false;
            }
        }
        if (test)
        {
            if (blur_size < 1 || blur_size > 15)
            {
                cout << "Range (1-15)!!!\n";
                test = false;
            }
        }
    }
    while (not test);
    //    turn answer to proper int
    blur_size = stoi(temp);

    int height = image.height;
    int width = image.width;

    Image blurred_image(image.width, image.height);
    cout << "Blurring Image...\n";
    // Iterate over each pixel in the image
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            int sumR = 0, sumG = 0, sumB = 0;
            int count = 0;

            // Iterate over the surrounding pixels within the blur size
            for (int dy = -blur_size; dy <= blur_size; ++dy) {
                for (int dx = -blur_size; dx <= blur_size; ++dx) {
                    int nx = j + dx;
                    int ny = i + dy;

                    // Check if the pixel is within the image bounds
                    if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                        sumR += image(nx, ny, 0);
                        sumG += image(nx, ny, 1);
                        sumB += image(nx, ny, 2);
                        count++;
                    }
                }
            }

            // Calculate the average value and assign it to the blurred image
            blurred_image(j, i, 0) = sumR / count;
            blurred_image(j, i, 1) = sumG / count;
            blurred_image(j, i, 2) = sumB / count;
        }
    }
    save(image,0,filePath) ;
    cout << "Filter Applied...\n";

}

//  ********************** Bonus ****************************
void Sunlight (string path,string filePath) {
    Image image(path) ;
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            int red = image(i, j, 0);
            int green = image(i, j, 1);
            int blue = image(i, j, 2);
            image(i, j, 0) = min(red + 30, 255);
            image(i, j, 1) = min(green + 30, 255);
            image(i, j, 2) = min(blue * 8 / 10, 255);
        }
    }
    save(image,0,filePath) ;
    cout << "Filter Applied...\n";


}

void look_Purple(string path,string filePath) //Abdallah (Done)
{ Image image(path) ;
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            unsigned int red = image(i, j, 0);  //initialize values of each channel
            unsigned int green = image(i, j, 1);
            unsigned int blue = image(i, j, 2);
            float newRed = static_cast<float > (red * 1.2 );//increase the red channel by 20 %
            float newGreen = static_cast<float > (green * 0.8);//decrease the green channel by 20 %
            float newBlue = static_cast<float > (blue * 1.2 );//raise the blue channel by 20 %
            if (newRed > 255) {
                newRed = 255;
            }
            if (newBlue > 255) {
                newBlue = 255;    // all channels that are larger than 255 should be set to (255).
            }
            if (newGreen > 255) {
                newGreen = 255;
            }

            image(i, j, 0) = newRed;
            image(i, j, 1) = newGreen;
            image(i, j, 2) = newBlue;
        }
    }
    save(image,0,filePath) ;
    cout << "Filter Applied...\n";

}

void IR (string path,string filePath) //Abdallah (Done)
{  Image image(path) ;
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned int red = image(i, j, 0);
            unsigned int New_Red = 255; // assign the red channel to be 255
            unsigned int New_Green = 255 - red;
            // fill green channel and blue channel with the inverse of the red channel
            unsigned int New_Blue = 255 - red;
            image(i, j, 0) = New_Red;
            image(i, j, 1) = New_Green;//put the new values in each channel
            image(i, j, 2) = New_Blue;
        }
    }
    save(image,0,filePath) ;
    cout << "Filter Applied...\n";

}

void tv(string path,string filePath) //Loai (Done)
{Image image(path) ;
    // Seed the random number generator
    srand(time(nullptr));

    // Constants for noise intensity
    const double noiseIntensity = 1; // Adjust as needed

    int width = image.width;
    int height = image.height;

    //    cout << "Image width: " << width << ", height: " << height << endl;

    // Generate random numbers outside the loop
    vector<int> randomValues(width * height * 3);
    for (int i = 0; i < width * height * 3; ++i) {
        randomValues[i] = rand() % 256; // Generate random numbers between 0 and 255
    }

    int count = 0;
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            // Get color values
            unsigned int red = image.getPixel(i, j, 0);
            unsigned int green = image.getPixel(i, j, 1);
            unsigned int blue = image.getPixel(i, j, 2);

            //            cout << "Pixel at (" << i << ", " << j << "): ";
            //            cout << "Red: " << red << ", Green: " << green << ", Blue: " << blue << endl;

            // Add noise to each channel, skipping if the color value is below a threshold
            const int threshold = 5; // Adjust as needed
            unsigned int noiseRed = (red < threshold) ? 0 : randomValues[count] % static_cast<int>(red * noiseIntensity);
            unsigned int noiseGreen = (green < threshold) ? 0 : randomValues[count + 1] % static_cast<int>(green * noiseIntensity);
            unsigned int noiseBlue = (blue < threshold) ? 0 : randomValues[count + 2] % static_cast<int>(blue * noiseIntensity);

            // Debugging noise values
            //            cout << "Noise - Red: " << noiseRed << ", Green: " << noiseGreen << ", Blue: " << noiseBlue << endl;

            // Add noise to the original pixel values
            unsigned int newRed = min(red + noiseRed, 255u);
            unsigned int newGreen = min(green + noiseGreen, 255u);
            unsigned int newBlue = min(blue + noiseBlue, 255u);

            // Update image with modified color channels
            image.setPixel(i, j, 0, newRed);
            image.setPixel(i, j, 1, newGreen);
            image.setPixel(i, j, 2, newBlue);

            count += 3;
        }
    }
    save(image,0,filePath) ;
    cout << "Filter Applied...\n";

}

void sepia(string path,string filePath) //Loai (Done)
{ Image image(path) ;
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            // Get color values
            unsigned int red = image(i, j, 0);
            unsigned int green = image(i, j, 1);
            unsigned int blue = image(i, j, 2);

            // Apply sepia tone
            unsigned int newRed = min((int)(red * 0.393 + green * 0.769 + blue * 0.189), 255);
            unsigned int newGreen = min((int)(red * 0.349 + green * 0.686 + blue * 0.168), 255);
            unsigned int newBlue = min((int)(red * 0.272 + green * 0.534 + blue * 0.131), 255);

            // Update image with modified color channels
            image(i, j, 0) = newRed;
            image(i, j, 1) = newGreen;
            image(i, j, 2) = newBlue;
        }
    }
    save(image,0,filePath) ;
    cout << "Filter Applied...\n";

}

void oil (string path,string filePath) //Loai (Done)
{  Image image(path) ;
    unsigned int brushSize = 5;
    bool test;
    int height = image.height;
    int width = image.width;

    Image oil_image(width, height);
    cout << "Applying oil painting filter...\n";

    const int nRadius = brushSize; // Equivalent to brush size in the provided algorithm
    const float fIntensityLevels = 1.0f; // Adjust intensity level as needed

    // Initialize arrays to store intensity count and sum of RGB values
    int nIntensityCount[256] = {0};
    int nSumR[256] = {0};
    int nSumG[256] = {0};
    int nSumB[256] = {0};

    // Iterate over each pixel in the image
    for (int y = nRadius; y < height - nRadius; ++y) {
        for (int x = nRadius; x < width - nRadius; ++x) {
            // Find intensities of nearest nRadius pixels in four directions
            for (int nY_O = -nRadius; nY_O <= nRadius; ++nY_O) {
                for (int nX_O = -nRadius; nX_O <= nRadius; ++nX_O) {
                    // Get color of neighboring pixel
                    unsigned int red = image(x + nX_O, y + nY_O, 0);
                    unsigned int green = image(x + nX_O, y + nY_O, 1);
                    unsigned int blue = image(x + nX_O, y + nY_O, 2);

                    // Find intensity of RGB value and apply intensity level
                    int nCurIntensity = ((red + green + blue) / 3.0) * fIntensityLevels;
                    if (nCurIntensity > 255)
                        nCurIntensity = 255;
                    int i = nCurIntensity;
                    nIntensityCount[i]++;

                    nSumR[i] += red;
                    nSumG[i] += green;
                    nSumB[i] += blue;
                }
            }

            // Find the intensity with the maximum count
            int nCurMax = 0;
            int nMaxIndex = 0;
            for (int nI = 0; nI < 256; ++nI) {
                if (nIntensityCount[nI] > nCurMax) {
                    nCurMax = nIntensityCount[nI];
                    nMaxIndex = nI;
                }
            }

            // Assign the average color to the oil painted image
            oil_image(x, y, 0) = nSumR[nMaxIndex] / nCurMax;
            oil_image(x, y, 1) = nSumG[nMaxIndex] / nCurMax;
            oil_image(x, y, 2) = nSumB[nMaxIndex] / nCurMax;

            // Reset intensity count and sum arrays for the next pixel
            fill_n(nIntensityCount, 256, 0);
            fill_n(nSumR, 256, 0);
            fill_n(nSumG, 256, 0);
            fill_n(nSumB, 256, 0);
        }
    }
    save(oil_image,0,filePath) ;
    cout << "Filter Applied...\n";

}
//!
void Skewed(string path,string filePath,int degree) {
    Image image(path);
    int deg1 = degree;
    bool flip = deg1 > 90;
    if (flip)deg1 -= 90;//if degree greater than 90 just skew it normally then flip
    int margin_of_error = 0;
    if (deg1 <= 20 && deg1>0){
        deg1 = 20;
        margin_of_error = image.width * 2;
    }
    if (deg1 <= 40 && deg1>20){
        deg1 = 40;
        margin_of_error = image.width * 3;
        margin_of_error/=2;
    }
    if (deg1 <= 60 && deg1>40)deg1 = 60;
    double y = deg1 * 3.14159 / 180;//convert degree to radian so we can use cosine
    int cnt = (double) image.height * cos(y);
    Image white(abs((int) (image.width + cnt + margin_of_error)), image.height);
    for (int i = 0; i < white.height; ++i) {
        for (int j = 0; j < white.width; ++j) {
            for (int k = 0; k < 3; ++k) {
                white(j, i, k) = 255;
            }
        }
    }
    cnt+=margin_of_error;
    int denom = ceil(image.height / (double) cnt);
    int diff = 1;
    if (deg1 <= 20 && deg1>0)diff = 2;
    if (deg1 <= 40 && deg1>20){
        denom = 1;
        diff = 1;
    }
    for (int i = 0; i < image.height; ++i) {
        if (cnt <= 0)cnt = 0;
        for (int j = 0; j < image.width; ++j) {
            for (int k = 0; k < 3; ++k) {
                white(j + cnt, i, k) = image(j, i, k);
            }
        }
        if (cnt <= 0)cnt = 0;
        if (i % denom == 0){
            cnt-=diff;
        }
    }
    if (flip) {
        Image flipped_image(white.width, white.height);
        for (int i = white.width - 1; i >= 0; i--) {
            for (int j = 0; j < white.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    flipped_image(white.width - 1 - i, j, k) = white(i, j, k);
                }
            }
        }
        cout << "Filter Applied...\n";
        save(flipped_image);
        return;
    }
    cout << "Filter Applied...\n";
    save(white);
}
//!
void Pixelate(string path,string filePath) {
    Image image(path);
    int Pixel_Size = 10 ;  // This variable handles the size of each pixel
    for (int i = 0; i < image.width; i += Pixel_Size) {
        // Set the new size of the width of each pixel
        for (int j = 0; j < image.height; j += Pixel_Size) {
            // Set the new size of the height of each pixel
            unsigned int avgRed = 0, avgGreen = 0, avgBlue = 0;
            //variables to store the avg of each channel
            int counter = 0;
            for (int x = i; x < i + Pixel_Size && x < image.width; ++x) {
                for (int y = j; y < j + Pixel_Size && y < image.height; ++y) {
                    avgRed += image(x, y,0); // assign it to equal the sum of each red channel                                avgGreen += image(x, y, 1);
                    avgGreen += image(x, y, 1); // assign it to equal the sum of each green channel
                    avgBlue += image(x, y, 2);// assign it to equal the sum of each blue channel
                    counter++;
                }
            }
            // Obtain the avg for each channel
            avgRed = avgRed / counter;
            avgGreen = avgGreen / counter;
            avgBlue = avgBlue / counter;
            for (int x = i; x < i + Pixel_Size && x < image.width; ++x) {
                for (int y = j; y < j + Pixel_Size && y < image.height; ++y) {
                    image(x, y, 0) = avgRed;
                    image(x, y, 1) = avgGreen;
                    image(x, y, 2) = avgBlue;
                }
            }


        }}
    cout << "Pixelation Filter Applied...\n";
    save(image,0,filePath) ;}
