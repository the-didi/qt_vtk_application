#ifndef HARDWARE_INFOMATION_H
#define HARDWARE_INFOMATION_H

#include <QWidget>
#include <QColor>
class hardware_infomation: public QWidget
{
    Q_OBJECT
private:
    QColor mColorBack=Qt::white;
    QColor mColorBorder=Qt::black;
    QColor mColorPower=Qt::green;
    QColor mColorWarning=Qt::red;
    int mPowerLeve=50;
    int mWarning=20;
protected:
    void  paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
public:
    explicit hardware_infomation(QWidget *parent = 0);
    int powerLeve() const;
    void setPowerLeve(int newPowerLeve);
};

#endif // HARDWARE_INFOMATION_H
