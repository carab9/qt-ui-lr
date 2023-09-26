#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QScatterSeries>
#include <QtCharts/QValueAxis>

QT_USE_NAMESPACE

#include <iostream>
#include <vector>
#include <numeric>
#include "UI.h"
using namespace std;

void UI::display_LR(double intercept, double slope, vector<pair<int, double>> db) {
    QScatterSeries *series = new QScatterSeries();
    series->setName("scatter");
    series->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    series->setMarkerSize(10.0);

    QLineSeries *series2 = new QLineSeries();
    series2->setName("scatter2");
    series2->setMarkerSize(10.0);

    int size = db.size();
    if (size == 0) {
        return;
    }

    series2->append(db[0].first, db[0].first * slope + intercept);
    series2->append(db[size - 1].first, db[size - 1].first * slope + intercept);

    for (size_t i = 0; i < db.size(); i++) {
        series->append(db[i].first, db[i].second);
    }

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->addSeries(series2);
    //chart->createDefaultAxes();
    chart->setTitle("CO2/Year Linear Regression");

    pair<int, double> min_x = (*min_element(db.begin(), db.end(), [](const pair<int, double>& a, const pair<int, double>& b){
        return a.first < b.first;
    }));
    pair<int, double> max_x = (*max_element(db.begin(), db.end(), [](const pair<int, double>& a, const pair<int, double>& b){
        return a.first < b.first;
    }));
    cout << "Min_x: " << min_x.first << endl;
    cout << "Max_x: " << max_x.first << endl;

    pair<int, double> min_y = (*min_element(db.begin(), db.end(), [](const pair<int, double>& a, const pair<int, double>& b){
        return a.second < b.second;
    }));
    pair<int, double> max_y = (*max_element(db.begin(), db.end(), [](const pair<int, double>& a, const pair<int, double>& b){
        return a.second < b.second;
    }));

    cout << "Min_y: " << min_y.second << endl;
    cout << "Max_y: " << max_y.second << endl;

    QValueAxis *axisX = new QValueAxis;
    axisX->setRange(min_x.first, max_x.first);
    axisX->setTickCount(7);
    axisX->setLabelFormat("%d");

    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(min_y.second, min_y.second);
    axisY->setTickCount(7);
    axisY->setLabelFormat("%.2f");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->chart()->addAxis(axisX, Qt::AlignBottom);
    chartView->chart()->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisX);
    series->attachAxis(axisY);
    series2->attachAxis(axisX);
    series2->attachAxis(axisY);

    window.setWindowTitle("Qt");
    window.setCentralWidget(chartView);
    window.resize(400, 300);
    window.show();
}
