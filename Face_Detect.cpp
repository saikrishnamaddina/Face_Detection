#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/objdetect/objdetect.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	std::vector<Rect> faces;
	Mat frame=imread("5.jpg",1);
	// Load Face cascade (.xml file)
	CascadeClassifier face_cascade;
	face_cascade.load("haarcascade_frontalface_alt2.xml" );
	face_cascade.detectMultiScale( frame, faces, 1.2,
			2, 0|CV_HAAR_SCALE_IMAGE, Size(30,30) );
	cout << "Number of detected faces: " << faces.size() << std::endl;
	// Draw circles on the detected faces
	for( int i = 0; i < faces.size(); i++ )
	{
		Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );
		//ellipse( frame, center, Size( faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar( 255, 255, 0 ), 4, 8, 0 );
		Rect myROI(faces[i].x,faces[i].y,faces[i].width,faces[i].height);
		rectangle( frame, myROI, Scalar( 0, 255, 0 ), 4, 8, 0 );
	}
	imshow("MyVideo", frame); //show the frame in "MyVideo" window
	waitKey(0);
}
