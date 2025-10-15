#include <stdio.h>
#include "reader.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage : meow file\n");
        return 1;
    }
    return reader(argv[1]);
}