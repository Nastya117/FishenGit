#include "logi.h"
#include "ui_logi.h"

Logi::Logi(class Client &clienter) :
   client(clienter), ui(new Ui::Logi)
{
    ui->setupUi(this);
    connect(ui->toolButton, &QToolButton::clicked, this, &Logi::cloosLe);
}

Logi::~Logi()
{
    delete ui;
}

void Logi::cloosLe()
{
    fong();
    close();
}
