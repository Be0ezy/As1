// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:				CS213-2023-20220834-20210861-20210821.cpp
// Last Modification Date:	10/10/2023
// Author1 and ID and Group:	Mohamed Yassin Eisa 20210821
// Author2 and ID and Group:	Muntasir gaafar elfaki 20220834
// Author3 and ID and Group:	Salah aldin Faisal Attaelmannan 80210861

#ifndef PEditor_H
#define PEditor_H

const int SIZE = 256;
const int RGB = 3;

// read full-color image from the file specified by filename, into inputImage
int readRGBBMP(const char* filename, unsigned char inputImage[][SIZE][RGB]);

// write full-color image to the file specified by filename, from outputImage
int writeRGBBMP(const char* filename, unsigned char outputImage[][SIZE][RGB]);

// display full-color image with eog, pause 0.2 seconds. (uses a temp file)
void showRGBBMP(unsigned char inputImage[][SIZE][RGB]);

// read grayscale image from the file specified by filename, into inputImage
int readGSBMP(const char* filename, unsigned char image[][SIZE]);

// write grayscale image to the file specified by filename, from outputImage
int writeGSBMP(const char* filename, unsigned char outputImage[][SIZE]);

// display grayscale image with eog, pause 0.2 seconds. (uses a temp file)
void showGSBMP(unsigned char inputImage[][SIZE]);




#endif
