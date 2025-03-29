# Realsense-CPP
This is a realsense library which can be used to access realsense cameras (D435 and D435i) and use it with opencv

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/ayushkumar8340/Realsense-CPP.git
   ```
2. Building instructions:

    In this project we are using a docker environment for setting up things. The code is on local machine and we create a docker environment to run the code. The current directory is mounted live onto the docker environment so we can make changes and build the code in real-time.
    ```bash
    cd Realsense-CPP/
    sudo chmod +x build_docker.sh
    sudo chmod +x run_docker.sh
    ./buid_docker.sh
    ./run_docker.sh realsense
    mkdir build
    cd build
    cmake ..
    make -j4
    ```
## Running Demo Scripts

1. This is a demo for getting real-time camera feed and showing it on the screen using opencv window.

```bash
./demo/realsense_cam_feed
```
2. This demo is for getting the depth of a particular point in the image frame.
```bash 
./demo/realsense_depth
```

### Steps for integration of realsense c++ lib with a code:
1. Adding the library to your code.
    1. Copy the **Realsense-CPP** folder to the target project folder.
    2. In the CMakeLists.txt of your project add this line:
        ```bash
        add_subdirectory(Realsense-CPP)
        ```
    3. The name of the library is realsense_lib. To link to your code add the following line to your CMakeLists.txt:
        ```bash 
        target_link_library(<your-executable-name> PUBLIC realsense_lib)
        ```
    4. Build the project
2. APIs / Usage instructions:
    1. Include **"realsense.h"**
    2. Make an object of **Realsense** class.
    3. **InputDevConfig** is a structure which holds all the configurations for the camera. It has a function **setDefault()** which sets the default value for the variables. 
    4. Setup the Realsense class by calling **setupInputDevice()** which initializes all the required sensors.
    5. To enable IMU of the camera change the **#define D435i** to **false** in **realsense.h**
    6. In while loop run **startStreaming()**.
    7. Call function like **getColourFrame()**, **getDepthFrame()** and **getIMUData()** to get various data from the camera.
    8. Various Data types are defined for colour frame , depth frame and imu frame check the frames.h file for more info