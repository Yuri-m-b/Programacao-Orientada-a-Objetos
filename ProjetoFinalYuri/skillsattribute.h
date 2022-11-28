#ifndef SKILLSATTRIBUTE_H
#define SKILLSATTRIBUTE_H

#include <QtWidgets>

class skillsAttribute : public QWidget
{
    Q_OBJECT
public:
    explicit skillsAttribute(QString name, int initial_value, bool progressBar = false, int max = 100, int min = 0, QWidget *parent = nullptr);

signals:

public slots:
    void updateValue(int new_value);


private:
    QLabel _name;
    int    _value;
    QHBoxLayout _frameH;
    QVBoxLayout _frameV;
    QProgressBar _progressBar;
    QLabel _dValue;

};

#endif // SKILLSATTRIBUTE_H
