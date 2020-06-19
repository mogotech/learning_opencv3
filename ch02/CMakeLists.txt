project(CH02)

add_executable(example_02-01 example_02-01.cpp)
target_link_libraries(example_02-01 LINK_PUBLIC opencv_core opencv_highgui opencv_imgcodecs)

add_executable(example_02-02 example_02-02.cpp)
target_link_libraries(example_02-02 LINK_PUBLIC opencv_core opencv_highgui opencv_imgcodecs)

add_executable(example_02-03 example_02-03.cpp)
target_link_libraries(example_02-03 LINK_PUBLIC opencv_core opencv_highgui opencv_imgcodecs opencv_videoio)

add_executable(example_02-04 example_02-04.cpp)
target_link_libraries(example_02-04 LINK_PUBLIC opencv_core opencv_highgui opencv_imgcodecs opencv_videoio)

add_executable(example_02-05 example_02-05.cpp)
target_link_libraries(example_02-05 LINK_PUBLIC opencv_core opencv_highgui opencv_imgcodecs opencv_imgproc)