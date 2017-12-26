#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

int main(int argc, char **argv)
{
   Mat imG = imread("sudoku.jpg", 0);

   imshow("Gray image", imG);

   Mat imBlur;
   GaussianBlur(imG, imBlur, Size(11,11), 0);

   imshow("Blurred image", imBlur);

   while ( waitKey( 33 ) != 27 );

   return 0;
}

// int main( int argc, char **argv)
// {
//    Mat image = imread( argv[1] );
   
//    namedWindow( "Original", CV_WINDOW_NORMAL | CV_WINDOW_KEEPRATIO | CV_GUI_EXPANDED );
//    imshow( "Original", image );
   
//    // Sobel example from http://docs.opencv.org/doc/user_guide/ug_mat.html#visualizing-images
//    Mat gray;
   
//    cvtColor( image, gray, CV_BGR2GRAY );
   
//    Mat sobelx;
   
//    Sobel( gray, sobelx, CV_32F, 1, 0 );
   
//    double minVal = 0.0;
//    double maxVal = 0.0;
   
//    minMaxLoc(sobelx, &minVal, &maxVal); //find minimum and maximum intensities
   
//    Mat draw;
   
//    sobelx.convertTo( draw, CV_8U, 255.0/(maxVal - minVal), -minVal * 255.0/(maxVal - minVal) );
   
//    namedWindow( "Sobel", CV_WINDOW_NORMAL | CV_WINDOW_KEEPRATIO | CV_GUI_EXPANDED );
//    imshow( "Sobel", draw );

//    while ( waitKey( 33 ) != 27 )
//       ;
      
//    return 0;
// }