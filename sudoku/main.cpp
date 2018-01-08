#include "Util.h"

#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"

// Following Tutorial:
// http://aishack.in/tutorials/sudoku-grabber-opencv-detection/

using namespace cv;


int main(int argc, char **argv)
{
	string imgFilename = "sudoku.jpg";
	Mat imG = imread(imgFilename, 0);

	Mat imDilate = processRawImage(imG);

    Point center = findBoardCenter(imDilate);

    floodFill(imDilate, center, CV_RGB(255,255,255));

   	imshow("Boarders", imDilate); press('q');


	takeOutBoard(imDilate, center);
	
   	imshow("Boarders", imDilate); press('q');

   	return 0;
}
