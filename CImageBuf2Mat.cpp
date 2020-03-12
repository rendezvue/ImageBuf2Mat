#include "CImageBuf2Mat.h"

CImageBuf2Mat::CImageBuf2Mat()
{

}

CImageBuf2Mat::~CImageBuf2Mat(void)
{
}

cv::Mat CImageBuf2Mat::Cvt(ImageBuf& image_buf)
{
	cv::Mat mat_image ;
	
    if( image_buf.image_width > 0 && image_buf.image_height > 0 )
	{
        if( image_buf.image_type == IMAGE_YUV420 )
		{
			//YUV420 
            cv::Mat get_image(image_buf.image_height + image_buf.image_height / 2, image_buf.image_width, CV_8UC1, image_buf.p_buf) ;

	        CImgDec cls_image_decoder ;
	        mat_image = cls_image_decoder.Decoding(get_image) ;

		}
        else if( image_buf.image_type == IMAGE_RGB888 )
		{
            cv::Mat get_image(image_buf.image_height, image_buf.image_width, CV_8UC3, image_buf.p_buf) ;
			cv::cvtColor(get_image, mat_image, cv::COLOR_BGR2RGB) ;
		}
        else if( image_buf.image_type == ImageTypeOption::IMAGE_JPG)
        {
        	//cv::Mat get_image = cv::imdecode(cv::Mat(image_buf.p_buf), 1);
            cv::Mat get_image = cv::imdecode(cv::Mat(1, image_buf.buf_length, CV_8UC1, image_buf.p_buf), cv::IMREAD_UNCHANGED) ;
			if( !get_image.empty() )	cv::cvtColor(get_image, mat_image, cv::COLOR_BGR2RGB) ;
        }
	}

	return mat_image ;
}

