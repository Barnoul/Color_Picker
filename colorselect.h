#ifndef COLORSELECT_H
#define COLORSELECT_H

#include <QWidget>
#include <QColor>

namespace Ui {
class ColorSelect;
}

class ColorSelect : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ color NOTIFY colorChanged)

public:
    explicit ColorSelect(QWidget *parent = nullptr);
    ~ColorSelect();

    QColor color() const {
        return m_color;
    }

signals:
    void colorChanged(QColor arg);

private slots:
    void onColorChanged();

private:
    Ui::ColorSelect *ui;
    QColor m_color;
};

#endif // COLORSELECT_H
