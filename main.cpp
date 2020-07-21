#include "ascii.h"

int main(int argc, char *argv[]) {

    if(argc != 4) {
        printf("Usage: ./ascii <image.bmp> <M> <N>\n(Where MxN is the size of the pixels group)\n");
        return -1;
    }

    string str_image = argv[1];
    string ext = str_image.substr(str_image.size() - 3, str_image.size() - 1);

    if(ext.compare("bmp") != 0) {
      printf("The file %s is not a .bmp image\n", str_image.data());
      return -1;
    }

    unsigned char *header = new unsigned char[54];
    image *bi = new_image();
    bi->bh = read_header(str_image, header);

    if(bi->bh->b != B && bi->bh->m != M) {
        delete_image(bi);
        printf("The file %s is not a .bmp image\n", str_image.data());
        return -1;
    }

    bi->bb = read_body(str_image, bi->bh->width, bi->bh->height, 
                    atoi(argv[2]), atoi(argv[3]), bi->bh->bits);
    to_ascii(bi);
    delete_image(bi);
    delete [] header;
    
    return 0;
}