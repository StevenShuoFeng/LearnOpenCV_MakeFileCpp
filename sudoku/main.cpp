#include "Util.h"

#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"

// Following Tutorial:
// http://aishack.in/tutorials/sudoku-grabber-opencv-detection/

using namespace cv;
// using namespace std;

int main(int argc, char **argv)
{
	string imgFilename = "sudoku.jpg";
	Mat imG = imread(imgFilename, 0);

	Mat imDilate = processRawImage(imG);

    Point center = findBoardCenter(imDilate);

    floodFill(imDilate, center, CV_RGB(255,255,255));

   	imshow("Hightlighted Boarders", imDilate); press('q');

   	Mat outerBox = imDilate;
	takeOutBoard(outerBox, center);

   	imshow("Only Boarders", outerBox); press('q');

	vector<Vec2f> lines;
    HoughLines(outerBox, lines, 1, CV_PI/180, 200);

	for(int i=0;i<lines.size();i++)
    {
        drawLine(lines[i], outerBox, CV_RGB(0,0,128));
    }

   	imshow("Lines", outerBox); press('q');press('q');

   	return 0;
}
