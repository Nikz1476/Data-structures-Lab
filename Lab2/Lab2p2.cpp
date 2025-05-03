#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

class Square {
    int s, area;
    public:
        void squareArea(int x) {
            s = x;  // Correct assignment
            area = s * s;
            printf("Area of the square is: %d\n", area);
        }
};

class Rectangle {
    int length, breadth, area;
    public:
        void rectArea(int x1, int x2) {
            length = x1;
            breadth = x2;
            area = length * breadth;
            printf("Area of the rectangle is: %d\n", area);
        }
};

class Cube {
    int l1, area;
    public:
        void cubeArea(int x) {
            l1 = x;  // Correct assignment
            area = 6 * l1 * l1;
            printf("Area of the cube is: %d\n", area);
        }
};

class Cuboid {
    int l, b, h, area;
    public:
        void cuboidArea(int x1, int x2, int x3) {
            l = x1;
            b = x2;
            h = x3;
            area = 2 * (l * b + b * h + h * l);
            printf("Area of the cuboid is: %d\n", area);
        }
};

int main() {
    int choice;

    do {
        printf("1. Area of square\n");
        printf("2. Area of rectangle\n");
        printf("3. Area of cube\n");
        printf("4. Area of cuboid\n");
        printf("5. Exit\n");

        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                {
                    Square sq;
                    int v1;
                    printf("Enter side length to calculate area of the square: ");
                    scanf("%d", &v1);
                    sq.squareArea(v1);
                    break;
                }
            case 2:
                {
                    Rectangle rt;
                    int v1, v2;
                    printf("Enter length of the rectangle: ");
                    scanf("%d", &v1);
                    printf("Enter breadth of the rectangle: ");
                    scanf("%d", &v2);
                    rt.rectArea(v1, v2);
                    break;
                }
            case 3:
                {
                    Cube cb;
                    int v1;
                    printf("Enter side length to calculate area of the cube: ");
                    scanf("%d", &v1);
                    cb.cubeArea(v1);
                    break;
                }
            case 4:
                {
                    Cuboid cd;
                    int v1, v2, v3;
                    printf("Enter length of the cuboid: ");
                    scanf("%d", &v1);
                    printf("Enter breadth of the cuboid: ");
                    scanf("%d", &v2);
                    printf("Enter height of the cuboid: ");
                    scanf("%d", &v3);
                    cd.cuboidArea(v1, v2, v3);
                    break;
                }
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
