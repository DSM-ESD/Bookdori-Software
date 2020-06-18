#pragma once
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing.h>
#include <dlib/opencv.h>

#include <array>
#include <string>

using namespace dlib;

class face_encode
{
private:
	frontal_face_detector faceDetector = get_frontal_face_detector();

	shape_predictor landmarkDetector;

public:
	face_encode(std::string _path = "shape_predictor_68_face_landmarks.dat")
	{
		deserialize(_path) >> landmarkDetector;
	}

	std::array<double, 128> get_face_encode(cv_image<bgr_pixel> img, rectangle pos)
	{

	}
};
