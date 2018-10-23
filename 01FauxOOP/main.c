#include <stdio.h>
#include <stdlib.h>

typedef struct _rectangle {
    int w;
    int h;

    int (*getArea) (struct _rectangle * r);
    int (*getPerimeter) (struct _rectangle * r);
} Rectangle;

int getArea (struct _rectangle * r) {
    return r->w * r->h;
}

int getPerimeter(struct _rectangle * r) {
    return (r->w * 2) + (r->h * 2);
}

Rectangle *createRect(int w, int h) {
    Rectangle * rect = malloc(sizeof(Rectangle));
    rect->w = w;
    rect->h = h;

    rect->getArea = getArea;
    rect->getPerimeter = getPerimeter;

    return rect;
}

int main() {
    Rectangle *rect = createRect(5,2);

    printf("a:%d p:%d\n", rect->getArea(rect), rect->getPerimeter(rect));
    return 0;
}