#include <iostream>
#include "BMP.h"
#include <cmath>

int main() {

    int width = 2000;
    int height = 1000;
    BMP bmpNew(width,height,false);
    bmpNew.fill_region(0, 0, width, height, 0, 0, 0, 0);


    // repositioning the resulting ellipse to land at the center of the image
    // prefixed 'x' to indicate these numbers apply to the loop iterating across the x-axis
    int x_repos_x = 232;
    int x_repos_y = 308;

    // j will iterate in the opposite direction as i
    // each will increment by 0.5 in their respective directions
    double j = 768;
    for(double i=0;i<769;i=i+0.5)
    {
        // set pixels for the righthand side of the ellipse in RED
        bmpNew.set_pixel(i+768+x_repos_x, (sqrt(pow(64, 2) - pow(i/12, 2)) * 6)+x_repos_y, 0, 0, 255, 0);
        // set pixels for the lefthand side of the ellipse in GREEN
        bmpNew.set_pixel(j+x_repos_x, (sqrt(pow(64, 2) - pow(i/12, 2)) * 6)+x_repos_y, 0, 255, 0, 0);

        j = j - 0.5;
    }

    // repositioning the resulting ellipse to land at the center of the image
    // prefixed 'y' to indicate these numbers apply to the loop iterating across the y-axis
    int y_repos_x = 1000;
    int y_repos_y = -77;

    for(double i=0;i<385;i=i+0.5)
    {
        // set pixels for the righthand side of the ellipse in RED
        bmpNew.set_pixel((sqrt(pow(64, 2) - pow(i/6, 2)) * 12)+y_repos_x, i+385+y_repos_y, 0, 0, 255, 0);
        // set pixels for the lefthand side of the ellipse in GREEN
        bmpNew.set_pixel(-(sqrt(pow(64, 2) - pow(i/6, 2)) * 12)+y_repos_x, i+385+y_repos_y, 0, 255, 0, 0);

    }
  

    bmpNew.write("output.bmp");


}
