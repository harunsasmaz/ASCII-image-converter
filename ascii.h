#ifndef ASCII_H
#define ASCII_H

#include <cstdlib>
#include <cstdio>
#include <string>
#include <fstream>

using namespace std;

#define BODY_OFFSET 55
#define B_OFFSET 0
#define B_SIZE 1
#define B 'B'
#define M_OFFSET 1
#define M_SIZE 1
#define M 'M'
#define WIDTH_OFFSET 18
#define WIDTH_SIZE 4
#define HEIGHT_OFFSET 22
#define HEIGHT_SIZE 4
#define BITS_OFFSET 28
#define BITS_SIZE 2

typedef struct body {
  int width;
  int height;
  int m;
  int n;
  int **body;
} body;

typedef struct header {
  char b; // offset: 0 | size: 1
  char m; // offset: 1 | size: 1
  signed int width; // offset: 18 | size 4
  signed int height; // offset: 22 | size 4
  signed int bits; // offset: 28 | size 2
} header;

typedef struct image {
  header *bh;
  body *bb;
} image;

body *new_body(int width, int height, int m, int n);
void delete_body(body *bb);

header *new_header();
void delete_header(header *bh);

image *new_image();
void delete_image(image *bi);

void to_ascii(image *bi);

header *read_header(string image, unsigned char *header);
body *read_body(string image, int width, int height, int m, int n, int bitsperpixel);

#endif /* ASCII_H */