////include system in/out libraries
//#include <iostream>

////include ros libraries
//#include<ros/ros.h>

////include messege libraries
//#include <sensor_msgs/image_encodings.h>
//#include "geometry_msgs/Vector3.h"

////include opencv libraries
//#include <opencv2/opencv.hpp>

////include ros transport&bridge libraries
//#include <image_transport/image_transport.h>
//#include <cv_bridge/cv_bridge.h>

////include ros aruco libraries
//#include "aruco_lib/aruco.h"
//#include "aruco_lib/cvdrawingutils.h"
//#include "aruco_lib/marker.h"

//using namespace cv;
//using namespace std;
//using namespace aruco;

//#define THRESHOLD 80
//#define SCALE 2
///* ****CONST DEFINITION**** */
////
////      * ------------------->  x
////      |
////      |
////      |
////     \/ y
//// below are the positions of markers relative to home point


//ros::Publisher pub;

//double MKsize;
//Mat Rmtx;
//float posX, posY, posZ;
//float numOfMarkersDetected;
//float center_x,center_y;
//Mat pos_tmp;

//CameraParameters camParam;

//void imageCallback(const sensor_msgs::ImageConstPtr& msg);

//int main(int argc,char **argv)
//{
//    ros::init(argc, argv, "use_aruco_track");
//    ros::NodeHandle nh;

//    //read camera parameters
//    camParam.readFromXMLFile("/home/mylove/ws/src/vision_uav/ca150.yml");

//    cout<< "here is the 1st."<<endl;
//    image_transport::ImageTransport it(nh);
//    image_transport::Subscriber imgSub;

//    nh.param("MKsize", MKsize, double(27));

//    imgSub = it.subscribe("/uav_cam/image", 5, imageCallback);
//    pub = nh.advertise<geometry_msgs::Vector3>("duck_aruco_posi",200);

//    ros::spin();
//    return 0;
//}

//void imageCallback(const sensor_msgs::ImageConstPtr& msg)
//{
//    cout<< "get a Image."<<endl;
//    Mat Image;
//    geometry_msgs::Vector3 outMsg;

//    cv_bridge::CvImagePtr cv_ptr;
//    cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
//    Image = cv_ptr -> image;



//    MarkerDetector MDetector;
//    vector<Marker> Markers;

//    //read the input image
//    cv::Mat InImage;
//    InImage = Image;

//    //Ok, let's detect
//    MDetector.detect(InImage, Markers, camParam, MKsize);

//    //for each marker, draw info and its boundaries in the image
//    for (unsigned int i=0;i<Markers.size();i++)
//    {
//        cout<<Markers[i].Tvec<<endl;

//        Markers[i].draw(InImage,Scalar(0,255,255),2);
//        CvDrawingUtils::draw3dCube(InImage, Markers[i], camParam);
//    }

//    numOfMarkersDetected = Markers.size();

//    for(int i = 0; i < Markers.size(); i++)
//    {
//        Rodrigues(Markers[i].Rvec, Rmtx);
//        pos_tmp = -Rmtx.t()*Markers[i].Tvec;
//        posX = pos_tmp.at<float>(0,0);
//        posY = pos_tmp.at<float>(1,0);
//        posZ = pos_tmp.at<float>(2,0);
//        cout<< Markers[i].id << " posXYZ| "
//           <<posX<<" | "<<posY<<" | " << posZ << endl;

//        // Current recognize as only one aruco
//        outMsg.x = posX;
//        outMsg.y = posY;
//        outMsg.z = posZ;
//        // Add id in the outMsg[0]
//        //outMsg[0].x = outMsg[0].y = outMsg[0].z = Markers[i].id;

//        pub.publish(outMsg);

//        cout<<center_x<<" "<<center_y<<endl;
//    }

//    imshow("debug",InImage);

//    //wait for key to be pressed
//    waitKey(1);
//    cout<< "ALL done."<<endl<<endl;

//    waitKey(1);
//}
