#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14
#define ShapeText(TYPE) char name[10];



typedef struct shape_s {
    ShapeText(shape_s);
    double (*perimeter) (struct shape_s*);
    double length;
    double width;
    double *edge;
} shape_t;

typedef struct circle_s {
    ShapeText(circle_s);
    double (*perimeter) (struct circle_s*);
    double radius;
} circle_t;

double perimeter(struct shape_s* shape){
    if (!strcmp(shape->name, "R"))
        return 2 * (shape->length + shape->width);
    if (!strcmp(shape->name, "S"))
        return 4 * shape->edge[0];
    else
        return shape->edge[0] + shape->edge[1] + shape->edge[2];
}

double perimeter_c(struct circle_s* circle) {
    return 2 * circle->radius * PI;
}

void clearBuffer() {
    char c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

int main(){
    int count;
    double total = 0;
    scanf("%d", &count);
    clearBuffer();
    double result[count];
    
    for (int i=0; i<count; i++) {
        double perimeter_value;
        char name;
        scanf("%c", &name);
        if (name == 'C') {
            circle_t circle;
            strcpy(circle.name, "C");
            scanf("%lf", &circle.radius);
            circle.perimeter = perimeter_c;
            perimeter_value = circle.perimeter(&circle);
        } else if (name == 'T') {
            shape_t triangle;
            triangle.edge = (double*) malloc(3 * sizeof(double));
            strcpy(triangle.name, "T");
            scanf("%lf%lf%lf", triangle.edge, triangle.edge+1, triangle.edge+2);
            triangle.perimeter = perimeter;
            perimeter_value = triangle.perimeter(&triangle);
        } else if (name == 'S') {
            shape_t square;
            square.edge = (double*) malloc(sizeof(double));
            strcpy(square.name, "S");
            scanf("%lf", square.edge);
            square.perimeter = perimeter;
            perimeter_value = square.perimeter(&square);
        } else if (name == 'R') {
            shape_t rectangle;
            strcpy(rectangle.name, "R");
            scanf("%lf%lf", &(rectangle.length), &(rectangle.width));
            rectangle.perimeter = perimeter;
            perimeter_value = rectangle.perimeter(&rectangle);
        } else {
            perimeter_value = 0;
        }
        clearBuffer();
        
        total += perimeter_value;
        perimeter_value *= 100;
        perimeter_value = round(perimeter_value);
        perimeter_value /= 100;
        result[i] = perimeter_value;
    }
    
    for (int i=0; i<count; i++)
        printf("%.2lf\n", result[i]);
    
    printf("%.2lf\n", total);
    return 0;
}

