#ifndef CIMAGEBUF2MAT_H
#define CIMAGEBUF2MAT_H

#include "opencv2/opencv.hpp"
#include "EnsembleCommon.h"
#include "ImgDec.h"

class CImageBuf2Mat
{
public:
	CImageBuf2Mat(void) ;
 	virtual ~CImageBuf2Mat() ;

public:
	cv::Mat Cvt(ImageBuf& image_buf) ;
};

#endif // CENSEMBLE_H
