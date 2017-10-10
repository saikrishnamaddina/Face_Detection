
cmake_minimum_required(VERSION 2.8)
project( Facedetection )
find_package(OpenCV REQUIRED)
add_executable(Facedetect Face_Detect.cpp)
target_link_libraries( Facdetect ${OpenCV_LIBS})    
