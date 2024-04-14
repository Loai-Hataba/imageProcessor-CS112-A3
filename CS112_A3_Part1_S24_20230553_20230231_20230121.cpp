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
using namespace std;

//prototypes
void menu(Image image);
void choose_filter(string ans, Image image);
void save(Image image, int back = 0);
string file_check(string file_name);
int valid(string& input) ;
/*--------------------------------------------*/
void grayscale(Image image);
void black_white(Image image);
void inverted(Image& image);
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
*/

int main() {
    bool flag = true;
    while (flag) {
        cout << "\n\n      Welcome to Photoshop on a budget! \n\n";
        string file_name;
        cout << "Please enter the image name (Default is .jpg): ";
        cin >> file_name;
//        check file
        string check = file_check(file_name);
//        doesn't exist
        if (check == "None")
        {
            continue;
        }
//    construct image object
        string path = check;
;        Image image(path);

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
            "9)  Frame \n"
            "10) Edges\n"
            "11) Resize \n"
            "12) Blur\n"
            "13) Look Purple\n"
            "14) Infrared Radiation (IR)\n"
            "15) TV\n"
            "16) Oil Painting\n"
            "17) Sepia\n"
            "18) Sunlight\n"
            "19) Skewed\n"
            "20) Pixelate \n"
            "21) Save Image\n"
            "22) Load Image\n"
            "23) Exit\n"
            "Choice: ";
    cin >> ans;
    choose_filter(ans, image);
}


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
    } else if (ans == "13") {
        look_Purple(image);
    } else if (ans == "14") {
        IR(image);
    } else if (ans == "15") {
        tv(image);
    } else if (ans == "16") {
        oil(image);
    } else if (ans == "17") {
        sepia(image);
    } else if (ans == "18") {
        Sunlight(image);
    } else if (ans == "19") {
        Skewed(image);
    } else if (ans == "20") {
        Pixelate(image);
    }
//    Save
    else if (ans == "21") {
        save(image, 1);
    }
//    Load new image
    else if (ans == "22") {
        main();
    }
//    Exit
    else if (ans == "23") {
        string ex;
        cout << "Do you want to save before exiting?\n"
                "1) Yes\n"
                "2) No\n"
                "Choice: ";
        cin >> ex;
        if (ex == "1")
        {
            save(image);
        }
        else if (ex == "2")
        {
            cout << "\nGoodbye!!";
            return;
        } else {
            cout << "Invalid choice!\n";
        }
    } else {
        cout << "Invalid choice!\n";
        menu(image);
    }
}

//name and save the new file
void save(Image image, int back)
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    string file_name;
    cout << "Choose the name of the new image (Default is .jpg):";
    getline(cin, file_name);
    bool check = false;
    bool def = true;
    for (int i = 0; i < file_name.size(); ++i) {
        if (file_name[i] == '.')def = false;
    }
    if (def)file_name += ".jpg";
    else if (not def) {
        do
        {
            for (int i = 0; i < file_name.length(); i++) {
                if (file_name[i] == '.') {
                    string t = file_name.substr(i + 1, 3);
                    if (t != "jpg" && t != "png" && t != "bmp" && t != "tga") {
                        cout << "File extension unsupported (jpg, png, bmp, tga)!\n";
                        menu(image);
                    }
                }
            }
        }
        while (check);
    }
    cout << "Saving " << file_name << "...\n";
    image.saveImage(file_name);
    cout << file_name << " has been saved successfully.\n";
    if (back == 1)
    {
        menu(image);
    }
}

//checks file is valid
string file_check(string file_name)
{
//    auto name extension
    bool def = true;
    for (int i = 0; i < file_name.size(); ++i) {
        if (file_name[i] == '.')def = false;
    }
//    default .jpg
    if (def)file_name += ".jpg";
//  check file exists
    ifstream file;
    file.open(file_name);
//    exists
    if (file)
    {
        file.close();
        return file_name;
    }
//        doesn't exist
    else
    {
        cout << "File Doesn't exist!\n";
        return "None";
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
    cout << "Filter Applied...\n";
    menu(image);

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
    cout << "Filter Applied...\n";
    menu(image);
}

void inverted(Image& image) //Loai (Done)
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
    cout << "Filter Applied...\n";
    menu(image);
}

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

void merge(Image image1) //Hossam (Done)
{
    string file_name;  //2nd image input
    cout << "Please enter 2nd image name (Default is .jpg): ";
    cin >> file_name;
    string check = file_check(file_name);
    while (check == "None") {
        cout << "Please enter 2nd image name (Default is .jpg): ";
        cin >> file_name;
        check = file_check(file_name);
    }
    string path = check;
    Image image(path);
    string choice;
    cout<<"1) Scale both images to the biggest height and width\n"
          "2) Merge common area of the smaller image\n"
          "Choice: ";
    cin >> choice;
    while (choice!="1" && choice!="2" || choice.size()!=1){
        cout<<"Invalid choice,please choose from (1,2):";
        cin>>choice;
    }
    if (choice == "1") { //common area of smaller image
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
        cout << "Filter Applied...\n";
        menu(image3);
    } else { //resized both images to the greatest height and width
        int m_width = max(image1.width, image.width);
        int m_height = max(image1.height, image.height);
        Image image3(m_width, m_height);
        Image resized_im1 = resizeMerge(image1,m_width,m_height);
        Image resized_im2 = resizeMerge(image,m_width,m_height);
        for (int i = 0; i < image3.width; ++i) {
            for (int j = 0; j < image3.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image3(i, j, k) = (resized_im1(i, j, k) + resized_im2(i, j, k)) / 2;
                }
            }
        }
        cout << "Filter Applied...\n";
        menu(image3);
    }
}


void flip(Image image) //Abdallah (Done)
{
    char choice;
    cout << "Which flip you want to do Vertical or  Horizontal (V/H):  ";
    cin >> choice;
    if (isalpha(choice)) {
        choice = toupper(choice); // change the input to uppercase character
        Image flipped_image(image.width, image.height); // store the  flipped image in a new one
        if (choice == 'V') {
            // we will flip the image vertically
            for (int i = 0; i < image.width; ++i) {
                for (int j = image.height - 1; j >= 0; --j) { //  to reach each column of the image in reverse order
                    for (int k = 0; k < 3; ++k) {
                        flipped_image(i, image.height - 1 - j, k) = image(i, j, k);
                        //we start from the last index the last colum
                    }
                }
            }
        } else if (choice == 'H') {
            // we will flip the image horizontally
            for (int i = image.width - 1; i >= 0; i--) {//  to reach each row of the image in reverse order
                for (int j = 0; j < image.height; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        flipped_image(image.width - 1 - i, j, k) = image(i, j, k);
                    }
                }
            }
        } else {
            cout << "Invalid Input ,please insert a correct character !  \n";
            flip(image);
        }
        cout << "Filter Applied...\n";
        menu(flipped_image);
    } else {
        cout << "\nInvalid Input ,please insert a correct character !  \n";
        flip(image);
    }
}

void rotate(Image image) //Loai (Done)
{
    int angle;
    string ang;
    cout << "How much rotation angle would you like? (90, 180, 270)\n"
            "Choice: ";
    cin >> ang;
    while (ang != "90" && ang != "180" && ang != "270") {
        cout << "Please Enter a valid angle (90, 180, 270): ";
        cin >> ang;
    }
    angle = stoi(ang);
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
        cout << "Filter Applied...\n";
        menu(rotated_image);
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
        menu(rotated_image);
    } else {
        cout << "Invalid angle. Please choose 90, 180, or 270." << endl;
    }
}

void darken_lighten(Image image) //Hossam (Done)
{
    cout << "1) darken   2)lighten\n"
            "Choice: ";
    int degree;
    string choice;
    cin >> choice;              //choice whether you want to darken your image or lighten it
    while (choice != "1" && choice != "2" || choice.size()!=1) {
        cout << "Invalid choice please enter a valid value:";
        cin >> choice;
    }
    string choice2;
    if (choice == "1")choice2 = "darkening";
    else choice2 = "lighting";
    cout << "choose the level of " << choice2 << " from 0 to 100 percent :"; //choosing level of darkening or lighting
    cin >> degree;
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            //getting color values
            int red = image(i, j, 0);
            int green = image(i, j, 1);
            int blue = image(i, j, 2);
            if (choice == "1") { //darkening
                red = red - red * degree /
                            100;                //take the original value of the color and subtracting it from its determined fraction value thus darkening it
                green = green - green * degree / 100;
                blue = blue - blue * degree / 100;
            } else {
                red = min(red + red * degree / 100,
                          255);      // same as darkening but adding its determined fraction instead and taking the minimum of it and the color white in case the addition exceeds 255
                green = min(green + green * degree / 100, 255);
                blue = min(blue + blue * degree / 100, 255);
            }
            image(i, j, 2) = blue;
            image(i, j, 1) = green;
            image(i, j, 0) = red;
        }
    }
    cout << "Filter Applied...\n";
    menu(image);
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

void crop(Image image) {
    string strX, strY, strW, strH;
    int x, y, w, h;
    // x and y reference  to the starting  point
    // w and h reference to the width and the height of the cropped image

    cout << "The dimensions of the image are: " << image.width << " * " << image.height << endl;
    cout << "Please enter the starting point (x, y)" << endl; //to show the original dimensions

    cout << "  The Starting point of X-axis: ";
    cin.ignore(1);
    cin >> strX;
    x = valid(strX);
    while (x == -1 ){
        // this step to allow the user to Reenter The Staring point of X-axis
        //--> (-1) is a returned  value  from function valid if there is error
        cout << "  The Starting point of X-axis: ";
        cin.ignore(1);
        cin >> strX;
        x = valid(strX);
    }
    //------------------------------------------------------------------------------------------------------------------
    cout << "The Starting point of Y-axis: ";
    cin.ignore(1);
    cin >> strY;
    y = valid(strY);
    while (y == -1){
        // this step to allow the user to Reenter The Staring point of Y-axis  again
        //--> (-1) is a returned  value  from function valid if there is error
        cout << "The Starting point of Y-axis: ";
        cin.ignore(1);
        cin >> strY;
        y = valid(strY);
    }
    //------------------------------------------------------------------------------------------------------------------
    cout << "Please enter the dimensions of the cropped image" << endl;
    cout << "  The Width of the Cropped Image: ";
    cin.ignore(1);
    cin >> strW;
    w = valid(strW);
    while(w == -1){
        // this step to allow the user to Reenter The Width of the Cropped Image again
        //--> (-1) is a returned  value  from function valid if there is error
        cout << "  The Width of the Cropped Image: ";
        cin.ignore(1);
        cin >> strW;
        w = valid(strW);
    }
    //------------------------------------------------------------------------------------------------------------------
    cout << "The Height of the Cropped Image: ";
    cin.ignore(1);
    cin >> strH;
    h = valid(strH);
    while (h == -1){
        // this step to allow the user to Reenter The Height of the Cropped Image again
        //--> (-1) is a returned  value  from function valid if there is error
        cout << "The Height of the Cropped Image: ";
        cin.ignore(1);
        cin >> strH;
        h = valid(strH);
    }
    //------------------------------------------------------------------------------------------------------------------
    if ((x + w) > image.width || (y + h) > image.height) {
        // if the sum  is higher than the original dimensions
        cout << "Out of bounds, Please enter valid dimensions!\n";
        cin.clear();  // Clear the input buffer to avoid the infinite loop
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        crop(image) ;
    }
    else {
        Image cropped_Img(w, h); // create a new image to store the cropped one
        for (int i = 0; i < w; ++i) {
            for (int j = 0; j < h; ++j) {
                for (int k = 0; k < 3; ++k) {
                    cropped_Img(i, j, k) = image(i + x, j + y, k);
                    // we add x to i and add y to j to start the image  at the starting points
                }
            }
        }
        cout << "Filter Applied...\n";
        menu(cropped_Img);
    }
}



void frame(Image image) //Loai (Done)
{
    int frame_size;
    string temp;
    bool test;
    do {
        test = true;
        cout << "Choose Frame size in pixels (Best: 3% of image): ";
        cin >> temp;
        for (auto digit: temp) {
            if (not isdigit(digit)) {
                test = false;
            }
        }
    } while (not test);
    frame_size = stoi(temp);
    string ans;
    cout << "1) Simple Frame\n"
            "2) Textured Frame\n"
            "3) Fancy Frame\n"
            "Choice: ";
    cin >> ans;
    while (ans != "1" && ans != "2" && ans != "3") {
        cout << "Please Enter a valid choice!\n\n";
        cout << "1) Simple Frame\n"
                "2) Textured Frame\n"
                "3) Fancy Frame\n"
                "Choice: ";
        cin >> ans;
    }
//        Simple frame
    if (ans == "1") {
        unsigned int Rcolor, Gcolor, Bcolor;
        char col = '0';
        while (col == '0') {
            cout << "Frame color\n"
                    "1) Colors\n"
                    "2) Manual RGB values\n"
                    "Choice: ";
            cin >> col;
            if (col == '1') {
                char color_choice = '0';
                while (color_choice == '0') {
                    cout << "Colors:\n"
                            "1) Red\n"
                            "2) Blue\n"
                            "3) Green\n"
                            "4) Brown\n"
                            "5) Yellow\n"
                            "6) Turquoise\n"
                            "Choice: ";
                    cin >> color_choice;
//                       Red
                    if (color_choice == '1') {
                        Rcolor = 255;
                        Bcolor = 0;
                        Gcolor = 0;
                    }
//                      Blue
                    else if (color_choice == '2') {
                        Rcolor = 0;
                        Bcolor = 255;
                        Gcolor = 0;
                    }
//                        Green
                    else if (color_choice == '3') {
                        Rcolor = 0;
                        Bcolor = 0;
                        Gcolor = 255;
                    }
//                        Brown
                    else if (color_choice == '4') {
                        Rcolor = 149;
                        Bcolor = 23;
                        Gcolor = 78;
                    }
//                        Yellow
                    else if (color_choice == '5') {
                        Rcolor = 225;
                        Bcolor = 39;
                        Gcolor = 206;
                    }
//                        Turquoise
                    else if (color_choice == '6') {
                        Rcolor = 51;
                        Bcolor = 189;
                        Gcolor = 230;
                    } else {
                        cout << "Please enter a valid option!\n";
                    }
                }
            } else if (col == '2') {
                cout << "Enter RGB values (Usage: R G B): ";
                cin >> Rcolor >> Gcolor >> Bcolor;
//                valid color values
                while (Rcolor > 255 || Rcolor < 0 || Gcolor > 255 || Gcolor < 0 || Bcolor > 255 || Bcolor > 255) {
                    cout << "Color Values should between 0 and 255\n";
                    cout << "Enter Color values (Usage: R G B): ";
                    cin >> Rcolor >> Gcolor >> Bcolor;
                }
            } else {
                cout << "Please choose a valid option!\n";
            }
        }
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
    else if (ans == "2")
    {
        unsigned int Rtexture; // Color of the texture
        unsigned int Gtexture;
        unsigned int Btexture;
        char col = '0';
        while (col == '0')
        {
            cout << "Frame color\n"
                    "1) Colors\n"
                    "2) Manual RGB values\n"
                    "Choice: ";
            cin >> col;
            if (col == '1')
            {
                char color_choice = '0';
                while (color_choice == '0') {
                    cout << "Colors:\n"
                            "1) Red\n"
                            "2) Blue\n"
                            "3) Green\n"
                            "4) Brown\n"
                            "5) Yellow\n"
                            "6) Turquoise\n"
                            "Choice: ";
                    cin >> color_choice;
//                       Red
                    if (color_choice == '1') {
                        Rtexture = 255;
                        Btexture = 0;
                        Gtexture = 0;
                    }
//                      Blue
                    else if (color_choice == '2') {
                        Rtexture = 0;
                        Btexture = 255;
                        Gtexture = 0;
                    }
//                        Green
                    else if (color_choice == '3') {
                        Rtexture = 0;
                        Btexture = 0;
                        Gtexture = 255;
                    }
//                        Brown
                    else if (color_choice == '4') {
                        Rtexture = 149;
                        Btexture = 23;
                        Gtexture = 78;
                    }
//                        Yellow
                    else if (color_choice == '5') {
                        Rtexture = 225;
                        Btexture = 39;
                        Gtexture = 206;
                    }
//                        Turquoise
                    else if (color_choice == '6') {
                        Rtexture = 51;
                        Btexture = 189;
                        Gtexture = 230;
                    }
                    else {
                        cout << "Please enter a valid option!\n";
                    }
                }
            }
            else if (col == '2')
            {
                cout << "Enter RGB values (Usage: R G B): ";
                cin >> Rtexture >> Gtexture >> Btexture;
                //                valid color values
                while (Rtexture > 255 || Rtexture < 0 || Gtexture > 255 || Gtexture < 0 || Btexture > 255 || Btexture > 255) {
                    cout << "Color Values should between 0 and 255\n";
                    cout << "Enter Color values (Usage: R G B): ";
                    cin >> Rtexture >> Gtexture >> Btexture;
                }
            }
            else
            {
                cout << "Please choose a valid option!\n";
            }
        }
//        best at 0.1
        float frequency = 0.1; // Adjust this for texture frequency
//        best using one color

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
// Fancy frame
    else
    {
        int lineThickness = 5;
//      choose color
        unsigned int Rcolor, Gcolor, Bcolor;
        char col = '0';
        while (col == '0') {
            cout << "Frame color\n"
                    "1) Colors\n"
                    "2) Manual RGB values\n"
                    "Choice: ";
            cin >> col;
            if (col == '1') {
                char color_choice = '0';
                while (color_choice == '0') {
                    cout << "Colors:\n"
                            "1) Red\n"
                            "2) Blue\n"
                            "3) Green\n"
                            "4) Brown\n"
                            "5) Yellow\n"
                            "6) Turquoise\n"
                            "Choice: ";
                    cin >> color_choice;
//                       Red
                    if (color_choice == '1') {
                        Rcolor = 255;
                        Bcolor = 0;
                        Gcolor = 0;
                    }
//                      Blue
                    else if (color_choice == '2') {
                        Rcolor = 0;
                        Bcolor = 255;
                        Gcolor = 0;
                    }
//                        Green
                    else if (color_choice == '3') {
                        Rcolor = 0;
                        Bcolor = 0;
                        Gcolor = 255;
                    }
//                        Brown
                    else if (color_choice == '4') {
                        Rcolor = 149;
                        Bcolor = 23;
                        Gcolor = 78;
                    }
//                        Yellow
                    else if (color_choice == '5') {
                        Rcolor = 225;
                        Bcolor = 39;
                        Gcolor = 206;
                    }
//                        Turquoise
                    else if (color_choice == '6') {
                        Rcolor = 51;
                        Bcolor = 189;
                        Gcolor = 230;
                    } else {
                        cout << "Please enter a valid option!\n";
                    }
                }
            } else if (col == '2') {
                cout << "Enter RGB values (Usage: R G B): ";
                cin >> Rcolor >> Gcolor >> Bcolor;
//                valid color values
                while (Rcolor > 255 || Rcolor < 0 || Gcolor > 255 || Gcolor < 0 || Bcolor > 255 || Bcolor > 255) {
                    cout << "Color Values should between 0 and 255\n";
                    cout << "Enter Color values (Usage: R G B): ";
                    cin >> Rcolor >> Gcolor >> Bcolor;
                }
            } else {
                cout << "Please choose a valid option!\n";
            }
        }
        bool check = true;
        string pattern;
        do {
            cout << "1) Diagonals\n"
                    "2) Checkerboard\n"
                    "Choice: ";
            cin >> pattern;
            if (pattern != "1" && pattern != "2")
            {
                cout << "Invalid Option!\n";
            }
            else if (pattern == "1" || pattern == "2")
            {
                check = false;
            }
        } while (check);
//        diagonals
        if (pattern == "1") {
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
        else if (pattern == "2")
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
    cout << "Filter Applied...\n";
    menu(image);
}

void edges(Image image) { //Hossam (Done)

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
    int sens = 150; //doesnt matter value of sensitivity between pixels since image is in black and white filter
    //end with less height and width by one because we only check the right and bottom side pixels since they are all we need to check and if we iterate at last pixel of row or column we dont get out of image limits
    for (int i = 0; i < image.width - 1; i++) {
        for (int j = 0; j < image.height -1; j++) {
            for (int k = 0; k < 3; ++k) {
                if (abs(image(i, j, k) - image(i, j + 1, k)) >=sens || abs(image(i, j, k) - image(i + 1, j, k)) >= sens) {
                        image(i, j, k) = 0;
                } else {
                        image(i, j, k) = 255;
                }
            }
        }
    }
    cout << "Filter Applied...\n";
    menu(image);

}

void resize(Image image) //Abdallah (Done)
{
    while (true) {
        cout << "The original size of the image is :  " << image.width << "x" << image.height << endl;
        int w, h;
        cout << "Please enter the new dimensions (Width & Height)\n";
        cout << " The Width : ";
        cin >> w;                     // getting the values of new dimensions
        cin.ignore(1);
        cout << "The Height : ";
        cin >> h;
        cin.ignore(1);
        if (w > 0 && h > 0) {
            Image resized_Img(w, h); //create a new image to store the resized one
            float s; // the ratio between the width of the original img and the new width
            float r; //the ratio between the height of the original img and the new height
            // -------------------------------------------------------------------------------------------------------------
            s = static_cast<float>(image.width) / w;
            r = static_cast<float>(image.height) / h;
            //--------------------------------------------------------------------------------------------------------------
            for (int i = 0; i < w; ++i) {
                for (int j = 0; j < h; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        int new1 = round(s * i); // we make s and i normal integers
                        int new2 = round(r * j);
                        resized_Img(i, j, k) = image(new1, new2, k);
                    }
                }
            }
            cout << "Filter Applied...\n";
            menu(resized_Img);
        } else {
            cout << "\n\nInvalid,Please enter Valid Dimensions\n "
                    "---> Must be greater than zero  !\n\n";
            // Clear the input buffer in case of invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    }
}

void blur(Image image) //Loai (Done)
{
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
    cout << "Filter Applied...\n";
    menu(blurred_image);
}

//  ********************** Bonus ****************************
void Sunlight(Image image) {
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
    cout << "Filter Applied...\n";
    menu(image);

}


void look_Purple(Image image) //Abdallah (Done)
{
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
    cout << "Filter Applied...\n";
    menu(image);
}

void IR (Image image) //Abdallah (Done)
{
    cout << "Applying Infrared (IR) Filter....................\n";
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
    cout << "Filter Applied...\n";
    menu(image);
}

void tv(Image image) //Loai (Done)
{
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
    cout << "Filter Applied...\n";
    menu(image);
}

void sepia(Image image) //Loai (Done)
{
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
    cout << "Filter Applied...\n";
    menu(image);
}

void oil(Image image) //Loai (Done)
{
    unsigned int brushSize;
    string temp;
    bool test;
    do
    {
        test = true;
        cout << "Choose brush size (1-15) \"Recommended 15\": ";
        cin >> temp;
        for (auto digit: temp) {
            if (not isdigit(digit)) {
                test = false;
            }
        }
        if (stoi(temp) > 15 || stoi(temp) < 1) {
            cout << "Brush size (1-15)!!!\n";
            test = false;
        }
    } while (not test);
    brushSize = stoi(temp);

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
    cout << "Filter Applied...\n";
    menu(oil_image);
}

void Skewed(Image image) {
    Image white(image.width * 3, image.height);
    for (int i = 0; i < white.height; ++i) {
        for (int j = 0; j < white.width; ++j) {
            for (int k = 0; k < 3; ++k) {
                white(j, i, k) = 255;
            }
        }
    }
    int base = image.width / 5;
    int cnt = image.height;
    cout << "Enter the degree of skewness: (1-80)" << endl;
    string deg;
    cin >> deg;
    bool flag = true;
    while (flag) {
        if (!isdigit(deg[0]) || !isdigit(deg[1]) || stoi(deg) < 1 || stoi(deg) > 80) {
            cout << "invalid value please enter a valid degree(1-80):";
            cin >> deg;
        } else flag = false;
    }
    int deg1 = stoi(deg);
    deg1 = abs(deg1 - 81);
    int dinom = max(deg1 / 20, 1);
    //cout<<dinom;
    for (int i = 0; i < image.height; ++i) {
        for (int j = 0; j < image.width; ++j) {
            for (int k = 0; k < 3; ++k) {
                white(j + cnt + base, i, k) = image(j, i, k);
            }
        }
        if (i % dinom == 0)cnt--;
    }
    menu(white);

}

void Pixelate(Image image) {
    int Pixel_Size = 0;  // This variable handles the size of each pixel
    while (true) {
        try {
            cout << "If The Pixelation Level is higher The image will be Distorted\n"
                 << "Hint ---> Pixelation level is the size of each pixel\n";
            cout << "Please enter the pixelation level :  ";
            cin >> Pixel_Size;
            if (Pixel_Size > 0) {
                for (int i = 0; i < image.width; i += Pixel_Size) {
                    // Set the new size of the width of each pixel
                    for (int j = 0; j < image.height; j += Pixel_Size) {
                        // Set the new size of the height of each pixel
                        unsigned int avgRed = 0, avgGreen = 0, avgBlue = 0;
                        //variables to store the avg of each channel
                        int counter = 0;
                        for (int x = i; x < i + Pixel_Size && x < image.width; ++x) {
                            for (int y = j; y < j + Pixel_Size && y < image.height; ++y) {
                                avgRed += image(x, y,
                                                0); // assign it to equal the sum of each red channel                                avgGreen += image(x, y, 1);
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
                    }
                }
                cout << "Pixelation Filter Applied...\n";
                menu(image);
            } else { throw Pixel_Size; }
        }
        catch (int myNum) { //catch the error
            cout << "Invalid input, Please insert numbers!!\n";
            cout << "=========================================\n";
            // Clear the input buffer to avoid the infinite loop
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

/*
 *
 * The line `cin.ignore(numeric_limits<streamsize>::max(), '\n');` is a call to the `ignore` function from the `cin` object, which is used to clear the input buffer.

Here's a breakdown of the parameters:

1. `numeric_limits<streamsize>::max()`: This part retrieves the maximum value that can be stored in a `streamsize` data type.
 `streamsize` is a data type used for stream buffer sizes. `numeric_limits` is a template class in the `<limits>` header
 , and its `max()` function returns the maximum value representable by the specified data type
 . In this case
 , it returns the maximum value representable by `streamsize`. This value is used to specify the maximum number of characters
 to extract and discard from the input stream.

2. `'\n'`: This character specifies the delimiter until which the extraction will occur.
 In this case, it's the newline character (`'\n'`). It indicates that `cin` should ignore characters in the input buffer
 until it encounters a newline character. This is typically used to clear any remaining characters in the input buffer
 after reading a line of input.

So, `cin.ignore(numeric_limits<streamsize>::max(), '\n');` essentially tells the program to ignore and discard all characters
 in the input buffer until it reaches a newline character (`'\n'`). This is commonly used after using `cin` to read input,
 especially when there might be extra characters left in the input buffer. It ensures that the input buffer is cleared before
 further input operations.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * */