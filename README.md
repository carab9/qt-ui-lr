# qt-ui-lr

Qt is a cross-platform application and UI framework. This project reads co2 data in a CSV file (co2.csv), averages the monthly co2 values to annual averages and then runs a linear regression algorithm on annual co2 values vs. years to calculate the slope and intercept of the linear regression line. The program then uses Qt UI to plot a scatter plot of annual co2 data and the linear regression line. Qt components are in UI.h, UI.cpp and main.cpp.


## Architecture

The main program uses a FileIO class object to read an encrypted binary file and store the data in a DataBase class object. It then uses a Run_LR class object to run the linear regression algorithm on the processed annual co2 data to get the slope and intercept of the linear regression line. The program then uses UI class object which uses Qt window and QtCharts (QtCharts: QChartView, QLineSeries, QScatterSeries, QValueAxis) to plot a scatter plot and the regression line of annual co2 data.

## Requirements

C++ and C++ libraries: iostream, fstream, vector, map, algorithm, numeric, regex, smart pointers, memory
Qt and Qt Creator, QtCharts: QChartView, QLineSeries, QScatterSeries, QValueAxis

## Technical Skills

QtWidgets, QApplication, QMainWindow and QtCharts for UI display, regular expressions to parse co2.csv (regex), smart pointers, STL containers such as vector, and map, a few functions in STL algorithms, linear regression algorithm.

## Results

![image](https://github.com/carab9/qt_ui_lr/blob/main/qt_ui_lr.png?raw=true)
