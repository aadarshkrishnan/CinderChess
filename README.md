# Chess

A classic chess game that can be played turn by turn using C++.
![](https://imgur.com/PCVgr6R.gif)

## Dependencies

- Environment: CLion
- Cinder
- Cmake

## CLion

Download CLion from JetBrains https://www.jetbrains.com/clion/?gclsrc=aw.ds&&gclid=CjwKCAjwm7mEBhBsEiwA_of-TEu76KmMNIiCarzNdTgnruK2zlXYZgoUHACCJYlmhlee5TgndpJ2XxoCVpoQAvD_BwE

## Cinder

1. Download Cinder (v0.9.2) for your platform. Create a folder named Cinder and extract the downloaded item into it. We’ll call this folder ~/Cinder throughout the instructions (where ~ represents the higher level directories that contains Cinder folder)

2. https://libcinder.org/download
If your directory structure looks like ~/Cinder/cinder_0.9.2_vc2015, then, you should get rid of the outer folder and refer to the inner folder as ~/Cinder
Open the ~/Cinder folder in CLion and click the green build button. This will build libcinder. You only need to do this once per machine. This build might take a while.

3. Open ~/Cinder/samples/BasicApp in a NEW PROJECT WINDOW in CLion and click the run button. A window should pop up, and you should be able to draw a line in the window using your mouse.

    - If you are not able to click on the run button, it means the CMake project hasn’t loaded. Open the BasicApp.cpp file under the src/ directory. You should see a warning that says CMake project isn't loaded. Select CMakeLists.txt file. Click on Select CMakeLists.txt file and select the file at BasicApp/proj/cmake/CMakeLists.txt

    - MacOS users: It’s possible that you may come across a Permission denied error. In this case, try doing: Edit configurations -> Executable -> Select Other -> Find samples/BasicApp/proj/cmake/cmake-build-debug/Debug/BasicApp/BasicApp/Contents/MacOS/BasicApp, and then click run again.

- If you're using Ubuntu, you can follow the instructions: https://libcinder.org/docs/guides/cmake/cmake.html#command-line-options

## Cmake 
### Ubuntu

```console
$ sudo apt-get install gcc cmake libsdl2-dev
```

### MacOS

```console
$ brew install gcc cmake sdl2
```

## Controls

### Game
| Key                 | Action                   |
|---------------------|--------------------------|
| `Mouse Click`               | Moves piece from original click to new click location if move is valid.             |


## Chess Rules

https://www.chess.com/learn-how-to-play-chess


## Created By

Aadarsh Krishnan