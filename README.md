# VOCABER
![C++](https://img.shields.io/badge/-C%2B%2B-black?style=flat-square&logo=C%2B%2B&logoColor=white) ![wxWidgets](https://img.shields.io/badge/-wxWidgets-black?style=flat-square&logo=&logoColor=white) ![nlohmann/json](https://img.shields.io/badge/-nlohmann/json-black?style=flat-square&logo=JSON&logoColor=white) ![CMake](https://img.shields.io/badge/-CMake-black?style=flat-square&logo=CMake&logoColor=white)

<div align="center">
    <img width="300" height="100" src="doc/assets/vocaber_logo.png" alt="Vocaber Logo">

_An app for learning vocabulary (and not only!)_
</div>

## About

Vocaber is an application that makes learning new vocabulary or terms easier. It makes revising material feel more like a game rather than a cramming.

The application is testing user on vocabulary (or definitions, for example), using a provided data file.

_Remark: appliction is under development and more testing tools are likely to appear in the future._

## Requirements
- [wxWidgets](https://www.wxwidgets.org/) installed and `<wxWidgets directory path>` set for cmake.

## Build and run
```shell
mkdir build_dir
cd build_dir
cmake -DwxWidgets_ROOT_DIR=<wxWidgets directory path> ..
make
./vocaber
```
Make sure to replace `<wxWidgets directory path>` with actual path to your wxWidgets root directory (eg. `/home/user/Libraries/wxWidgets-3.2.2.1`).
