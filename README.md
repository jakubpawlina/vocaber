# VOCABER
An app for learning vocabulary (and not only!)


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
