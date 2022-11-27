#ifndef BARRAPROGRESSO_H
#define BARRAPROGRESSO_H

#include <QtWidgets>

class barraProgresso : public QWidget
{
    Q_OBJECT
public:
    explicit barraProgresso(int min_value, int max_value, QWidget *parent = nullptr);

signals:

public slots:

private:
    int _valueMin;
    int _valueMax;
    QProgressBar barraProg;
    QHBoxLayout _frameBar;
};

#endif // BARRAPROGRESSO_H
