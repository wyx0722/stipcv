
#ifndef HARRISBUFFER_H
#define HARRISBUFFER_H

#include "cv.h"
#include "stbuffer.h"



class HarrisBuffer
{
private:

	CvMat* normvec;
	CvMat JetFilter;

	std::vector<double> SpatialMaskSeparable;
	std::vector<double> SpatialMask;
	std::vector<double> TemporalMask1;
	std::vector<double> TemporalMask2;
	std::vector<double> DerivMask;

	STBuffer original;	

	STBuffer databuffer;
	STBuffer convbuffer;

	STBuffer cxxbuffer;
	STBuffer cxybuffer;
	STBuffer cxtbuffer;
	STBuffer cyybuffer;
	STBuffer cytbuffer;
	STBuffer cttbuffer;	

	STBuffer Hbuffer;

	std::ofstream FeatureFile;

	int iFrame;

	InterestPointList ipList;


	//temp images
	IplImage* tmp;
	IplImage* tmp1;
	IplImage* tmp2;
	IplImage* tmp3;
	IplImage* tmp4;
	IplImage* header;
	IplImage* gray;	//input grayscale image 
	IplImage* frame; //input image type=IMGTYPE
	IplImage* vis;	//hbuffer image
	

	IplImage* cxx;
	IplImage* cxy;
	IplImage* cxt;
	IplImage* cyy;
	IplImage* cyt;
	IplImage* ctt;

	IplImage* L;
	IplImage* Lt;
	IplImage* Lx;
	IplImage* Ly;

	void GaussianSmoothingMul(IplImage* im1, IplImage* im2, IplImage* dst, double sigma);
	void HarrisFunction(/*IplImage* cxx,IplImage* cxy,IplImage* cxt,IplImage* cyy,IplImage* cyt,IplImage* ctt,*/ double k, IplImage* dst);
	void WriteFeatures(InterestPoint &ip);

public:
	
	double kparam;	//parameter of point detection with the default value 0.0005
	double sig2;	//variance of spatial smoothing filter 
	double tau2;	
	int delay;
	double SignificantPointThresh;
	int Border;

	HarrisBuffer(void);
	~HarrisBuffer(void);

	IplImage* getHBufferImage(int type);

	bool Init(IplImage* firstfrm, std::string fname);
	void ProcessFrame(IplImage* frame);
	void DetectInterestPoints(int border=0);
	void DrawInterestPoints(IplImage* im);
	int NumberOfDetectedIPs();
};




#endif //HARRISBUFFER_H
