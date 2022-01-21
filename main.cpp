/************************************************************
▪MacのXCode7.0~にHomebrewを使ってOpenCV3.0.0を導入する
	http://ithat.me/2015/09/27/how-to-build-opencv3-on-xcode7
	
	note
	-	前のversionをinstallする方法も記載
	-	Xcodeの設定も記載
	-	動作確認OK
	-	header path は、ダブルクリックからrecursiveに設定すること
		複数header指定もここから"+"をクリックして追加
		→スペースで区切られているようだ
		
	-	exeの実行は Ctrl + C で中止
	
■XcodeでOpenCVを使えるようにする
	http://shirashinomiya.hatenablog.com/entry/2018/07/26/212524
	
■MacにOpenCV4をインストールする(C++)
	https://qiita.com/HoriThe3rd/items/2829463cd5bfe5cba03f

▪️Homebrew OpenCV 2.4.5（バージョンを指定してインストール）
	http://ruirui.jp/blog/2013/03/homebrewopencv-243.html
	http://ruirui.jp/blog/2013/10/homebrewopencv-245.html
	

■Homebrew で Python3, numpy, OpenCV3 を macOS 10.14 Mojave にインストール
	https://qiita.com/Atsuyuki_Adachi/items/6271c0b519fee5937605
	
■Xcode 12 で missing one or more architectures
	https://ykakinoki.hateblo.jp/entry/2020/09/19/053250
************************************************************/


/************************************************************
■Research : solution with openCV
	■cv::VideoCaptureAPIs
		https://docs.opencv.org/3.2.0/d4/d15/group__videoio__flags__base.html#ga023786be1ee68a9105bf2e48c700294d
	
	■OpenCVでオートフォーカスWebカメラのフォーカスを設定する（Python）
		https://qiita.com/fate_shelled/items/3951e10400a443508180
	
	■Disable Auto Focus in Video Input Library or OpenCV
		https://stackoverflow.com/questions/9191597/disable-auto-focus-in-video-input-library-or-opencv
	
	■画像とビデオの読み込みと書き込み
		http://opencv.jp/opencv-2svn/cpp/reading_and_writing_images_and_video.html#cv-videocapture-get
************************************************************/
#include <iostream>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/highgui.hpp>

/******************************
******************************/
int main(int argc, const char * argv[])
{
	/********************
	********************/
	cv::VideoCapture cap(1);
	
	printf("%d\n", cap.set(cv::CAP_PROP_SETTINGS, 1));
	printf("CAP_PROP_AUTOFOCUS    : %d\n", cap.set(cv::CAP_PROP_AUTOFOCUS, 0));
	printf("CAP_PROP_FRAME_WIDTH  : %d\n", cap.set(cv::CAP_PROP_FRAME_WIDTH, 1280));
	printf("CAP_PROP_FRAME_HEIGHT : %d\n", cap.set(cv::CAP_PROP_FRAME_HEIGHT, 720));
	printf("CAP_PROP_FPS          : %d\n", cap.set(cv::CAP_PROP_FPS, 60));
	printf("CAP_PROP_BRIGHTNESS   : %d\n", cap.set(cv::CAP_PROP_BRIGHTNESS, 200));
	printf("CAP_PROP_FOCUS        : %d\n", cap.set(cv::CAP_PROP_FOCUS, 100));
	
	printf("%d, %d, %d, %d, %d, %d\n", (int)cap.get(cv::CAP_PROP_AUTOFOCUS), (int)cap.get(cv::CAP_PROP_FRAME_WIDTH), (int)cap.get(cv::CAP_PROP_FRAME_HEIGHT), (int)cap.get(cv::CAP_PROP_FPS), (int)cap.get(cv::CAP_PROP_BRIGHTNESS), (int)cap.get(cv::CAP_PROP_FOCUS));
	fflush(stdout);
	
	/********************
	********************/
	if(!cap.isOpened()) return 0;
    for (;;){
        cv::Mat frame;
        cap.read(frame);
        if (frame.empty()) break; // end of video stream
        imshow("this is you, smile! :)", frame);
		
        if (cv::waitKey(10) == 27) break; // stop capturing by pressing ESC 
    }
	
	/********************
	********************/
    // the camera will be closed automatically upon exit
	// cap.close();
    return 0;
}


