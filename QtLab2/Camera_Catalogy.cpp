#include "Camera_Catalogy.h"
#include <QtWidgets/QApplication>
#include "SaveDatah.h"
#include <QtCore>
#include <QVector>
#include <QDebug>
//#include "Info_Storage.h"

Camera_Catalogy::Camera_Catalogy(QWidget *parent)
    : QMainWindow(parent)
{
    
    ui.setupUi(this);
    
    //Подключение кнопок(2 лаба)
    /*
    connect(ui.pushButton_SaveInfo1, SIGNAL(clicked()), this, SLOT(slot_save1()));
    connect(ui.pushButton_SaveInfo2, SIGNAL(clicked()), this, SLOT(slot_save2()));
    connect(ui.pushButton_ShowInfo1, SIGNAL(clicked()), this, SLOT(slot_show1()));
    connect(ui.pushButton_ShowInfo2, SIGNAL(clicked()), this, SLOT(slot_show2()));
    */

    

    //Подключение кнопок редактирования
    connect(ui.pushButton_add, SIGNAL(clicked()), this, SLOT(slot_Add_data()));
    connect(ui.pushButton_add10, SIGNAL(clicked()), this, SLOT(slot_Add_data10()));
    connect(ui.pushButton_save, SIGNAL(clicked()), this, SLOT(slot_Save_data()));
    connect(ui.pushButton_delete, SIGNAL(clicked()), this, SLOT(slot_Delete_data()));
    //Подключение чекбоксов
    connect(ui.checkBox_LensOptions, SIGNAL(stateChanged(int)), this, SLOT(slot_LensOptions()));
    connect(ui.checkBox_IsDigital, SIGNAL(stateChanged(int)), this, SLOT(slot_IsDigital()));
    //Подключение выпадающих списков
    connect(ui.comboBox_Category, SIGNAL(activated(int)), this, SLOT(slot_ChooseCategory()));
    connect(ui.comboBox_Producer, SIGNAL(activated(int)), this, SLOT(slot_ChooseProducer()));
    //Подключения браузера
    connect(ui.tableWidget, SIGNAL(cellClicked(int, int)), this, SLOT(slot_TableInfo()));
    ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //запрет на редактирование ячеек
    ui.tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);

    //Подключение валидатора для первой строки ввода
    QRegExp regExp("[A-Za-z][A-Za-z0-9]+");
    ui.lineEdit_ModelName->setValidator(new QRegExpValidator(regExp));
    ui.lineEdit_Dimensions->setInputMask("00-00-00");

    
    //Параметры по умолчанию (2 лаба)
    /*
    
    ui.lineEdit_ModelName->setText("No more then 30 symbols");
    ui.comboBox_Category->setCurrentIndex(0);
    ui.comboBox_Producer->setCurrentIndex(0);
    ui.doubleSpinBox_CamMatrix->setValue(10.0); //при запуске программы этот пункт не будет видимым, так как камера по умолчанию не цифровая
    ui.lineEdit_Dimensions->setInputMask("00-00-00");
    ui.spinBox_Weight->setValue(30);
    ui.spinBox_Price->setValue(50000);
    //ui.dateEdit->setDate(QDate(2017, 12, 1));
    ui.dateEdit->setDate(QDate::currentDate());
    //Параметры видимости
    ui.checkBox_IsDigital->setChecked(false); //По умолчанию камера будет не цифровой
    ui.checkBox_LensOptions->setChecked(false);
    */
    //Параметры по умолчанию
    ui.comboBox_Category->setCurrentIndex(0);
    ui.comboBox_Producer->setCurrentIndex(0);
    
    ui.lineEdit_Dimensions->setText("00-00-00");
    ui.doubleSpinBox_CamMatrix->setValue(2.0);
    ui.spinBox_Weight->setValue(100);
    ui.spinBox_Price->setValue(1000);
    ui.dateEdit->setDate(QDate::currentDate());

    //Делаем левую сторону неактивной
    ui.lineEdit_ModelName->setEnabled(false);
    ui.comboBox_Category->setEnabled(false);
    ui.comboBox_Producer->setEnabled(false);
    ui.lineEdit_Dimensions->setEnabled(false);
    ui.doubleSpinBox_CamMatrix->setEnabled(false);
    ui.spinBox_Weight->setEnabled(false);
    ui.spinBox_Price->setEnabled(false);
    ui.dateEdit->setEnabled(false);
    ui.checkBox_IsDigital->setEnabled(false);
    ui.checkBox_LensOptions->setEnabled(false);


    ui.pushButton_delete->setEnabled(false);
    ui.pushButton_save->setEnabled(false);
    
   

    //Условия видимости

    //Условия видимости для чекбокса "Возможности смена объектива"
    if (ui.comboBox_Category->currentIndex() == 2) {
        ui.checkBox_LensOptions->setEnabled(true);
    }
    else {
        ui.checkBox_LensOptions->setEnabled(false);
    }
    //Условие видимости для даблспинбокса
    if (ui.checkBox_IsDigital->isChecked()) {
        ui.doubleSpinBox_CamMatrix->setEnabled(true);
        ui.label_4->setEnabled(true);
    }
    else {
        ui.doubleSpinBox_CamMatrix->setEnabled(false);
        ui.label_4->setEnabled(false);
    }
   
    Items.resize(sizeVector);

    //Зафиксирования фокуса таблицы
    ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    
    
    
    //Sort();
    
}

//save1
/*
void Camera_Catalogy::slot_save1()
{
    //Считывание текущих записей
    QString Current_Module = ui.lineEdit_ModelName->text();
    int Current_Category = ui.comboBox_Category->currentIndex();
    int Current_Producer = ui.comboBox_Producer->currentIndex();
    double Current_PX = ui.doubleSpinBox_CamMatrix->value();
    QString Current_Dimension = ui.lineEdit_Dimensions->text();
    int Current_Weight = ui.spinBox_Weight->value();
    int Current_Price = ui.spinBox_Price->value();
    QDate Current_Date = ui.dateEdit->date();
    bool Current_IsD = ui.checkBox_IsDigital->checkState();
    bool Current_LensOP = ui.checkBox_LensOptions->checkState();
    
    //Присваивание новых значений в первый слот
    Items[0].modul = Current_Module;
    Items[0].category_value = Current_Category;
    Items[0].producer_value = Current_Producer;
    Items[0].matrix_px = Current_PX;
    Items[0].dimension = Current_Dimension;
    Items[0].weight = Current_Weight;
    Items[0].price = Current_Price;
    Items[0].date_release = Current_Date;
    Items[0].IsDigital = Current_IsD;
    Items[0].LensOption = Current_LensOP;


}
*/
//save2
/*
void Camera_Catalogy::slot_save2()
{
    //Считывание текущих записей
    QString Current_Module = ui.lineEdit_ModelName->text();
    int Current_Category = ui.comboBox_Category->currentIndex();
    int Current_Producer = ui.comboBox_Producer->currentIndex();
    double Current_PX = ui.doubleSpinBox_CamMatrix->value();
    QString Current_Dimension = ui.lineEdit_Dimensions->text();
    int Current_Weight = ui.spinBox_Weight->value();
    int Current_Price = ui.spinBox_Price->value();
    QDate Current_Date = ui.dateEdit->date();
    bool Current_IsD = ui.checkBox_IsDigital->checkState();
    bool Current_LensOP = ui.checkBox_LensOptions->checkState();

    //Присваивание новых значений во второй слот
    Items[1].modul = Current_Module;
    Items[1].category_value = Current_Category;
    Items[1].producer_value = Current_Producer;
    Items[1].matrix_px = Current_PX;
    Items[1].dimension = Current_Dimension;
    Items[1].weight = Current_Weight;
    Items[1].price = Current_Price;
    Items[1].date_release = Current_Date;
    Items[1].IsDigital = Current_IsD;
    Items[1].LensOption = Current_LensOP;


}
*/

//show1
/*
void Camera_Catalogy::slot_show1()
{
    //ui.lineEdit_ModelName->setClearButtonEnabled(true);
    

    ui.lineEdit_ModelName->clear();
    ui.lineEdit_Dimensions->clear();

    ui.lineEdit_ModelName->setText(QString(Items[0].modul));
    ui.comboBox_Category->setCurrentIndex(Items[0].category_value);
    ui.comboBox_Producer->setCurrentIndex(Items[0].producer_value);
    ui.doubleSpinBox_CamMatrix->setValue(Items[0].matrix_px);
    ui.lineEdit_Dimensions->setText(QString(Items[0].dimension));
    ui.spinBox_Weight->setValue(Items[0].weight);
    ui.spinBox_Price->setValue(Items[0].price);
    ui.dateEdit->setDate(Items[0].date_release);
    ui.checkBox_IsDigital->setChecked(Items[0].IsDigital);
    ui.checkBox_LensOptions->setChecked(Items[0].LensOption);

    //Условия видимости для чекбокса "Возможности смена объектива"
    int index = Items[0].category_value;

    if (index == 2) {
        ui.checkBox_LensOptions->setEnabled(true);
    }
    else {
        ui.checkBox_LensOptions->setEnabled(false);
    }

    //Условие видимости для даблспинбокса
    if (ui.checkBox_IsDigital->isChecked()) {
        ui.doubleSpinBox_CamMatrix->setEnabled(true);
        ui.label_4->setEnabled(true);
    }
    else {
        ui.doubleSpinBox_CamMatrix->setEnabled(false);
        ui.label_4->setEnabled(false);
    }
    

}
*/
//show2
/*
void Camera_Catalogy::slot_show2()
{
    ui.lineEdit_ModelName->clear();
    ui.lineEdit_Dimensions->clear();

    ui.lineEdit_ModelName->setText(QString(Items[1].modul));
    ui.comboBox_Category->setCurrentIndex(Items[1].category_value);
    ui.comboBox_Producer->setCurrentIndex(Items[1].producer_value);
    ui.doubleSpinBox_CamMatrix->setValue(Items[1].matrix_px);
    ui.lineEdit_Dimensions->setText(QString(Items[1].dimension));
    ui.spinBox_Weight->setValue(Items[1].weight);
    ui.spinBox_Price->setValue(Items[1].price);
    ui.dateEdit->setDate(Items[1].date_release);
    ui.checkBox_IsDigital->setChecked(Items[1].IsDigital);
    ui.checkBox_LensOptions->setChecked(Items[1].LensOption);

    //Условия видимости для чекбокса "Возможности смена объектива"
    int index = Items[1].category_value;

    if (index == 2) {
        ui.checkBox_LensOptions->setEnabled(true);
    }
    else {
        ui.checkBox_LensOptions->setEnabled(false);
    }

    //Условие видимости для даблспинбокса
    if (ui.checkBox_IsDigital->isChecked()) {
        ui.doubleSpinBox_CamMatrix->setEnabled(true);
        ui.label_4->setEnabled(true);
    }
    else {
        ui.doubleSpinBox_CamMatrix->setEnabled(false);
        ui.label_4->setEnabled(false);
    }
}
*/

void Camera_Catalogy::slot_LensOptions()
{
    //Оно для галочки существует
}

void Camera_Catalogy::slot_IsDigital()
{
    if (ui.checkBox_IsDigital->isChecked()) {
        ui.doubleSpinBox_CamMatrix->setEnabled(true);
        ui.label_4->setEnabled(true);
    }
    else {
        ui.doubleSpinBox_CamMatrix->setEnabled(false);
        ui.label_4->setEnabled(false);
    }
}

void Camera_Catalogy::slot_ChooseCategory()
{
    //Условия видимости для чекбокса "Возможности смена объектива"

    int index = ui.comboBox_Category->currentIndex();

    if (index == 2) {
        ui.checkBox_LensOptions->setEnabled(true);
    }
    else {
        ui.checkBox_LensOptions->setEnabled(false);
    }
}

void Camera_Catalogy::slot_ChooseProducer()
{
    //Оно тоже для галочки существует
}

void Camera_Catalogy::slot_Add_data()
{
    //Очищаем данные правой части
    ui.lineEdit_ModelName->clear();
    ui.lineEdit_Dimensions->clear();

    ui.comboBox_Category->setCurrentIndex(0);
    ui.comboBox_Producer->setCurrentIndex(0);

    ui.lineEdit_Dimensions->setText("00-00-00");
    ui.doubleSpinBox_CamMatrix->setValue(2.0);
    ui.spinBox_Weight->setValue(100);
    ui.spinBox_Price->setValue(1000);
    ui.dateEdit->setDate(QDate::currentDate());

    //Делаем правой сторону активной
    ui.lineEdit_ModelName->setEnabled(true);
    ui.comboBox_Category->setEnabled(true);
    ui.comboBox_Producer->setEnabled(true);
    ui.lineEdit_Dimensions->setEnabled(true);
    ui.spinBox_Weight->setEnabled(true);
    ui.spinBox_Price->setEnabled(true);
    ui.dateEdit->setEnabled(true);
    ui.checkBox_IsDigital->setEnabled(true);

    sizeVector = sizeVector + 1;
    int pos = ui.tableWidget->rowCount();
    ui.tableWidget->insertRow(pos); // создаем строку
    QTableWidgetItem* item;
    item = new QTableWidgetItem();  // создаем item
    ui.tableWidget->setItem(0, 0, item);
    ui.tableWidget->setCurrentCell(pos, 0);

    Items.append(Base()); //Добавляем пустой элемент
    Items.resize(sizeVector); //Изменяем размер массива
    

    Sort();

    ui.pushButton_save->setEnabled(true);
    ui.pushButton_delete->setEnabled(true);
    ui.pushButton_add10->setEnabled(false);
}

void Camera_Catalogy::slot_Add_data10()
{
    //Делаем правой сторону активной
    ui.lineEdit_ModelName->setEnabled(true);
    ui.comboBox_Category->setEnabled(true);
    ui.comboBox_Producer->setEnabled(true);
    ui.lineEdit_Dimensions->setEnabled(true);
    ui.spinBox_Weight->setEnabled(true);
    ui.spinBox_Price->setEnabled(true);
    ui.dateEdit->setEnabled(true);
    ui.checkBox_IsDigital->setEnabled(true);

    sizeVector = sizeVector + 10;
    ui.pushButton_add10->setEnabled(false);

    for (int i = 0; i < sizeVector; i++)
    {
        int pos = ui.tableWidget->rowCount();
        ui.tableWidget->insertRow(pos); // создаем строку
        QTableWidgetItem* item;
        item = new QTableWidgetItem();  // создаем item
        ui.tableWidget->setItem(0, 0, item);
        ui.tableWidget->setCurrentCell(pos, 0);
        Items.append(Base());
    }

    Items.resize(sizeVector);

    //Сведения о первом фотоапарате
    Items[0].modul = "KKLg";
    Items[0].category_value = 1;
    Items[0].producer_value = 3;
    Items[0].matrix_px = 10.5;
    Items[0].dimension = "30-30-30";
    Items[0].weight = 300;
    Items[0].price = 15000;
    Items[0].date_release = QDate(2012, 5, 17);
    Items[0].IsDigital = false;
    Items[0].LensOption = false;

    //Сведения о втором фотоапарате
    Items[1].modul = "Jlksg";
    Items[1].category_value = 2;
    Items[1].producer_value = 4;
    Items[1].matrix_px = 15.8;
    Items[1].dimension = "50-20-30";
    Items[1].weight = 300;
    Items[1].price = 5000;
    Items[1].date_release = QDate(2015, 3, 27);
    Items[1].IsDigital = true;
    Items[1].LensOption = true;

    Items[2].modul = "Hjaoras";
    Items[2].category_value = 2;
    Items[2].producer_value = 4;
    Items[2].matrix_px = 12.5;
    Items[2].dimension = "50-60-30";
    Items[2].weight = 500;
    Items[2].price = 14000;
    Items[2].date_release = QDate(2015, 3, 27);
    Items[2].IsDigital = true;
    Items[2].LensOption = true;

    Items[3].modul = "Lmfsed";
    Items[3].category_value = 1;
    Items[3].producer_value = 3;
    Items[3].matrix_px = 17.4;
    Items[3].dimension = "50-20-30";
    Items[3].weight = 300;
    Items[3].price = 5000;
    Items[3].date_release = QDate(2015, 3, 27);
    Items[3].IsDigital = true;
    Items[3].LensOption = false;

    Items[4].modul = "JMLasf";
    Items[4].category_value = 0;
    Items[4].producer_value = 2;
    Items[4].matrix_px = 13;
    Items[4].dimension = "20-20-30";
    Items[4].weight = 5300;
    Items[4].price = 75000;
    Items[4].date_release = QDate(2015, 3, 27);
    Items[4].IsDigital = true;
    Items[4].LensOption = false;

    Items[5].modul = "Aiven";
    Items[5].category_value = 1;
    Items[5].producer_value = 1;
    Items[5].matrix_px = 10;
    Items[5].dimension = "40-20-30";
    Items[5].weight = 300;
    Items[5].price = 8000;
    Items[5].date_release = QDate(2015, 3, 27);
    Items[5].IsDigital = true;
    Items[5].LensOption = false;

    Items[6].modul = "Wor";
    Items[6].category_value = 2;
    Items[6].producer_value = 1;
    Items[6].matrix_px = 11.2;
    Items[6].dimension = "50-20-30";
    Items[6].weight = 1300;
    Items[6].price = 67000;
    Items[6].date_release = QDate(2015, 3, 27);
    Items[6].IsDigital = true;
    Items[6].LensOption = false;

    Items[7].modul = "Mfdd";
    Items[7].category_value = 0;
    Items[7].producer_value = 2;
    Items[7].matrix_px = 14.7;
    Items[7].dimension = "10-20-30";
    Items[7].weight = 5000;
    Items[7].price = 89000;
    Items[7].date_release = QDate(2015, 3, 27);
    Items[7].IsDigital = true;
    Items[7].LensOption = false;

    Items[8].modul = "nifoef";
    Items[8].category_value = 1;
    Items[8].producer_value = 3;
    Items[8].matrix_px = 18.4;
    Items[8].dimension = "50-20-30";
    Items[8].weight = 4000;
    Items[8].price = 75000;
    Items[8].date_release = QDate(2015, 3, 27);
    Items[8].IsDigital = true;
    Items[8].LensOption = false;

    Items[9].modul = "Hehehehe";
    Items[9].category_value = 2;
    Items[9].producer_value = 1;
    Items[9].matrix_px = 19.5;
    Items[9].dimension = "50-20-30";
    Items[9].weight = 5300;
    Items[9].price = 67000;
    Items[9].date_release = QDate(2015, 3, 27);
    Items[9].IsDigital = true;
    Items[9].LensOption = false;

    Sort();

    //Внесение данных в таблицу
    QString Table_Price;
    for (int i = 0; i < sizeVector; i++)
    {
        QString Table_Name = Items[i].modul;
        Table_Price = QString::number(Items[i].price);

        ui.tableWidget->setItem(i, 0, new QTableWidgetItem(Table_Name));
        ui.tableWidget->setItem(i, 1, new QTableWidgetItem(Table_Price));
    }

    ui.tableWidget->setCurrentCell(0, 0);


    ui.pushButton_save->setEnabled(true);
    ui.pushButton_delete->setEnabled(true);
}

void Camera_Catalogy::slot_Save_data()
{
    int k = ui.tableWidget->currentRow();

    Items[k].modul = ui.lineEdit_ModelName->text();
    Items[k].category_value = ui.comboBox_Category->currentIndex();
    Items[k].producer_value = ui.comboBox_Producer->currentIndex();
    Items[k].matrix_px = ui.doubleSpinBox_CamMatrix->value();
    Items[k].dimension = ui.lineEdit_Dimensions->text();
    Items[k].weight = ui.spinBox_Weight->value();
    Items[k].price = ui.spinBox_Price->value();
    Items[k].date_release = ui.dateEdit->date();
    Items[k].IsDigital = ui.checkBox_IsDigital->checkState();
    Items[k].LensOption = ui.checkBox_LensOptions->checkState();

    int n = ui.tableWidget->currentRow();
    int p = ui.tableWidget->rowCount();
    ui.tableWidget->clearContents();

    QVector <Base> dop;
    dop.append(Items[n]);

    Sort();

    //Внесение данных в таблицу
    QString Table_Price;
    for (int i = 0; i < p; i++)
    {
        QString Table_Name = Items[i].modul;
        Table_Price = QString::number(Items[i].price);

        ui.tableWidget->setItem(i, 0, new QTableWidgetItem(Table_Name));
        ui.tableWidget->setItem(i, 1, new QTableWidgetItem(Table_Price));
    }

    for (int i = 0; i < p; i++) {
        if (dop[0].modul == Items[i].modul) {
            if (dop[0].category_value == Items[i].category_value) {
                if (dop[0].producer_value == Items[i].producer_value) {
                    if (dop[0].matrix_px == Items[i].matrix_px) {
                        if (dop[0].dimension == Items[i].dimension) {
                            if (dop[0].date_release == Items[i].date_release) {
                                if (dop[0].IsDigital == Items[i].IsDigital) {
                                    if (dop[0].LensOption == Items[i].LensOption) {
                                        ui.tableWidget->setCurrentCell(i, 0);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    //ui.pushButton_delete->setEnabled(true);
}

void Camera_Catalogy::slot_Delete_data()
{
    int cure = ui.tableWidget->currentRow();
    ui.tableWidget->removeRow(cure);
    Items.remove(cure);
    int k = ui.tableWidget->rowCount();
    if (cure == k)
    {
        ui.tableWidget->setCurrentCell(0, 0);
        slot_TableInfo();
    }
    else
    {
        ui.tableWidget->setCurrentCell(cure, 0);
        slot_TableInfo();
    }

    sizeVector = sizeVector - 1;
    Items.resize(sizeVector);

    Sort();

    int prov = ui.tableWidget->rowCount();

    if (prov == 0) {

        //Очищаем данные правой части
        ui.lineEdit_ModelName->clear();
        ui.lineEdit_Dimensions->clear();

        ui.comboBox_Category->setCurrentIndex(0);
        ui.comboBox_Producer->setCurrentIndex(0);

        ui.lineEdit_Dimensions->setText("00-00-00");
        ui.doubleSpinBox_CamMatrix->setValue(2.0);
        ui.spinBox_Weight->setValue(100);
        ui.spinBox_Price->setValue(1000);
        ui.dateEdit->setDate(QDate::currentDate());

        //Делаем правую сторону неактивной
        ui.lineEdit_ModelName->setEnabled(false);
        ui.comboBox_Category->setEnabled(false);
        ui.comboBox_Producer->setEnabled(false);
        ui.lineEdit_Dimensions->setEnabled(false);

        ui.doubleSpinBox_CamMatrix->setEnabled(false);
        ui.label_4->setEnabled(false);

        ui.spinBox_Weight->setEnabled(false);
        ui.spinBox_Price->setEnabled(false);
        ui.dateEdit->setEnabled(false);
        ui.checkBox_IsDigital->setEnabled(false);
        ui.checkBox_LensOptions->setEnabled(false);

        ui.pushButton_delete->setEnabled(false);
        ui.pushButton_save->setEnabled(false);
        ui.pushButton_add10->setEnabled(true);
    }
}

void Camera_Catalogy::slot_TableInfo()
{
    int k = ui.tableWidget->currentRow();

    if (k == -1)
    {
        return;
    }
    else {
        ui.lineEdit_ModelName->clear();
        ui.lineEdit_Dimensions->clear();

        ui.lineEdit_ModelName->setText(QString(Items[k].modul));
        ui.comboBox_Category->setCurrentIndex(Items[k].category_value);
        ui.comboBox_Producer->setCurrentIndex(Items[k].producer_value);
        ui.doubleSpinBox_CamMatrix->setValue(Items[k].matrix_px);
        ui.lineEdit_Dimensions->setText(QString(Items[k].dimension));
        ui.spinBox_Weight->setValue(Items[k].weight);
        ui.spinBox_Price->setValue(Items[k].price);
        ui.dateEdit->setDate(Items[k].date_release);
        ui.checkBox_IsDigital->setChecked(Items[k].IsDigital);
        ui.checkBox_LensOptions->setChecked(Items[k].LensOption);

        //Условия видимости для чекбокса "Возможности смена объектива"
        int index = Items[k].category_value;

        if (index == 2) {
            ui.checkBox_LensOptions->setEnabled(true);
        }
        else {
            ui.checkBox_LensOptions->setEnabled(false);
        }

        //Условие видимости для даблспинбокса
        if (ui.checkBox_IsDigital->isChecked()) {
            ui.doubleSpinBox_CamMatrix->setEnabled(true);
            ui.label_4->setEnabled(true);
        }
        else {
            ui.doubleSpinBox_CamMatrix->setEnabled(false);
            ui.label_4->setEnabled(false);
        }
    }
}


