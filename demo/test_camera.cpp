#include "realsense.h"
#include "memory"

using namespace std;

int main()
{
    std::unique_ptr<Realsense> realsense_cam = std::make_unique<Realsense>();
    InputDevSetup camera_setup;
    camera_setup.setDefault();
    realsense_cam->setupInputDevice(camera_setup);

    while(true)
    {
        ColourFrame frame;
        DepthFrame depth;
        realsense_cam->startStreaming();
        realsense_cam->getColourFrame(frame);
        realsense_cam->getDepthFrame(depth);

        frame.vis("camera_feed");
    }

}