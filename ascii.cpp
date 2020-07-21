#include "ascii.h"

body *new_body(int width, int height, int m, int n) 
{
    body *bb = (body *) malloc(sizeof(body));
    bb->body = new int * [height];
    for(int i = 0 ; i < height ; i++) bb->body[i] = new int[width];
    bb->width = width;
    bb->height = height;
    bb->m = m;
    bb->n = n;
    return bb;
}

void delete_body(body *bb) 
{
    if(bb->body != NULL) {
        for(int i = 0 ; i < bb->height ; i++) 
            if(bb->body[i] != NULL) delete [] bb->body[i];
        delete [] bb->body;
    }

    if(bb != NULL) free(bb);
}

header *new_header() 
{
    header *bh = (header *) malloc(sizeof(header));
    return bh;
}

void delete_header(header *bh) 
{
    if(bh != NULL) free(bh);
}

image *new_image() 
{
    image *bi = (image *) malloc(sizeof(image));
    return bi;
}

void delete_image(image *bi) 
{
    if(bi->bh != NULL) delete_header(bi->bh);
    if(bi->bb != NULL) delete_body(bi->bb);
    if(bi != NULL) free(bi);
}

void to_ascii(image *bi) 
{
    for(int i = (bi->bb->height - 1) ; i >= 0  ; i -= bi->bb->n) {
        for(int j = 0 ; j < bi->bb->width ; j += bi->bb->m) {
            int color = 0;
            for(int k = 0 ; k < bi->bb->n ; k++) {
                for(int l = 0 ; l < bi->bb->m ; l++) {
                    if((i - k) >= 0 && (j + l) < bi->bb->width) 
                        color += bi->bb->body[i - k][j + l];
                }
            }
            int pixel = (color/(bi->bb->m * bi->bb->n));
            if(pixel >= 0 && pixel <= 25) printf("#");
            else if(pixel > 25 && pixel <= 50) printf("$");
            else if(pixel > 50 && pixel <= 75) printf("O");
            else if(pixel > 75 && pixel <= 100) printf("=");
            else if(pixel > 100 && pixel <= 125) printf("+");
            else if(pixel > 125 && pixel <= 150) printf("|");
            else if(pixel > 150 && pixel <= 175) printf("-");
            else if(pixel > 175 && pixel <= 200) printf("^");
            else if(pixel > 200 && pixel <= 225) printf(".");
            else if(pixel > 225 && pixel <= 255) printf(" ");
        }
        printf("\n");
    }
}

header *read_header(string image, unsigned char *head) 
{
    ifstream istrm(image, ios::binary);
    if(!istrm.is_open()) 
        printf("Failed to open %s\n", image.data());
    else 
        istrm.read((char *)head, 54);

    header *bh = new_header();
    bh->b = head[B_OFFSET];
    bh->m = head[M_OFFSET];
    bh->width = *(int*)&head[WIDTH_OFFSET];
    bh->height = *(int*)&head[HEIGHT_OFFSET];
    bh->bits = *(int*)&head[BITS_OFFSET];
    return bh;
}

body *read_body(string image, int width, int height, int m, int n, int bitsperpixel) 
{
    body *bb = new_body(width, height, m, n);
    ifstream istrm(image, ios::binary);

    if(!istrm.is_open()) 
        printf("Failed to open %s\n", image.data());
    else {
        int offset = BODY_OFFSET;
        int k = (bb->height - 1);
        for(int i = 0 ; i < bb->height ; i++) {
            istrm.seekg(offset + (k * bb->width));
            for(int j = 0 ; j < bb->width ; j++) {
                unsigned char cbuf[4];
                istrm.read((char *)cbuf, bitsperpixel/8);
                int color = ((short)cbuf[2]+(short)cbuf[1]+(short)cbuf[0])/3;
                bb->body[i][j] = color;
                offset += bitsperpixel/8;
                istrm.seekg(offset);
            }
            k--;
        }
    }
    return bb;
}