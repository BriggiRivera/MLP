#define cimg_use_jpeg
#include "Common/ImageProcessing/CImg.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;
using namespace cimg_library;

struct Feature
{
	float sum;
	float mean;
	float median;
	float max;
	float min;

	Feature() {
		sum = 0;
        	mean = 0;
        	median = 0;
        	max = -1 * numeric_limits<float>::infinity();
        	min = numeric_limits<float>::infinity();
	}

};

Feature getStatistics(CImg<float>& wavelet){
	vector<float> features;
	Feature result;

	float value = 0;
	for(int y=0; y<32 ;y++)
        {
        	for(int x=0; x<32  ;x++)
                {
			value = wavelet(x,y);
                	features.push_back(value);
			result.sum += value;
			result.min = result.min > value ? value : result.min;
			result.max = result.max < value ? value : result.max;
                }
        }
	result.mean = result.sum / 1024;

	sort(features.begin(), features.end());
	result.median = features[512];
	
	return result;
}

void process(vector<string>& id, vector<string>& pictures)
{
	for(int index=0;index<pictures.size(); index++)
	{
		CImg<float> image(pictures[index].c_str());
		image.resize(256,256);
		CImg<float> wavelet = image.haar(false, 3);
		Feature result = getStatistics(wavelet);
		cout<<id[index]<<", "<<result.mean<<", "<<result.median<<", "<<result.max<<", "<<result.min<<endl;
	}
}

void loadTest(vector<string>& ids, vector<string>& paths)
{
	ids.push_back("1"); paths.push_back("Resources/faces/adhast/adhast.5.jpg");
	ids.push_back("1"); paths.push_back("Resources/faces/adhast/adhast.10.jpg");
	ids.push_back("1"); paths.push_back("Resources/faces/adhast/adhast.15.jpg");
	ids.push_back("1"); paths.push_back("Resources/faces/adhast/adhast.20.jpg");
	ids.push_back("2"); paths.push_back("Resources/faces/ajbake/ajbake.5.jpg");
	ids.push_back("2"); paths.push_back("Resources/faces/ajbake/ajbake.10.jpg");
	ids.push_back("2"); paths.push_back("Resources/faces/ajbake/ajbake.15.jpg");
	ids.push_back("2"); paths.push_back("Resources/faces/ajbake/ajbake.20.jpg");
	ids.push_back("3"); paths.push_back("Resources/faces/apapou/apapou.5.jpg");
	ids.push_back("3"); paths.push_back("Resources/faces/apapou/apapou.10.jpg");
	ids.push_back("3"); paths.push_back("Resources/faces/apapou/apapou.15.jpg");
	ids.push_back("3"); paths.push_back("Resources/faces/apapou/apapou.20.jpg");
	ids.push_back("4"); paths.push_back("Resources/faces/apdavi/apdavi.5.jpg");
	ids.push_back("4"); paths.push_back("Resources/faces/apdavi/apdavi.10.jpg");
	ids.push_back("4"); paths.push_back("Resources/faces/apdavi/apdavi.15.jpg");
	ids.push_back("4"); paths.push_back("Resources/faces/apdavi/apdavi.20.jpg");
	ids.push_back("5"); paths.push_back("Resources/faces/ardper/ardper.5.jpg");
	ids.push_back("5"); paths.push_back("Resources/faces/ardper/ardper.10.jpg");
	ids.push_back("5"); paths.push_back("Resources/faces/ardper/ardper.15.jpg");
	ids.push_back("5"); paths.push_back("Resources/faces/ardper/ardper.20.jpg");
	ids.push_back("6"); paths.push_back("Resources/faces/awjsud/awjsud.5.jpg");
	ids.push_back("6"); paths.push_back("Resources/faces/awjsud/awjsud.10.jpg");
	ids.push_back("6"); paths.push_back("Resources/faces/awjsud/awjsud.15.jpg");
	ids.push_back("6"); paths.push_back("Resources/faces/awjsud/awjsud.20.jpg");
	ids.push_back("7"); paths.push_back("Resources/faces/boylee/boylee.5.jpg");
	ids.push_back("7"); paths.push_back("Resources/faces/boylee/boylee.10.jpg");
	ids.push_back("7"); paths.push_back("Resources/faces/boylee/boylee.15.jpg");
	ids.push_back("7"); paths.push_back("Resources/faces/boylee/boylee.20.jpg");
	ids.push_back("8"); paths.push_back("Resources/faces/bschap/bschap.1.jpg");
	ids.push_back("8"); paths.push_back("Resources/faces/bschap/bschap.2.jpg");
	ids.push_back("8"); paths.push_back("Resources/faces/bschap/bschap.3.jpg");
	ids.push_back("8"); paths.push_back("Resources/faces/bschap/bschap.4.jpg");
	ids.push_back("8"); paths.push_back("Resources/faces/bschap/bschap.6.jpg");
	ids.push_back("8"); paths.push_back("Resources/faces/bschap/bschap.7.jpg");
	ids.push_back("8"); paths.push_back("Resources/faces/bschap/bschap.8.jpg");
	ids.push_back("8"); paths.push_back("Resources/faces/bschap/bschap.9.jpg");
	ids.push_back("8"); paths.push_back("Resources/faces/bschap/bschap.11.jpg");
	ids.push_back("8"); paths.push_back("Resources/faces/bschap/bschap.12.jpg");
	ids.push_back("8"); paths.push_back("Resources/faces/bschap/bschap.13.jpg");
	ids.push_back("8"); paths.push_back("Resources/faces/bschap/bschap.14.jpg");
	ids.push_back("8"); paths.push_back("Resources/faces/bschap/bschap.16.jpg");
	ids.push_back("8"); paths.push_back("Resources/faces/bschap/bschap.17.jpg");
	ids.push_back("8"); paths.push_back("Resources/faces/bschap/bschap.18.jpg");
	ids.push_back("8"); paths.push_back("Resources/faces/bschap/bschap.19.jpg");
	ids.push_back("9"); paths.push_back("Resources/faces/cadugd/cadugd.5.jpg");
	ids.push_back("9"); paths.push_back("Resources/faces/cadugd/cadugd.10.jpg");
	ids.push_back("9"); paths.push_back("Resources/faces/cadugd/cadugd.15.jpg");
	ids.push_back("9"); paths.push_back("Resources/faces/cadugd/cadugd.20.jpg");
	ids.push_back("10"); paths.push_back("Resources/faces/cdlarg/cdlarg.5.jpg");
	ids.push_back("10"); paths.push_back("Resources/faces/cdlarg/cdlarg.10.jpg");
	ids.push_back("10"); paths.push_back("Resources/faces/cdlarg/cdlarg.15.jpg");
	ids.push_back("10"); paths.push_back("Resources/faces/cdlarg/cdlarg.20.jpg");
	ids.push_back("11"); paths.push_back("Resources/faces/cfloro/cfloro.5.jpg");
	ids.push_back("11"); paths.push_back("Resources/faces/cfloro/cfloro.10.jpg");
	ids.push_back("11"); paths.push_back("Resources/faces/cfloro/cfloro.15.jpg");
	ids.push_back("11"); paths.push_back("Resources/faces/cfloro/cfloro.20.jpg");
	ids.push_back("12"); paths.push_back("Resources/faces/cladam/cladam.5.jpg");
	ids.push_back("12"); paths.push_back("Resources/faces/cladam/cladam.10.jpg");
	ids.push_back("12"); paths.push_back("Resources/faces/cladam/cladam.15.jpg");
	ids.push_back("12"); paths.push_back("Resources/faces/cladam/cladam.20.jpg");
}


void loadTrainning(vector<string>& ids, vector<string>& paths)
{
	ids.push_back("1"); paths.push_back("Resources/faces/adhast/adhast.1.jpg");
	ids.push_back("1"); paths.push_back("Resources/faces/adhast/adhast.2.jpg");
	ids.push_back("1"); paths.push_back("Resources/faces/adhast/adhast.3.jpg");
	ids.push_back("1"); paths.push_back("Resources/faces/adhast/adhast.4.jpg");
	ids.push_back("1"); paths.push_back("Resources/faces/adhast/adhast.6.jpg");
	ids.push_back("1"); paths.push_back("Resources/faces/adhast/adhast.7.jpg");
	ids.push_back("1"); paths.push_back("Resources/faces/adhast/adhast.8.jpg");
	ids.push_back("1"); paths.push_back("Resources/faces/adhast/adhast.9.jpg");
	ids.push_back("1"); paths.push_back("Resources/faces/adhast/adhast.11.jpg");
	ids.push_back("1"); paths.push_back("Resources/faces/adhast/adhast.12.jpg");
	ids.push_back("1"); paths.push_back("Resources/faces/adhast/adhast.13.jpg");
	ids.push_back("1"); paths.push_back("Resources/faces/adhast/adhast.14.jpg");
	ids.push_back("1"); paths.push_back("Resources/faces/adhast/adhast.16.jpg");
	ids.push_back("1"); paths.push_back("Resources/faces/adhast/adhast.17.jpg");
	ids.push_back("1"); paths.push_back("Resources/faces/adhast/adhast.18.jpg");
	ids.push_back("1"); paths.push_back("Resources/faces/adhast/adhast.19.jpg");
	ids.push_back("2"); paths.push_back("Resources/faces/ajbake/ajbake.1.jpg");
	ids.push_back("2"); paths.push_back("Resources/faces/ajbake/ajbake.2.jpg");
	ids.push_back("2"); paths.push_back("Resources/faces/ajbake/ajbake.3.jpg");
	ids.push_back("2"); paths.push_back("Resources/faces/ajbake/ajbake.4.jpg");
	ids.push_back("2"); paths.push_back("Resources/faces/ajbake/ajbake.6.jpg");
	ids.push_back("2"); paths.push_back("Resources/faces/ajbake/ajbake.7.jpg");
	ids.push_back("2"); paths.push_back("Resources/faces/ajbake/ajbake.8.jpg");
	ids.push_back("2"); paths.push_back("Resources/faces/ajbake/ajbake.9.jpg");
	ids.push_back("2"); paths.push_back("Resources/faces/ajbake/ajbake.11.jpg");
	ids.push_back("2"); paths.push_back("Resources/faces/ajbake/ajbake.12.jpg");
	ids.push_back("2"); paths.push_back("Resources/faces/ajbake/ajbake.13.jpg");
	ids.push_back("2"); paths.push_back("Resources/faces/ajbake/ajbake.14.jpg");
	ids.push_back("2"); paths.push_back("Resources/faces/ajbake/ajbake.16.jpg");
	ids.push_back("2"); paths.push_back("Resources/faces/ajbake/ajbake.17.jpg");
	ids.push_back("2"); paths.push_back("Resources/faces/ajbake/ajbake.18.jpg");
	ids.push_back("2"); paths.push_back("Resources/faces/ajbake/ajbake.19.jpg");
	ids.push_back("3"); paths.push_back("Resources/faces/apapou/apapou.1.jpg");
	ids.push_back("3"); paths.push_back("Resources/faces/apapou/apapou.2.jpg");
	ids.push_back("3"); paths.push_back("Resources/faces/apapou/apapou.3.jpg");
	ids.push_back("3"); paths.push_back("Resources/faces/apapou/apapou.4.jpg");
	ids.push_back("3"); paths.push_back("Resources/faces/apapou/apapou.6.jpg");
	ids.push_back("3"); paths.push_back("Resources/faces/apapou/apapou.7.jpg");
	ids.push_back("3"); paths.push_back("Resources/faces/apapou/apapou.8.jpg");
	ids.push_back("3"); paths.push_back("Resources/faces/apapou/apapou.9.jpg");
	ids.push_back("3"); paths.push_back("Resources/faces/apapou/apapou.11.jpg");
	ids.push_back("3"); paths.push_back("Resources/faces/apapou/apapou.12.jpg");
	ids.push_back("3"); paths.push_back("Resources/faces/apapou/apapou.13.jpg");
	ids.push_back("3"); paths.push_back("Resources/faces/apapou/apapou.14.jpg");
	ids.push_back("3"); paths.push_back("Resources/faces/apapou/apapou.16.jpg");
	ids.push_back("3"); paths.push_back("Resources/faces/apapou/apapou.17.jpg");
	ids.push_back("3"); paths.push_back("Resources/faces/apapou/apapou.18.jpg");
	ids.push_back("3"); paths.push_back("Resources/faces/apapou/apapou.19.jpg");
	ids.push_back("4"); paths.push_back("Resources/faces/apdavi/apdavi.1.jpg");
	ids.push_back("4"); paths.push_back("Resources/faces/apdavi/apdavi.2.jpg");
	ids.push_back("4"); paths.push_back("Resources/faces/apdavi/apdavi.3.jpg");
	ids.push_back("4"); paths.push_back("Resources/faces/apdavi/apdavi.4.jpg");
	ids.push_back("4"); paths.push_back("Resources/faces/apdavi/apdavi.6.jpg");
	ids.push_back("4"); paths.push_back("Resources/faces/apdavi/apdavi.7.jpg");
	ids.push_back("4"); paths.push_back("Resources/faces/apdavi/apdavi.8.jpg");
	ids.push_back("4"); paths.push_back("Resources/faces/apdavi/apdavi.9.jpg");
	ids.push_back("4"); paths.push_back("Resources/faces/apdavi/apdavi.11.jpg");
	ids.push_back("4"); paths.push_back("Resources/faces/apdavi/apdavi.12.jpg");
	ids.push_back("4"); paths.push_back("Resources/faces/apdavi/apdavi.13.jpg");
	ids.push_back("4"); paths.push_back("Resources/faces/apdavi/apdavi.14.jpg");
	ids.push_back("4"); paths.push_back("Resources/faces/apdavi/apdavi.16.jpg");
	ids.push_back("4"); paths.push_back("Resources/faces/apdavi/apdavi.17.jpg");
	ids.push_back("4"); paths.push_back("Resources/faces/apdavi/apdavi.18.jpg");
	ids.push_back("4"); paths.push_back("Resources/faces/apdavi/apdavi.19.jpg");
	ids.push_back("5"); paths.push_back("Resources/faces/ardper/ardper.1.jpg");
	ids.push_back("5"); paths.push_back("Resources/faces/ardper/ardper.2.jpg");
	ids.push_back("5"); paths.push_back("Resources/faces/ardper/ardper.3.jpg");
	ids.push_back("5"); paths.push_back("Resources/faces/ardper/ardper.4.jpg");
	ids.push_back("5"); paths.push_back("Resources/faces/ardper/ardper.6.jpg");
	ids.push_back("5"); paths.push_back("Resources/faces/ardper/ardper.7.jpg");
	ids.push_back("5"); paths.push_back("Resources/faces/ardper/ardper.8.jpg");
	ids.push_back("5"); paths.push_back("Resources/faces/ardper/ardper.9.jpg");
	ids.push_back("5"); paths.push_back("Resources/faces/ardper/ardper.11.jpg");
	ids.push_back("5"); paths.push_back("Resources/faces/ardper/ardper.12.jpg");
	ids.push_back("5"); paths.push_back("Resources/faces/ardper/ardper.13.jpg");
	ids.push_back("5"); paths.push_back("Resources/faces/ardper/ardper.14.jpg");
	ids.push_back("5"); paths.push_back("Resources/faces/ardper/ardper.16.jpg");
	ids.push_back("5"); paths.push_back("Resources/faces/ardper/ardper.17.jpg");
	ids.push_back("5"); paths.push_back("Resources/faces/ardper/ardper.18.jpg");
	ids.push_back("5"); paths.push_back("Resources/faces/ardper/ardper.19.jpg");
	ids.push_back("6"); paths.push_back("Resources/faces/awjsud/awjsud.1.jpg");
	ids.push_back("6"); paths.push_back("Resources/faces/awjsud/awjsud.2.jpg");
	ids.push_back("6"); paths.push_back("Resources/faces/awjsud/awjsud.3.jpg");
	ids.push_back("6"); paths.push_back("Resources/faces/awjsud/awjsud.4.jpg");
	ids.push_back("6"); paths.push_back("Resources/faces/awjsud/awjsud.6.jpg");
	ids.push_back("6"); paths.push_back("Resources/faces/awjsud/awjsud.7.jpg");
	ids.push_back("6"); paths.push_back("Resources/faces/awjsud/awjsud.8.jpg");
	ids.push_back("6"); paths.push_back("Resources/faces/awjsud/awjsud.9.jpg");
	ids.push_back("6"); paths.push_back("Resources/faces/awjsud/awjsud.11.jpg");
	ids.push_back("6"); paths.push_back("Resources/faces/awjsud/awjsud.12.jpg");
	ids.push_back("6"); paths.push_back("Resources/faces/awjsud/awjsud.13.jpg");
	ids.push_back("6"); paths.push_back("Resources/faces/awjsud/awjsud.14.jpg");
	ids.push_back("6"); paths.push_back("Resources/faces/awjsud/awjsud.16.jpg");
	ids.push_back("6"); paths.push_back("Resources/faces/awjsud/awjsud.17.jpg");
	ids.push_back("6"); paths.push_back("Resources/faces/awjsud/awjsud.18.jpg");
	ids.push_back("6"); paths.push_back("Resources/faces/awjsud/awjsud.19.jpg");
	ids.push_back("7"); paths.push_back("Resources/faces/boylee/boylee.1.jpg");
	ids.push_back("7"); paths.push_back("Resources/faces/boylee/boylee.2.jpg");
	ids.push_back("7"); paths.push_back("Resources/faces/boylee/boylee.3.jpg");
	ids.push_back("7"); paths.push_back("Resources/faces/boylee/boylee.4.jpg");
	ids.push_back("7"); paths.push_back("Resources/faces/boylee/boylee.6.jpg");
	ids.push_back("7"); paths.push_back("Resources/faces/boylee/boylee.7.jpg");
	ids.push_back("7"); paths.push_back("Resources/faces/boylee/boylee.8.jpg");
	ids.push_back("7"); paths.push_back("Resources/faces/boylee/boylee.9.jpg");
	ids.push_back("7"); paths.push_back("Resources/faces/boylee/boylee.11.jpg");
	ids.push_back("7"); paths.push_back("Resources/faces/boylee/boylee.12.jpg");
	ids.push_back("7"); paths.push_back("Resources/faces/boylee/boylee.13.jpg");
	ids.push_back("7"); paths.push_back("Resources/faces/boylee/boylee.14.jpg");
	ids.push_back("7"); paths.push_back("Resources/faces/boylee/boylee.16.jpg");
	ids.push_back("7"); paths.push_back("Resources/faces/boylee/boylee.17.jpg");
	ids.push_back("7"); paths.push_back("Resources/faces/boylee/boylee.18.jpg");
	ids.push_back("7"); paths.push_back("Resources/faces/boylee/boylee.19.jpg");
	ids.push_back("8"); paths.push_back("Resources/faces/bschap/bschap.5.jpg");
	ids.push_back("8"); paths.push_back("Resources/faces/bschap/bschap.10.jpg");
	ids.push_back("8"); paths.push_back("Resources/faces/bschap/bschap.15.jpg");
	ids.push_back("8"); paths.push_back("Resources/faces/bschap/bschap.20.jpg");
	ids.push_back("9"); paths.push_back("Resources/faces/cadugd/cadugd.1.jpg");
	ids.push_back("9"); paths.push_back("Resources/faces/cadugd/cadugd.2.jpg");
	ids.push_back("9"); paths.push_back("Resources/faces/cadugd/cadugd.3.jpg");
	ids.push_back("9"); paths.push_back("Resources/faces/cadugd/cadugd.4.jpg");
	ids.push_back("9"); paths.push_back("Resources/faces/cadugd/cadugd.6.jpg");
	ids.push_back("9"); paths.push_back("Resources/faces/cadugd/cadugd.7.jpg");
	ids.push_back("9"); paths.push_back("Resources/faces/cadugd/cadugd.8.jpg");
	ids.push_back("9"); paths.push_back("Resources/faces/cadugd/cadugd.9.jpg");
	ids.push_back("9"); paths.push_back("Resources/faces/cadugd/cadugd.11.jpg");
	ids.push_back("9"); paths.push_back("Resources/faces/cadugd/cadugd.12.jpg");
	ids.push_back("9"); paths.push_back("Resources/faces/cadugd/cadugd.13.jpg");
	ids.push_back("9"); paths.push_back("Resources/faces/cadugd/cadugd.14.jpg");
	ids.push_back("9"); paths.push_back("Resources/faces/cadugd/cadugd.16.jpg");
	ids.push_back("9"); paths.push_back("Resources/faces/cadugd/cadugd.17.jpg");
	ids.push_back("9"); paths.push_back("Resources/faces/cadugd/cadugd.18.jpg");
	ids.push_back("9"); paths.push_back("Resources/faces/cadugd/cadugd.19.jpg");
	ids.push_back("10"); paths.push_back("Resources/faces/cdlarg/cdlarg.1.jpg");
	ids.push_back("10"); paths.push_back("Resources/faces/cdlarg/cdlarg.2.jpg");
	ids.push_back("10"); paths.push_back("Resources/faces/cdlarg/cdlarg.3.jpg");
	ids.push_back("10"); paths.push_back("Resources/faces/cdlarg/cdlarg.4.jpg");
	ids.push_back("10"); paths.push_back("Resources/faces/cdlarg/cdlarg.6.jpg");
	ids.push_back("10"); paths.push_back("Resources/faces/cdlarg/cdlarg.7.jpg");
	ids.push_back("10"); paths.push_back("Resources/faces/cdlarg/cdlarg.8.jpg");
	ids.push_back("10"); paths.push_back("Resources/faces/cdlarg/cdlarg.9.jpg");
	ids.push_back("10"); paths.push_back("Resources/faces/cdlarg/cdlarg.11.jpg");
	ids.push_back("10"); paths.push_back("Resources/faces/cdlarg/cdlarg.12.jpg");
	ids.push_back("10"); paths.push_back("Resources/faces/cdlarg/cdlarg.13.jpg");
	ids.push_back("10"); paths.push_back("Resources/faces/cdlarg/cdlarg.14.jpg");
	ids.push_back("10"); paths.push_back("Resources/faces/cdlarg/cdlarg.16.jpg");
	ids.push_back("10"); paths.push_back("Resources/faces/cdlarg/cdlarg.17.jpg");
	ids.push_back("10"); paths.push_back("Resources/faces/cdlarg/cdlarg.18.jpg");
	ids.push_back("10"); paths.push_back("Resources/faces/cdlarg/cdlarg.19.jpg");
	ids.push_back("11"); paths.push_back("Resources/faces/cfloro/cfloro.1.jpg");
	ids.push_back("11"); paths.push_back("Resources/faces/cfloro/cfloro.2.jpg");
	ids.push_back("11"); paths.push_back("Resources/faces/cfloro/cfloro.3.jpg");
	ids.push_back("11"); paths.push_back("Resources/faces/cfloro/cfloro.4.jpg");
	ids.push_back("11"); paths.push_back("Resources/faces/cfloro/cfloro.6.jpg");
	ids.push_back("11"); paths.push_back("Resources/faces/cfloro/cfloro.7.jpg");
	ids.push_back("11"); paths.push_back("Resources/faces/cfloro/cfloro.8.jpg");
	ids.push_back("11"); paths.push_back("Resources/faces/cfloro/cfloro.9.jpg");
	ids.push_back("11"); paths.push_back("Resources/faces/cfloro/cfloro.11.jpg");
	ids.push_back("11"); paths.push_back("Resources/faces/cfloro/cfloro.12.jpg");
	ids.push_back("11"); paths.push_back("Resources/faces/cfloro/cfloro.13.jpg");
	ids.push_back("11"); paths.push_back("Resources/faces/cfloro/cfloro.14.jpg");
	ids.push_back("11"); paths.push_back("Resources/faces/cfloro/cfloro.16.jpg");
	ids.push_back("11"); paths.push_back("Resources/faces/cfloro/cfloro.17.jpg");
	ids.push_back("11"); paths.push_back("Resources/faces/cfloro/cfloro.18.jpg");
	ids.push_back("11"); paths.push_back("Resources/faces/cfloro/cfloro.19.jpg");
	ids.push_back("12"); paths.push_back("Resources/faces/cladam/cladam.1.jpg");
	ids.push_back("12"); paths.push_back("Resources/faces/cladam/cladam.2.jpg");
	ids.push_back("12"); paths.push_back("Resources/faces/cladam/cladam.3.jpg");
	ids.push_back("12"); paths.push_back("Resources/faces/cladam/cladam.4.jpg");
	ids.push_back("12"); paths.push_back("Resources/faces/cladam/cladam.6.jpg");
	ids.push_back("12"); paths.push_back("Resources/faces/cladam/cladam.7.jpg");
	ids.push_back("12"); paths.push_back("Resources/faces/cladam/cladam.8.jpg");
	ids.push_back("12"); paths.push_back("Resources/faces/cladam/cladam.9.jpg");
	ids.push_back("12"); paths.push_back("Resources/faces/cladam/cladam.11.jpg");
	ids.push_back("12"); paths.push_back("Resources/faces/cladam/cladam.12.jpg");
	ids.push_back("12"); paths.push_back("Resources/faces/cladam/cladam.13.jpg");
	ids.push_back("12"); paths.push_back("Resources/faces/cladam/cladam.14.jpg");
	ids.push_back("12"); paths.push_back("Resources/faces/cladam/cladam.16.jpg");
	ids.push_back("12"); paths.push_back("Resources/faces/cladam/cladam.17.jpg");
	ids.push_back("12"); paths.push_back("Resources/faces/cladam/cladam.18.jpg");
	ids.push_back("12"); paths.push_back("Resources/faces/cladam/cladam.19.jpg");
}

int main(int argc, char** argv)
{
	vector<string> ids;
	vector<string> paths;
	if (argc > 1)
	{
		loadTest(ids, paths);
	}
	else
	{
		loadTrainning(ids, paths);
	}
	process(ids, paths);
	return 0;
}


