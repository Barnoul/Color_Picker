#include <QPalette>
#include "colorselect.h"
#include "ui_colorselect.h"
#include <string>
#include <QString>

std::string tohex(int x) {
    if (x == 10) return "A";
    else if (x == 11) return "B";
    else if (x == 12) return "C";
    else if (x == 13) return "D";
    else if (x == 14) return "E";
    else if (x == 15) return "F";
    else return std::to_string(x);
}

ColorSelect::ColorSelect(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ColorSelect)
{
    ui->setupUi(this);
    connect(ui->redSlider, SIGNAL(valueChanged(int)), SLOT(onColorChanged()));
    connect(ui->greenSlider, SIGNAL(valueChanged(int)), SLOT(onColorChanged()));
    connect(ui->blueSlider, SIGNAL(valueChanged(int)), SLOT(onColorChanged()));
    connect(ui->opacitySlider, SIGNAL(valueChanged(int)), SLOT(onColorChanged()));
    onColorChanged();
}

ColorSelect::~ColorSelect()
{
    delete ui;
}

void ColorSelect::onColorChanged() {
    m_color.setRgb(ui->redSlider->value(), ui->greenSlider->value(),
    ui->blueSlider->value(), ui->opacitySlider->value());
    QPalette pal = ui->displayWidget->palette();
    pal.setColor(QPalette::Window, m_color);
    ui->displayWidget->setPalette(pal);
    emit colorChanged(m_color);
    std::string r1 = tohex(ui->redSlider->value() / 16), r2 = tohex(ui->redSlider->value() % 16),
    g1 = tohex(ui->greenSlider->value() / 16), g2 = tohex(ui->greenSlider->value() % 16),
    b1 = tohex(ui->blueSlider->value() / 16), b2 = tohex(ui->blueSlider->value() % 16);
    QString hexcolor = QString::fromStdString("#"+r1+r2+g1+g2+b1+b2);
    ui->label_5->setText(hexcolor);
}


