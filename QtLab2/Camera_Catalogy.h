#pragma once

//#define CAMERACATALOGY_H
//#ifndef CAMERACATALOGY_H


#include <QtWidgets/QMainWindow>
#include "ui_Camera_Catalogy.h"
#include <QMainWindow>
#include "SaveDatah.h"
#include <QtCore>
#include <QVector>
#include <QDebug>
//#include "Info_Storage.h"

//Клас из 2 лабы
/*
class Storage_Camera {
    public:
        QString modul;
        int category_value;
        int producer_value;
        double matrix_px;
        QString dimension;
        int weight;
        int price;
        QDate date_release;
        bool IsDigital;
        bool LensOption;
        Storage_Camera() {
            modul = "";
            category_value = 0;
            producer_value = 0;
            matrix_px = 2;
            dimension = "00-00-00";
            weight = 100;
            price = 10000;
            date_release = QDate::currentDate();
            IsDigital = false;
            LensOption = false;
        }
};
*/

class Camera_Catalogy : public QMainWindow
{
    Q_OBJECT

public:
    Camera_Catalogy(QWidget *parent = Q_NULLPTR);
    //Base Items[2];
    
    //Создаем массив структур
    QVector <Base> Items;
    int sizeVector = 0;
    
    void Sort()
    {
        for (int i = 0; i < Items.count(); i++) {
            for (int j = 0; j < Items.count() - 1; j++) {
                if (Items[j] > Items[j + 1]) {
                    Base b = Items[j]; // создали дополнительную переменную
                    Items[j] = Items[j + 1]; // меняем местами
                    Items[j + 1] = b; // значения элементов
                }
            }
        }

    }
    //Storage_Camera* Items = new Storage_Camera[2];

    /*
    int Data_arr_size = 2; //Размер массива по умолчанию

    //Функция для переворачивания массива(нужна при удалении элемента)
    void Data_Reverse(Storage_Camera* Current_Arr, int Data_arr_size) {
        Storage_Camera* x = new Storage_Camera[Data_arr_size];

        for (int i = 0; i < (Data_arr_size/2); i++) {
            x[i] = Current_Arr[i];
            Current_Arr[i] = Current_Arr[Data_arr_size - i - 1];
            Current_Arr[Data_arr_size - i - 1] = x[i];
        }
        delete[]x;
    }
    */
    

private:
    Ui::Camera_CatalogyClass ui;
    private slots:
        //Кнопки из 2 лабы
        /*
        void slot_save1(); //Сохранить|Перезаписать первую запись
        void slot_save2(); //Сохранить|Перезаписать вторую запись
        void slot_show1(); //Показать данные первой записи
        void slot_show2(); //Показать данные второй записи
        */
        void slot_LensOptions(); //Чекбокс о возможностях смены объектива
        void slot_IsDigital(); //Чекбокс является ли камера цифровой
        void slot_ChooseCategory(); //Выбор категории камеры из выподающего списка
        void slot_ChooseProducer(); //Выбор производителя камеры из выподающего списка
        //Кнопки редактирования
        void slot_Add_data();
        void slot_Add_data10();
        void slot_Save_data();
        void slot_Delete_data();

        //Слот для браузера
        void slot_TableInfo();

        
};

//#endif // CAMERACATALOGY_H