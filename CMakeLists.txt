cmake_minimum_required(VERSION 2.8)
project( OpenCVTutorial )
find_package( OpenCV REQUIRED )
add_executable( DisplayImage DisplayImage.cpp )
add_executable( ChangeImage ChangeImage.cpp )
add_executable( FilterImage FilterImage.cpp )
add_executable( CreateImage CreateImage.cpp )
add_executable( CaptureVideo CaptureVideo.cpp )
add_executable( CaptureWebcam CaptureWebcam.cpp )
add_executable( CreateAndSaveImage CreateAndSaveImage.cpp )
target_link_libraries( ChangeImage ${OpenCV_LIBS} )
target_link_libraries( DisplayImage ${OpenCV_LIBS} )
target_link_libraries( FilterImage ${OpenCV_LIBS} )
target_link_libraries( CreateImage ${OpenCV_LIBS} )
target_link_libraries( CaptureVideo ${OpenCV_LIBS} )
target_link_libraries( CaptureWebcam ${OpenCV_LIBS} )
target_link_libraries( CreateAndSaveImage ${OpenCV_LIBS} )
