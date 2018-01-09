
#pragma once

#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"

cv::Mat processRawImage(cv::Mat imIn);

// press 'c' button to continue
void press(char c);

cv::Point findBoardCenter(cv::Mat imDilate);

void takeOutBoard(cv::Mat& imDilate, cv::Point center);

void drawLine(cv::Vec2f line, cv::Mat &img, cv::Scalar rgb = CV_RGB(0,0,255));