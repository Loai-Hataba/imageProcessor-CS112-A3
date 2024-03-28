/*
Program: Image Processor (baby photoshop)
Description: A program that applies several filters and modifications to a photo.
Version: 1.0
Date: 20/3/2024
Authors: Loai Hataba,       ID: 20230553, Section: S24, Email: Loaiwleed2005@gmail.com,       Filters: 3, 6, 9, 12
         Abdallah mohammed, ID: 20230231, Section: S24, Email: abdallamohammmed649@gmail.com, Filters: 2, 5, 8, 11
         Hossam Abdelaziz,  ID: 20230121, Section: S24, Email: saulgoodman2005@gmail.com,     Filters: 1, 4, 7, 10
*/

#include <iostream>
#include <cmath>
#include <vector>
#include "Image_Class.h"
using namespace std;

//prototypes
void menu(Image image);
void save(Image image);
void continuePhotshop () ;

void choose_filter(string ans, Image image);

/*--------------------------------------------*/
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
/*------------------------------------------*/
void Magenta(Image image) ;
//void applyInfraredFilter(Image image);

/*To make:
1- Endless program loop
2- Safeguard unsigned colors
3- Handle current image save and Load
4- add automatic naming for file name in main menu
5- add usage instructions
6- safeguard all int input with chars
7- add fancier frame (as in assignment sheet or better)
*/


int main() {
    bool flag = true ;
    while (flag) {
        cout << "\n      Welcome to Photoshop on a budget! \n"
                "       (Last updated to the A3 V6.0!!)\n\n";
        string file_name;
        cout << "Please enter the image name (with the extension included): ";
        cin >> file_name;

//    construct image object
        string path = file_name;
        Image image(path);
//        display menu
        menu(image);
    }
    return 0;
}

//display menu
void menu(Image image) {
    string ans;
    cout << "\n\nChoose which filter you would like to apply\n"
            "1)  Grayscale\n"
            "2)  Black & White\n"
            "3)  Inverted\n"
            "4)  Merge\n"
            "5)  Flip \n"
            "6)  Rotate\n"
            "7)  Darken/Lighten\n"
            "8)  Crop \n"
            "9)  Add Frame (Under Construction...)\n"
            "10) Edges\n"
            "11) Resize \n"
            "12) Blur\n"
            "13) Exit\n"
            "Choice: ";
    cin >> ans;
    choose_filter(ans, image);
}

//call filter
void choose_filter(string ans, Image image) {
    if (ans == "1") {
        grayscale(image);
    } else if (ans == "2") {
        black_white(image);
    } else if (ans == "3") {
        inverted(image);
    } else if (ans == "4") {
        merge(image);
    } else if (ans == "5") {
        flip(image);
    } else if (ans == "6") {
        rotate(image);
    } else if (ans == "7") {
        darken_lighten(image);
    } else if (ans == "8") {
        crop(image);
    } else if (ans == "9") {
        frame(image);
    } else if (ans == "10") {
        edges(image);
    } else if (ans == "11") {
        resize(image);
    } else if (ans == "12") {
        blur(image);
    }
    else if (ans == "13")
    {
        cout << "Goodbye!!";
        return;
    }
    else if (ans == "14") {
        Magenta(image);
    }
  /*  else if (ans == "15") {
        applyInfraredFilter(image);
    }*/
    else {
        cout << "Invalid choice!\n";
    }
}

//name and save the new file
void save(Image image) {
    string file_name;
    cout << "Choose the name of the new image(include extension <default is jpg>):";
    cin >> file_name;
    // Clear input buffer
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    bool def = true;
    for (int i = 0; i < file_name.size(); ++i) {
        if (file_name[i] == '.')def = false;
    }
    if (def)file_name += ".jpg";
    image.saveImage(file_name);
    cout << file_name << " has been saved successfully.\n";
}

void continuePhotshop () {
    int answer ;
    cout << "\nDo you want to continue in the program or exit  \n1) continue\n2)Exit\nyour choice : " ;
    cin >>answer ;
    if (answer == 1)
    {
        main();
    }
    else if (answer == 2){
        cout << "Goodbye!!";
        return;
    }

}

//  ********************** Filters ****************************
void grayscale(Image image) //Hossam (Done)
{
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
    save(image);
    continuePhotshop () ;

}

void black_white(Image image) //Abdallah (Done)
{
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
    save(image);
    continuePhotshop ();
}

void inverted(Image image) //Loai (done)
{
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

    save(image);
    continuePhotshop () ;
}

void merge(Image image1) //Hossam (Done)
{
    string file_name;  //2nd image input
    cout << "Please enter 2nd image name (with the extension included): ";
    cin >> file_name;
    string path = file_name;
    Image image(path);
    //making another image that have them both merged and setting its dimensions to the smaller image
    Image image3(min(image1.width, image.width), min(image1.height, image.height));
    for (int i = 0; i < image3.width; ++i) {
        for (int j = 0; j < image3.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                //merging them by adding the colors of evey pixel from both images to output image and dividing by 2
                image3(i, j, k) = (image(i, j, k) + image1(i, j, k)) / 2;
            }
        }
    }
    save(image3);
    continuePhotshop () ;

}

void flip(Image image) //Abdallah (done)
{ char choice ;
  cout << "Which flip you want to do Vertical or  Horizontal (V/H) :  " ;
  cin >> choice ;
  choice = toupper(choice) ;
    Image flipped_image(image.width, image.height) ; // store the  flipped image in a new one
  if (choice == 'V'){
      // we will flip the image vertically
      for (int i = 0; i < image.width; ++i) {
          for (int j = image.height - 1; j >= 0; --j) { //  to reach each column of the image in reverse order
              for (int k = 0; k < 3; ++k) {
                  flipped_image(i, image.height - 1 - j, k) = image(i, j, k);
              }
          }
      }

  }
  else if (choice == 'H') {
      // we will flip the image horizontally
      for (int i = image.width - 1; i >= 0 ; i--) {//  to reach each row of the image in reverse order
          for (int j = 0; j < image.height ; ++j) {
              for (int k = 0; k <  3; ++k) {
                  flipped_image(image.width - 1 - i, j, k) = image(i, j, k);
              }
          }
      }
  }
    save(flipped_image);
    continuePhotshop ();
}

void rotate(Image image) //Loai (Done)
{
    int angle;
    cout << "How much rotation angle would you like? (90, 180, 270)\n"
            "Choice: ";
    cin >> angle;
    Image final;
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
        save(rotated_image);
        continuePhotshop () ;
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
        save(rotated_image);
        continuePhotshop () ;
    } else {
        cout << "Invalid angle. Please choose 90, 180, or 270." << endl;
    }
}

void darken_lighten(Image image) //Hossam (Done)
{
    cout << "1) darken   2)lighten\n"
            "Choice: ";
    int choice;
    cin >> choice;              //choice whether you want to darken your image or lighten it
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            //getting color values
            int red = image(i, j, 0);
            int green = image(i, j, 1);
            int blue = image(i, j, 2);
            if (choice == 1) { //darkening
                red = red - red / 2;                //take the original value of the color and subtracting it from its half value thus darkening it
                green =green - green / 2;
                blue =blue - blue / 2;
            } else {
                red = min(red + red / 2, 255);      // same as darkening but adding its half instead and taking the minimum of it and the color white in case the addition exceeds 255
                green = min(green + green / 2, 255);
                blue = min(blue + blue / 2, 255);
            }
            image(i, j, 2) = blue;
            image(i, j, 1) = green;
            image(i, j, 0) = red;
        }
    }
    save(image);
}

void crop(Image image) //Abdallah (done)
{
    int x, y; // the starting points
    int w, h; //  the width and the height of the cropped image
    cout << "Please enter the starting point (x, y): ";
    cin >> x >> y;
    cout << "Please enter the dimensions  of the area to crop: ";
    cin >> w >> h;
    // check validation of user inputs
    if (x < 0 || y < 0){
        cout << "Invalid , please enter a valid starting points \n"  ;
        return;}
    else if (w <= 0 || h <= 0)
    { cout << "Invalid , please enter a valid dimensions \n ";
        return ;}
    else if (x + w > image.width || y + h > image.height){
        cout << "Out of boundaries , please enter a valid dimensions \n " ;
        return;}
    Image cropped_Img(w, h); //create a new image to store the cropped one
    for (int i  =  0  ; i < w  ; ++i) {
        for (int j =   0  ; j < h  ; ++j) {
            for (int k = 0; k < 3; ++k) {
                cropped_Img(i, j, k) = image(i + x  , j  + y  , k);
            }
        }
    }
    save(cropped_Img) ;
    continuePhotshop () ;
}

void frame(Image image) //Loai (Done)
{
    int frame_size;
    cout << "Choose Frame size (Best: 3% of image): ";
    cin >> frame_size;
    char ans;
    cout << "1) Simple Frame\n"
            "2) Textured Frame\n"
            "Choice: ";
    cin >> ans;
    while (ans != '1' || ans != '2')
    {
        cout << "Please a valid choice!\n\n";
        cout << "1) Simple Frame\n"
                "2) Textured Frame\n"
                "Choice: ";
        cin >> ans;
    }
//        Simple frame
    if (ans == '1')
    {
        unsigned int Rcolor, Gcolor, Bcolor;
        cout << "Enter Color values (Usage: R G B): ";
        cin >> Rcolor >> Gcolor >> Bcolor;
//        valid color values
        while (Rcolor > 255 || Rcolor < 0 || Gcolor > 255 || Gcolor < 0 || Bcolor > 255 || Bcolor > 255) {
            cout << "Color Values should between 0 and 255\n";
            cout << "Enter Color values (Usage: R G B): ";
            cin >> Rcolor >> Gcolor >> Bcolor;
        }

//    Horizontal Frame
        for (int i = 0; i < image.width; i++)
        {
            for (int j = 0; j < frame_size; j++)
            {
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
        for (int j = 0; j < image.height; j++)
        {
            for (int i = 0; i < frame_size; i++)
            {
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
    else
    {
//        best at 0.1
        float frequency = 0.1; // Adjust this for texture frequency
//        best using one color
        unsigned int Rtexture = 0; // Color of the texture (adjustable)
        unsigned int Gtexture = 0;
        unsigned int Btexture = 255;
//        Horizontal Frame
        for (int i = 0; i < image.width; i++)
        {
            for (int j = 0; j < frame_size; j++)
            {
                // Calculate the texture intensity based on the sine function
                float texture_intensity = sin(frequency * i) * sin(frequency * j);

                // Interpolate color based on texture intensity
                unsigned int R = static_cast<unsigned int>(Rtexture * texture_intensity);
                unsigned int G = static_cast<unsigned int>(Gtexture * texture_intensity);
                unsigned int B = static_cast<unsigned int>(Btexture * texture_intensity);

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
                unsigned int R = static_cast<unsigned int>(Rtexture * texture_intensity);
                unsigned int G = static_cast<unsigned int>(Gtexture * texture_intensity);
                unsigned int B = static_cast<unsigned int>(Btexture * texture_intensity);

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
    save(image);
    continuePhotshop() ;
}

void edges(Image image) //Hossam (Done)
{
    for (int i = 0; i < image.width; i++) {     //just grey scaling the image before __edging__ it to make it easier
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
    //setting the sensitivity of the diff between each color of the pixels in comparison so that if it exceeds the limit we edge(make it black) that pixel else we whiten it
    int sens = 25;
    //end with less height and width by one because we only check the right and bottom side pixels since they are all we need to check and if we iterate at last pixel of row or column we dont get out of image limits
    for (int i = 0; i < image.width - 1; i++) {
        for (int j = 0; j < image.height - 1; j++) { //here since we grey scaled the image before the values of each color gonna be the same so we just roll with red
            if (abs(image(i, j, 0) - image(i, j + 1, 0) >= sens || abs(image(i, j, 0) - image(i + 1, j, 0)) >= sens)) {
                for (int k = 0; k < 3; ++k) {
                    image(i, j, k) = 0;
                }
            } else {
                for (int k = 0; k < 3; ++k) {
                    image(i, j, k) = 255;
                }
            }
        }
    }
    save(image);
    continuePhotshop () ;

}

void resize(Image image) //Abdallah (Done)
{   int w, h;
    cout <<"Please enter the new dimensions (Width & Height): " ;
    cin >> w >> h ; // getting the values of new dimensions

    Image resized_Img (w,h) ; //create a new image to store the resized one
     float  s ; // the ratio between the width of the original img and the new width
     float  r ; //the ratio between the height of the original img and the new height

    s = static_cast<float>(image.width) / w  ;
    r = static_cast<float>(image.height) / h  ;
    for (int i = 0; i < w ; ++i) {
        for (int j = 0; j <  h; ++j) {
            for (int k = 0; k < 3  ; ++k) {
                int new1 = round(s*i) ;
                int new2 = round(r*j);
                resized_Img (i ,j ,k) = image (new1, new2  , k) ;

            }
        }
    }
 save(resized_Img) ;
    continuePhotshop () ;
}

void blur(Image image) //Loai (Done)
{
    int blur_size;
    cout << "Choose Blur size (1-15)\n"
            "1-->\"Less Blur, more efficient, Time: 5 Sec\"\n"
            "15-->\"More Blur,less efficient, Time: 3 Min\"\n"
            "Choice: ";
    cin >> blur_size;
    while (blur_size < 1 || blur_size > 15) {
        cout << "Range (1-15)!!!\n";
        cout << "Choose Blur size (1-10) (Less Blur,efficient--More Blur,less efficient): ";
        cin >> blur_size;
    }
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
    // Copy the blurred image back to the original image
    save(blurred_image);
    continuePhotshop () ;
}

//  ********************** Bonus ****************************
void Magenta(Image image) {
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            unsigned int red = image(i, j, 0);
            unsigned int blue = image(i, j, 2);


//            invert colors
            image(i, j, 0) = red ;
            image(i, j, 1) = 0;
            image(i, j, 2) = blue;
    }}
    save(image);
    continuePhotshop () ;}

















