//be02ezy@gmail.com
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "PEditor.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char image3[SIZE][SIZE];
void loadImage ();
void saveImage ();
void Blackwhi();
void InvertPic();
void MergePic();
void loadImage2();
void FlipPic();
void Rotateimage();
void DarkenLightenPic();
void MirrorHalfImage();
void BlurImage();
void CropImage();
void Detect_Image();
void EnlargeImage();
void Shrinkimage();
void skew();
//void skewVertical();
void  shuffle();
void moveQuart(int idx, int i, int j );

void  shuffled();
int main()
{
    loadImage();
    char choice;

    while (true){

        cout << endl
             << "1-\t Black & White Filter.\n"
             << "2- \tInvert Filter\n"
             << "3-\tMerge Filter \n"
             << "4-\tFlip Image\n"
             << "5-\tDarken and Lighten Image \n"
             << "6-\tRotate Image\n"
             << "7-\tDetect Image Edges \n"
             << "8-\tEnlarge Image\n"
             << "9-\tShrink Image\n"
             << "a-\tMirror 1/2 Image\n"
             << "b-\tShuffle Image\n"
             << "c-\tBlur Image\n"
             << "d-\tCrop Image\n"
             << "e-\tSkew Image Right  \n"
            // << "f-\tSkew Image Up  \n"
             << "s-\tSave the image to a file\n"
             << "0-\tExit\n";
        cin >> choice;
        switch (choice) {
            case '1':
            {
                Blackwhi();
                break;
            }
            case '2':
            {
                InvertPic();
                break;
            }
            case '3':
            {
                loadImage2();
                MergePic();
                break;
            }
            case '4':
            {
                FlipPic();
                break;
            }
            case '5':
            {
                DarkenLightenPic();
                break;
            }
            case '6':
            {
                Rotateimage();
                break;
            }
            case'7':
            {
                Detect_Image();
                break;
            }
            case '8': {
                EnlargeImage();
                break;
            }
            case '9':
            {
                Shrinkimage();
                break;
            }
            case 'a':
            {
                MirrorHalfImage();
                break;
            }
            case 'b':
            {
                shuffle();
                break;
            }
            case'c':
            {
                BlurImage();
                break;
            }
            case 'd':
            {
                CropImage();
                break;
            }
            case 'e':
            {
                skew();
                break;
            }
           // case 'f':
           // {
               // skewVertical();
              //  break;
           // }
            case 's':
            {
                saveImage();
                break;
            }
            case '0':
            {
                return 0;
            }
            default: {
                cout << "Invalid option. Please select a valid option." << endl;
            }
        }
    }
}


//_______________
void loadImage () {
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}

void loadImage2 () {
    char imageFileName[100];
// Helper function to load a second image for merging
    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image2);
}

//_______________
void saveImage () {
    char imageFileName[100];
    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}

//_______________
void InvertPic() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {



            image[i][j] = 255 - image[i][j];

        }
    }
}
void MergePic() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            image[i][j] = (image[i][j] + image2[i][j])/2;

        }
    }
}
void Blackwhi() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {

// Example code to convert to BW the image
            // A better version should NOt use 127 but the
            //average of the pixels

            if (image[i][j] > 110)
                image[i][j] = 255;
            else
                image[i][j] = 0;
// do something with the image
        }
    }
}
void FlipPic() {
    // Helper function to flip the image horizontally or vertically
    char choice1;
    cout << "Flip (h)orizontally or (v)ertically ?\n";
    cin >> choice1;
    if (choice1 == 'h') {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE/2; j++) {
                unsigned char temp = image[i][j];
                image[i][j] = image[i][SIZE - 1 - j];
                image[i][SIZE - 1 - j] = temp;
            }
        }
    } else if (choice1 == 'v')

        for (int i = 0; i < SIZE/2; i++) {
            for (int j = 0; j < SIZE; j++) {
                unsigned char temp = image[i][j];
                image[i][j] = image[SIZE - i - 1][j];
                image[SIZE - i - 1][j] = temp;
            }
        };

    // Helper function to rotate the image by a user-specified degree
}
void DarkenLightenPic() {
    char choice2;
    cout << "Do you want to (d)arken or (l)ighten ?";
    cin >> choice2;

    int value;

    if (choice2 == 'd') {
        cout << "Enter the darkness value from (-255 to 255): ";
        cin >> value;

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                //  Darken the image by adjusting pixel values
                int Darkenvalue = image[i][j] + value;
                if (Darkenvalue < 0) {
                    //  Ensure pixel values stay within the valid range [0, 255]
                    image[i][j] = 0;
                } else {
                    // Ensure pixel values stay within the valid range [0, 255]
                    image[i][j] = (Darkenvalue);
                }
            }
        }
    }
    else if (choice2 == 'l') {
        cout << "Enter the lighting value from (0 to 255): ";
        cin >> value;

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                int Lightenvalue = image[i][j] + value;
                if (Lightenvalue > 255) {
                    image[i][j] = 255;
                } else {
                    image[i][j] = (Lightenvalue);
                }
            }
        }
    }
    else {
        cout << "Invalid choice. Please select 'd' for darken or 'l' for lighten." << endl;
    }
}
void Rotateimage(){
    // Helper function to rotate the image by a user-specified degree
    int degree;
    cout<<"Enter ther rotate degree: ";
    cin>>degree;
    unsigned char newImage[SIZE][SIZE];

    if (degree == 90) {
        //  Rotate the image 90 degrees clockwise
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                newImage[i][j] = image[SIZE - 1 - j][i];
            }
        }
    } else if (degree == 180) {
        //Rotate the image 180 degrees
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                newImage[i][j] = image[SIZE - 1 - i][SIZE - 1 - j];
            }
        }
    } else if (degree == 270) {
        // Rotate the image 270 degrees clockwise
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                newImage[i][j] = image[j][SIZE - 1 - i];
            }
        }
    } else {
        cout << "Invalid rotation degree. Supported degrees are 90, 180, and 270." << endl;
    }

    // Copy the rotated image back to the original image array
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = newImage[i][j];
        }
    }
}
void MirrorHalfImage() {
    char choosea;
    cout<<"Mirror (l)eft, (r)ight, (u)pper, (d)own side :";
    cin>>choosea;
    if (choosea=='l'){
        for (int i = 0; i < SIZE; i++){
            for (int j =0 ; j <SIZE/2; j++){
                image[i][SIZE-j]=image[i][j];
            }
        }
    }
    if (choosea=='r'){
        for (int i = 0; i < SIZE; i++){
            for (int j =0 ; j <SIZE/2; j++){
                image[i][j]=image[i][SIZE-j];
            }
        }
    }
    if (choosea=='u'){
        for (int i = 0; i < SIZE/2; i++){
            for (int j =0 ; j <SIZE; j++){
                image[SIZE-i][j]=image[i][j];
            }
        }
    }
    if (choosea=='d'){
        for (int i = 0; i < SIZE/2; i++){
            for (int j =0 ; j <SIZE; j++){
                image[i][j]=image[SIZE-i][j];
            }
        }
    }
}
void BlurImage() {
    unsigned char blurredImage[SIZE][SIZE];

    // Apply the box blur algorithm
    for (int i = 1; i < SIZE - 1; i++) {
        for (int j = 1; j < SIZE - 1; j++) {
            int sum = 0;

            // Calculate the average of the surrounding pixels
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    sum += image[i + k][j + l];
                }
            }

            blurredImage[i][j] = sum /9 ;

        }
    }

    // Copy the blurred image back to the original image
    for (int i = 1; i < SIZE - 1; i++) {
        for (int j = 1; j < SIZE - 1; j++) {
            image[i][j] = blurredImage[i][j];
        }
    }
}
void CropImage() {
    int startX, startY, length, width;

    // Get the cropping parameters from the user
    cout << "Enter the starting X coordinate: ";
    cin >> startX;
    cout << "Enter the starting Y coordinate: ";
    cin >> startY;
    cout << "Enter the length: ";
    cin >> length;
    cout << "Enter the width: ";
    cin >> width;

    // Validate the cropping parameters
    if (startX < 0 || startX >= SIZE || startY < 0 || startY >= SIZE ||
        length <= 0 || startX + length > SIZE || width <= 0 || startY + width > SIZE) {
        cout << "Invalid cropping parameters. Please make sure the coordinates and dimensions are within the image boundaries.\n";
        return;
    }

    // Create a temporary image to store the cropped portion
    unsigned char croppedImage[SIZE][SIZE];

    // Copy the cropped portion from the original image to the temporary image
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            croppedImage[i][j] = image[startY + i][startX + j];
        }
    }

    // Copy the cropped portion back to the original image
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i >= startY && i < startY + length && j >= startX && j < startX + width) {
                image[i][j] = croppedImage[i - startY][j - startX];
            } else {
                // Set pixels outside the cropped area to black
                image[i][j] = 0;
            }
        }
    }

    cout << "Image cropped.\n";
}

void Detect_Image(){
    for (int i=0; i<SIZE-1; i++){
        for (int j=0; j<SIZE-1; j++){
            if((abs(image[i][j]-image[i][j+1])>=40)||(abs(image[i][j]-image[i+1][j])>=40)) image[i][j]=0;
            else image[i][j]=255;
        }
    }
}
void EnlargeImage(){
    int chose;
    cout<<"Which quarter to enlarge 1, 2, 3 or 4 : ";
    cin>>chose;
    if(chose==1){
        for (int i = 0; i < (SIZE/2); i++){
            for (int j =0 ; j <(SIZE/2); j++){
                image2[(i*2)][(j*2)]=image[i][j];
                image2[(i*2)+1][(j*2)]=image[i][j];
                image2[(i*2)][(j*2)+1]=image[i][j];
                image2[(i*2)+1][(j*2)+1]=image[i][j];
            }
        }
        for (int i = 0; i < (SIZE); i++){
            for (int j =0 ; j <(SIZE); j++){
                image[i][j]=image2[i][j];
            }
        }
    }
    else if(chose==2){
        for (int i = 0; i < (SIZE/2); i++){
            for (int j =0 ; j <(SIZE/2); j++){
                image2[i*2][j*2]=image[i][j+128];
                image2[(i*2)+1][(j*2)]=image[i][j+128];
                image2[(i*2)][(j*2)+1]=image[i][j+128];
                image2[(i*2)+1][(j*2)+1]=image[i][j+128];
            }
        }
        for (int i = 0; i < (SIZE); i++){
            for (int j =0 ; j <(SIZE); j++){
                image[i][j]=image2[i][j];
            }
        }
    }
    else if(chose==3){
        for (int i = 0; i < (SIZE/2); i++){
            for (int j =0 ; j <(SIZE/2); j++){
                image2[i*2][j*2]=image[i+128][j];
                image2[(i*2)+1][(j*2)]=image[i+128][j];
                image2[(i*2)][(j*2)+1]=image[i+128][j];
                image2[(i*2)+1][(j*2)+1]=image[i+128][j];
            }
        }
        for (int i = 0; i < (SIZE); i++){
            for (int j =0 ; j <(SIZE); j++){
                image[i][j]=image2[i][j];
            }
        }
    }
    else if(chose==4){
        for (int i = 0; i < (SIZE/2); i++){
            for (int j =0 ; j <(SIZE/2); j++){
                image2[i*2][j*2]=image[i+128][j+128];
                image2[(i*2)+1][(j*2)]=image[i+128][j+128];
                image2[(i*2)][(j*2)+1]=image[i+128][j+128];
                image2[(i*2)+1][(j*2)+1]=image[i+128][j+128];
            }
        }
        for (int i = 0; i < (SIZE); i++){
            for (int j =0 ; j <(SIZE); j++){
                image[i][j]=image2[i][j];
            }
        }
    }
    else cout<<"ERROR INVALID CHOOSE";
}
void Shrinkimage(){
    float Choce;
    cout<<"1-Shrink to (1/2)\n2-Shrink to (1/3) \n3-Shrink to (1/4) \nchoose :";
    cin>>Choce;
    if (Choce==1){
     //   Shrinking by 1/2 (Choce == 1):

       // A nested loop iterates through each pixel of the original image (SIZE x SIZE).
      //  For each pixel at coordinates (i, j), its value is copied to the corresponding pixel in the shrunk image, which is at coordinates (i/2, j/2)
      //  . This effectively reduces the dimensions of the image by half.
         //       After copying, the remaining right and bottom quarters of the image are filled with white pixels (pixel value 255) to
         //       maintain the original image dimensions.
        for (int i = 0; i < SIZE; i++){
            for (int j =0 ; j <SIZE; j++){
                image[i/2][j/2]=image[i][j];
            }
        }
        for (int i = 0; i < SIZE; i++){
            for (int j =SIZE/2 ; j <SIZE; j++){
                image[i][j]=255;
            }
        }
        for (int i = SIZE/2; i < SIZE; i++){
            for (int j =0 ; j <SIZE; j++){
                image[i][j]=255;
            }
        }
    }
    if (Choce==2){
       // Shrinking by 1/3 (Choce == 2):

       // Similar to the previous case, a nested loop iterates through each pixel of the original image.
              //  For each pixel at coordinates (i, j), its value is copied to the corresponding pixel in the shrunk image,
              //  which is at coordinates (i/3, j/3). This reduces the image dimensions by a factor of 3.
     //   After copying, the right and bottom parts of the image are filled with white pixels.
        for (int i = 0; i < SIZE; i++){
            for (int j =0 ; j <SIZE; j++){
                image[i/3][j/3]=image[i][j];
            }
        }
        for (int i = 0; i < SIZE; i++){
            for (int j =SIZE/3 ; j <SIZE; j++){
                image[i][j]=255;
            }
        }
        for (int i = SIZE/3; i < SIZE; i++){
            for (int j =0 ; j <SIZE; j++){
                image[i][j]=255;
            }
        }
    }
    if (Choce==3){
       // Shrinking by 1/4 (Choce == 3):
//
       // Once again, the function loops through each pixel of the original image.
           //     For each pixel at coordinates (i, j), its value is copied to the corresponding pixel in the shrunk image at coordinates (i/4, j/4), reducing the image dimensions by a factor of 4.
       // After copying, the right and bottom parts of the image are filled with white pixels.
        for (int i = 0; i < SIZE; i++){
            for (int j =0 ; j <SIZE; j++){
                image[i/4][j/4]=image[i][j];
            }
        }
        for (int i = 0; i < SIZE; i++){
            for (int j =SIZE/4 ; j <SIZE; j++){
                image[i][j]=255;
            }
        }
        for (int i = SIZE/4; i < SIZE; i++){
            for (int j =0 ; j <SIZE; j++){
                image[i][j]=255;
            }
        }
    }
}

void skew() {
    string  dr;
    cout << "Enter 'h' to horizontally or 'v' to  vertically : ";
    cin >> dr;
    cout << "Enter the degree : \n";
    double rad;
    cin >> rad;
    rad = (rad * 22) / (180 * 7);
    unsigned char sh[SIZE][SIZE];
    unsigned char skew[SIZE][SIZE];
    int x = (tan(rad) * 256) / (tan(rad) + 1);;
    double step = SIZE - x;
    double move = step / SIZE;

    if (dr == "h") {
       // Horizontal Skewing (`dr == "h"):

       // First, it computes the new positions in the sh array for the horizontally skewed image. It uses the formula sh[i][(j * x) / SIZE] = image[i][j] to calculate the new pixel positions.

        //        The skewed image is then copied back to the original image array.

          //     A new array skew is created with all pixel values initially set to 255 (white).

             //   The pixels from the sh array are copied to the skew array with an adjustment for skewing, creating the skewed effect.

                //Finally, the resulting skewed image is copied back to the image array.
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                sh[i][(j * x) / SIZE] = image[i][j];
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = sh[i][j];
            }
        }

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                skew[i][j] = 255;
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = (int)step; j < step + x; j++) {
                skew[i][j] = sh[i][(int)(j - step)];
            }
            step -= move;
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = skew[i][j];
            }
        }
    }
    else if (dr == "v") {
     //   Vertical Skewing (`dr == "v"):
//
     //   Similar to horizontal skewing, the positions of the pixels in the sh array are computed for vertical skewing using sh[j][(i * x) / SIZE] = image[i][j].
//
        //        The skewed image is copied back to the original image array.

          //      A new array skew is created and initialized with white pixels (255).

          //      The pixels from the sh array are copied to the skew array with an adjustment for skewing, creating the skewed effect.

            //    The resulting skewed image is copied back to the image array.

            //    In summary, this function allows the user to skew an image both horizontally and vertically by a specified degree. It does this by first computing the new positions of pixels after skewing and then copying them to a new array before transferring them back to the original image array. The result is an image with the desired skew transformation.
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE;j++) {
                sh[j][(i * x) / SIZE] = image[i][j];
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = sh[i][j];
            }
        }

        for (int j = 0; j < SIZE; j++) {
            for (int i = 0; i < SIZE; i++) {
                skew[j][i] = 255;
            }
        }
        for (int j = 0; j < SIZE; j++) {
            for (int i = (int)step; i < step + x; i++) {
                skew[i][j] = sh[j][(int)(i - step)];
            }
            step -= move;
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = skew[i][j];
            }
        }
    }
}

void moveQuart(int idx, int i, int j)
{
   // Function Parameters: The function takes three parameters: idx (which indicates the quarter to move),
   // i (the starting row index), and j (the starting column index).
    int temp = j;
    if (idx == 1)
    {
        for (int k = 0; k < SIZE / 2; i++, k++)
        {
            j = temp;
            for (int z = 0; z < SIZE / 2; j++, z++)
                image[i][j] = image2[k][z];
        }
    }
    else if (idx == 2)
    {
        for (int k = 0; k < SIZE / 2; i++, k++)
        {
            j = temp;
            for (int z = SIZE / 2; z < SIZE; j++, z++)
                image[i][j] = image2[k][z];
        }
    }
    else if (idx == 3)
    {
        for (int k = SIZE / 2; k < SIZE; i++, k++)
        {
            j = temp;
            for (int z = 0; z < SIZE / 2; j++, z++)
                image[i][j] = image2[k][z];
        }
    }
    else if (idx == 4)
    {
        for (int k = SIZE / 2; k < SIZE; i++, k++)
        {
            j = temp;
            for (int z = SIZE / 2; z < SIZE; j++, z++)
                image[i][j] = image2[k][z];
        }
    }
}

void shuffle()
{
bool check = true;
    //User Input: The function starts by taking user input for four quarters (q1, q2, q3, q4) of the image.
    // The user is prompted to enter a number from 1 to 4 for each quarter.
int q1, q2, q3, q4;
cout << "Please enter the quarters : \n just form 1 to 4 \n";
cin >> q1;
if (q1 == 1) {
for (int i = 0; i < 127; i++) {
for (int j = 0; j < 127; j++) {
image[i][j] = image[i][j];
}
}
}
else if (q1 == 2) {
for (int i = 0; i < 127; i++) {
for (int j = 127; j < SIZE; j++) {
image[i][j - 127] = image[i][j];
}
}
}

else if (q1 == 3) {
for (int r = 127; r < SIZE; r++) {
for (int j = 0; j < 127; j++) {
image[r - 127][j] = image[r][j];
}
}
}
else if (q1 == 4) {
for (int r = 127; r < SIZE; r++) {
for (int j = 127; j < SIZE; j++) {
image[r - 127][j - 127] = image[r][j];
}
}
}

cin >> q2;
if (q2 == 1) {
for (int r = 0; r < 127; r++) {
for (int j = 0; j < 127; j++) {
image[r][j + 127] = image[r][j];
}
}
}
else if (q2 == 2) {
for (int r = 0; r < 127; r++) {
for (int j = 127; j < SIZE; j++) {
image[r][j] = image[r][j];
}
}
}

else if (q2 == 3) {
for (int r = 127; r < SIZE; r++) {
for (int j = 0; j < 127; j++) {
image[r - 127][j + 127] = image[r][j];
}
}
}
else if (q2 == 4) {
for (int r = 127; r < SIZE; r++) {
for (int j = 127; j < SIZE; j++) {
image[r - 127][j] = image[r][j];
}
}
}
cin >> q3;
if (q3 == 1) {
for (int i = 0; i < 127; i++) {
for (int j = 0; j < 127; j++) {
image[i + 127][j] = image[i][j];
}
}
}
else if (q3 == 2) {
for (int i = 0; i < 127; i++) {
for (int j = 127; j < SIZE; j++) {
image[i + 127][j - 127] = image[i][j];
}
}
}

else if (q3 == 3) {
for (int i = 127; i < SIZE; i++) {
for (int j = 0; j < 127; j++) {
image[i][j] = image[i][j];
}
}
}
else if (q3 == 4) {
for (int i = 127; i < SIZE; i++) {
for (int j = 127; j < SIZE; j++) {
image[i][j - 127] = image[i][j];
}
}
}
cin >> q4;
if (q4 == 1) {
for (int i = 0; i < 127; i++) {
for (int j = 0; j < 127; j++) {
image[i + 127][j + 127] = image[i][j];
}
}
}
else if (q4 == 2) {
for (int i = 0; i < 127; i++) {
for (int j = 127; j < SIZE; j++) {
image[i + 127][j] = image[i][j];
}
}
}

else if (q4 == 3) {
for (int i = 127; i < SIZE; i++) {
for (int j = 0; j < 127; j++) {
image[i][j + 127] = image[i][j];
}
}
}
else if (q4 == 4) {
for (int i = 127; i < SIZE; i++) {
for (int j = 127; j < SIZE; j++) {
image[i][j] = image[i][j];
}
}
}
else {
cin.clear();
cin.ignore();
cout << "Please enter available quarter " << endl;



}
}