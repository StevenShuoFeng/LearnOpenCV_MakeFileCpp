#include "Util.h"


using namespace cv;

Mat processRawImage(Mat imIn)
{
	Mat out;

	// imshow("Gray image", imIn);

	Mat imBlur, outerBox;
   	GaussianBlur(imIn, imBlur, Size(11,11), 0);
   	// imshow("Blurred image", imBlur);

   	adaptiveThreshold(imBlur, outerBox, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY_INV, 5, 2);
   	// imshow("Binary image", outerBox);


   	// Mat imDilate;
   	Mat kernel = (Mat_<uchar>(3,3) << 0,1,0,1,1,1,0,1,0);
    dilate(outerBox, out, kernel);

    return out;
}

Point findBoardCenter(Mat imDilate)
{
    Point center;

    int max=-1;


    for(int y = 0; y < imDilate.size().height; y++)
    {
        uchar *row = imDilate.ptr(y);
        for(int x = 0; x < imDilate.size().width; x++)
        {
            if(row[x]>=128)
            {

                 int area = floodFill(imDilate, Point(x,y), CV_RGB(0,0,64));

                 if(area > max)
                 {
                    center = Point(x,y);
                    max = area;
                 }
            }
        }

    }

    return center;
}

void takeOutBoard(Mat& imDilate, Point center)
{	
	for(int y = 0; y < imDilate.size().height; y++)
    {
        uchar *row = imDilate.ptr(y);
        for(int x = 0; x < imDilate.size().width; x++)
        {
            if(row[x]==64 && x!=center.x && y!=center.y)
            {
                floodFill(imDilate, Point(x,y), CV_RGB(0,0,0));
            }
        }
    }
}

void drawLine(Vec2f line, Mat &img, Scalar rgb)
{
    if(line[1]!=0)
    {
        float m = -1/tan(line[1]);

        float c = line[0]/sin(line[1]);

        cv::line(img, Point(0, c), Point(img.size().width, m*img.size().width+c), rgb);
    }
    else
    {
        cv::line(img, Point(line[0], 0), Point(line[0], img.size().height), rgb);
    }

}


void press(char c)
{
   	while(waitKey(1) != c); 
}